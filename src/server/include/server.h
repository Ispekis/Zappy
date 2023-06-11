/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #define MAX_CONNECTIONS 100
    #include "game_macro.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/select.h>
    #include <signal.h>
    #include <sys/signalfd.h>
    #include <uuid/uuid.h>
    #include <time.h>
    #include "server_structs.h"

static const char *GUI_CMD_LIB[] __attribute__((unused)) = {
    "msz", "bct", "mct", "tna", "ppo", "plv", "pin", "sgt", "sst", NULL
};

static const char *AI_CMD_LIB[] __attribute__((unused)) = {
    "Forward", "Right", "Left", "Look", "Inventory", "Broadcast",
    "Connect_nbr", "Fork", "Eject", "Take", "Set", "Incantation", NULL
};

static const char *RESOURCES_LIB[] __attribute__((unused)) = {
    FOOD_NAME, LINEMATE_NAME, DERAUMERE_NAME, SIBUR_NAME, MENDIANE_NAME,
    PHIRAS_NAME, THYSTAME_NAME, NULL
};

enum gui_cmd_e {
    CMD_MSZ,
    CMD_BCT,
    CMD_MCT,
    CMD_TNA,
    CMD_PPO,
    CMD_PLV,
    CMD_PIN,
    CMD_SGT,
    CMD_SST
};

enum ai_cmd_e {
    CMD_FORWARD,
    CMD_RIGHT,
    CMD_LEFT,
    CMD_LOOK,
    CMD_INV,
    CMD_BROAD,
    CMD_CONN_NBR,
    CMD_FORK,
    CMD_EJECT,
    CMD_TAKE,
    CMD_SET,
    CMD_INC
};

void show_usage(const char *binary, int fd);

int get_options(const int ac, char *const *av, info_t *info);

// Buffer management
bool check_buffer_format(char *buffer);

// Tools
int write_error(char *message, char *label, int ret_value);
bool can_convert_to_int(const char* str);
int get_cmd_pos(char *str, const char **lib);
int rand_nbr(int min, int max);
char **str_to_word_array(char *buffer, char *sep);
void my_strcat(char **dest, char *src);

// Init
int init_server(server_t *server, int port);
int global_init(server_t *server, int port);
int init_game(data_t *data, info_t info);
void init_commands(server_t *server);

int run_server(server_t server);

int catch_shutdown(server_t server);

// Client management
void accept_client_to_server(server_t *server);
void read_from_client(server_t *server, node_t *client);

// Linked list utils
node_t *add_client_node(node_t **head);
void print_client_list(node_t *head);
void remove_client_node(node_t **head, int fd);
node_t *get_client_node(node_t **head, int fd);

// Set options
int set_number_arg(int *opt);
int set_teams_name(const int ac, char *const *av, info_t *info);
void set_non_set_info(info_t *info);
int check_all_info_set(info_t info);

// Memory handling
void global_free(server_t server);
void free_server(server_t server);
void free_game(data_t data, int height);

//** COMMANDS **//

// Graphic commands
int do_graphic_first_connect(char *buffer, node_t *client, data_t *data);
int do_graphic_communication(char *buffer, node_t *client, server_t *server);

// Ai commands
int do_ai_first_connect(char *buffer, node_t *client, data_t *data);
int do_ai_communication(char *buffer, node_t *client, server_t *server);

// Gui send commands
void send_map_size(int fd, data_t *data, char *params __attribute__((unused)));
void send_content_tile(int fd, data_t *data, char *params);
void send_content_map(int fd, data_t *data,
char *params __attribute__((unused)));
void send_teams_name(int fd, data_t *data,
char *params __attribute__((unused)));
void send_player_position(int fd, data_t *data, char *params);
void send_player_level(int fd, data_t *data, char *params);
void send_player_inventory(int fd, data_t *data, char *params);
void send_time_unit_request(int fd, data_t *data,
char *params __attribute__((unused)));
void send_time_unit_modif(int fd, data_t *data, char *params);

// Ai commands
void ai_cmd_forward(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_right(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_left(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_look(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_inventory(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_broadcast(node_t *client, data_t *data, char **params);
void ai_cmd_team_unused_slot(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_fork_player(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_eject(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_take_object(node_t *client, data_t *data, char **params);
void ai_cmd_set_object(node_t *client, data_t *data, char **params);
void ai_cmd_incantation(node_t *client, data_t *data,
char **params __attribute__((unused)));

void cross_map_border(int *x, int *y, data_t data);
tile_t get_correct_tile(tile_t **map, int x, int y, data_t data);

//** Utils **//

/**
 * @brief Get the number of players on tile
 *
 * @param pos
 * @param head
 * @return int
 */
int get_nb_players_on_tile(pos_t pos, node_t *head);

/**
 * @brief Get a linked list of player present on a tile
 *
 * @param pos
 * @param head
 * @return node_t*
 */
node_t *get_players_on_tile(pos_t pos, node_t *head);

/**
 * @brief Check if the concerned client is an ai client and its connected,
 * then its returning true else false
 *
 * @param player
 * @return true
 * @return false
 */
bool is_ai_player(client_t player);

/**
 * @brief Get a pointer of the resource by name in inventory, return NULL if
 * the resource are not found
 * @param name
 * @param inventory
 * @return resource_t*
 */
resource_t *get_resource_by_name_in_inventory(char *name,
inventory_t *inventory);

/**
 * @brief Get a pointer of the resource by name on a tile, return NULL if
 * the resource are not found
 * @param name
 * @param tile
 * @return resource_t*
 */
resource_t *get_resource_by_name_on_tile(char *name, tile_t *tile);

#endif /* !SERVER_H_ */
