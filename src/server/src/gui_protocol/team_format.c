/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** team_format
*/

#include "server.h"

void fmt_name_of_teams(int fd, team_t *teams, int nb_teams)
{
    for (int i = 0; i < nb_teams; i++) {
        dprintf(fd, "tna %s\n", teams[i].name);
    }
}
