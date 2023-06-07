/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** server_structs
*/

#ifndef SERVER_STRUCTS_H_
    #define SERVER_STRUCTS_H_
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <arpa/inet.h>

/**
 * @brief Resources struct
 * 
 */
typedef struct resource_s {
    float density;
    int quantity;
} resource_t;

/**
 * @brief Position structure
 *
 */
typedef struct pos_s {
    int x;
    int y;
} pos_t;

/**
 * @brief Teams structure
 * 
 */
typedef struct team_s {
    char *name;
    int clients_nbr;
} team_t;

/**
 * @brief Any nodes
 * 
 */
typedef struct node_s {
    // team_t team;
    struct node_s *next;
} node_t;

typedef struct tile_s {
    pos_t pos;
    resource_t food;
    resource_t linemate;
    resource_t deraumere;
    resource_t sibur;
    resource_t mendiane;
    resource_t phiras;
    resource_t thystame;
} tile_t;

typedef struct client_s {
    int fd;
    bool is_conn;
    bool is_graphic;
    uuid_t uuid;
} client_t;

typedef struct info_s {
    int port;
    int width;
    int height;
    char **teams_name;
    int nb_teams;
    int clients_nb;
    int freq;
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
    // node_t *teams;
    team_t *teams;
    int nb_teams;
    tile_t **map;
} data_t;

typedef struct server_s {
    sock_addrs_t addrs;
    info_t info;
    int sfd;
    struct signalfd_siginfo fdsi;
    data_t data;
} server_t;

#endif /* !SERVER_STRUCTS_H_ */
