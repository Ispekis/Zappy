/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ARessource
*/

#ifndef ARESSOURCE_HPP_
#define ARESSOURCE_HPP_
    #include "IRessource.hpp"
    #include <string>

namespace Zappy {
    class ARessource : public IRessource {
        public:
            ARessource(int quantity);
            ~ARessource();

            /**
             * @brief Get the Quantity of ressource
             * 
             * @return int 
             */
            int getQuantity();

            /**
             * @brief Set the Quantity of ressource
             * 
             * @param quantity 
             */
            void setQuantity(int quantity);

        protected:
            int _quantity;
        private:
    };
}

#endif /* !ARESSOURCE_HPP_ */
