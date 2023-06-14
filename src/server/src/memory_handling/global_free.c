/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** global_free
*/

#include "server.h"

void global_free(server_t server)
{
    free_game(server.data, server.info.height);
    free_server(server);
}
