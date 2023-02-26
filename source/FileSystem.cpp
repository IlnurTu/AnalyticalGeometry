#include "../include/FileSystem.h"

std::vector<Point> FileReader(const std::string &name) {
    std::vector<Point> ans;
    std::ifstream inf(name);
    if (!inf.is_open()) {
        throw std::runtime_error("File error");
    }
    double x, y, z;
    for (int i = 0; i < 4; ++i) {
        inf >> x >> y >> z;
        ans.push_back({x, y, z});
    }
    return ans;
}

