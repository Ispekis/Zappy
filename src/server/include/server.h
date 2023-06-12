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

/**
 * @brief Gui commands library for his array of pointer on function
 *
 * @return const char*[]
 */
static const char *GUI_CMD_LIB[] __attribute__((unused)) = {
    "msz", "bct", "mct", "tna", "ppo", "plv", "pin", "sgt", "sst", NULL
};


/**
 * @brief Ai commands library for his array of pointer on function
 *
 * @return const char*[]
 */
static const char *AI_CMD_LIB[] __attribute__((unused)) = {
    "Forward", "Right", "Left", "Look", "Inventory", "Broadcast",
    "Connect_nbr", "Fork", "Eject", "Take", "Set", "Incantation", NULL
};

static const char *RESOURCES_LIB[] __attribute__((unused)) = {
    FOOD_NAME, LINEMATE_NAME, DERAUMERE_NAME, SIBUR_NAME, MENDIANE_NAME,
    PHIRAS_NAME, THYSTAME_NAME, NULL
};

/**
 * @brief Enumeration for the gui commands
 *
 */
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

/**
 * @brief Enumeration for the ai commands
 *
 */
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

/**
 * @brief Display the usage with the fd specification
 *
 * @param binary
 * @param fd
 */
void show_usage(const char *binary, int fd);

/**
 * @brief Fill the info_t struct with all the parameters
 *
 * @param ac
 * @param av
 * @param info
 * @return FAILURE(-1) if there are missing parameters, SUCCESS(0) instead
 */
int get_options(const int ac, char *const *av, info_t *info);

//** Buffer management *//

/**
 * @brief Check if the buffer is correctly formated, if so then return true and
 * reformate the buffer, else return false
 *
 * @param buffer
 * @return true
 * @return false
 */
bool check_buffer_format(char *buffer);

//** Tools **//

/**
 * @brief Write a message on the standart error, if a label is specified
 * (!= NULL) then print the label in front. return the expected return value
 *
 * @param message
 * @param label
 * @param ret_value
 * @return int
 */
int write_error(char *message, char *label, int ret_value);

/**
 * @brief Check if a string can be converted to int
 *
 * @param str
 * @return true
 * @return false
 */
bool can_convert_to_int(const char* str);

/**
 * @brief Get the index of an element in the lib with the str
 *
 * @param str
 * @param lib
 * @return int
 */
int get_cmd_pos(char *str, const char **lib);

/**
 * @brief Generate random number with a minimum and a maximum
 *
 * @param min
 * @param max
 * @return int
 */
int rand_nbr(int min, int max);

/**
 * @brief Convert a string to an array of string
 *
 * @param buffer
 * @param sep
 * @return char**
 */
char **str_to_word_array(char *buffer, char *sep);

/**
 * @brief Do a strcat without needed to alloc memory before
 *
 * @param dest
 * @param src
 */
void my_strcat(char **dest, char *src);

//** Init **//

/**
 * @brief Init all the data related to the server
 *
 * @param server
 * @param port
 * @return int
 */
int init_server(server_t *server, int port);

/**
 * @brief Init all the data
 *
 * @param server
 * @param port
 * @return int
 */
int global_init(server_t *server, int port);

/**
 * @brief Init all the data related to the game
 *
 * @param data
 * @param info
 * @return int
 */
int init_game(data_t *data, info_t info);

/**
 * @brief Init array of pointer on functions
 *
 * @param server
 */
void init_commands(server_t *server);

/**
 * @brief Launch the server
 *
 * @param server
 * @return int
 */
int run_server(server_t server);

/**
 * @brief Catch SIGINT signal, then free all the memory
 *
 * @param server
 * @return int
 */
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

void cross_map_border(int *x, int *y, int width, int height);
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

//** GUI PROTOCOL FORMATS **//

void fmt_player_egg_laying(int fd, client_t player);

void fmt_egg_laid(int fd, int egg_nb, client_t player, pos_t pos);

void fmt_egg_conn(int fd, int egg_nb);

void fmt_egg_death(int fd, int egg_nb);

void fmt_player_start_incantation(int fd);

void fmt_player_end_incantation(int fd);

void fmt_map_size(int fd, int width, int height);

void fmt_content_of_tile(int fd, tile_t tile);

void fmt_content_of_map(int fd, tile_t **map, int width, int height);

void fmt_end_of_game(int fd, char *team_name);

void fmt_msg_from_server(int fd, char *msg);

void fmt_unknown_cmd(int fd);

void fmt_cmd_parameter(int fd);

void fmt_player_expulsion(int fd, client_t player);

void fmt_player_broadcast(int fd, client_t player, char *msg);

void fmt_player_dropping(int fd, client_t player, resource_t resource);

void fmt_player_collecting(int fd, client_t player, resource_t resource);

void fmt_conn_new_player(int fd, client_t player);

void fmt_player_pos(int fd, client_t player);

void fmt_player_lvl(int fd, client_t player);

void fmt_player_inv(int fd, client_t player);

void fmt_player_death(int fd, client_t player);

void fmt_name_of_teams(int fd, team_t *teams, int nb_teams);

void fmt_tm_request(int fd, int time);

void fmt_tm_modification(int fd, int time);

#endif /* !SERVER_H_ */
