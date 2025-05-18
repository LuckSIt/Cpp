#include "iostream"

#define CALL1(app) app(arr)
#define CALL2(analys) analys(arr,sum)

using namespace std;

void append(int array[10]) {
    for (int i = 0; i != 10; ++i) {
        cout << "Input the number of passengers in the carriage: ";
        cin >> array[i];
    }
}

void analysis(int array[10], int sum) {
    sum = 0;
    for (int i = 0; i != 10; ++i) {
        sum += array[i];
        if (array[i] == 20) cout << "Carriage " << i << " completely filled" << endl;
        else if (array[i] < 20) cout << "In the carriage " << i << " " << 20-array[i] << " free places" << endl;
    }
    cout << "Passengers: " << sum;
}

int main() {
    int arr[10];
    int sum;
    CALL1(append);
    CALL2(analysis);
    return 0;
}