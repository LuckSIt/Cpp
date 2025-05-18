#include <iostream>

using namespace std;

void evendigits(long long n, int& a) {
    if (n == 0) return;
    int digit = n % 10;
    if (digit % 2 == 0) a += 1;
    evendigits(n/10, a);
}

int main() {
    int ans;
    evendigits(9223372036854775806, ans);
    cout << ans;
}
