/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** main
*/

#include "server.h"

static void show_usage(const char *binary, int fd)
{
    dprintf(fd, "USAGE:\t%s -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n", binary);
    dprintf(fd, "\tport\t\tis the port number\n");
    dprintf(fd, "\twidth\t\tis the width of the world\n");
    dprintf(fd, "\theight\t\tis the height of the world\n");
    dprintf(fd, "\tnameX\t\tis the name of the team X\n");
    dprintf(fd, "\tclientsNb\tis the number of authorized clients per team\n");
    dprintf(fd, "\tfreq\t\tis the reciprocal of time unit for execution of actions\n");
}

int main(const int ac, const char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        show_usage(av[0], STDOUT_FILENO);
        return 0;
    }
    printf("Server here !\n");
    return 0;
}
