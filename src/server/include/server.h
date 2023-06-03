/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <signal.h>
    #include <sys/signalfd.h>
    #include <uuid/uuid.h>
    #define MAX_CONNECTIONS 100

typedef struct team_s {
    char *name;
    int clients_nbr;
} team_t;

typedef struct node_s {
    team_t team;
    struct node_s *next;
} node_t;

typedef struct client_s {
    int fd;
    bool is_conn;
    uuid_t uuid;
} client_t;

typedef struct info_s {
    int port;
    int width;
    int height;
    char **teams_name;
    int clients_nb;
    float freq;
} info_t;

typedef struct sock_addrs_s {
    struct sockaddr_in server;
    struct timeval timeout;
    int socket_fd;
    int name;
    int status;
    fd_set rfds;
} sock_addrs_t;

typedef struct data_s {
    client_t clients[MAX_CONNECTIONS];
    node_t *teams;
} data_t;

typedef struct server_s {
    sock_addrs_t addrs;
    info_t info;
    int sfd;
    struct signalfd_siginfo fdsi;
    data_t data;
} server_t;

void show_usage(const char *binary, int fd);

int get_options(const int ac, char *const *av, info_t *info);

// Tools
size_t get_array_length(char** array);
int write_error(char *message, char *label, int ret_value);
bool can_convert_to_int(const char* str);
bool can_convert_to_float(const char* str);
bool is_int(int value);
bool is_float(float value);

// Init
int init_server(server_t *server, int port);

int run_server(server_t server);

int catch_shutdown(server_t server);

// Client management
void accept_client_to_server(server_t *server);
void read_from_client(server_t *server, int index);

// Team linked list utils
void print_team_list(node_t *head);
void add_team_node(node_t **head, const char *name, int clients_nbr);

#endif /* !SERVER_H_ */
