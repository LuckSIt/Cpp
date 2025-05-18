#include "ram.h"
#include <iostream>

int buffer[8];

void write(int index, int value) {
    if (index >= 0 && index < 8) {
        buffer[index] = value;
    }
}

int read(int index) {
    if (index >= 0 && index < 8) {
        //std::cout << buffer[index] << std::endl;
        return buffer[index];
    }
    return 0;
}