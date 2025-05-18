#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream statement;
    statement.open("stream\\ifstream\\pz3\\pz3.txt", ios::binary);
    int sum, result=0, max=0;
    string str, firstName, name, person;
    while (!statement.eof()) {
        if (statement.is_open()) {
            getline(statement, str);
            stringstream temp_stream(str);
            temp_stream >> firstName >> name >> sum;
            result += sum;
            if (max < sum) {
                max = sum;
                person = firstName+" "+name;
            }
        }
        else cout << "Invalid path";

    }
    statement.close();
    cout << "Total: " << result << endl;
    cout << "Person with max payment: " << person << endl;

}
