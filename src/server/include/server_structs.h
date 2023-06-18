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
    #define TOTAL_GUI_CMD 9
    #define TOTAL_AI_CMD 12

enum orientation_e {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
};

/**
 * @brief Resources struct
 *
 */
typedef struct resource_s {
    int id;
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

typedef struct inventory_s {
    resource_t food;
    resource_t linemate;
    resource_t deraumere;
    resource_t sibur;
    resource_t mendiane;
    resource_t phiras;
    resource_t thystame;
} inventory_t;

/**
 * @brief Teams structure
 *
 */
typedef struct team_s {
    char *name;
    int clients_nbr;
} team_t;

typedef struct client_s {
    /**
     * @brief File descriptor of a player
     *
     */
    int fd;

    /**
     * @brief The timerfd of a player
     *
     */
    int tfd;
    /**
     * @brief Timer spec of the player
     *
     */
    struct itimerspec timer_spec;
    bool is_conn;
    bool is_graphic;
    pos_t pos;
    int orientation;
    int level;
    inventory_t inventory;
    team_t *team;
    bool is_ready;
} client_t;

/**
 * @brief Any nodes
 *
 */
typedef struct node_s {
    // team_t team;
    client_t client;
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
    node_t *clients;
    team_t *teams;
    int nb_teams;
    tile_t **map;
    int freq;
    int width;
    int height;
    int graphic_fd;
    /**
     * @brief Pointer to the rfds of the sock_addrs_t's struct
     *
     */
    fd_set *rfds;
} data_t;

typedef struct server_s {
    sock_addrs_t addrs;
    info_t info;
    int sfd;
    struct signalfd_siginfo fdsi;
    data_t data;
    void (*gui_cmd[TOTAL_GUI_CMD])(int fd, data_t *data, char *params);
    void (*ai_cmd[TOTAL_AI_CMD])(node_t *client, data_t *data, char **params);
} server_t;

#endif /* !SERVER_STRUCTS_H_ */
