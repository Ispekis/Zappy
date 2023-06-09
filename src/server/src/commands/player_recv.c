/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** player_recv
*/

#include "server.h"
#include "macro.h"

static int get_right_params(int fd, data_t data, char *params, node_t **player)
{
    if (params == NULL || !can_convert_to_int(params)) {
        return FAILURE;
    }
    (*player) = get_client_node(&data.clients, atoi(params));
    if ((*player) == NULL) {
        return FAILURE;
    }
    if ((*player)->client.is_graphic)
        return FAILURE;
    return SUCCESS;
}

void send_player_position(int fd, data_t data, char *params)
{
    node_t *player = NULL;

    if (get_right_params(fd, data, params, &player) == FAILURE) {
        dprintf(fd, "sbp\n");
        return;
    }
    dprintf(fd, "ppo %i %i %i %i\n", player->client.fd, player->client.pos.x,
    player->client.pos.y, player->client.orientation);
}

void send_player_level(int fd, data_t data, char *params)
{
    node_t *player = NULL;

    if (get_right_params(fd, data, params, &player) == FAILURE) {
        dprintf(fd, "sbp\n");
        return;
    }
    dprintf(fd, "plv %i %i\n", player->client.fd, player->client.level);
}

void send_player_inventory(int fd, data_t data, char *params)
{
    node_t *player = NULL;

    if (get_right_params(fd, data, params, &player) == FAILURE) {
        dprintf(fd, "sbp\n");
        return;
    }
    dprintf(fd, "pin %i %i %i %i %i %i %i %i %i %i\n",
    player->client.fd, player->client.pos.x, player->client.pos.y,
    player->client.inventory.food.quantity,
    player->client.inventory.linemate.quantity,
    player->client.inventory.deraumere.quantity,
    player->client.inventory.sibur.quantity,
    player->client.inventory.mendiane.quantity,
    player->client.inventory.phiras.quantity,
    player->client.inventory.thystame.quantity);
}
