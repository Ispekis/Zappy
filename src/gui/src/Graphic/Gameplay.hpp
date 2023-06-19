/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Gameplay
*/

#ifndef GAMEPLAY_HPP_
#define GAMEPLAY_HPP_
    #include <map>
    #include <memory>

    #include "raylib-cpp.hpp"
    #include "Data.hpp"
    #include "Cube.hpp"
namespace Zappy {
    class Gameplay {
        public:
            Gameplay();
            ~Gameplay();

            void setData(std::shared_ptr<Data>);
            void setCamera();

            void setTexture();

            void setCube();

            void run();

            void event();
            void cameraEvent();

            void draw();
            void drawMap();
            void drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map);
            bool tilehover(float posX, float posY, float posZ, float size);
            void drawItem(Vector3, std::size_t, std::vector<std::shared_ptr<IRessource>>);
            void drawSpacedItem(std::size_t qty, Vector3 pos, std::string ressource, std::size_t size, std::size_t i);
            void drawWater();

        protected:
        private:
            raylib::Camera3D _camera;

            std::map<std::string, raylib::Texture2D> _texture;
            std::map<std::string, Cube> _cube;
            std::map<std::string, Shader> _shader;

            std::shared_ptr<Data> _data;
            bool _cameraMove;
            int _cameraMode;
            bool _animated;
    };
}

#endif /* !GAMEPLAY_HPP_ */
