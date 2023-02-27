#include "include/Algoritms.h"
#include "include/FileSystem.h"

int main() {
    try {
        std::cout << "Введите название файла" << std::endl;
        std::string name;
        std::cin >> name;

        auto Points = FileReader(name);

        Plane plane(Points[0], Points[1], Points[2]);

        if(plane.D() == 0){
            std::cout<<"Плоскость проходит через начало координат";
            return 0;
        }

        bool AreOnDifferentSize = areOnDifferentSize(Points[3], plane);

        //Если точка лежит на плоскости треугольника, то считается, что ее видно

        if (!AreOnDifferentSize) {
            std::cout << "Видно за треугольником" << std::endl;
            return 0;
        }

        Vector vectorToA(Points[0]), vectorToB(Points[1]), vectorToC(Points[2]), vectorToCurrentPoint(Points[3]);

        auto vectorToCurrentPointInNewBasis = getVectorInNewBasis(vectorToCurrentPoint, vectorToA, vectorToB,
                                                                  vectorToC);

        if (vectorToCurrentPointInNewBasis.X() >= 0 && vectorToCurrentPointInNewBasis.Y() >= 0 &&
            vectorToCurrentPointInNewBasis.Z() >= 0) {
            std::cout << "Не видно за треугольником" << std::endl;
            return 0;
        }

        std::cout << "Видно за треугольником" << std::endl;
    }catch (std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

    return 0;
}
