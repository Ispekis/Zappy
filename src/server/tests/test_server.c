/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** test_server
*/

#include <criterion/criterion.h>
#include "server.h"

Test(tools, test_can_convert_to_int)
{
    cr_assert_eq(can_convert_to_int("1"), 1);
}

Test(tools, test_rand_nbr)
{
    cr_assert_eq(rand_nbr(1, 1), 1);
}

