#pragma once
#include <iostream>

class Vector{
public:
    double x, y;

    Vector();
    Vector(double in_x, double in_y);

    Vector operator+ (const Vector& a);

    Vector operator- (const Vector& a);

    template<typename T>
    Vector operator* (T a) {
        return Vector(a * x, a * y);
    }

    template<typename T>
    Vector operator/ (T a) {
        return Vector(x / a, y / a);
    }

    double abs();

    double static dot(const Vector& a, const Vector& b);
};
