/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** world_clock
*/

#include "server.h"

bool is_need_freeze_timer(client_t player)
{
    if (player.is_elevating) {
        if (player.elevation_triggerer)
            return false;
        else
            return true;
    } else {
        return false;
    }
}

void inc_players_timer(node_t *head)
{
    node_t *current = head;

    while (current != NULL) {
        if (is_ai_player(current->client) && current->client.nb_await_cmd > 0
            && !is_need_freeze_timer(current->client))
            current->client.timer++;
        current = current->next;
    }
}

void handle_world_clock(server_t *server)
{
    uint64_t num_exp;
    ssize_t bytes;

    if (FD_ISSET(server->data.w_clock.tfd, &server->addrs.rfds)) {
        bytes = read(server->data.w_clock.tfd, &num_exp, sizeof(uint64_t));
        server->data.food_eat_tick++;
        server->data.food_refill_res++;
        inc_players_timer(server->data.clients);
        eat_food(&server->data);
        refill_resources(&server->data);
    }
}
