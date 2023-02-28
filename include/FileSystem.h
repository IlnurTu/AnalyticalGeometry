#include "Plane.h"
#ifndef GEO_FILESYSTEM_H
#define GEO_FILESYSTEM_H


std::vector<Point> FileReader(std::ifstream& );

std::ifstream openFile(std::filesystem::path);


#endif //GEO_FILESYSTEM_H
