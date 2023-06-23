/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** free_game
*/

#include "server.h"

static void free_teams(data_t data)
{
    for (int i = 0; i < data.nb_teams; i++)
        free(data.teams[i].name);
    free(data.teams);
}

static void free_eggs(node_t *head)
{
    node_t *current = head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_map(data_t data, int height)
{
    for (int y = 0; y < height; y++) {
        free(data.map[y]);
    }
    free(data.map);
}

void free_game(data_t data, int height)
{
    free_teams(data);
    free_map(data, height);
    free_eggs(data.egg);
}
