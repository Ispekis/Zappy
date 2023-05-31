/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "Error.hpp"
#include "Parser.hpp"
#include "macro.hpp"
#include "unistd.h"
#include "Gui.hpp"

void show_usage(char *binary, int fd)
{
    std::cout << "USAGE: " << binary << " -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

int main(const int ac, char *const *av)
{
    if (ac == 2 && std::strcmp(av[1], "-help") == 0) {
        show_usage(av[0], STDOUT_FILENO);
        return MY_EXIT_SUCCESS;
    }

    try {
        Zappy::Parser parser(ac, av);
        Zappy::Gui Gui(parser.getPort(), parser.getMachine());
    } catch (Error &e) {
        std::cerr << e.what() << std::endl;
        return MY_EXIT_FAILURE;
    }
    return MY_EXIT_SUCCESS;
}