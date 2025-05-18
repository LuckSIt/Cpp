#include <iostream>
#include <string>

using namespace std;

double stringToDouble(string str)
{
    double res = stod(str);
    return res;
}

int main() 
{
    string integer;
    string doubles;
    string result;
    cout << "Input integer and double parts: ";
    cin >> integer >> doubles;
    result = integer + '.' + doubles;
    cout << stringToDouble(result);

}