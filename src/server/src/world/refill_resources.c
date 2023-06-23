/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** world_refill_clock
*/

#include "server.h"
#include "game_macro.h"

void check_resources_on_tiles(data_t *data, inventory_t *inv)
{
    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            inv->linemate.quantity -= data->map[y][x].linemate.quantity;
            inv->deraumere.quantity -= data->map[y][x].deraumere.quantity;
            inv->sibur.quantity -= data->map[y][x].sibur.quantity;
            inv->mendiane.quantity -= data->map[y][x].mendiane.quantity;
            inv->phiras.quantity -= data->map[y][x].phiras.quantity;
            inv->thystame.quantity -= data->map[y][x].thystame.quantity;
        }
    }
}

inventory_t get_resources_on_map(data_t *data)
{
    inventory_t resources;

    resources = data->max_res;
    resources.food.quantity = 5;
    check_resources_on_tiles(data, &resources);
    set_rand_resource_in_tiles(data, resources);
    printf("%i\n", resources.linemate.quantity);

}

void refill_resources(data_t *data)
{
    if (data->food_refill_res >= COOLDOWN_REFILL) {
        get_resources_on_map(data);
        data->food_refill_res = 0;
    }
}
