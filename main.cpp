#include <cmath>
#include <SDL2/SDL.h>
#include "string.h"

void drawCircle(SDL_Renderer *renderer) {
    int steps = 100;
    for(int i = 0; i < steps; ++i) {
        double theta = i * 2 * 3.14159/steps;
        double pre_theta = (i - 1) * 2 * 3.14159/steps;

        SDL_RenderDrawLine(renderer, \
            (0.5 * (480/4) * cos(theta)) + (480/1.5), \
            (480 / 4) * ((0.5 * sin(theta)) + 1), \
            (0.5 * (480/4) * cos(pre_theta)) + (480/1.5), \
            (480 / 4) * ((0.5 * sin(pre_theta)) + 1) \
        );
    }
}

int main() {
    String string(100);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow( \
        "String Simulator", \
        SDL_WINDOWPOS_UNDEFINED, \
        SDL_WINDOWPOS_UNDEFINED, \
        640, \
        480, \
        SDL_WINDOW_SHOWN);

    SDL_Surface *screen = SDL_GetWindowSurface(window);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    bool quit = false;
    SDL_Event evt;
    while(!quit) {
        while(SDL_PollEvent(&evt) != 0) {
            if(evt.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        drawCircle(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        string.draw(renderer);
        SDL_RenderPresent(renderer);
        int ticks_per_frame = 100;
        for(int i = 0; i < ticks_per_frame; ++i) {
            string.update(0.00001);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
