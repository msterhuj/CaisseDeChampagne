#include <SDL2/SDL.h>
#include "ui.h"

void ui_listen_for_events() {
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_WINDOWEVENT) {
            switch (event.window.event) {
                case SDL_WINDOWEVENT_CLOSE:
                    puts("Close app");
                    return;
                default:
                    break;
            }
        } else if (event.type == SDL_MOUSEBUTTONUP) {
            printf("Mouse position: %d, %d\n", event.button.x, event.button.y);
        }
    }
}