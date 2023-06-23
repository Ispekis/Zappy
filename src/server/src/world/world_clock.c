/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** world_clock
*/

#include "server.h"

void handle_world_clock(server_t *server)
{
    uint64_t num_exp;
    ssize_t bytes;

    if (FD_ISSET(server->data.w_clock.tfd, &server->addrs.rfds)) {
        bytes = read(server->data.w_clock.tfd, &num_exp, sizeof(uint64_t));
        server->data.food_eat_tick++;
        server->data.food_refill_res++;
        eat_food(&server->data);
        refill_resources(&server->data);
    }
}
