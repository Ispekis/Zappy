/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_first_connect
*/

#include "server.h"
#include "macro.h"

static void connect_player(node_t *client)
{
    client->client.is_conn = true;
}

static int add_player_to_team(char *name, int fd, data_t *data)
{
    for (int i = 0; i < data->nb_teams; i++) {
        if (strcmp(name, data->teams[i].name) == 0
        && data->teams[i].clients_nbr > 0) {
            data->teams[i].clients_nbr--;
            dprintf(fd, "%i\n", data->teams[i].clients_nbr);
            dprintf(fd, "%i %i\n", data->width, data->height);
            return SUCCESS;
        }
    }
    return FAILURE;
}

int do_ai_first_connect(char *buffer, node_t *client, data_t *data)
{
    if (add_player_to_team(buffer, client->client.fd,
    data) == SUCCESS) {
        connect_player(client);
        return SUCCESS;
    }
    return FAILURE;
}
