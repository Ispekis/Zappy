/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** MyModel
*/

#ifndef MYMODEL_HPP_
#define MYMODEL_HPP_

    #include <memory>
    #include <map>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"

namespace Zappy
{
    class MyModel {
        public:
            MyModel(std::string path, unsigned int animsCount, std::string texture);
            ~MyModel();

            void draw(Vector3 pose, float size);

            void moveAnimation(int animation);

        protected:
        private:
            // std::shared_ptr<Data> _data;
            // std::map<std::string, raylib::ModelAnimation> _modelAnimation;
            ModelAnimation *_animation;
            raylib::Model _model;
            raylib::Texture2D _texture;
            int i = 0;
            int _animFrameCounter = 0;
    };
} // namespace Zappy


#endif /* !MYMODEL_HPP_ */
