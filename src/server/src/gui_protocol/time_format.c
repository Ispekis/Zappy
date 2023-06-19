/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** time_format
*/

#include <stdio.h>

void fmt_tm_request(int fd, int time)
{
    dprintf(fd, "sgt %i\n", time);
}

void fmt_tm_modification(int fd, int time)
{
    dprintf(fd, "sst %i\n", time);
}
