/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_
    #include "Socket.hpp"
    #include <unistd.h>

class Data {
    public:
        Data(std::string, int);
        ~Data();

        void readFromServer();

    protected:
    private:
        Socket _socket;
        std::string _machine;
};

#endif /* !DATA_HPP_ */
