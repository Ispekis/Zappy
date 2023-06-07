/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_first_connect
*/

#include "server.h"
#include "macro.h"

static void connect_player(client_t *client)
{
    client->is_conn = true;
}

static int add_player_to_team(char *name, int fd, data_t *data, info_t info)
{
    for (int i = 0; i < data->nb_teams; i++) {
        if (strcmp(name, data->teams[i].name) == 0
        && data->teams[i].clients_nbr > 0) {
            data->teams[i].clients_nbr--;
            dprintf(fd, "%i\n", data->teams[i].clients_nbr);
            dprintf(fd, "%i %i\n", info.width, info.height);
            return SUCCESS;
        }
    }
    return FAILURE;
}

int do_ai_first_connect(char *buffer, int index, data_t *data, info_t info)
{
    if (add_player_to_team(buffer, data->clients[index].fd,
    data, info) == SUCCESS) {
        connect_player(&data->clients[index]);
        return SUCCESS;
    }
    return FAILURE;
}
