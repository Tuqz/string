#include "string.h"
#include <cmath>

String::String(int points) {
    length = 2.0 / (points - 1);
    mass = 1.0 / points;
    mesh = std::unique_ptr<Point[]>(new Point[points]);
    size = points;
    for(int i = 0; i < points; ++i) {
        Point point;
        point.pos = Vector(0.4 + (i * length), 0);
        point.vel = Vector(0, 1);
        mesh[i] = point;
        mesh[i].left = i ? &mesh[i - 1] : nullptr;
        mesh[i].right = nullptr;
        if(i) {
            mesh[i - 1].right = &mesh[i];
        }
    }
}

void String::update(double delta_t) {
    for(int i = 0; i < size; ++i) {
        mesh[i].pos = mesh[i].pos + (mesh[i].vel * delta_t);
    }

    for(int i = 0; i < size; ++i) {
        Vector accel(0, 0.5);
        Point curr = mesh[i];
        if(mesh[i].left) {
            Point left = *curr.left;
            Vector diff = curr.pos - left.pos; //Don't use the old position - using the new position and old velocity improves the conservation of energy
            accel = accel +  (diff/diff.abs()) * ((-k * (diff.abs() - length))/mass);
        }

        if(mesh[i].right) {
            Point right = *curr.right;
            Vector diff = curr.pos - right.pos;
            accel = accel + (diff/diff.abs()) * ((-k * (diff.abs() - length))/mass);
        }

        if((curr.pos - Vector(0, 1)).abs() < 0.5) {
            curr.vel = Vector(0, 0);
        } else {
            curr.vel = curr.vel + (accel * delta_t);
        }

        mesh[i] = curr;
    }
}

void String::draw(SDL_Renderer *renderer) {
    for(int i = 1; i < size; ++i) {
        double len = (mesh[i].pos - mesh[i - 1].pos).abs();
        double stress = std::abs(k * (len - length));
        double col_val = (stress) * (255/1);
        col_val = col_val > 255 ? 255 : col_val;
        SDL_SetRenderDrawColor(renderer, col_val, 255 - col_val, 0, 255);
        SDL_RenderDrawLine(renderer, \
            (mesh[i].pos.x + (8.0 / 3)) * (480/4), \
            mesh[i].pos.y * (480/4), \
            (mesh[i - 1].pos.x + (8.0 / 3)) * (480/4), \
            mesh[i - 1].pos.y * (480/4));
    }
}
