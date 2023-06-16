/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** test
*/

#include <memory>

class Test {
    public:
        Test(int b) {
            a = b;
        };
        ~Test(){};

    private:
        int a;
};

int main()
{
        Test test(4);
        std::shared_ptr<Test> d= std::make_shared<Test>(test);
}