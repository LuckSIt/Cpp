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
    char result[sizeof(file)];
    if (file.is_open())
    {
        file.read(result, sizeof(result));
        cout << "Counted characters: " << file.gcount() << endl;
    }
    else cout << "Invalid path";
    file.close();

    cout << result;
}