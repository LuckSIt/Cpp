#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Employee {
private:
    string nameEmployee;
    bool busy;

public:
    Employee(const string& inNameEmployee) : nameEmployee(inNameEmployee), busy(false) {}

    string getNameEmployee() const {
        return nameEmployee;
    }

    bool isBusy() const {
        return busy;
    }

    void assignTask(char taskType) {
        busy = true;
        cout << nameEmployee << " получил задачу типа " << taskType << endl;
    }
};

class Manager {
private:
    string nameManager;
    vector<Employee*> workers;

public:
    Manager(const string& inNameManager) : nameManager(inNameManager) {}

    void addEmpl(Employee* employee) {
        workers.push_back(employee);
    }

    void assignTasks(int commandId, int managerIndex) {
        srand(commandId + managerIndex); // Инициализация генератора
        int tasksCount = rand() % (workers.size() + 1); // Количество задач от 1 до количества работников, может быть 0

        // Чтобы tasksCount был минимум 1, если есть работники незанятые
        int freeWorkers = 0;
        for (auto w : workers) if (!w->isBusy()) freeWorkers++;
        if (tasksCount == 0 && freeWorkers > 0) tasksCount = 1;

        cout << nameManager << " распределяет " << tasksCount << " задач(и) среди работников." << endl;

        vector<char> taskTypes = {'A', 'B', 'C'};
        random_shuffle(taskTypes.begin(), taskTypes.end());

        int assigned = 0;
        for (auto& worker : workers) {
            if (!worker->isBusy() && assigned < tasksCount) {
                char task = taskTypes[assigned % taskTypes.size()];
                worker->assignTask(task);
                assigned++;
            }
            if (assigned >= tasksCount) break;
        }
    }

    bool allWorkersBusy() const {
        for (const auto& worker : workers) {
            if (!worker->isBusy()) {
                return false;
            }
        }
        return true;
    }

    ~Manager() {
        for (auto w : workers) {
            delete w;
        }
    }
};

class HeadCompany {
private:
    string nameHead;
    vector<Manager*> managers;

public:
    HeadCompany(const string& inNameHead) : nameHead(inNameHead) {}

    void addManager(Manager* manager) {
        managers.push_back(manager);
    }

    void giveCommand(int commandId) {
        cout << nameHead << " отдает команду с ID: " << commandId << endl;
        for (size_t i = 0; i < managers.size(); ++i) {
            managers[i]->assignTasks(commandId, static_cast<int>(i));
        }
    }

    bool allManagersBusy() const {
        for (const auto& manager : managers) {
            if (!manager->allWorkersBusy()) {
                return false;
            }
        }
        return true;
    }

    ~HeadCompany() {
        for (auto m : managers) {
            delete m;
        }
    }
};

int main() {
    int teams, workersPerTeam;
    cout << "Введите количество команд и количество работников в каждой команде: ";
    cin >> teams >> workersPerTeam;

    string nameManager, nameEmployee, nameHead;
    cout << "Введите имя главы компании: ";
    cin >> nameHead;

    HeadCompany* headCompany = new HeadCompany(nameHead);

    for (int i = 0; i < teams; ++i) {
        cout << "Введите имя менеджера " << i + 1 << ": ";
        cin >> nameManager;
        Manager* manager = new Manager(nameManager);
        for (int j = 0; j < workersPerTeam; ++j) {
            cout << "Введите имя работника " << j + 1 << ": ";
            cin >> nameEmployee;
            Employee* employee = new Employee(nameEmployee);
            manager->addEmpl(employee);
        }
        headCompany->addManager(manager);
    }

    cout << "Введите команды (целые числа), для завершения введите -1: " << endl;
    int commandId;
    while (true) {
        cin >> commandId;
        if (commandId == -1) break;

        // Проверим, все ли работники заняты до выдачи команды
        if (headCompany->allManagersBusy()) {
            cout << "Все работники заняты. Завершение работы программы." << endl;
            break;
        }

        headCompany->giveCommand(commandId);

        // Проверим, все ли работники заняты после выдачи команды
        if (headCompany->allManagersBusy()) {
            cout << "Все работники заняты. Завершение работы программы." << endl;
            break;
        }
    }

    delete headCompany;

    return 0;
}