/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Gui
*/

#ifndef GUI_HPP_
    #define GUI_HPP_
    #include <string>
    #include <iostream>
    #include "Raylib.hpp"

namespace Zappy {
    class Gui {
        public:
            Gui(int port, std::string machine);
            ~Gui();

            void run();

        protected:
        private:
            Zappy::Raylib _graphic;
    };
}

#endif /* !GUI_HPP_ */
