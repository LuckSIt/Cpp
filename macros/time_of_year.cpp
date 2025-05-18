#include <iostream>
#define SPRING

int main() {
#if defined(SPRING)
    std::cout << "spring" << std::endl;
#elif defined(SUMMER)
    std::cout << "summer" << std::endl;
#elif defined(AUTUMN)
    std::cout << "autumn" << std::endl;
#elif defined(WINTER)
    std::cout << "winter" << std::endl;
#endif
    return 0;
}