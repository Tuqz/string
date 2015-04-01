#include "vector.hpp"
#include <cmath>

Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}

Vector Vector::operator+ (const Vector& a) {
    return Vector(x + a.x, y + a.y);
}

Vector Vector::operator- (const Vector& a) {
    return Vector(x - a.x, y - a.y);
}

double Vector::dot(const Vector& a, const Vector& b) {
    return (a.x * b.x) + (a.y * b.y);
}

double Vector::abs() {
    return sqrt(Vector::dot(*this, *this));
}
