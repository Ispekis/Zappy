/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Team
*/

#ifndef TEAM_HPP_
#define TEAM_HPP_
    #include <string>
    #include <iostream>

namespace Zappy {
    class Team {
        public:
            Team(std::string);
            ~Team();

        protected:
        private:
            std::string _name;
    };
}

#endif /* !TEAM_HPP_ */
