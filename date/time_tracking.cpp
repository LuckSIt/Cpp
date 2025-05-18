#include <iostream>
#include <ctime>
#include <string>
#include <map>

using namespace std;

map<string, double> completedTasks;
string currentTask;
time_t startTime;

void inputCommand(string& command) {
    cout << "Input command (begin, end, status, exit): ";
    cin >> command;
}

void beginTask() {
    if (!currentTask.empty()) {
        time_t endTime = time(nullptr);
        double duration = difftime(endTime, startTime) / 3600.0;
        completedTasks[currentTask] = duration;
        cout << "Ended task: " << currentTask << " (Duration: " << duration << " hours)" << endl;
    }

    cout << "Input name task: ";
    cin >> currentTask;
    startTime = time(nullptr);
    cout << "Started task: " << currentTask << endl;
}

void endTask() {
    if (!currentTask.empty()) {
        time_t endTime = time(nullptr);
        double duration = difftime(endTime, startTime) / 3600.0; // Время в часах
        completedTasks[currentTask] = duration;
        cout << "Ended task: " << currentTask << " (Duration: " << duration << " hours)" << endl;
        currentTask.clear();
    }
}

void showStatus() {
    cout << "Completed tasks:" << endl;
    for (const auto& task : completedTasks) {
        cout << "Task: " << task.first << ", Duration: " << task.second << " hours" << endl;
    }
    if (!currentTask.empty()) {
        cout << "Current task: " << currentTask << endl;
    } else {
        cout << "No current task." << endl;
    }
}

int main() {
    string command;

    while (true) {
        inputCommand(command);
        if (command == "begin") {
            beginTask();
        } else if (command == "end") {
            endTask();
        } else if (command == "status") {
            showStatus();
        } else if (command == "exit") {
            endTask();
            return 0;
        } else {
            cout << "Incorrect command!" << endl;
        }
    }
}