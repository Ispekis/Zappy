/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** graphic_communication
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

int do_graphic_communication(char *buffer, int index, data_t *data, info_t info)
{
    if (!data->clients[index].is_conn)
        if (do_graphic_first_connect(buffer, index, data, info) == SUCCESS)
            return SUCCESS;
    if (data->clients[index].is_graphic) {
        printf("from graphic\n");
        return SUCCESS;
    }
    return FAILURE;
}