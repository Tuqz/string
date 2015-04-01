#pragma once
#include "vector.hpp"

struct Point {
friend class String;
public:
    Vector pos, vel;
private:
    Point *left, *right;
};

typedef struct Point Point;
