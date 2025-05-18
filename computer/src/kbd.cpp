#include "kbd.h"
#include "ram.h"
#include <iostream>

void input() {
    int value;
    for (int i = 0; i < 8; ++i) {
        std::cout << "Input value: ";
        std::cin >> value;
        write(i, value);
    }
}