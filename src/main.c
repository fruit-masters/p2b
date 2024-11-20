#include <stdio.h>
#include "gui.h"

int main(int argc, char* argv[]) {
    printf("p2b\n");

    SDL_Window* window;
    SDL_Renderer* renderer;
    gui_init(&window, &renderer);

    int close = 0;

    while (!close) {
        gui_loop(window, renderer, &close);

        SDL_Delay(1000 / 60);
    }

    return 0;
}