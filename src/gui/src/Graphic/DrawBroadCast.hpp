/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawBroadCast
*/

#ifndef DRAWBROADCAST_HPP_
#define DRAWBROADCAST_HPP_
    #include <memory>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"

namespace Zappy {
    class DrawBroadCast {
        public:
            DrawBroadCast();
            ~DrawBroadCast();

            void setData(std::shared_ptr<Data>);

            void draw();

            void drawChatBox();

            void drawAnimation();

            void event();

            void boxHover();

        protected:
        private:
            std::shared_ptr<Data> _data;
            bool _drawChatBox = true;
            std::pair<int, int> _windowSize;
            std::size_t _scrollIndex = 0;
    };
}

#endif /* !DRAWBROADCAST_HPP_ */
