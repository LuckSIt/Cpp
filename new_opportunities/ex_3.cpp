#include <iostream>
#include <filesystem>
#include <string>

int main() {
    auto recursiveGetFileNamesByExtension = [](std::filesystem::path &path, const std::string &extension){
        for(auto& p: std::filesystem::recursive_directory_iterator(path)) {
            if (p.is_regular_file() && p.path().extension() == extension) {
                std::cout << p.path().string() << std::endl;
            }
        }
            //std::cout << p.path() << '\n';

    };
    std::filesystem::path p("C:/Users/Vladimir/CLionProjects");
    //std::string ext = "cpp";
    recursiveGetFileNamesByExtension(p, ".cpp");
}