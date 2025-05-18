#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

using namespace std;

mutex access;
condition_variable cv;
bool ready = false;

class Train {
private:
    char name;
public:
    Train(char inName) : name(inName) {}
    void traffic(int time, vector<char>& vec) {
        this_thread::sleep_for(chrono::seconds(time));

        unique_lock<mutex> lock(access);
        if (!vec.empty()) {
            cout << "Train " << name << " waiting free place" << endl;
            cv.wait(lock, [] { return ready; });
        }
        else {
            cout << "Train " << name << " arrived at the station" << endl;
            vec.push_back(name);
            /*cout << "Enter 'depart' to release the train: ";
            string depart;
            cin >> depart;
            vec.pop_back();*/
            ready = true;
            cv.notify_one();
        }
    }
};

void trafficThread(Train& train, int time, vector<char>& vec) {
    train.traffic(time, vec);
}

int main() {
    Train a('A');
    Train b('B');
    Train c('C');
    int timeA, timeB, timeC;
    vector<char> station;

    cout << "Enter time for A, B and C: ";
    cin >> timeA >> timeB >> timeC;

    thread trainA(trafficThread, ref(a), timeA, ref(station));
    thread trainB(trafficThread, ref(b), timeB, ref(station));
    thread trainC(trafficThread, ref(c), timeC, ref(station));
    trainA.join();
    trainB.join();
    trainC.join();
}