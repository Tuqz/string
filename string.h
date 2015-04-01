#pragma once
#include <memory>
#include <SDL2/SDL.h>
#include "point.h"
#include "vector.hpp"

class String {
public:
    String(int points);
    void update(double delta_t);
    void draw(SDL_Renderer *renderer);
private:
    double k = 100;
    double length;
    double mass;
    std::unique_ptr<Point[]> mesh;
    int size;
};
