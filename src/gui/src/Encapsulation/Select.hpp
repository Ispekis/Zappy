/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Select
*/

#ifndef SELECT_HPP_
#define SELECT_HPP_
    #include <iostream>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <unistd.h>
    #include <vector>

    #include "Error.hpp"

class Select {
    public:
        Select(std::vector<int> Fds);
        Select(int);
        ~Select();

        void setFd(std::vector<int> Fds);

        void doSelect();

        fd_set _readfds;
    protected:
    private:
        int _maxFd;
        struct timeval _timeout;
};

#endif /* !SELECT_HPP_ */
