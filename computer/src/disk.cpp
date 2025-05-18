#include "disk.h"
#include "ram.h"
#include <iostream>
#include <fstream>

void save() {
    std::ofstream file("C:\\Users\\Vladimir\\CLionProjects\\computer\\memory\\data.txt");
    for (int i = 0; i < 8; ++i) {
        file << read(i) << std::endl;
    }
    file.close();
}

void load() {
    std::ifstream file("C:\\Users\\Vladimir\\CLionProjects\\computer\\memory\\data.txt");
    int value;
    for (int i = 0; i < 8; ++i) {
        file >> value;
        write(i, value);
    }
    file.close();
}