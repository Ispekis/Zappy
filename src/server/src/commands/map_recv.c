/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** map_recv
*/

#include "server.h"
#include "macro.h"

void send_map_size(int fd, data_t *data, char *params  __attribute__((unused)))
{
    dprintf(fd, "msz %i %i\n", data->width, data->height);
}

static int set_params(int *x, int *y, char *params)
{
    char *str_token = str_token = strtok(params, " ");
    if (str_token != NULL && can_convert_to_int(str_token)) {
        (*x) = atoi(str_token);
    } else {
        return FAILURE;
    }
    str_token = strtok(NULL, " ");
    if (str_token != NULL && can_convert_to_int(str_token)) {
        (*y) = atoi(str_token);
    } else {
        return FAILURE;
    }
    return SUCCESS;
}

void send_content_tile(int fd, data_t *data, char *params)
{
    int x = 0;
    int y = 0;

    if (params == NULL || set_params(&x, &y, params) == FAILURE) {
        dprintf(fd, "sbp\n");
    } else {
        if ((x >= 0 && x <= data->width - 1)
        && (y >= 0 && y <= data->height -1))
            dprintf(fd, "bct %i %i %i %i %i %i %i %i %i\n", x, y,
            data->map[y][x].food.quantity, data->map[y][x].linemate.quantity,
            data->map[y][x].deraumere.quantity, data->map[y][x].sibur.quantity,
            data->map[y][x].mendiane.quantity, data->map[y][x].phiras.quantity,
            data->map[y][x].thystame.quantity);
        else
            dprintf(fd, "sbp\n");
    }
}

void send_content_map(int fd, data_t *data,
char *params __attribute__((unused)))
{
    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            dprintf(fd, "bct %i %i %i %i %i %i %i %i %i\n", x,
            y, data->map[y][x].food.quantity, data->map[y][x].linemate.quantity,
            data->map[y][x].deraumere.quantity, data->map[y][x].sibur.quantity,
            data->map[y][x].mendiane.quantity, data->map[y][x].phiras.quantity,
            data->map[y][x].thystame.quantity);
        }
    }
}

void send_teams_name(int fd, data_t *data, char *params __attribute__((unused)))
{
    for (int i = 0; i < data->nb_teams; i++) {
        dprintf(fd, "tna %s\n", data->teams[i].name);
    }
}
