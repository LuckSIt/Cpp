#include "iostream"
#include "map"
#include "string"
#include "vector"

using namespace std;

int main() {
    map<string, vector<string>> surnameTelephone;
    surnameTelephone["Елизаров"].push_back("89656331466");
    while (1) {
        cout << "Input request type (1 - append telephone and surname users;"
                " 2 - find out the surname by telephone;"
                " 3 - find out the telephone by surname;"
                " 4 - exit): ";
        string requestType;
        cin >> requestType;
        if (requestType == "1") {
            string surname, telephone;
            cout << "Input telephone and surname: ";
            cin >> telephone >> surname;
            surnameTelephone[surname].push_back(telephone);
        } else if (requestType == "2") {
            string telephone;
            cout << "Input telephone: ";
            cin >> telephone;
            for (map<string, vector<string>>::iterator it = surnameTelephone.begin(); it != surnameTelephone.end(); ++it) {
                cout << it->first << endl;
            }
        } else if (requestType == "3") {
            string surname;
            cout << "Input surname: ";
            cin >> surname;
            for (map<string, vector<string>>::iterator it = surnameTelephone.begin(); it != surnameTelephone.end(); ++it) {
                for (size_t i = 0; i != it->second.size(); ++i) {
                    cout << it->second[i] << endl;
                }
            }
        }
        else if (requestType == "4") return 0;
    }
}