#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL.h>

#define WIDTH 1920
#define HEIGHT 1080
#define vw * (WIDTH / 100.0)
#define vh * (HEIGHT / 100.0)

int gui_init(SDL_Window** window, SDL_Renderer** renderer);
void gui_loop(SDL_Window* window, SDL_Renderer* renderer, int* close);