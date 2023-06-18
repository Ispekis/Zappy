/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** command_tools
*/

#include "server.h"

int get_cmd_pos(char *str, const char **lib)
{
    for (int i = 0; lib[i] != NULL; i++) {
        if (strcmp(str, lib[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void set_cooldown_in_nanosec(node_t *player, uint64_t nseconds)
{
    int sec = (nseconds / 1000000000);
    player->client.timer_spec.it_value.tv_sec = sec;
    player->client.timer_spec.it_value.tv_nsec = 0;
    timerfd_settime(player->client.tfd, 0, &player->client.timer_spec, NULL);
    if (sec > 0)
        player->client.is_ready = false;
}

void send_res_cd(node_t *client, int cooldown, int freq)
{
    dprintf(client->client.fd, "ok\n");
    set_cooldown_in_nanosec(client,
    sec_to_nanosec(((double) cooldown / (double) freq)));
}
