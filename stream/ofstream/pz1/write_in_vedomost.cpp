#include "iostream"
#include "fstream"
#include "string"

using namespace std;

int main()
{
    cout << "Input name, surname, date, sum: ";
    string name, surname, date, sum;
    cin >> name >> surname >> date >> sum;
    int month = stoi(date.substr(3,2));
    if (month >= 1 && month <= 12) {
        ofstream file(
                "stream\\ofstream\\pz1\\vedomost.txt",
                ios::app);
        file << name << " " << surname << " " << date << " " << sum << endl;
        file.close();
    }
    else {
        cout << "Invalid date!";
    }
}