#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct PaymentRecord {
    string name;
    string surname;
    string date;
    string sum;
};

void listRecords(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Invalid path!" << endl;
        return;
    }

    vector<PaymentRecord> records;
    PaymentRecord record;

    while (file >> record.name >> record.surname >> record.date >> record.sum) {
        records.push_back(record);
    }
    file.close();

    for (const auto& rec : records) {
        cout << "Name: " << rec.name << ", Surname: " << rec.surname << ", Date: " << rec.date << ", Sum: " << rec.sum << endl;
    }
}

void addRecord(const string& filePath) {
    cout << "Input name, surname, date and sum: ";
    PaymentRecord record;
    cin >> record.name >> record.surname >> record.date >> record.sum;

    ofstream file(filePath, ios::app);
    if (!file.is_open()) {
        cout << "Invalid path" << endl;
        return;
    }

    file << record.name << " " << record.surname << " " << record.date << " " << record.sum << endl;
    file.close();
}

int main() {
    cout << "Input command (list, add): ";
    string command;
    cin >> command;

    const string filePath = "struct/vedomost/vedomost.txt";

    if (command == "list") {
        listRecords(filePath);
    }
    else if (command == "add") {
        addRecord(filePath);
    }
    else {
        cout << "Invalid command!" << endl;
    }

    return 0;
}