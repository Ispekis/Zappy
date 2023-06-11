/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_action
*/

#include "server.h"

void ai_cmd_team_unused_slot(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    dprintf(client->client.fd, "%i\n", client->client.team->clients_nbr);
}

void ai_cmd_fork_player(node_t *client, data_t *data,
char **params __attribute__((unused)))
{

}

void ai_cmd_eject(node_t *client, data_t *data,
char **params __attribute__((unused)))
{

}
