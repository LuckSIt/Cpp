#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

void inputBirthday(string& str, map<string, tm>& m) {
    time_t t = time(nullptr);
    tm local = *localtime(&t);
    cout << "Input surname and birthday: ";
    cin >> str;
    if (str != "end") {
        cin >> get_time(&local, "%Y/%m/%d");
        m[str] = local;
    }
}

void findNearestBirthday(const map<string, tm>& m) {
    time_t current = time(nullptr);
    tm currentTm = *localtime(&current);
    currentTm.tm_mon += 1; // Устанавливаем месяц (0-11)

    time_t nearestTime;
    string nearestName;
    tm nearestBirthDate;

    for (const auto& entry : m) {
        tm birth = entry.second;

        time_t birthTime = mktime(&birth);
        if (birthTime < nearestTime) {
            nearestTime = birthTime;
            nearestName = entry.first;
            nearestBirthDate = birth;
        }
    }

    if (nearestName.empty()) {
        cout << "No save birthday" << endl;
    } else {
        cout << "Nearest birthday: " << nearestName
             << " on " << put_time(&nearestBirthDate, "%m/%d") << endl;
    }
}

int main() {
    map<string, tm> birthday;
    string nameFriend;
    while (nameFriend != "end") {
        inputBirthday(nameFriend, birthday);
    }
    findNearestBirthday(birthday);
    return 0;
}