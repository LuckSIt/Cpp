#include <iostream>

int main() {
    std::initializer_list<int> numbers = {1, 2, 3, 4, 5};
    for(auto element : numbers) {
        std::cout << element << std::endl;
    }
}
