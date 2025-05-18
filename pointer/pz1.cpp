#include <iostream>

using namespace std;

void swap(int* one, int* two)
{
    int c = *one;
    *one = *two;
    *two = c;
}

int main()
{
    int a = 10;
    int b = 20;
    swap(&a, &b);
    cout << a << " " << b;
}