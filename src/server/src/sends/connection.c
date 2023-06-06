/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** connection
*/

#include "server.h"

static void connect_player(client_t *client)
{
    client->is_conn = true;
    uuid_generate(client->uuid);
}

static bool add_player_to_team(char *name, int fd, node_t *current, info_t info)
{
    if (strcmp(name, current->team.name) == 0) {
        if (current->team.clients_nbr == 0)
            return false;
        current->team.clients_nbr -= 1;
        dprintf(fd, "%i\n", current->team.clients_nbr);
        dprintf(fd, "%i %i\n", info.width, info.height);
        return true;
    }
    return false;
}

void send_available_stock(char *name, int index, data_t *data, info_t info)
{
    node_t *current = data->teams;

    if (data->clients[index].is_conn) {
        dprintf(data->clients[index].fd, "ko\n");
        return;
    }
    while (current != NULL) {
        if (add_player_to_team(name, data->clients[index].fd, current, info)) {
            connect_player(&data->clients[index]);
            return;
        }
        current = current->next;
    }
    dprintf(data->clients[index].fd, "ko\n");
}
