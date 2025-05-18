#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void askQuestion(int questionNumber, int &countExpert, int &countSpectators) {
    ifstream fileQuestion("stream\\pz5\\Q" + to_string(questionNumber) + ".txt");
    ifstream fileAnswer("stream\\pz5\\A" + to_string(questionNumber) + ".txt");

    if (!fileQuestion.is_open() || !fileAnswer.is_open()) {
        cerr << "Error open" << endl;
    }

    string question((istreambuf_iterator<char>(fileQuestion)), istreambuf_iterator<char>());
    cout << question << endl;

    string answer;
    cout << "Input answer: ";
    getline(cin, answer);

    string correctAnswer((istreambuf_iterator<char>(fileAnswer)), istreambuf_iterator<char>());

    if (answer == correctAnswer) {
        countExpert++;
        cout << "Wonderful! Expert points: " << countExpert << endl;
    } else {
        countSpectators++;
        cout << "Wrong answer. Viewer points: " << countSpectators << endl;
    }
}

int main() {
    int sector = 1, countExpert = 0, countSpectators = 0;
    vector<int> drum;

    while (countExpert < 6 && countSpectators < 6) {
        cout << "Input offset: ";
        int offset;
        cin >> offset;

        sector = (sector + offset) % 13;
        if (sector == 0) sector = 1;

        if (find(drum.begin(), drum.end(), sector) == drum.end()) {
            drum.push_back(sector);
        } else {

            int attempts = 0;
            while (find(drum.begin(), drum.end(), sector) != drum.end() && attempts < 13) {
                sector++;
                if (sector > 13) sector = 1;
                attempts++;
            }
            if (attempts < 13) {
                drum.push_back(sector);
            }
        }

        askQuestion(sector, countExpert, countSpectators);
    }


    if (countExpert >= 6) {
        cout << "Experts winner with " << countExpert << " points" << endl;
    } else if (countSpectators >= 6) {
        cout << "Spectators winner with " << countSpectators << " points" << endl;
    }

    return 0;
}
