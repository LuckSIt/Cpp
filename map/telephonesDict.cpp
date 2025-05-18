#include "iostream"
#include "map"
#include "string"

using namespace std;

int main() {
    multimap<string, string> surnameTelephone;
    map<string, string> telephoneSurname;
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
            surnameTelephone.insert({surname, telephone});
            telephoneSurname.insert({telephone, surname});
        } else if (requestType == "2") {
            string telephone;
            cout << "Input telephone: ";
            cin >> telephone;
            map<string, string>::iterator it = telephoneSurname.find(telephone);
            cout << it->second << endl;
        } else if (requestType == "3") {
            string surname;
            cout << "Input surname: ";
            cin >> surname;
            map<string, string>::iterator it = surnameTelephone.find(surname);
            for (;it->first == surname;++it) {
                cout << it->second << endl;
            }
        }
        else if (requestType == "4") return 0;
    }
}