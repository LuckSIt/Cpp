#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

template<typename Key, typename Value>
struct Entry {
    Key key;
    Value value;
};

template<typename Key, typename Value>
class Registry {
private:
    vector<Entry<Key, Value>> data;
public:
    void add(const Key& k, const Value& v) {
        data.push_back({k, v});
    }

    void remove(const Key& k) {
        data.erase(
                remove_if(data.begin(), data.end(),
                          [&](const Entry<Key, Value>& e){ return e.key == k; }),
                data.end());
    }

    void print() const {
        if (data.empty()) {
            cout << "[empty]\n";
            return;
        }
        for (const auto& e : data)
            cout << "Key: " << e.key << " | Value: " << e.value << "\n";
    }

    void find(const Key& k) const {
        bool found = false;
        for (const auto& e : data) {
            if (e.key == k) {
                cout << "Key: " << e.key << " | Value: " << e.value << "\n";
                found = true;
            }
        }
        if (!found) cout << "No elements with this key.\n";
    }
};

enum class DataType { Int, Double, String };

template<typename Key, typename Value>
void runRegistry() {
    Registry<Key, Value> reg;
    cout << "Commands:\n"
         << "  add    - add element (key value)\n"
         << "  remove - remove all elements with key\n"
         << "  print  - print all elements\n"
         << "  find   - find by key\n"
         << "  exit   - quit\n";

    string cmd;
    while (true) {
        cout << "> ";
        if (!(cin >> cmd)) break;

        if (cmd == "exit") break;
        else if (cmd == "add") {
            Key k; Value v;
            if (!(cin >> k >> v)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input\n";
                continue;
            }
            reg.add(k, v);
        }
        else if (cmd == "remove") {
            Key k;
            if (!(cin >> k)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid key\n";
                continue;
            }
            reg.remove(k);
        }
        else if (cmd == "print") {
            reg.print();
        }
        else if (cmd == "find") {
            Key k;
            if (!(cin >> k)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid key\n";
                continue;
            }
            reg.find(k);
        }
        else {
            cerr << "Unknown command\n";
        }
    }
}

int main() {
    cout << "Select KEY type (int/double/string): ";
    string keyType;
    cin >> keyType;

    cout << "Select VALUE type (int/double/string): ";
    string valueType;
    cin >> valueType;

    if (keyType == "int" && valueType == "int")
        runRegistry<int,int>();
    else if (keyType == "int" && valueType == "double")
        runRegistry<int,double>();
    else if (keyType == "int" && valueType == "string")
        runRegistry<int,string>();
    else if (keyType == "double" && valueType == "int")
        runRegistry<double,int>();
    else if (keyType == "double" && valueType == "double")
        runRegistry<double,double>();
    else if (keyType == "double" && valueType == "string")
        runRegistry<double,string>();
    else if (keyType == "string" && valueType == "int")
        runRegistry<string,int>();
    else if (keyType == "string" && valueType == "double")
        runRegistry<string,double>();
    else if (keyType == "string" && valueType == "string")
        runRegistry<string,string>();
    else
        cerr << "Unsupported type combination.\n";

    return 0;
}
