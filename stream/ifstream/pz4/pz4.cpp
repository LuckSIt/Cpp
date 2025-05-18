#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Input path file: ";
    string path;
    cin >> path;

    ifstream file;
    file.open(path, ios::binary);
    char result[8];
    if (file.is_open())
    {
        file.read(result, sizeof(result));
        if (result[0] == -119 &&
            result[1] == 'P' &&
            result[2] == 'N' &&
            result[3] == 'G') {
            cout << "Yes";
        }
        else cout << "No";
    }
    else cout << "Invalid path";
    file.close();
}