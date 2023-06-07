/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** get_options
*/

#include "macro.h"
#include <stdio.h>
#include <unistd.h>
#include "server.h"

static int check_all_info_set(info_t info)
{
    if (info.port == -1 || info.width == -1 || info.height == -1
        || info.clients_nb == -1 || info.freq == -1 || info.teams_name == NULL)
        return write_error("All the option needs to be set : -help to display help message", ARG_ERROR_LABEL, FAILURE);
    if (info.port < 1 || info.port > 65535)
        return write_error("-p option only accepts integer values between 0 and 65535", ARG_ERROR_LABEL, FAILURE);
    if (info.width < 10 || info.width > 30)
        return write_error("-x option only accepts integer values between 10 and 30", ARG_ERROR_LABEL, FAILURE);
    if (info.height < 10 || info.height > 30)
        return write_error("-y option only accepts integer values between 10 and 30", ARG_ERROR_LABEL, FAILURE);
    if (info.clients_nb < 1)
        return write_error("-c option only accepts integer values greater or equal to 1", ARG_ERROR_LABEL, FAILURE);
    if (info.freq < 2 || info.freq > 10000)
        return write_error("-f option only accepts integer values between 2 and 10000", ARG_ERROR_LABEL, FAILURE);
    return SUCCESS;
}

static void free_team(char **teams_name)
{
    if (teams_name == NULL)
        return;
    for (int i = 0; teams_name[i] != NULL; i++) {
        free(teams_name[i]);
    }
    free(teams_name);
}

int get_options(const int ac, char *const *av, info_t *info)
{
    int opt = 0;
    int status = SUCCESS;

    set_non_set_info(info);
    while (opt != -1 && status == SUCCESS) {
        opt = getopt(ac, av, "p:x:y:n:c:f:");
        if (opt == '?') {
            status = FAILURE;
            break;
        }
        switch (opt) {
            case 'p':
                if (set_number_arg(&info->port) == FAILURE)
                    status = FAILURE;
                break;
            case 'x':
                if (set_number_arg(&info->width) == FAILURE)
                    status = FAILURE;
                break;
            case 'y':
                if (set_number_arg(&info->height) == FAILURE)
                    status = FAILURE;
                break;
            case 'n':
                // Check if its already set
                if (info->teams_name != NULL)
                    return write_error("Cannot set the same option", ARG_ERROR_LABEL, FAILURE);
                if (set_teams_name(ac, av, info) == FAILURE)
                    status = FAILURE;
                break;
            case 'c':
                if (set_number_arg(&info->clients_nb) == FAILURE)
                    status = FAILURE;
                break;
            case 'f':
                if (set_number_arg(&info->freq) == FAILURE)
                    status = FAILURE;
                break;
        }
    }
    if (status == FAILURE) {
        free_team(info->teams_name);
        return FAILURE;
    }
    if (check_all_info_set(*info) == FAILURE) {
        free_team(info->teams_name);
        return FAILURE;
    }
    return SUCCESS;
}
