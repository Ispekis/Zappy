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

int do_graphic_first_connect(char *buffer, int index, data_t *data, info_t info)
{
    if (strcmp(buffer, GRAPHIC_TEAM_NAME) == 0) {
        connect_player(&data->clients[index]);
        dprintf(data->clients[index].fd, "HELLO GRAPHIC\n");
        return SUCCESS;
    }
    return FAILURE;
}
