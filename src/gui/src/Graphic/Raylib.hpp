/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Raylib
*/

#ifndef RAYLIB_HPP_
    #define RAYLIB_HPP_
    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080

    #include <raylib.h>
    #include <raylib-cpp.hpp>
    #include <string>
    #include <iostream>
    #include <memory>

    #include "Cube.hpp"
    #include "Rectangle.hpp"
    #include "Error.hpp"
    #include "Data.hpp"
    #include "Gameplay.hpp"

namespace Zappy {
    class Raylib {
        public:
            Raylib(std::string title);
            ~Raylib();

            /**
             * @brief Set the Data object
             * 
             * @param data 
             */
            void setData(std::shared_ptr<Data> data);

            /**
             * @brief Set the Camera object
             * 
             */
            void setCamera();

            /**
             * @brief load Texture from file
             * 
             */
            void setTexture();

            /**
             * @brief load Music from file
             * 
             */
            void setMusic();

            /**
             * @brief Launch loop game and set isRunning to false if end
             *
             * @param isRunning
             */
            void run(bool &isRunning);

            /**
             * @brief function that call all drawing element
             * 
             */
            void draw();

            /**
             * @brief function that draw the menu
             * 
             */
            void drawMenu();

            /**
             * @brief Draw background of the menu
             * 
             */
            void drawBackground();

            /**
             * @brief function Handle client event
             *
             */
            void event();

            /**
             * @brief function Handle mouse hovering
             *
             */
            void mouseHovering();

            /**
             * @brief function Handle mouse clicking
             *
             */
            void mouseClicking();

            /**
             * @brief Menu Event
             * 
             */
            void menuEvent();

            /**
             * @brief function Handle camera event
             *
             */
            void cameraEvent();

            /**
             * @brief Draw the map with the map size
             * 
             */
            void drawMap();

            /**
             * @brief Draw the map with the map size
             * 
             */
            void drawLogo();

            /**
             * @brief Draw the menu buttons
             * 
             */
            void drawButton();

            /**
             * @brief Draw the menu buttons text
             * 
             */
            void drawText();

            /**
             * @brief Draw the tile a position x and y
             * 
             */
            void drawTile(std::size_t, std::size_t,  std::pair<std::size_t, std::size_t>);

            /**
             * @brief Draw water
             * 
             */
            void drawWater();

            void drawItem(std::size_t, std::size_t,  std::pair<std::size_t, std::size_t>);

        protected:
        private:
            raylib::Window _window;
            raylib::Camera3D _camera;
            raylib::Camera3D _cameraMenu;

            int _cameraMode;
            float _cameraSpeed;
            bool _cameraMove;
            bool _menu;
            bool _exitWindow = false;
            Music _music;
            Sound _click;

            Vector3 pos;
    
            std::map<std::string, raylib::Texture2D> _texture;
            std::map<std::string, Cube> _cube;
            std::map<std::string, std::shared_ptr<Rect>> _rectangle;
            std::map<std::string, Shader> _shader;
            std::shared_ptr<Data> _data;

            // Gameplay _gameplay;
    };
}

#endif /* !RAYLIB_HPP_ */
