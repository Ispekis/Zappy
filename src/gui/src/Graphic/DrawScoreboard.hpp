/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawScoreboard
*/

#ifndef DRAWSCOREBOARD_HPP_
    #define DRAWSCOREBOARD_HPP_

    #include <memory>
    #include <map>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"

namespace Zappy {
    class DrawScoreboard {
        public:
            DrawScoreboard();
            ~DrawScoreboard();

            void setData(std::shared_ptr<Data>);

        protected:
        private:
            std::shared_ptr<Data> _data;
    };
}

#endif /* !DRAWSCOREBOARD_HPP_ */
