#include <iostream>
#include "instruments.h"
#include <string>


struct Logic {
    double x;
    double y;
    double point;

    void inputCut() {
        std::cout << "Input begin and end: ";
        std::cin >> x >> y;
    }
    void inputPoint() {
        std::cout << "Input point: ";
        std::cin >> point;
    }
    bool compare(const Logic& other) {
        return (x == other.x) && (y == other.y);
    }
};
int main() {
    Logic a, b;
    std::string command;
    a.inputCut();
    scalpel(a.x, a.y);
    while(true) {
        std::cout << "Input command (hemostat, tweezers, suture): ";
        std::cin >> command;
        if (command == "hemostat") {
            a.inputPoint();
            hemostat(a.point);
        }
        else if (command == "tweezers") {
            a.inputPoint();
            tweezers(a.point);
        }
        else if (command == "suture") {
            b.inputCut();
            if (a.compare(b)) {
                suture(b.x, b.y);
                return 0;
            }
            else std::cout << "You can't make a seam where there is no cut!" << std::endl;
        }
    }
}
