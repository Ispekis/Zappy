/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** init
*/

#include "server.h"
#include "macro.h"

static int create_server(sock_addrs_t *addrs, int port)
{
    addrs->server.sin_family = AF_INET;
    addrs->server.sin_port = htons(port);
    addrs->server.sin_addr.s_addr = INADDR_ANY;
    addrs->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (addrs->socket_fd < 0)
        return FAILURE;
    addrs->name = bind(addrs->socket_fd,
    (const struct sockaddr *) &addrs->server, sizeof(addrs->server));
    if (addrs->name < 0)
        return FAILURE;
    addrs->status = listen(addrs->socket_fd, MAX_CONNECTIONS);
    if (addrs->status < 0)
        return FAILURE;
    FD_ZERO(&addrs->rfds);
    return SUCCESS;
}

int init_server(sock_addrs_t *addrs, int port)
{
    if (create_server(addrs, port) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
