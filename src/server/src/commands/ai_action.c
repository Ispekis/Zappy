/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_action
*/

#include "server.h"

void ai_cmd_team_unused_slot(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    dprintf(client->client.fd, "%i\n", client->client.team->clients_nbr);
}

void ai_cmd_fork_player(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    client = client;
    data = data;
}

static void move_player(node_t *player, int orient, int width, int height)
{
    switch (orient) {
        case NORTH:
                player->client.pos.y++;
            break;
        case EAST:
                player->client.pos.x++;
            break;
        case SOUTH:
                player->client.pos.y--;
            break;
        case WEST:
                player->client.pos.x--;
            break;
    }
    cross_map_border(&player->client.pos.x, &player->client.pos.y, width,
    height);
}

void ai_cmd_eject(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    node_t *current = NULL;

    if (get_nb_players_on_tile(client->client.pos, data->clients) <= 1) {
        dprintf(client->client.fd, "ko\n");
        return;
    }
    current = data->clients;
    fmt_player_expulsion(data->graphic_fd, client->client);
    while (current != NULL) {
        if (is_ai_player(current->client)
        && current->client.fd != client->client.fd) {
            move_player(current, client->client.orientation, data->width,
            data->height);
            fmt_player_pos(data->graphic_fd, current->client);
        }
        current = current->next;
    }
    send_res_cd(client, COOLDOWN_EJECT, data->freq);
}
