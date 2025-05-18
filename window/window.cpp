#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Window {
private:
    int x;
    int y;
    int widthWindow;
    int heightWindow;
public:
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getWidthWindow() {
        return widthWindow;
    }
    int getHeightWindow() {
        return heightWindow;
    }
    void setX(int newX) {
        if (newX >= 0) {
            x = newX;
        }
        else {
            x = 0;
        }
    }
    void setY(int newY) {
        if (newY >= 0) {
            y = newY;
        }
        else {
            y = 0;
        }
    }
    void setWidthWindow(int newWidthWindow) {
        if (newWidthWindow >= 0) {
            widthWindow = newWidthWindow;
        }
        else {
            widthWindow = 0;
        }
    }
    void setHeightWindow(int newHeightWindow) {
        if (newHeightWindow >= 0) {
            heightWindow = newHeightWindow;
        }
        else {
            heightWindow = 0;
        }
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    void resize(int newWidth, int newHeight) {
        setWidthWindow(newWidth);
        setHeightWindow(newHeight);
    }
};


class Screen {
private:
    int widthScreen = 80;
    int heightScreen = 50;
    vector<vector<int>> pixels;
public:
    void initialize() {
        pixels.resize(heightScreen, std::vector<int>(widthScreen, 0));
    }

    void drawWindow(Window& window) {
        for (int i = 0; i < heightScreen; ++i) {
            for (int j = 0; j < widthScreen; ++j) {
                pixels[i][j] = 0;
            }
        }
        for (int i = window.getY(); i < window.getY() + window.getHeightWindow(); ++i) {
            for (int j = window.getX(); j < window.getX() + window.getWidthWindow(); ++j) {
                if (i >= 0 && i < heightScreen && j >= 0 && j < widthScreen) {
                    pixels[i][j] = 1;
                }
            }
        }
    }
    void display() {
        for (const auto& row : pixels) {
            for (int pixel : row) {
                std::cout << pixel << " ";
            }
            std::cout << std::endl;
        }
    }

};

int main() {
    Screen* screen = new Screen();
    screen->initialize();
    Window* window = new Window();

    window->setX(0);
    window->setY(0);
    window->setWidthWindow(5);
    window->setHeightWindow(5);

    string command;
    while (true) {
        cout << "Enter command (move, resize, display, close): ";
        cin >> command;
        if (command == "move") {
            int dx, dy;
            cout << "Enter displacement vector (dx and dy): ";
            cin >> dx >> dy;
            window->move(dx, dy);
        }
        else if (command == "resize") {
            int newWidth, newHeight;
            cout << "Enter new size of window (width and height): ";
            cin >> newWidth >> newHeight;
            window->resize(newWidth, newHeight);
        }
        else if (command == "display") {
            screen->drawWindow(*window);
            screen->display();
        }
        else if (command == "close") {
            return 0;
        }
        else {
            cout << "Incorrect command! Try again" << endl;
        }
    }
    delete window;
    window = nullptr;
    delete screen;
    screen = nullptr;
}
