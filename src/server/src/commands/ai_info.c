/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_info
*/

#include "server.h"

void ai_cmd_look(node_t *client, data_t *data,
char **params __attribute__((unused)))
{

}

void ai_cmd_inventory(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    inventory_t inv = client->client.inventory;

    dprintf(client->client.fd, "[ food %i, linemate %i, deraumere %i, \
sibur %i, mendiane %i, phiras %i, thystame %i ]\n", inv.food.quantity,
    inv.linemate.quantity, inv.deraumere.quantity, inv.sibur.quantity,
    inv.mendiane.quantity, inv.phiras.quantity, inv.thystame.quantity);
}

void ai_cmd_broadcast(node_t *client, data_t *data, char **params)
{

}
