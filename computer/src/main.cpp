#include <iostream>
#include <string>
#include <fstream>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"

using namespace std;

int main() {
    string command;
    while (true) {
        cout << "Input command (sum, save, load, input, display, exit): ";
        cin >> command;
        if (command == "sum") {
            compute();
        } else if (command == "save") {
            save();
        } else if (command == "load") {
            load();
        } else if (command == "input") {
            input();
        } else if (command == "display") {
            output();
        } else if (command == "exit") {
            return 0;
        } else {
            cout << "Invalid command!" << endl;
        }
    }
}
