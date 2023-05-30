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

size_t get_array_length(char** array)
{
    size_t length = 0;

    while (array[length] != NULL) {
        length++;
    }

    return length;
}

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

bool can_convert_to_float(const char* str)
{
    char* end;
    strtof(str, &end);
    return *end == '\0';
}

bool is_int(int value)
{
    return sizeof(value) == sizeof(int);
}

bool is_float(float value)
{
    return sizeof(value) == sizeof(float);
}
