/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** free_server
*/

#include "server.h"

static void free_clients(node_t *head)
{
    node_t *current = head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_server(server_t server)
{
    for (int i = 0; server.info.teams_name[i] != NULL; i++)
        free(server.info.teams_name[i]);
    free(server.info.teams_name);
    free_clients(server.data.clients);
}
