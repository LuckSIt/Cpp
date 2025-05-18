#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> queue;
    string newHuman;

    while (1) {
        cout << "Input new human or 'Next': ";
        cin >> newHuman;

        if (newHuman != "Next") {
            queue[newHuman]++;
            cout << "<-" << newHuman << endl;
        } else {
            if (!queue.empty()) {
                auto it = queue.begin();
                cout << "->" << it->first << endl;

                if (--(it->second) == 0) {
                    queue.erase(it);
                }
            } else {
                cout << "-> No patients in queue" << endl;
                return 0;
            }
        }
    }
}