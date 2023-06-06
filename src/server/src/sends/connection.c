/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** connection
*/

#include "server.h"

void send_available_stock(char *name, int fd, data_t data, info_t info)
{
    node_t *current = data.teams;
    // print_team_list(data.teams);
    while (current != NULL) {
        if (strcmp(name, current->team.name) == 0) {
            dprintf(fd, "%i\n", current->team.clients_nbr - 1);
            dprintf(fd, "%i %i\n", info.width, info.height);
            return;
        }
        current = current->next;
    }
    dprintf(fd, "Team not found\n");
}
