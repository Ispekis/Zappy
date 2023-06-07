/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_
    #include <unistd.h>
    #include <string.h>
    #include <cstring>
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdio>
    #include <iostream>
    #include <iostream>
#include <sstream>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>

#include <sstream>
#include <cstdio>
#include <unistd.h>
    #include "Socket.hpp"
    #include "Select.hpp"

class Data {
    public:
        Data(std::string, int);
        ~Data();

        /**
         * @brief reading data from the server
         * 
         */
        void readFromServer();

        /**
         * @brief writing data to the server
         * 
         */
        void writeToServer(char *str);

        /**
         * @brief Updating the Data game
         * 
         */
        void updateGame();
        std::vector<std::vector<int>> map;

    protected:
    private:
        Socket _socket;
        std::string _machine;
        Select _select;
};

#endif /* !DATA_HPP_ */
