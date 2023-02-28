#ifndef GEO_MATRIX_H
#define GEO_MATRIX_H

#include "Plane.h"

template<int N>
class SquareMatrix {
private:
    std::vector<std::vector<double>> array;
public:
    SquareMatrix(std::initializer_list<double> list) {
        if (list.size() != N * N)
            throw std::runtime_error("Not enough element for square matrix");

        for (int i = 0; i < N; ++i) {
            array.emplace_back(std::vector<double>());
        }

        size_t i = 0;

        for (auto elem: list) {
            array[i / N].push_back(elem);
            ++i;
        }
    }

    SquareMatrix &changeColumn(size_t index, std::initializer_list<double> list) {
        if (list.size() != N)
            throw std::runtime_error("Not enough elem to change column");
        if (index >= N)
            throw std::runtime_error("There is no column with such index");
        size_t i = 0;
        for (auto elem: list) {
            array[i][index] = elem;
            ++i;
        }
        return *this;
    }

    double getElem(size_t i, size_t j) const {
        return array[i][j];
    }

};


#endif //GEO_MATRIX_H
