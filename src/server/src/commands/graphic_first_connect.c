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
    send_map_size(fd, data, "");
    dprintf(fd, "sgt 100\n");
    send_content_map(fd, data, "");
    send_teams_name(fd, data, "");
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
