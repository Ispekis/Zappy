#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{1, "apple"}, {2, "banana"}, {3, "cherry"}};

    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        int key = it->first;
        std::string value = it->second;
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    return 0;
}
