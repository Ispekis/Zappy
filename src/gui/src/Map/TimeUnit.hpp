/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** TimeUnit
*/

#ifndef TIMEUNIT_HPP_
#define TIMEUNIT_HPP_
    #include <iostream>

namespace Zappy {
    class TimeUnit {
        public:
            TimeUnit();
            ~TimeUnit();

            /**
             * @brief Get the TimeUnit 
             * 
             * @return int 
             */
            int getTimeUnit() const;

            /**
             * @brief Set the TimeUnit
             * 
             */
            void setTimeUnit(int);

        protected:
        private:
            int _timeUnit;
    };
}

#endif /* !TIMEUNIT_HPP_ */
