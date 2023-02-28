#include "../include/Algoritms.h"

void normalize(Plane &plane) {
    double sqr_k = std::pow(plane.A(), 2) + std::pow(plane.B(), 2) + std::pow(plane.C(), 2);

    double k = std::pow(sqr_k, -0.5);

    k = plane.D() > 0 ? -k : k;

    plane.A(plane.A() * k).B(plane.B() * k).C(plane.C() * k).D(plane.D() * k);
};

double getPointDeviation(Point m, const Plane &plane) {
    auto NormalizePlane = plane;

    normalize(NormalizePlane);

    double ans = m.x * NormalizePlane.A() + m.y * NormalizePlane.B() + m.z * NormalizePlane.C() + NormalizePlane.D();

    return ans;
}

bool areOnDifferentSize(Point m, const Plane &plane) {

    double PointDeviation = getPointDeviation(m, plane);

    return PointDeviation > 0 ? true : false;

}

double getDeterminantSquareMatrix(const SquareMatrix<3> &table) {
    double ans = table.getElem(0, 0) * table.getElem(1, 1) * table.getElem(2, 2) -
                 table.getElem(0, 2) * table.getElem(1, 1) * table.getElem(2, 0) +
                 table.getElem(1, 0) * table.getElem(2, 1) * table.getElem(0, 2) +
                 table.getElem(0, 1) * table.getElem(1, 2) * table.getElem(2, 0) -
                 table.getElem(0, 0) * table.getElem(2, 1) * table.getElem(1, 2) -
                 table.getElem(0, 1) * table.getElem(1, 0) * table.getElem(2, 2);

    return ans;
}

Vector getVectorInNewBasis(const Vector &source, const Vector &l1, const Vector &l2, const Vector &l3) {
    Vector ans = source;

    SquareMatrix<3> Matrix = {l1.X(), l2.X(), l3.X(), l1.Y(), l2.Y(), l3.Y(), l1.Z(), l2.Z(), l3.Z()};

    double det = getDeterminantSquareMatrix(Matrix);
    if (det == 0) throw std::runtime_error("det is equal 0");

    auto Matrix1 = Matrix;
    Matrix1.changeColumn(0,{source.X(), source.Y(),source.Z()});
    double det1 = getDeterminantSquareMatrix(Matrix1);

    auto Matrix2 = Matrix;
    Matrix2.changeColumn(1,{source.X(), source.Y(),source.Z()});
    double det2 = getDeterminantSquareMatrix(Matrix2);

    auto Matrix3 = Matrix;
    Matrix3.changeColumn(2,{source.X(), source.Y(),source.Z()});
    double det3 = getDeterminantSquareMatrix(Matrix3);

    ans.setX(det1 / det);
    ans.setY(det2 / det);
    ans.setZ(det3 / det);

    return ans;
}
