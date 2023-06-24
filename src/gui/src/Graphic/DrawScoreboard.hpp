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
    #include "Rectangle.hpp"

namespace Zappy {
    class DrawScoreboard {
        public:
            DrawScoreboard();
            ~DrawScoreboard();

            void setData(std::shared_ptr<Data>);

            void drawScoreboard();

        protected:
        private:
            std::shared_ptr<Data> _data;
            std::map<std::string, raylib::Texture2D> _texture;
            std::map<std::string, std::shared_ptr<Rect>> _rectangle;
    };
}

#endif /* !DRAWSCOREBOARD_HPP_ */