/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** player_utils
*/

#include "server.h"

bool is_ai_player(client_t player)
{
    if (player.is_conn && !player.is_graphic)
        return true;
    return false;
}
