/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_
    #include <string>
    #include <unordered_map>
    #include <memory>

    #include "IRessource.hpp"

namespace Zappy {
    enum Orientation
    {
        N = 1,
        E,
        S,
        W
    };

    class Player
    {
    public:
        Player();
        ~Player();

    protected:
    private:
        std::pair<std::size_t, std::size_t> Position;
        std::unordered_map<std::string, std::shared_ptr<IRessource>> _Inventory;
        Orientation _orientation;
        bool _incantation;
    };
}

#endif /* !PLAYER_HPP_ */
