#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

mutex access;

class Swimmer {
private:
    string name;
    int speed;
    double distance = 0;
    double result;
public:
    void setName(string str) {
        name = str;
    }
    void setSpeed(int x) {
        speed = x;
    }
    void swim(map<string, double>& res) {
        auto start = chrono::steady_clock::now();
        while (distance < 100) {
            this_thread::sleep_for(chrono::seconds(1));
            distance += speed;
            if (distance >= 100) distance = 100;
            access.lock();
            cout << name << " covered the distance in: " << distance << endl;
            access.unlock();
        }
        access.lock();
        result = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - start).count();
        res[name] = result;
        access.unlock();
    }
};

void swimmerThread(Swimmer& swimmer, map<string, double>& res1) {
    swimmer.swim(res1);
}

int main() {
    vector<Swimmer> vecSwimmers;
    map<string, double> res;
    Swimmer swimmer;
    string nameSwimmer;
    int speed;
    for (size_t i = 0; i != 6; ++i) {
        cout << "Enter swimmer name in lane " << i+1 << " and his speed: ";
        cin >> nameSwimmer >> speed;
        swimmer.setName(nameSwimmer);
        swimmer.setSpeed(speed);
        vecSwimmers.push_back(swimmer);
    }

    vector<thread> threads;
    for(size_t i = 0; i != 6; ++i) {
        threads.emplace_back(swimmerThread, ref(vecSwimmers[i]), ref(res));
    }
    for(auto& t : threads) {
        t.join();
    }
    vector<pair<string, double>> sortedResults(res.begin(), res.end());
    sort(sortedResults.begin(), sortedResults.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second < b.second;
    });
    cout << "Swim finished! Final results: " << endl;
    for (size_t i = 0; i != sortedResults.size(); ++i) {
        cout << i+1 << " " << sortedResults[i].first << " " << sortedResults[i].second << endl;
    }
    return 0;
}
