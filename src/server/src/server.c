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
    node_t *current = server->data.clients;

    FD_ZERO(&server->addrs.rfds);
    FD_SET(sfd, &server->addrs.rfds);
    FD_SET(server->data.w_clock.tfd, &server->addrs.rfds);
    while (current != NULL) {
        if (current->client.fd >= 0) {
            FD_SET(current->client.fd, &server->addrs.rfds);
        }
        if (current->client.tfd >= 0) {
            FD_SET(current->client.tfd, &server->addrs.rfds);
        }
        current = current->next;
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
    node_t *current = NULL;

    if (FD_ISSET(server->addrs.socket_fd, &server->addrs.rfds))
        accept_client_to_server(server);
    handle_world_clock(server);
    current = server->data.clients;
    while (current != NULL) {
        if (FD_ISSET(current->client.tfd, &server->addrs.rfds))
            current->client.is_ready = true;
        if (current->client.is_ready && current->client.is_elevating)
            elevate_player(current, &server->data);
        execute_waiting_cmd(current, server);
        if (FD_ISSET(current->client.fd, &server->addrs.rfds)
        && current->client.fd != server->addrs.socket_fd) {
            read_from_client(server, current);
            break;
        }
        current = current->next;
    }
    return 0;
}

int run_server(server_t server)
{
    printf("Server Started!\n");
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
