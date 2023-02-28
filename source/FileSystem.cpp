#include "../include/FileSystem.h"

std::ifstream openFile(std::filesystem::path path){
    std::ifstream file(path);
    if(!file.is_open()){
        throw std::runtime_error("File error");
    }
    return file;
}

std::vector<Point> FileReader(std::ifstream& inf) {
    std::vector<Point> ans;

    double x, y, z;

    for (int i = 0; i < 4; ++i) {
        inf >> x >> y >> z;
        ans.push_back({x, y, z});
    }

    return ans;
}

