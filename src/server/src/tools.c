/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** tools
*/

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

int write_error(char *message, char *label, int ret_value)
{
    if (label == NULL) {
        dprintf(STDERR_FILENO, "%s\n", message);
    } else {
        dprintf(STDERR_FILENO, "%s: %s\n", label, message);
    }
    return ret_value;
}

bool can_convert_to_int(const char* str)
{
    char* end;
    strtol(str, &end, 10);
    return *end == '\0';
}

int rand_nbr(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
