#pragma once
#include "iostream"

void scalpel(double& x, double& y) {
    std::cout << "An incision is made between " << x << " and " << y << std::endl;
}

void hemostat(double& x) {
    std::cout << "Clamp in " << x << std::endl;
}

void tweezers(double& x) {
    std::cout << "Tweezers in " << x << std::endl;
}

void suture(double& x, double& y) {
    std::cout << "The seam is made between " << x << " and " << y << std::endl;
}