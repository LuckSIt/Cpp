#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Branch {
public:
    Branch *parent;
    std::vector<Branch*> children;
    std::vector<std::string> elves;
    Branch() : parent(nullptr) {}

    void addChild(Branch *child) {
        child->parent = this;
        children.push_back(child);
    }

    bool findElf(const std::string &name, int &count) {
        for (const auto &elf: elves) {
            if (elf == name) {
                count += elves.size() - 1;
                return true;
            }
        }
        for (auto &child: children) {
            if (child->findElf(name, count)) {
                return true;
            }
        }
        return false;
    }

    Branch *getTopBranch() {
        if (parent == nullptr) return nullptr;
        if (parent->parent == nullptr) return parent;
        return parent->getTopBranch();
    }
};
int main() {
    srand(static_cast<unsigned int>(time(0)));
    Branch* tree = new Branch();
    for (int i = 0; i < 5; ++i) {
        Branch* bigBranch = new Branch();
        int numMediumBranches = rand() % 3 + 2;
        for (int j = 0; j < numMediumBranches; ++j) {
            Branch* mediumBranch = new Branch();
            int numElves = rand() % 3 + 1;
            for (int k = 0; k < numElves; ++k) {
                std::string elfName;
                std::cout << "Input name of elf (or 'None' for continue): ";
                std::getline(std::cin, elfName);
                if (elfName != "None") {
                    mediumBranch->elves.push_back(elfName);
                }
            }
            bigBranch->addChild(mediumBranch);
        }
        tree->addChild(bigBranch);
    }
    std::string searchElf;
    std::cout << "Input name of elf for search: ";
    std::getline(std::cin, searchElf);
    int neighborCount = 0;
    if (tree->findElf(searchElf, neighborCount)) {
        std::cout << "Number neighbors elfs " << searchElf << ": " << neighborCount << std::endl;
    } else {
        std::cout << "Elf with name " << searchElf << " not found" << std::endl;
    }
    delete tree;
    tree = nullptr;
    return 0;
}