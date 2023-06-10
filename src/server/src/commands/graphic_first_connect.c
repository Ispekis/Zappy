/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** graphic_fist_connect
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static void connect_player(node_t *client)
{
    client->client.is_conn = true;
    client->client.is_graphic = true;
}

static void display_connected_player(int fd, data_t data)
{
    node_t *current = data.clients;

    while (current != NULL) {
        if (current->client.is_conn && !current->client.is_graphic) {
            dprintf(fd, "pnw %i %i %i %i %i %s\n", current->client.fd,
            current->client.pos.x, current->client.pos.y,
            current->client.orientation, current->client.level,
            current->client.team->name);
        }
        current = current->next;
    }
}

static void send_first_connection_message(int fd, data_t data)
{
    send_map_size(fd, &data, "");
    dprintf(fd, "sgt 100\n");
    send_content_map(fd, &data, "");
    send_teams_name(fd, &data, "");
    display_connected_player(fd, data);
}

int do_graphic_first_connect(char *buffer, node_t *client, data_t *data)
{
    if (strcmp(buffer, GRAPHIC_TEAM_NAME) == 0) {
        connect_player(client);
        data->graphic_fd = client->client.fd;
        send_first_connection_message(client->client.fd, *data);
        return SUCCESS;
    }
    return FAILURE;
}
