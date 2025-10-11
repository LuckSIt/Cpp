#include <iostream>
#include <string>
#include <memory>

class Toy {
public:
    Toy(const std::string& name) {
        name_ = name;
    }
    std::string getName() {
        return name_;
    }
    ~Toy() {
        std::cout << "Toy " << name_ << " was dropped " << std::endl;
    }
private:
    std::string name_;
};

class Dog {
private:
    std::string name;
    std::shared_ptr<Toy> toy;
public:
    Dog(std::string _name, std::shared_ptr<Toy> _toy) : name(_name), toy(_toy) {};
    Dog() : Dog("Unknown", std::make_shared<Toy>("SomeToy")) {};
    Dog(std::string _name) : Dog(_name, std::make_shared<Toy>("SomeToy")) {};
    void getToy(std::shared_ptr<Toy> &t) {
        if (t.use_count() <= 1) {
            toy = t;
            std::cout << name << " get " << toy->getName() << std::endl;
        }
        else if (toy == t) {
            std::cout << "I already have this toy" << std::endl;
        }
        else {
            std::cout << "Another dog is playing with this toy" << std::endl;
        }
    }
    void dropToy() {
        if(toy == nullptr) {
            std::cout << "Nothing to drop" << std::endl;
        }
        else {
            toy = nullptr;
            std::cout << name << " drop toy" << std::endl;
        }
    }
};

int main() {
    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
    Dog c("Barsik");
    c.getToy(ball);
    c.dropToy();
    Dog d("Sharik");
    d.getToy(ball);
    c.getToy(ball);
    d.dropToy();
    d.dropToy();
    c.getToy(ball);
    d.getToy(ball);
    d.dropToy();
    ball.reset();
}
