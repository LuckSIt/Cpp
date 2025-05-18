#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
using namespace std;
vector<char> station;       // Общий ресурс — вектор поездов
mutex station_mtx;
void trainArrives(char name, int waitSeconds) {
    this_thread::sleep_for(chrono::seconds(waitSeconds)); // Имитация времени прибытия поезда

    // Блокируем мьютекс перед доступом к вектору
    {
        lock_guard<mutex> lock(station_mtx);

        if (!station.empty()) {
            cout << "Train " << name << " waiting for a free place\n";
        } else {
            cout << "Train " << name << " arrived at the station\n";
            station.push_back(name);
        }
    } // мьютекс автоматически разблокируется здесь

}
int main() {
    // Запускаем несколько потоков, имитируя поезда
    thread t1(trainArrives, 'A', 2);
    thread t2(trainArrives, 'B', 10);
    thread t3(trainArrives, 'C', 3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}

