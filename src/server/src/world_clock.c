/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** world_clock
*/

#include "server.h"

static void remove_foods(node_t *head)
{
    node_t *current = head;

    while (current != NULL) {
        if (is_ai_player(current->client)
        && current->client.inventory.food.quantity > 0)
            current->client.inventory.food.quantity--;
        current = current->next;
    }
}

void is_player_death(data_t *data, node_t *head)
{
    node_t *current = head;
    node_t *tmp = NULL;

    while (current != NULL) {
        if (is_ai_player(current->client)
        && current->client.inventory.food.quantity <= 0) {
            tmp = current;
            current = current->next;
            dprintf(tmp->client.fd, "dead\n");
            disconnect_player(data, tmp);
            continue;
        }
        current = current->next;
    }
}

void handle_world_clock(server_t *server)
{
    uint64_t num_exp;
    ssize_t bytes;

    if (FD_ISSET(server->data.w_clock.tfd, &server->addrs.rfds)) {
        bytes = read(server->data.w_clock.tfd, &num_exp, sizeof(uint64_t));
        remove_foods(server->data.clients);
        is_player_death(&server->data, server->data.clients);
    }
}