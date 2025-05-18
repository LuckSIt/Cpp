#include "gpu.h"
#include "ram.h"
#include <iostream>

void output() {
    for (int i = 0; i < 8; ++i) {
        std::cout << read(i) << std::endl;
    }
}