#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

const int WIDTH = 1920;
const int HEIGHT = 1080;
#define vw * (WIDTH / 100.0)
#define vh * (HEIGHT / 100.0)

int main(int argc, char* argv[]) {
    printf("p2b\n");

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER);

    SDL_Window* window = SDL_CreateWindow("p2b", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_MAXIMIZED);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    int close = 0;

    while (!close) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    close = 1;
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 41, 41, 41, 255);
        SDL_FRect rect = {0, 0, 20 vw, 100 vh};
        SDL_RenderFillRectF(renderer, &rect);
        SDL_RenderPresent(renderer);

        SDL_Delay(1000 / 60);
    }

    return 0;
}