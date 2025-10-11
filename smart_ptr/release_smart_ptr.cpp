#include <iostream>
#include <string>

class Toy {
public:
    Toy(const std::string& name) : name_(name) {
        std::cout << "Toy '" << name_ << "' created." << std::endl;
    }

    std::string getName() const {
        return name_;
    }

    ~Toy() {
        std::cout << "Toy '" << name_ << "' destroyed." << std::endl;
    }

private:
    std::string name_;
};

class shared_ptr_toy {
public:
    shared_ptr_toy(const std::string& name)
            : t(new Toy(name)), counts(new int(1)) {
        std::cout << "New shared_ptr_toy created. Ref count: 1" << std::endl;
    }

    shared_ptr_toy() : t(nullptr), counts(nullptr) {}

    shared_ptr_toy(const shared_ptr_toy& other)
            : t(other.t), counts(other.counts) {
        if (counts) {
            (*counts)++;
            std::cout << "shared_ptr_toy copied. Ref count: " << *counts << std::endl;
        }
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        if (this != &other) {
            if (counts && --(*counts) == 0) {
                delete t;
                delete counts;
                std::cout << "Toy deleted due to assignment." << std::endl;
            }

            t = other.t;
            counts = other.counts;

            if (counts) {
                (*counts)++;
                std::cout << "shared_ptr_toy assigned. Ref count: " << *counts << std::endl;
            }
        }
        return *this;
    }

    ~shared_ptr_toy() {
        if (counts && --(*counts) == 0) {
            delete t;
            delete counts;
            std::cout << "Last reference deleted. Toy destroyed." << std::endl;
        } else if (counts) {
            std::cout << "Reference decremented. Ref count: " << *counts << std::endl;
        }
    }

    std::string getToyName() const {
        return t ? t->getName() : "Nothing";
    }

    int use_count() const {
        return counts ? *counts : 0;
    }

    void reset() {
        if (counts && --(*counts) == 0) {
            delete t;
            delete counts;
            std::cout << "Toy deleted due to reset." << std::endl;
        }
        t = nullptr;
        counts = nullptr;
    }

    Toy* get() const {
        return t;
    }

private:
    Toy* t;
    int* counts;
};

shared_ptr_toy make_shared_toy(const std::string& name) {
    return shared_ptr_toy(name);
}

shared_ptr_toy make_shared_toy(const shared_ptr_toy& other) {
    return shared_ptr_toy(other);
}

int main() {
    shared_ptr_toy toy_01 = make_shared_toy("ball");
    shared_ptr_toy toy_02(toy_01);
    shared_ptr_toy toy_03 = make_shared_toy("duck");

    std::cout << "=================================================" << std::endl;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;

    toy_02 = toy_03;

    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;

    toy_01.reset();

    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;

    return 0;
}