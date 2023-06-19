/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawMap
*/

#ifndef DRAWMAP_HPP_
#define DRAWMAP_HPP_
    #include <memory>
    #include <map>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"
    #include "Cube.hpp"
    #include "DrawItems.hpp"

namespace Zappy {
    class DrawMap {
        public:
            DrawMap();
            ~DrawMap();

            void setData(std::shared_ptr<Data>);


            void setTexture();

            void setCube();

            void draw();

            void drawMap();
            void drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map);

        protected:
        private:
            std::shared_ptr<Data> _data;
            std::map<std::string, raylib::Texture2D> _texture;
            std::map<std::string, Shader> _shader;
            std::map<std::string, Cube> _cube;

            DrawItems _items;
    };
}
#endif /* !DRAWMAP_HPP_ */
