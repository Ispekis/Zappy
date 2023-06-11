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
             * @brief Launch loop game and set isRunning to false if end
             *
             * @param isRunning
             */
            void run(bool &isRunning);

            void draw();

            void event();

        protected:
        private:
            std::shared_ptr<Data> _data;
    };
}

#endif /* !RAYLIB_HPP_ */
