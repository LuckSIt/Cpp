#include "iostream"
#include "string"
#include "cmath"
#include "cstdlib"

using namespace std;

struct MathVector {
    double x;
    double y;
};

void add(MathVector &mathVector1, MathVector &mathVector2) {
    cout << mathVector1.x + mathVector2.x << "," << mathVector1.y + mathVector2.y;
}

void subtract(MathVector &mathVector1, MathVector &mathVector2) {
    mathVector2.x *= -1;
    mathVector2.y *= -1;
    cout << mathVector1.x + mathVector2.x << "," << mathVector1.y + mathVector2.y;
}

void scale(MathVector &mathVector, double s) {
    cout << mathVector.x * s << "," << mathVector.y * s;
}

void length(MathVector &mathVector) {
    int c;
    c = pow(pow(mathVector.x, 2) + pow(mathVector.y, 2), 0.5);
    cout << c;
}

void normalize(MathVector &mathVector) {
    cout << mathVector.x / abs(mathVector.x) << "," << mathVector.y / abs(mathVector.y);
}

int main() {
    cout << "Input command: ";
    string command;
    cin >> command;
    if (command == "add") {
        MathVector mathVector1, mathVector2;
        cout << "Input first vector`s coordinates: ";
        cin >> mathVector1.x >> mathVector1.y;
        cout << "Input second vector`s coordinates: ";
        cin >> mathVector2.x >> mathVector2.y;
        add(mathVector1, mathVector2);
    }
    else if (command == "subtract") {
        MathVector mathVector1, mathVector2;
        cout << "Input first vector`s coordinates: ";
        cin >> mathVector1.x >> mathVector1.y;
        cout << "Input second vector`s coordinates: ";
        cin >> mathVector2.x >> mathVector2.y;
        subtract(mathVector1, mathVector2);
    }
    else if (command == "scale") {
        MathVector mathVector;
        double scalar;
        cout << "Input vector`s coordinates: ";
        cin >> mathVector.x >> mathVector.y;
        cout << "Input scalar`s value: ";
        cin >> scalar;
        scale(mathVector, scalar);
    }
    else if (command == "length") {
        MathVector mathVector;
        cout << "Input vector`s coordinates: ";
        cin >> mathVector.x >> mathVector.y;
        length(mathVector);
    }
    else if (command == "normalize") {
        MathVector mathVector;
        cout << "Input vector`s coordinates: ";
        cin >> mathVector.x >> mathVector.y;
        normalize(mathVector);
    }
    else cout << "Invalid command";
    return 0;
}