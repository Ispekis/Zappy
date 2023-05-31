/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** server
*/

#include "server.h"
#include "macro.h"

void re_set_fds(sock_addrs_t *addrs, int sfd)
{
    FD_ZERO(&addrs->rfds);
    FD_SET(sfd, &addrs->rfds);
    // for (int i = 0; i < MAX_CONNECTIONS; i++) {
    //     if (addrs->clients[i].fd >= 0) {
    //         FD_SET(addrs->clients[i].fd, &addrs->rfds);
    //     }
    // }
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

int run_server(server_t server)
{
    printf("Server here !\n");
    block_signal(&server.sfd);
    while (true) {
        re_set_fds(&server.addrs, server.sfd);
        if (select(FD_SETSIZE, &server.addrs.rfds, NULL, NULL, NULL) < 0)
            return FAILURE;
        if (catch_shutdown(server) == 1) {
            break;
        }
    }
    return SUCCESS;
}