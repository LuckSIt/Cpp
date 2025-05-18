#include <iostream>
#include <ctime>
#include <iomanip>
#include "thread"
#include "chrono"

using namespace std;

void inputTime(tm& local) {
    time_t t = time(nullptr);
    local = *localtime(&t);
    cout << "Input time: ";
    cin >> get_time(&local, "%M:%S");
}

void startTimer(const tm& local) {
    int totalTime = local.tm_min * 60 + local.tm_sec;

    while (totalTime > 0) {
        int minutes = totalTime / 60;
        int seconds = totalTime % 60;
        cout << "Remaining time: " << minutes << ":" << seconds << endl;
        this_thread::sleep_for(chrono::seconds(1));
        totalTime--;
    }
    cout << endl << "DING! DING! DING!" << endl;
}

int main() {
    tm timeStruct = {};
    inputTime(timeStruct);
    startTimer(timeStruct);
}