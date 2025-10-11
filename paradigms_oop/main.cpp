#include <iostream>
#include <string>
#include <vector>

class Talent {
public:
    virtual void add_talent(std::vector<std::string>& vec) = 0;
};

class Swimming : virtual public Talent {
public:
    void add_talent(std::vector<std::string>& vec) override {
        vec.push_back("Swim");
    }
};

class Dancing : virtual public Talent {
public:
    void add_talent(std::vector<std::string>& vec) override {
        vec.push_back("Dance");
    }
};

class Counting : virtual public Talent {
public:
    void add_talent(std::vector<std::string>& vec) override {
        vec.push_back("Count");
    }
};

class Dog {
private:
    std::string name;
    std::vector<std::string> talents;
public:
    Dog(std::string in_name) : name(in_name) {}

    void show_talents() {
        std::cout << "This is " << name << " and it has some talents:" << std::endl;
        for (const auto& elem : talents) {
            std::cout << "It can " << elem << std::endl;
        }
    }

    std::vector<std::string>& getTalents() {
        return talents;
    }
};

int main() {
    Dog dog1("Steve");
    Swimming s;
    s.add_talent(dog1.getTalents());
    Dancing d;
    d.add_talent(dog1.getTalents());
    dog1.show_talents();
    return 0;
}