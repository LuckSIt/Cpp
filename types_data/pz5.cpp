#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

void checkWaterHeating(double outsideTemp, bool& waterHeating) {
    if (outsideTemp < 0 && !waterHeating) {
        waterHeating = true;
        cout << "Water heating turned on." << endl;
    } else if (outsideTemp > 5 && waterHeating) {
        waterHeating = false;
        cout << "Water heating turned off." << endl;
    }
}

void checkHeating(double insideTemp, bool& heating) {
    if (insideTemp < 22 && !heating) {
        heating = true;
        cout << "Heating turned on." << endl;
    } else if (insideTemp >= 25 && heating) {
        heating = false;
        cout << "Heating turned off." << endl;
    }
}

void checkAirConditioner(double insideTemp, bool& airConditioner) {
    if (insideTemp >= 30 && !airConditioner) {
        airConditioner = true;
        cout << "Air conditioner turned on." << endl;
    } else if (insideTemp < 25 && airConditioner) {
        airConditioner = false;
        cout << "Air conditioner turned off." << endl;
    }
}

void checkOutsideLight(int hour, bool motion, bool& outsideLight) {
    bool shouldBeOn = (hour >= 16 || hour < 5) && motion;
    if (shouldBeOn && !outsideLight) {
        outsideLight = true;
        cout << "Outside light turned on." << endl;
    } else if (!shouldBeOn && outsideLight) {
        outsideLight = false;
        cout << "Outside light turned off." << endl;
    }
}

void adjustColorTemperature(int hour, bool outsideLight, int& colorTemp) {
    if (hour >= 16 && hour < 20 && outsideLight) {
        double targetTemp = 2700 + (5000 - 2700) * (20 - hour) / 4;
        colorTemp = static_cast<int>(targetTemp);
        cout << "Color temperature: " << colorTemp << "K" << endl;
    }
}

string getTime(int hour) {
    stringstream ss;
    ss << setw(2) << setfill('0') << hour << ":00";
    return ss.str();
}

int main() {
    double outsideTemp, insideTemp;
    bool motion, light;
    bool heating = false, waterHeating = false, airConditioner = false, outsideLight = false;
    int colorTemp = 5000;

    for (int day = 0; day < 2; ++day) {
        for (int hour = 0; hour < 24; ++hour) {
            cout << "Enter data (Outside Temp, Inside Temp, Motion (1/0), Light in house (1/0)): ";
            string input;
            getline(cin, input);
            stringstream ss(input);
            ss >> outsideTemp >> insideTemp >> motion >> light;

            checkWaterHeating(outsideTemp, waterHeating);
            checkHeating(insideTemp, heating);
            checkAirConditioner(insideTemp, airConditioner);
            checkOutsideLight(hour, motion, outsideLight);
            adjustColorTemperature(hour, outsideLight, colorTemp);

            cout << getTime(hour) << " - Current states: "
                 << "\nOutside Temperature: " << outsideTemp
                 << "\nInside Temperature: " << insideTemp
                 << "\nMotion: " << (motion ? "yes" : "no") << ", "
                 << "\nLight in house: " << (light ? "on" : "off") << "." << endl;

            if (light) {
                cout << getTime(hour) << " - Light in house is on." << endl;
            }
        }
    }

    return 0;
}
