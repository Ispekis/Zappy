/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** map_utils
*/

#include "server.h"

int get_nb_players_on_tile(pos_t pos, node_t *head)
{
    node_t *current = head;
    int count = 0;

    while (current != NULL) {
        if (is_ai_player(current->client) && pos.x == current->client.pos.x
        && pos.y == current->client.pos.y) {
            count++;
        }
        current = current->next;
    }
    return count;
}

node_t *get_players_on_tile(pos_t pos, node_t *head)
{
    node_t *current = head;

    while (current != NULL) {
        printf("%i\n", current->client.fd);
        current = current->next;
    }
    return NULL;
}
