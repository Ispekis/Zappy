/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_info
*/

#include "server.h"
#include "macro.h"

void ai_cmd_inventory(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    inventory_t inv = client->client.inventory;

    dprintf(client->client.fd, "[ food %i, linemate %i, deraumere %i, \
sibur %i, mendiane %i, phiras %i, thystame %i ]\n", inv.food.quantity,
    inv.linemate.quantity, inv.deraumere.quantity, inv.sibur.quantity,
    inv.mendiane.quantity, inv.phiras.quantity, inv.thystame.quantity);
}

static void send_all_client(node_t *head, int current_fd, char *msg)
{
    node_t *current = head;

    while (current != NULL) {
        if (current->client.is_conn && !current->client.is_graphic
        && current->client.fd != current_fd) {
            dprintf(current->client.fd, "message %i, %s\n", 0, msg);
        }
        current = current->next;
    }
}

void ai_cmd_broadcast(node_t *client, data_t *data, char **params)
{
    if (params[0] == NULL) {
        fmt_cmd_parameter(client->client.fd);
    } else {
        if (data->graphic_fd != UNDEFINED)
            fmt_player_broadcast(data->graphic_fd, client->client, params[0]);
        send_all_client(data->clients, client->client.fd, params[0]);
        dprintf(client->client.fd, "ok\n");
    }
}
