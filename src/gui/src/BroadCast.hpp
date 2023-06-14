/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** BroadCast
*/

#ifndef BROADCAST_HPP_
#define BROADCAST_HPP_

#include <iostream>
namespace Zappy {
    class BroadCast {
        public:
            BroadCast(std::size_t, std::pair<std::size_t, std::size_t>, std::string);
            ~BroadCast();

            std::size_t _playerId;
            std::pair<std::size_t, std::size_t> _position;
            std::string _message;
        protected:
        private:

    };
}

#endif /* !BROADCAST_HPP_ */
