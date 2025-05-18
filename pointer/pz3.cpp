#include <iostream>
#include <cstring> // Для strlen

using namespace std;

bool substr(const char* one, const char* two)
{
    for (int j = 0; *(two + j) != '\0'; j++)
    {
        bool found = false;
        for (int i = 0; *(one + i) != '\0'; i++)
        {
            if (*(one + i) == *(two + j))
            {
                found = true;
            }
        }
        if (!found)
            return false;
    }
    return true; // Все символы найдены
}

int main()
{
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";
    cout << substr(a, b) << " " << substr(a, c);
}
