#include <iostream>

using namespace std;

int countWays(int n, int k = 3) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }

    int ways = 0;
    for (int jump = 1; jump <= k; ++jump) {
        ways += countWays(n - jump, k);
    }

    return ways;
}

int main() {

    cout << countWays(3, 2);
}
