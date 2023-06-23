/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** init_game
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

int init_game(data_t *data, info_t info)
{
    data->freq = info.freq;
    data->width = info.width;
    data->height = info.height;
    data->graphic_fd = UNDEFINED;
    data->egg = NULL;
    if (init_map(info.width, info.height, data) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
