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
    enum Animation
    {
        laying_egg = 0,
        drop,
        eject,
        incancation,
        marche,
        victory_danse1,
        ramassage,
        victory_danse2,
    };

    class MyModel
    {
    public:
        MyModel(std::string path, unsigned int animsCount, std::string texture);
        ~MyModel();

        void draw(Vector3 pose, float, std::size_t);

        void moveAnimation(int i);

    protected:
    private:
        // std::shared_ptr<Data> _data;
        // std::map<std::string, raylib::ModelAnimation> _modelAnimation;
        ModelAnimation *_animation;
        raylib::Model _model;
        raylib::Texture2D _texture;
        int i = 1;
        int _animFrameCounter = 3;
    };
} // namespace Zappy


#endif /* !MYMODEL_HPP_ */
