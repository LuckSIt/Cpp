#include <iostream>

using namespace std;

void swap(int* one)
{
    int c;
    for(int i = 0; i < 5; i++)
    {
        c = one[i];
        one[i] = one[9-i];
        one[9-i] = c;
    }
}

int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    swap(a);
    for(int i = 0; i < 10; ++i)
    {
        cout << a[i] << " ";
    }
}
