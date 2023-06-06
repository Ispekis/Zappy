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
    #include "Error.hpp"

namespace Zappy {
    class Raylib {
        public:
            Raylib(int screenWidth, int screenHeight, std::string title);
            ~Raylib();

            /**
             * @brief Launch loop game and set isRunning to false if end
             * 
             * @param isRunning 
             */
            void run(bool &isRunning);

        protected:
        private:
    };
}

#endif /* !RAYLIB_HPP_ */
