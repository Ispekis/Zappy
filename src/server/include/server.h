/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #define MAX_CONNECTIONS 100
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/select.h>
    #include <signal.h>
    #include <sys/signalfd.h>
    #include <uuid/uuid.h>
    #include "server_structs.h"

enum gui_cmd_e {
    MSZ,
    BCT,
    MCT,
    TNA,
    PPO,
    PLV,
    PIN,
    SGT,
    SST
};

void show_usage(const char *binary, int fd);

int get_options(const int ac, char *const *av, info_t *info);

// Tools
size_t get_array_length(char** array);
int write_error(char *message, char *label, int ret_value);
bool can_convert_to_int(const char* str);

// Init
int init_server(server_t *server, int port);
int global_init(server_t *server, int port);
int init_game(data_t *data, info_t info);
void init_commands(server_t *server);

int run_server(server_t server);

int catch_shutdown(server_t server);

// Client management
void accept_client_to_server(server_t *server);
void read_from_client(server_t *server, int index);

// Team linked list utils
void print_team_list(node_t *head);
void add_team_node(node_t **head, const char *name, int clients_nbr);

// Sends fonctions
void send_available_stock(char *name, int index, data_t *data, info_t info);

void recv_from_client(server_t *server, int index);

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
int do_graphic_first_connect(char *buffer, int index, data_t *data);
int do_graphic_communication(char *buffer, int index, data_t *data);

// Ai commands
int do_ai_first_connect(char *buffer, int index, data_t *data);
int do_ai_communication(char *buffer, int index, data_t *data);

// Gui send commands
void send_map_size(int fd, data_t data, char **params);
void send_content_tile(int fd, data_t data, char **params);
void send_content_map(int fd, data_t data, char **params);
void send_teams_name(int fd, data_t data, char **params);
void send_player_position(int fd, data_t data, char **params);
void send_player_level(int fd, data_t data, char **params);
void send_player_inventory(int fd, data_t data, char **params);
void send_time_unit_request(int fd, data_t data, char **params);
void send_time_unit_modif(int fd, data_t data, char **params);

#endif /* !SERVER_H_ */
