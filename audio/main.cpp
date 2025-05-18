#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Track {
    private:
        string name;
        tm* date;
        int duration;
    public:
        string getName() {
            return name;
        }
        string getDate() {
            return date;
        }
        int getDuration() {
            return duration;
        }
        void infoTrack(Track* track) {
            cout << "Name: " << track->getName() << endl;
            cout << "Date: " << track->getDate() << endl;
            cout << "Duration: " << track->getDuration() << endl;
        }
};

class Player {
private:
    vector<Track> tracks;
    int currentTrack = -1;
    bool flagPlay = false;
    bool flagPause = false;
public:
    void addTrack(Track& track) {
        tracks.push_back(track);
    }
    void play(const string& trackName) {
        if (flagPlay) {
            cout << "Track is already playing!" << endl;
            return;
        }

        for (size_t i = 0; i < tracks.size(); ++i) {
            if (tracks[i].getName() == trackName) {
                currentTrack = i;
                flagPlay = true;
                flagPause = false;
                tracks[i].infoTrack();
                return;
            }
        }
        cout << "Track not found!" << endl;
    }

    void pause() {
        if (!flagPlay || flagPause) {
            cout << "Cannot pause, track is not playing or already paused!" << endl;
            return;
        }
        flagPause = true;
        cout << "Paused" << endl;
    }

    void next() {
        if (tracks.empty()) {
            cout << "No tracks available!" << endl;
            return;
        }

        currentTrack = rand() % tracks.size();
        flagPlay = true;
        flagPause = false;
        tracks[currentTrack].infoTrack();
    }

    void stop() {
        if (!flagPlay) {
            cout << "No track is currently playing!" << endl;
            return;
        }
        flagPlay = false;
        cout << "Stopped" << endl;
    }
};
void inputCommand(string& command) {
    cout << "Input command players(play, pause, next, stop, exit): ";
    cin >> command;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Player *player = new Player();
    string command;
    while(true) {
        inputCommand(command);
        if (command == "play") {
            string trackName;
            cout << "Enter track name to play: ";
            cin >> trackName;
            player->play(trackName);
        }
        else if (command == "pause") {
            player->pause();
        }
        else if (command == "next") {
            player->next();
        }
        else if (command == "stop") {
            player->stop();
        }
        else if (command == "exit") {
            return 0;
        }
        else {
            cout << "Invalid command! Try again!";
        }


    }
    delete player;
    player = nullptr;

}
