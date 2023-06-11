/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** misc_format
*/

#include <stdio.h>

void fmt_end_of_game(int fd, char *team_name)
{
    dprintf(fd, "seg %s\n", team_name);
}

void fmt_msg_from_server(int fd, char *msg)
{
    dprintf(fd, "smg %s\n", msg);
}

void fmt_unknown_cmd(int fd)
{
    dprintf(fd, "suc\n");
}

void fmt_cmd_parameter(int fd)
{
    dprintf(fd, "sbp\n");
}
