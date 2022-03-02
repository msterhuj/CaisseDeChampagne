#include <SDL2/SDL.h>
#include "database/database.h"
#include "models/models.h"
#include "ui/ui.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
sqlite3* db = NULL;

int main(int argc, char** argv) {

    db = open_database("database.db");
    sqlite3_close(db);

    // Init la lib
    ui_init();
    window = ui_create_window();
    renderer = ui_create_renderer(window);

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

    ui_listen_for_events();
    ui_destroy(window, renderer);
}