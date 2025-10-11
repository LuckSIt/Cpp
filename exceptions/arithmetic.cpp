#include <iostream>
#include <limits>

template <typename T>
void inputArray(T arr[8]) {
    std::cout << "Fill the array with 8 values:\n";
    for (int i = 0; i < 8; ++i) {
        while (!(std::cin >> arr[i])) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input, try again: ";
        }
    }
}

template <typename T>
double average(const T arr[8]) {
    double sum = 0.0;
    for (int i = 0; i < 8; ++i)
        sum += static_cast<double>(arr[i]);
    return sum / 8.0;
}

int main() {
    std::cout << "Choose data type (int/double/float): ";
    std::string type;
    std::cin >> type;

    if (type == "int") {
        int arr[8];
        inputArray(arr);
        std::cout << "Average: " << average(arr) << "\n";
    }
    else if (type == "double") {
        double arr[8];
        inputArray(arr);
        std::cout << "Average: " << average(arr) << "\n";
    }
    else if (type == "float") {
        float arr[8];
        inputArray(arr);
        std::cout << "Average: " << average(arr) << "\n";
    }
    else {
        std::cerr << "Unsupported type.\n";
    }
    return 0;
}
