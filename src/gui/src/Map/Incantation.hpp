/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Incantation
*/

#ifndef INCANTATION_HPP_
#define INCANTATION_HPP_
    #include <iostream>
    #include <vector>

namespace Zappy {
    struct Incantation_t {
        std::size_t _level;
        std::pair<std::size_t, std::size_t> _position;
        std::size_t loading;
        std::vector<std::size_t> _playerIdList;
    };

    class Incantation
    {
    public:
        Incantation();
        ~Incantation();

        void addIncantation(std::vector<std::string>&);

        void startIncantation();

    protected:
    private:
        std::vector<Incantation_t> _incantationCurrent;
        std::vector<Incantation_t> _incantationDone;
    };
}
#endif /* !INCANTATION_HPP_ */
