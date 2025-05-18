#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout << "Input word: ";
    string userWord;
    cin >> userWord;

    ifstream word;
    word.open("stream\\pz1\\pz1.txt");

    vector<string> result;
    string wordRepeat;
    while (!word.eof()) {
        word >> wordRepeat;
        result.push_back(wordRepeat);
    }

    word.close();

    int count = 0;
    for(int i = 0; i < size(result); i++)
    {
        if(userWord == result[i]) count++;
    }
    cout << "Number repeat: " << count;

}
