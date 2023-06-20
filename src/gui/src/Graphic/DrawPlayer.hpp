/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** DrawPlayer
*/

#ifndef DRAWPLAYER_HPP_
    #define DRAWPLAYER_HPP_

    #include <memory>
    #include <map>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"
    #include "MyModel.hpp"

namespace Zappy {
    class DrawPlayer {
        public:
            DrawPlayer();
            ~DrawPlayer();

            void setData(std::shared_ptr<Data>);

            void setModel();

            void draw();


        protected:
        private:
            raylib::Camera3D _camera;
            std::shared_ptr<Data> _data;
            std::map<std::string, std::shared_ptr<MyModel>> _model;
    };
    
} // namespace Zappy


#endif /* !DRAWPLAYER_HPP_ */
