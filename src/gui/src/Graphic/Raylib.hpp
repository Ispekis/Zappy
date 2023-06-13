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
    #include <string>
    #include <iostream>
    #include <memory>

    #include "Sprite.hpp"
    #include "Error.hpp"
    #include "Data.hpp"

namespace Zappy {
    class Raylib {
        public:
            Raylib(int screenWidth, int screenHeight, std::string title);
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
             * @brief Draw the tile a position x and y
             * 
             */
            void drawTile(std::size_t, std::size_t,  std::pair<std::size_t, std::size_t>);

        protected:
        private:
            std::shared_ptr<Data> _data;
            Camera3D _camera = { 0 };
            Camera3D _cameraMenu = { 0 };
            int _cameraMode;
            float _cameraSpeed;
            bool _menu;

            bool _cameraMove;
            Vector3 pos;
            std::map<std::string, Texture2D> _texture;
            std::map<std::string, std::shared_ptr<Sprite>> _sprite;
    };
}

#endif /* !RAYLIB_HPP_ */
