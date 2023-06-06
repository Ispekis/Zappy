/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** set_options
*/

#include "macro.h"
#include "server.h"

void set_non_set_info(info_t *info)
{
    info->port = -1;
    info->width = -1;
    info->height = -1;
    info->clients_nb = -1;
    info->freq = -1;
    info->teams_name = NULL;
}

int set_number_arg(int *opt)
{
    // Check if its already set
    if (*opt != -1)
        return write_error("Cannot set the same option", ARG_ERROR_LABEL, FAILURE);
    if (!can_convert_to_int(optarg))
        return write_error("Cannot convert port to number", ARG_ERROR_LABEL, FAILURE);
    *opt = atoi(optarg);
    return SUCCESS;
}

int set_teams_name(const int ac, char *const *av, info_t *info)
{
    int count = ac - optind + 1;
    int sub = 0;

    for (int i = 0; i < count; i++) {
        sub++;
        if (av[optind + i] == NULL || av[optind + i][0] == '-')
            break;
    }
    info->teams_name = malloc(sizeof(char*) * (sub + 1));
    if (info->teams_name == NULL)
        return FAILURE;
    for (int i = 0; i < count; i++) {
        info->teams_name[i] = strdup(av[optind + i - 1]);
        if (av[optind + i] == NULL || av[optind + i][0] == '-')
            break;
    }
    info->teams_name[sub] = NULL;
    return SUCCESS;
}