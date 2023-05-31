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

typedef struct server_s {
    sock_addrs_t addrs;
    info_t info;
    int sfd;
    struct signalfd_siginfo fdsi;
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
int init_server(sock_addrs_t *addrs, int port);

int run_server(server_t server);

int catch_shutdown(server_t server);

#endif /* !SERVER_H_ */
