/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** init_game
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static void set_default_resource(int width, int height, resource_t *resource,
float density)
{
    resource->density = density;
    resource->quantity = width * height * resource->density;
}

static int set_default_tile(int width, int height, tile_t *tile,
pos_t pos)
{
    tile->pos = pos;
    set_default_resource(width, height, &tile->food, FOOD_DENSITY);
    set_default_resource(width, height, &tile->linemate, LINEMATE_DENSITY);
    set_default_resource(width, height, &tile->deraumere, DERAUMERE_DENSITY);
    set_default_resource(width, height, &tile->sibur, SIBUR_DENSITY);
    set_default_resource(width, height, &tile->mendiane, MENDIANE_DENSITY);
    set_default_resource(width, height, &tile->phiras, PHIRAS_DENSITY);
    set_default_resource(width, height, &tile->thystame, THYSTAME_DENSITY);
    return SUCCESS;
}

static int init_map(int width, int height, data_t *data)
{
    data->map = malloc(sizeof(tile_t*) * (height + 1));
    if (data->map == NULL)
        return FAILURE;
    for (int i = 0; i < height; i++) {
        data->map[i] = malloc(sizeof(tile_t) * width);
        if (data->map[i] == NULL)
            return FAILURE;
        for (int y = 0; y < width; y++) {
            set_default_tile(width, height, &data->map[i][y],
            (pos_t){i, y});
        }
    }
    data->map[height] = NULL;
    return SUCCESS;
}

int init_game(data_t *data, info_t info)
{
    if (init_map(info.width, info.height, data) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
