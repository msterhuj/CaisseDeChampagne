#include <SDL2/SDL.h>

void ui_init() {
    if (SDL_Init( SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error on sdl : %s", SDL_GetError());
        exit(1);
    }
}

// create a new window and return its pointer
SDL_Window *ui_create_window() {
    SDL_Window *window = SDL_CreateWindow("CaisseDeChampagne", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512, 512, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        exit(1);
    }
    return window;
}

// create a new renderer and return its pointer
SDL_Renderer *ui_create_renderer(SDL_Window *window) {
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
    return renderer;
}

// destroy window and renderer
void ui_destroy(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}