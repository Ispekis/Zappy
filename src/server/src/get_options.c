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

static void set_non_set_info(info_t *info)
{
    info->port = -1;
    info->width = -1;
    info->height = -1;
    info->clients_nb = -1;
    info->freq = -1;
    info->teams_name = NULL;
}

static int check_all_info_set(info_t info)
{
    if (info.port == -1 || info.width == -1 || info.height == -1
        || info.clients_nb == -1 || info.freq == -1)
        return FAILURE;
    if (info.teams_name == NULL)
        return FAILURE;
    return SUCCESS;
}

static int set_teams_name(const int ac, char *const *av, info_t *info)
{
    int count = ac - optind + 1;

    info->teams_name = malloc(sizeof(char*) * (count + 1));
    if (info->teams_name == NULL)
        return FAILURE;
    for (int i = 0; i < count; i++) {
        info->teams_name[i] = strdup(av[optind + i - 1]);
    }
    info->teams_name[count] = NULL;
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

static int set_number_arg(int *opt)
{
    // Check if its already set
    if (*opt != -1)
        return write_error("Cannot set the same option", ARG_ERROR_LABEL, FAILURE);
    if (!can_convert_to_int(optarg))
        return write_error("Cannot convert port to number", ARG_ERROR_LABEL, FAILURE);
    *opt = atoi(optarg);
    return SUCCESS;
}

static int set_float_arg(float *opt)
{
    // Check if its already set
    if (*opt != -1)
        return write_error("Cannot set the same option", ARG_ERROR_LABEL, FAILURE);
    if (!can_convert_to_float(optarg))
        return write_error("Cannot convert port to number", ARG_ERROR_LABEL, FAILURE);
    *opt = atof(optarg);
    return SUCCESS;
}

int get_options(const int ac, char *const *av, info_t *info)
{
    int opt = 0;

    set_non_set_info(info);
    while (opt != -1) {
        opt = getopt(ac, av, "p:x:y:n:c:f:");
        if (opt == '?') {
            free_team(info->teams_name);
            return FAILURE;
        }
        switch (opt) {
            case 'p':
                if (set_number_arg(&info->port) == FAILURE) {
                    free_team(info->teams_name);
                    return FAILURE;
                }
                break;
            case 'x':
                if (set_number_arg(&info->width) == FAILURE) {
                    free_team(info->teams_name);
                    return FAILURE;
                }
                break;
            case 'y':
                if (set_number_arg(&info->height) == FAILURE) {
                    free_team(info->teams_name);
                    return FAILURE;
                }
                break;
            case 'n':
                // Check if its already set
                if (info->teams_name != NULL)
                    return write_error("Cannot set the same option", ARG_ERROR_LABEL, FAILURE);
                if (set_teams_name(ac, av, info) == FAILURE)
                    return FAILURE;
                break;
            case 'c':
                if (set_number_arg(&info->clients_nb) == FAILURE) {
                    free_team(info->teams_name);
                    return FAILURE;
                }
                break;
            case 'f':
                if (set_float_arg(&info->freq) == FAILURE) {
                    free_team(info->teams_name);
                    return FAILURE;
                }
                break;
        }
    }
    if (check_all_info_set(*info)) {
        free_team(info->teams_name);
        return FAILURE;
    }
    return SUCCESS;
}