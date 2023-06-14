/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_communication
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static int choose_cmd(char *buffer, node_t *client, server_t *server)
{
    char **params = str_to_word_array(buffer, " ");
    char **params_cpy = params;
    char *cmd = NULL;
    int pos = 0;

    if (params == NULL) {
        return FAILURE;
    }
    cmd = params[0];
    pos = get_cmd_pos(cmd, AI_CMD_LIB);
    if (pos != -1) {
        params_cpy++;
        server->ai_cmd[pos](client, &server->data, params_cpy);
    } else {
        dprintf(client->client.fd, "ko\n");
    }
    for (int i = 0; params[i] != NULL; i++)
        free(params[i]);
    free(params);
    return SUCCESS;
}

int do_ai_communication(char *buffer, node_t *client, server_t *server)
{
    if (!client->client.is_conn) {
        if (do_ai_first_connect(buffer, client, &server->data) == SUCCESS)
            return SUCCESS;
    } else {
        return choose_cmd(buffer, client, server);
    }
    return FAILURE;
}
