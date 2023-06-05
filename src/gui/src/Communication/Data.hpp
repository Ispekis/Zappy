/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_
    #include "Socket.hpp"
class Data {
    public:
        Data(std::string, int);
        ~Data();

    protected:
    private:
        Socket _socket;
};

#endif /* !DATA_HPP_ */
