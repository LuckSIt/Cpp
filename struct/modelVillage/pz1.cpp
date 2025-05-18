#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum RoomType {
    Living,
    Children,
    Kitchen,
    Bathroom,
    Bedroom
};

struct Room {
    RoomType type;
    int area;
};

struct Floor {
    int number;
    int height;
    vector<Room> rooms;
};

struct House {
    int floorsCount;
    vector<Floor> floors;
    bool hasStove;
    int area;
};

struct Building {
    string type;
    int area;
    House house;
};

struct Plot {
    int number;
    int totalArea;
    vector<Building> buildings;
};

struct Village {
    std::vector<Plot> plots;
};

void fillVillage(Village &village) {
    int plotCount;
    cout << "Input number of plots: ";
    cin >> plotCount;

    for (int i = 0; i != plotCount; ++i) {
        Plot plot;
        plot.number = i + 1;

        cout << "Input total area of plot " << plot.number << ": ";
        cin >> plot.totalArea;

        int buildingCount;
        cout << "Input number of building on plot " << plot.number << ": ";
        cin >> buildingCount;

        for (int j = 0; j != buildingCount; ++j) {
            Building building;
            cout << "Input type of building (house, garage, barn, bathhouse): ";
            cin >> building.type;

            cout << "Input area of building: ";
            cin >> building.area;

            if (building.type == "house") {
                cout << "Input number of floors in house: ";
                cin >> building.house.floorsCount;

                cout << "Has stove? (1 - yes, 0 - no): ";
                cin >> building.house.hasStove;

                for (int k = 0; k != building.house.floorsCount; ++k) {
                    Floor floor;
                    floor.number = k + 1;

                    cout << "input height of ceiling in floor " << floor.number << ": ";
                    cin >> floor.height;

                    int roomCount;
                    cout << "input number of room in floor " << floor.number << ": ";
                    cin >> roomCount;

                    for (int l = 0; l != roomCount; ++l) {
                        Room room;
                        int roomType;
                        cout << "Input type of room (0 - living, 1 - children, 2 - kitchen, 3 - bathroom, 4 - bedroom): ";
                        cin >> roomType;
                        room.type = static_cast<RoomType>(roomType);

                        cout << "Input area of room: ";
                        cin >> room.area;

                        floor.rooms.push_back(room);
                    }
                    building.house.floors.push_back(floor);
                }
            }

            plot.buildings.push_back(building);
        }
        village.plots.push_back(plot);
    }
}
int main() {
    Village village;
    fillVillage(village);
    return 0;
}