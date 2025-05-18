#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    string nameEmployee;
    bool busy;
public:
    Employee(const string inNameEmployee) : nameEmployee(inNameEmployee), busy(false) {}
    string getNameEmployee() {
        return nameEmployee;
    }

    bool isBusy() {
        return busy;
    }

    friend ostream& operator<<(ostream& os, const Employee& employee) {
        os << "Name of worker: " << employee.nameEmployee;
        return os;
    }
};

class Manager {
private:
    string nameManager;
    vector<Employee*> workers;
public:
    Manager(const string inNameManager) : nameManager(inNameManager) {}

    void addEmpl(Employee* employee) {
        workers.push_back(employee);
    }

    vector<Employee*> getWorkers() {
        return workers;
    }

    friend ostream& operator<<(ostream& os, const Manager& manager) {
        os << "Manager: " << manager.nameManager << "\nWorkers:\n";
        for (const auto& worker : manager.workers) {
            os << *worker << endl; // Используем перегруженный оператор для Employee
        }
        return os;
    }

};

class HeadCompany {
private:
    string nameHead;
    vector<Manager*> managers;
public:
    HeadCompany(const string inNameHead) : nameHead(inNameHead) {}

    void addManager(Manager* manager) {
        managers.push_back(manager);
    }

    friend ostream& operator<<(ostream& os, const HeadCompany& head) {
        os << "Head company: " << head.nameHead << "\nManagers:\n";
        for (const auto& manager : head.managers) {
            os << *manager << endl; // Используем перегруженный оператор для Manager
        }
        return os;
    }
};

int main() {
    int teams, worker;
    cout << "Enter number teams: ";
    cin >> teams;

    string nameManager, nameEmployee, nameHead;

    cout << "Enter name head company: ";
    cin >> nameHead;

    HeadCompany* headCompany = new HeadCompany(nameHead);

    for (size_t i = 0; i != teams; ++i) {
        cout << "Enter name manager " << i+1 << " team: ";
        cin >> nameManager;
        Manager *manager = new Manager(nameManager);
        cout << "Enter number workers in the team: ";
        cin >> worker;
        for (size_t j = 0; j != worker; ++j) {
            cout << "Enter name employee: ";
            cin >> nameEmployee;
            Employee *employee = new Employee(nameEmployee);
            manager->addEmpl(employee);
        }
        headCompany->addManager(manager);
    }
    //cout << *headCompany << endl;
    delete headCompany;
    headCompany = nullptr;
}