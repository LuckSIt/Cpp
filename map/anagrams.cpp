#include "iostream"
#include "map"
#include "string"

using namespace std;

bool findAnagrams(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) return false;
    map<char, int> numberOfOccurrences;
    for (char i : str1) {
        numberOfOccurrences[i]++;
    }
    for (char i : str2) {
        numberOfOccurrences[i]--;
        if (numberOfOccurrences[i] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string first;
    string second;
    cout << "Input two strings: ";
    cin >> first >> second;
    if (findAnagrams(first, second)) {
        cout << "Is anagrams";
    }
    else cout << "NO";

}
