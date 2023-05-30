/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct info_s {
    int port;
    int width;
    int height;
    char **teams_name;
    int clients_nb;
    float freq;
} info_t;

typedef struct server_s {
    info_t info;

} server_t;

int error_handling(const int ac, const char **av);
int get_options(const int ac, char *const *av, info_t *info);

// Tools
size_t get_array_length(char** array);
int write_error(char *message, char *label, int ret_value);
bool can_convert_to_int(const char* str);
bool can_convert_to_float(const char* str);
bool is_int(int value);
bool is_float(float value);

#endif /* !SERVER_H_ */
