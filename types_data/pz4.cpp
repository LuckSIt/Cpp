#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

enum note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() {
    cout << "Input accord: ";
    string input;
    cin >> input;

    int chordMask = 0; // Битовая маска аккорда
    set<int> uniqueNotes; // Множество для уникальных нот

    // Обрабатываем введённые цифры
    for (char c : input) {
        int note = c - '0'; // Преобразуем символ в число
        if (note >= 1 && note <= 7) {
            uniqueNotes.insert(note); // Сохраняем уникальные ноты
        }
    }
    for (int note : uniqueNotes) {
        chordMask |= (1 << (note - 1)); // Устанавливаем соответствующий бит
    }

    // Выводим ноты из аккорда
    cout << "You clicked notes: ";
    if (chordMask & DO) cout << "DO ";
    else if (chordMask & RE) cout << "RE ";
    else if (chordMask & MI) cout << "MI ";
    else if (chordMask & FA) cout << "FA ";
    else if (chordMask & SOL) cout << "SOL ";
    else if (chordMask & LA) cout << "LA ";
    else if (chordMask & SI) cout << "SI ";
    else cout << "Error";
    cout << endl;

    return 0;
}
