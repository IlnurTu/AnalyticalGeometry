#include "../include/Algoritms.h"

void normalize(Plane &plane) {
    double k = 1 / sqrt(plane.A() * plane.A() + plane.B() * plane.B() + plane.C() * plane.C());
    if (plane.D() > 0)
        k *= -1;
    plane.setA(plane.A() * k);
    plane.setB(plane.B() * k);
    plane.setC(plane.C() * k);
    plane.setD(plane.D() * k);
};

double getPointDeviation(Point m, const Plane &plane) {
    Plane NormalizePlane = plane;
    normalize(NormalizePlane);
    double ans = m.x * NormalizePlane.A() + m.y * NormalizePlane.B() + m.z * NormalizePlane.C() + NormalizePlane.D();
    return ans;
}

bool areOnDifferentSize(Point m, const Plane &plane) {
    if (plane.D() == 0)
        return false;
    double PointDeviation = getPointDeviation(m, plane);

    if (PointDeviation > 0)
        return true;

    return false;
}

double getDeterminantSquareMatrix(const std::vector<std::vector<double>> &table) {
    double ans = table[0][0] * table[1][1] * table[2][2] - table[0][2] * table[1][1] * table[2][0] +
                 table[1][0] * table[2][1] * table[0][2] +
                 table[0][1] * table[1][2] * table[2][0] - table[0][0] * table[2][1] * table[1][2] -
                 table[0][1] * table[1][0] * table[2][2];

    return ans;
}

Vector getVectorInNewBasis(const Vector &source, const Vector &l1, const Vector &l2, const Vector &l3) {
    Vector ans = source;
    std::vector<std::vector<double>> Matrix;
    for (int i = 0; i < 3; ++i) {
        Matrix.emplace_back(std::vector<double>());
    }
    Matrix[0].push_back(l1.X());
    Matrix[0].push_back(l2.X());
    Matrix[0].push_back(l3.X());

    Matrix[1].push_back(l1.Y());
    Matrix[1].push_back(l2.Y());
    Matrix[1].push_back(l3.Y());

    Matrix[2].push_back(l1.Z());
    Matrix[2].push_back(l2.Z());
    Matrix[2].push_back(l3.Z());

    double det = getDeterminantSquareMatrix(Matrix);
    if (det == 0) throw std::runtime_error("det is equal 0");

    auto Matrix1 = Matrix;
    Matrix1[0][0] = source.X();
    Matrix1[1][0] = source.Y();
    Matrix1[2][0] = source.Z();
    double det1 = getDeterminantSquareMatrix(Matrix1);

    auto Matrix2 = Matrix;
    Matrix2[0][1] = source.X();
    Matrix2[1][1] = source.Y();
    Matrix2[2][1] = source.Z();
    double det2 = getDeterminantSquareMatrix(Matrix2);

    auto Matrix3 = Matrix;
    Matrix3[0][2] = source.X();
    Matrix3[1][2] = source.Y();
    Matrix3[2][2] = source.Z();
    double det3 = getDeterminantSquareMatrix(Matrix3);

    ans.setX(det1 / det);
    ans.setY(det2 / det);
    ans.setZ(det3 / det);

    return ans;
}
