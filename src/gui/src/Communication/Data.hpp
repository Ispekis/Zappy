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
        void writeToServer(std::string &cmd);

    protected:
    private:
        Socket _socket;
        std::string _machine;
        Select _select;
};

#endif /* !DATA_HPP_ */
