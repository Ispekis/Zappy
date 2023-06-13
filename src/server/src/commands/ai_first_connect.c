/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_first_connect
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static void connect_player(node_t *client, data_t data)
{
    client->client.is_conn = true;
    client->client.pos.x = rand_nbr(0, data.width - 1);
    client->client.pos.y = rand_nbr(0, data.height - 1);
    client->client.orientation = rand_nbr(1, NUMBER_OF_ORIENTATION);
    client->client.level = 1;
}

static team_t *add_player_to_team(char *name, int fd, data_t *data)
{
    for (int i = 0; i < data->nb_teams; i++) {
        if (strcmp(name, data->teams[i].name) == 0
        && data->teams[i].clients_nbr > 0) {
            data->teams[i].clients_nbr--;
            dprintf(fd, "%i\n", data->teams[i].clients_nbr);
            dprintf(fd, "%i %i\n", data->width, data->height);
            return &data->teams[i];
        }
    }
    return NULL;
}

int do_ai_first_connect(char *buffer, node_t *client, data_t *data)
{
    team_t *team = add_player_to_team(buffer, client->client.fd, data);
    if (team != NULL) {
        client->client.team = team;
        connect_player(client, *data);
        if (data->graphic_fd != UNDEFINED) {
            fmt_conn_new_player(data->graphic_fd, client->client);
        }
        return SUCCESS;
    }
    return FAILURE;
}
