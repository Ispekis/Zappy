/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_look
*/

#include "server.h"

void cross_map_border(int *x, int *y, data_t data)
{
    if ((*x) > data.width - 1)
        (*x) = (*x) - data.width;
    if ((*y) > data.height - 1)
        (*y) = (*y) - data.height;
    if (*x < 0)
        *x = data.width - abs(*x);
    if ((*y) < 0)
        (*y) = data.height - abs(*y);
}

tile_t get_correct_tile(tile_t **map, int x, int y, data_t data)
{
    cross_map_border(&x, &y, data);
    return map[y][x];
}

void check_presence_on_tile(tile_t tile, char **msg)
{
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
        for (int y = 0; y < i; y++)
            check_presence_on_tile(get_correct_tile(data->map, pos.x - (y + 1),
            pos.y + i, *data), &msg);
        check_presence_on_tile(get_correct_tile(data->map, pos.x, pos.y + i,
        *data), &msg);
        for (int y = 0; y < i; y++)
            check_presence_on_tile(get_correct_tile(data->map, pos.x + (y + 1),
            pos.y + i, *data), &msg);
    }
    msg[strlen(msg) - 2] = '\0';
    my_strcat(&msg, " ]");
    dprintf(client->client.fd, "%s\n", msg);
    free(msg);
}