/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** server
*/

#include "server.h"
#include "macro.h"

void re_set_fds(server_t *server, int sfd)
{
    FD_ZERO(&server->addrs.rfds);
    FD_SET(sfd, &server->addrs.rfds);
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (server->data.clients[i].fd >= 0) {
            FD_SET(server->data.clients[i].fd, &server->addrs.rfds);
        }
    }
}

int block_signal(int *sfd)
{
    sigset_t mask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &mask, NULL) == -1)
        return 1;
    *sfd = signalfd(-1, &mask, 0);
    if (*sfd == -1)
        return 1;
    return 0;
}

static int listen_events(server_t *server)
{
    if (FD_ISSET(server->addrs.socket_fd, &server->addrs.rfds)) {
        accept_client_to_server(server);
    }
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        read_from_client(server, i);
    }
    return 0;
}

int run_server(server_t server)
{
    printf("Server here !\n");
    block_signal(&server.sfd);

    while (true) {
        re_set_fds(&server, server.sfd);
        if (select(FD_SETSIZE, &server.addrs.rfds, NULL, NULL, NULL) < 0)
            return FAILURE;
        if (catch_shutdown(server) == 1) {
            break;
        }
        if (listen_events(&server) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}