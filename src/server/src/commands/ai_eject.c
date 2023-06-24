/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_eject
*/

#include "server.h"

static bool check_same_pos(pos_t pos1, pos_t pos2)
{
    if (pos1.x == pos2.x && pos1.y == pos2.y)
        return true;
    return false;
}

void eject_break_egg(client_t *client, data_t *data)
{
    node_t *current = data->egg;

    while (current != NULL) {
        if (check_same_pos(client->pos, current->egg.pos) == true) {
            remove_egg_node(&data->egg, current->egg.id);
        } else
            current = current->next;
    }
}
