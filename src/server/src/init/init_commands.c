/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** init_commands
*/

#include "server.h"

void init_commands(server_t *server)
{
    server->gui_cmd[MSZ] = send_map_size;
    server->gui_cmd[BCT] = send_content_tile;
    server->gui_cmd[MCT] = send_content_map;
    server->gui_cmd[TNA] = send_teams_name;
    server->gui_cmd[PPO] = send_player_position;
    server->gui_cmd[PLV] = send_player_level;
    server->gui_cmd[PIN] = send_player_inventory;
    server->gui_cmd[SGT] = send_time_unit_request;
    server->gui_cmd[SST] = send_time_unit_modif;
}
