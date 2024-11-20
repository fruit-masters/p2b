#include "gui.h"

int gui_init(SDL_Window** window, SDL_Renderer** renderer) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER);

    *window = SDL_CreateWindow("p2b", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_MAXIMIZED);
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    return 0;
}

void gui_loop(SDL_Window* window, SDL_Renderer* renderer, int* close) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *close = 1;
                break;
        }
    }

    SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 41, 41, 41, 255);
    SDL_FRect rect = {0, 0, 20 vw, 100 vh};
    SDL_RenderFillRectF(renderer, &rect);
    SDL_RenderPresent(renderer);
}