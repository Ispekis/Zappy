/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** graphic_communication
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static void choose_cmd(char *buffer, int index, server_t *server)
{
    char *cmd = strtok(buffer, " ");
    char *params = NULL;
    int pos = 0;

    pos = get_cmd_pos(cmd);
    if (pos != -1) {
        params = strtok(NULL, "");
        server->gui_cmd[pos](server->data.clients[index].fd, server->data,
        params);
    } else {
        dprintf(server->data.clients[index].fd, "ko\n");
    }
}

int do_graphic_communication(char *buffer, int index, server_t *server)
{
    if (!server->data.clients[index].is_conn)
        if (do_graphic_first_connect(buffer, index, &server->data) == SUCCESS)
            return SUCCESS;
    if (server->data.clients[index].is_graphic) {
        choose_cmd(buffer, index, server);
        printf("from graphic\n");
        return SUCCESS;
    }
    return FAILURE;
}
