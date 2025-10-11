#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

int main() {
    std::vector<int> v = {1, 2, 3, 3, 1, 7, 6, 1, 5, 9, 8, 8, 9, 3};
    auto func = [](std::vector<int> &vec) {
        std::unordered_set<int> unorderedSet;
        auto result = std::make_unique<std::vector<int>>();
        for (const auto& num : vec) {
            if (unorderedSet.insert(num).second) {
                result->push_back(num);
            }
        }
        return result;
    };
    std::unique_ptr<std::vector<int>> uniqueNumbers = func(v);
    std::cout << "Unique numbers in order of first appearance:\n";
    for (const auto& num : *uniqueNumbers) {
        std::cout << num << " ";
    }
}