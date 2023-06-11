/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** egg_format
*/

#include "server.h"

void fmt_player_egg_laying(int fd, client_t player)
{
    dprintf(fd, "pfk %i\n", player.fd);
}

void fmt_egg_laid(int fd, int egg_nb, client_t player, pos_t pos)
{
    dprintf(fd, "enw %i %i %i %i\n", egg_nb, player.fd, pos.x, pos.y);
}

void fmt_egg_conn(int fd, int egg_nb)
{
    dprintf(fd, "ebo %i\n", egg_nb);
}

void fmt_egg_death(int fd, int egg_nb)
{
    dprintf(fd, "edi %i\n", egg_nb);
}
