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
    #include <math.h>

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

        void setCamera(raylib::Camera3D camera);

        bool drawSelectedPlayer(Vector3 position, float size, float rotation);

        void draw(Vector3 pose, float, std::size_t, bool selected);

        void moveAnimation(int i, int frame);

        void moveAnimation(int i);

        void moveAnimationToStart(int i);

    protected:
    private:
        raylib::Camera3D _camera;
        raylib::Model _model;
        ModelAnimation *_animation;
        raylib::Texture2D _texture;
        raylib::BoundingBox _boundingBox;
        float _size;
        int i = 1;
        int _animFrameCounter = 3;
        bool _playerSelected = false;
    };
} // namespace Zappy


#endif /* !MYMODEL_HPP_ */
