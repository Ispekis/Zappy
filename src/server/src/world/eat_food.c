/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** eat_food
*/

#include "server.h"
#include "game_macro.h"

static void remove_foods(node_t *head)
{
    node_t *current = head;

    while (current != NULL) {
        if (is_ai_player(current->client)
        && current->client.inventory.food.quantity > 0)
            current->client.inventory.food.quantity--;
        current = current->next;
    }
}

void is_player_death(data_t *data, node_t *head)
{
    node_t *current = head;
    node_t *tmp = NULL;

    while (current != NULL) {
        if (is_ai_player(current->client)
        && current->client.inventory.food.quantity <= 0) {
            tmp = current;
            current = current->next;
            dprintf(tmp->client.fd, "dead\n");
            disconnect_player(data, tmp);
            continue;
        }
        current = current->next;
    }
}

void eat_food(data_t *data)
{
    if (data->food_eat_tick >= FOOD_LIVE_TIME) {
        remove_foods(data->clients);
        is_player_death(data, data->clients);
        data->food_eat_tick = 0;
    }
}
