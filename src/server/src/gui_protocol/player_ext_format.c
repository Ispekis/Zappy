/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** player_ext_format
*/

#include "server.h"

void fmt_player_expulsion(int fd, client_t player)
{
    dprintf(fd, "pex %i\n", player.fd);
}

void fmt_player_broadcast(int fd, client_t player, char *msg)
{
    dprintf(fd, "pbc %i %s\n", player.fd, msg);
}

void fmt_player_dropping(int fd, client_t player, resource_t resource)
{
    dprintf(fd, "pdr %i %i\n", player.fd, resource.id);
}

void fmt_player_collecting(int fd, client_t player, resource_t resource)
{
    dprintf(fd, "pgt %i %i\n", player.fd, resource.id);
}
