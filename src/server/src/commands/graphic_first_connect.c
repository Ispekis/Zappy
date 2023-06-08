/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** graphic_fist_connect
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static void connect_player(client_t *client)
{
    client->is_conn = true;
    client->is_graphic = true;
}

static void send_first_connection_message(int fd, data_t data)
{
    char *msg = "";
    dprintf(fd, "msg %i %i\n", data.width, data.height);
    dprintf(fd, "sgt 100\n");
    for (int y = 0; y < data.height; y++) {
        for (int x = 0; x < data.width; x++) {
            dprintf(fd, "bct %i %i %i %i %i %i %i %i %i\n", x,
            y, data.map[y][x].food.quantity, data.map[y][x].linemate.quantity,
            data.map[y][x].deraumere.quantity, data.map[y][x].sibur.quantity,
            data.map[y][x].mendiane.quantity, data.map[y][x].phiras.quantity,
            data.map[y][x].thystame.quantity);
        }
    }
    for (int i = 0; i < data.nb_teams; i++) {
        dprintf(fd, "tna %s\n", data.teams[i].name);
    }
}

int do_graphic_first_connect(char *buffer, int index, data_t *data)
{
    if (strcmp(buffer, GRAPHIC_TEAM_NAME) == 0) {
        connect_player(&data->clients[index]);
        send_first_connection_message(data->clients[index].fd, *data);
        return SUCCESS;
    }
    return FAILURE;
}
