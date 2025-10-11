#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <algorithm>

using namespace std;

struct FishCaught {
    int attempts;
    explicit FishCaught(int a) : attempts(a) {}
};

struct BootCaught {
    int sector;
    explicit BootCaught(int s) : sector(s) {}
};

struct Sector {
    bool hasFish = false;
    bool hasBoot = false;
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int SIZE = 9;
    vector<Sector> pond(SIZE);

    int fishIndex = rand() % SIZE;
    pond[fishIndex].hasFish = true;

    vector<int> positions;
    while (positions.size() < 3) {
        int pos = rand() % SIZE;
        if (pos != fishIndex && find(positions.begin(), positions.end(), pos) == positions.end())
            positions.push_back(pos);
    }
    for (int p : positions) pond[p].hasBoot = true;

    cout << "Fishing Game\n"
         << "There are 9 sectors (0-8).\n"
         << "Try to catch the fish!\n"
         << "Beware of boots - catching one ends the game.\n";

    int attempts = 0;
    try {
        while (true) {
            cout << "Enter sector number (0-8): ";
            int guess;
            if (!(cin >> guess) || guess < 0 || guess >= SIZE) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input. Please enter a number 0-8.\n";
                continue;
            }
            ++attempts;

            if (pond[guess].hasFish) throw FishCaught(attempts);
            if (pond[guess].hasBoot) throw BootCaught(guess);

            cout << "Nothing here. Try again!\n";
        }
    }
    catch (const FishCaught &f) {
        cout << "\nCongratulations! You caught the fish in "
             << f.attempts << " attempts!\n";
    }
    catch (const BootCaught &b) {
        cout << "\nOh no! You hooked a boot in sector "
             << b.sector << ". Game over.\n";
    }
    return 0;
}
