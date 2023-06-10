/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_info
*/

#include "server.h"

void cross_map_border(pos_t *pos, data_t data)
{
    if (pos->x > data.width)
        pos->x = pos->x - data.width - 1;
    if (pos->y > data.height)
        pos->y = pos->y - data.height - 1;
    if (pos->x < 0)
        pos->x = data.width - (pos->x - 1);
    if (pos->y < 0)
        pos->y = data.height - (pos->y - 1);
}

void check_presence_on_tile(tile_t **map, pos_t pos, data_t data, char **msg)
{
    tile_t tile;

    cross_map_border(&pos, data);
    tile = map[pos.y][pos.x];
    // Check player too
    for (int i = 0; i < tile.food.quantity; i++)
        my_strcat(msg, "food ");
    for (int i = 0; i < tile.linemate.quantity; i++)
        my_strcat(msg, "linemate ");
    for (int i = 0; i < tile.deraumere.quantity; i++)
        my_strcat(msg, "deraumere ");
    for (int i = 0; i < tile.sibur.quantity; i++)
        my_strcat(msg, "sibur ");
    for (int i = 0; i < tile.phiras.quantity; i++)
        my_strcat(msg, "phiras ");
    for (int i = 0; i < tile.thystame.quantity; i++)
        my_strcat(msg, "thystame ");
    (*msg)[strlen((*msg)) - 1] = '\0';
    my_strcat(msg, ", ");
}

void ai_cmd_look(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    char *msg = NULL;
    pos_t pos = client->client.pos;

    msg = strdup("[ player ");
    for (int i = 0; i < client->client.level + 1; i++) {
        for (int y = 0; y < i; y++) {
            check_presence_on_tile(data->map, (pos_t) {pos.x - y, pos.y + i}, *data, &msg);
        }
        for (int y = 0; y < i; y++) {
            check_presence_on_tile(data->map, (pos_t) {pos.x + y, pos.y + i}, *data, &msg);
        }
    }
    // msg = my_strcat(msg, "ok");
    printf("%s\n", msg);
    free(msg);
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
