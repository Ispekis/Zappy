/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** read_client
*/

#include "server.h"
#include "game_macro.h"
#include "macro.h"

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

void match_behavior(char *buffer, node_t *client, server_t *server)
{
    if (check_buffer_format(buffer)) {
        if (do_graphic_communication(buffer, client, server) == SUCCESS)
            return;
        if (do_ai_communication(buffer, client, server) == SUCCESS)
            return;
        dprintf(client->client.fd, "ko\n");
    }
}

void read_from_client(server_t *server, node_t *client)
{
    char buffer[1024];
    size_t bytes = 0;

    bytes = read(client->client.fd, buffer, 1024);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        match_behavior(buffer, client, server);
        memset(buffer, 0, sizeof(buffer));
    } else {
        printf("client %i has disconnected\n", client->client.fd);
        dprintf(server->data.graphic_fd, "pdi %i\n", client->client.fd);
        remove_client_node(&server->data.clients, client->client.fd);
    }
}
