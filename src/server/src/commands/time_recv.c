/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** time_recv
*/

#include "server.h"
#include "macro.h"

void send_time_unit_request(int fd, data_t *data,
char *params __attribute__((unused)))
{
    dprintf(fd, "sgt %i\n", data->freq);
}

static int get_right_params(char *params, int *nbr)
{
    if (params == NULL || !can_convert_to_int(params)) {
        return FAILURE;
    }
    (*nbr) = atoi(params);
    if ((*nbr) < 2 || (*nbr) > 10000)
        return FAILURE;
    return SUCCESS;
}

void send_time_unit_modif(int fd, data_t *data, char *params)
{
    int nbr = 0;

    if (get_right_params(params, &nbr) == FAILURE) {
        dprintf(fd, "sbp\n");
        return;
    }
    data->freq = nbr;
    dprintf(fd, "sst %i\n", data->freq);
}