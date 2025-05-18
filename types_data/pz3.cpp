#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    cout << "Input example: ";
    string buffer;
    getline(cin, buffer);

    stringstream temp_stream(buffer);
    double a;
    double b;
    char operation;
    temp_stream >> a >> operation >> b;

    double result;

    switch (operation) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0) {
                result = a / b;
            } else {
                cout << "Error: Division by zero\n";
                return 1;
            }
            break;
        default:
            cout << "Error: Unsupported operation\n";
            return 1;
    }

    cout << "Result: " << result;
    return 0;
}
