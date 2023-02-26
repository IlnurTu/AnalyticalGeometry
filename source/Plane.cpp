#include "../include/Plane.h"


Plane::Plane(const Point &k, const Point &l, const Point &m) {

    a = (l.y - k.y) * (m.z - k.z) - (l.z - k.z) * (m.y - k.y);
    b = -1 * ((l.x - k.x) * (m.z - k.z) - (l.z - k.z) * (m.x - k.x));
    c = (l.x - k.x) * (m.y - k.y) - (l.y - k.y) * (m.x - k.x);
    d = -1 * k.x * a - k.y * b - k.z * c;

}

double Plane::A() const {
    return a;
}

double Plane::B() const {
    return b;
}

double Plane::C() const {
    return c;
}

double Plane::D() const {
    return d;
}

void Plane::setA(double a_) {
    a = a_;
}

void Plane::setB(double b_) {
    b = b_;
}

void Plane::setC(double c_) {
    c = c_;
}

void Plane::setD(double d_) {
    d = d_;
}

Vector::Vector(Point to, Point from) :x(to.x - from.x), y(to.y - from.y), z(to.z - from.z){};

double Vector::X() const {
    return x;
}

double Vector::Y() const {
    return y;
}

double Vector::Z() const {
    return z;
}

void Vector::setX(double x_) {
    x = x_;
}

void Vector::setY(double y_) {
    y = y_;
}

void Vector::setZ(double z_) {
    z = z_;
}


