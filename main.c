#include <stdio.h>
#include <SDL2/SDL.h>

// pointers availables everywhere
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main(int argc, char** argv) {
    // Init la lib
    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "Oulala sdl marche pas, erreur : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    int windowWidth = 512, windowHeight = 512;
    char* windowName = "Oulala";

    window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        return -1;
    }

    SDL_RenderClear(renderer);

    //ici tu draw
    SDL_Rect rect = {
            .x = 0,
            .y = 0,
            .w = 100,
            .h = 50
    };
    SDL_RenderDrawRect(renderer, &rect);


    SDL_RenderPresent(renderer);

    SDL_Event event;
    int exit = 0;
    while (!exit) {
        while(SDL_WaitEvent(&event)) {
            if (event.type == SDL_WINDOWEVENT) {
                switch (event.window.event) {
                    case SDL_WINDOWEVENT_RESIZED:
                        puts("Oulala le resize");
                        break;
                    case SDL_WINDOWEVENT_CLOSE:
                        puts("Oulala le close");
                        exit = 1;
                        return EXIT_SUCCESS;
                        break;
                }
            }
        }
    }
}
