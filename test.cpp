#include <iostream>
#include <memory>

struct DummyDeleter {
    void operator()(int*) const {}
};

int main() {
    std::shared_ptr<int> ptr1(new int(42));
    std::shared_ptr<int> ptr2;
    ptr2 = std::make_shared<int>(ptr1, ptr1.get());

    std::cout
        << "ptr1: " << &ptr1 << std::endl;
    std::cout << "ptr2: " << &ptr2 << std::endl;

    *ptr1 = 99;

    std::cout << "ptr1: " << &ptr1 << std::endl;
    std::cout << "ptr2: " << &ptr2 << std::endl;

    return 0;
}