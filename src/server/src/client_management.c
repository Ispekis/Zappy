/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** client_management
*/

#include "server.h"

static void add_client(client_t *clients, int client_fd)
{
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (clients[i].fd < 0) {
            clients[i].fd = client_fd;
            // uuid_generate(clients[i].uuid);
            break;
        }
    }
}

void accept_client_to_server(server_t *server)
{
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    int client_fd = accept(server->addrs.socket_fd,
    (struct sockaddr *) &client, &len);

    if (client_fd >= 0) {
        printf("Connection from %s:%d\n", inet_ntoa(client.sin_addr),
        client.sin_port);
        add_client(server->data.clients, client_fd);
        dprintf(client_fd, "Welcome\n");
    }
}

static void do_remove_client(client_t *client)
{
    client->fd = -1;
    client->is_conn = false;
    uuid_clear(client->uuid);
}

static void recv_from_client(server_t *server, int index)
{
    char buffer[1024];
    size_t bytes = 0;

    bytes = read(server->data.clients[index].fd, buffer, 1024);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        send_available_stock(buffer, server->data.clients[index].fd, server->data, server->info);
        memset(buffer, 0, sizeof(buffer));
    } else {
        printf("client %i has disconnected\n", server->data.clients[index].fd);
        do_remove_client(&server->data.clients[index]);
    }
}

void read_from_client(server_t *server, int index)
{


    if (FD_ISSET(server->data.clients[index].fd, &server->addrs.rfds)) {
        if (server->data.clients[index].fd >= 0 &&
        server->data.clients[index].fd != server->addrs.socket_fd) {
            recv_from_client(server, index);
        }
    }
}
