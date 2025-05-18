#include "iostream"
#include "vector"

using namespace std;

void swapvec(vector<int>& vec, int* d)
{
    int t;
    for (int i = 0; i < vec.size(); ++i)
    {
        t = d[i];
        d[i] = vec[i];
        vec[i] = t;
    }
}

int main()
{
    vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};
    swapvec(a,b);
    for(int i = 0; i < 4; ++i)
        cout << a[i];
    cout << endl;
    for(int i = 0; i < 4; ++i)
        cout << b[i];
}