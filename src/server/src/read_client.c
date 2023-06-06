/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** read_client
*/

#include "server.h"

static void do_remove_client(client_t *client)
{
    client->fd = -1;
    client->is_conn = false;
    uuid_clear(client->uuid);
}

static bool check_buffer_format(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            return true;
        }
    }
    return false;
}

void recv_from_client(server_t *server, int index)
{
    char buffer[1024];
    size_t bytes = 0;

    bytes = read(server->data.clients[index].fd, buffer, 1024);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        if (check_buffer_format(buffer))
            send_available_stock(buffer, index, &server->data, server->info);
        print_team_list(server->data.teams);
        memset(buffer, 0, sizeof(buffer));
    } else {
        printf("client %i has disconnected\n", server->data.clients[index].fd);
        do_remove_client(&server->data.clients[index]);
    }
}
