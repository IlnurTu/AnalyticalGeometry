

#ifndef GEO_PLANE_H
#define GEO_PLANE_H
#include <exception>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

struct Point {
    double x, y, z;
};

class Plane {
    //Ax + By + Cz + D = 0
    double a;
    double b;
    double c;
    double d;
public:
    Plane(const Point &k, const Point &l, const Point &m);

    double A() const;

    double B() const;

    double C() const;

    double D() const;

    Plane& A(double a_);

    Plane& B(double b_);

    Plane& C(double c_);

    Plane& D(double d_);
};

class Vector {
    double x, y, z;
public:
    Vector(Point to, Point from = {0, 0, 0});

    double X() const;

    double Y() const;

    double Z() const ;

    void setX(double x_);

    void setY(double y_);

    void setZ(double z_);
};

#endif
