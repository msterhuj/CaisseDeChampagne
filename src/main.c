#include <stdio.h>
#include <SDL2/SDL.h>
#include "sqlite3.h"
#include "database/database.h"
#include "ui/ui.h"
#include "models/models.h"
#include "models/prototypes.c"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture *briques_texture = NULL;
SDL_Texture *qblocks_texture = NULL;
sqlite3* db = NULL;

int main(int argc, char** argv) {

    db = open_database("database.db");
    sqlite3_close(db);

    // Init la lib
    ui_init();
    window = ui_create_window();
    renderer = ui_create_renderer(window);

    SDL_RenderClear(renderer);

    // ========================================= START draw ========================================

    ui_create_question_area(renderer, briques_texture);
    int nb = 2;
    ui_create_qbox(renderer, qblocks_texture, nb);



    // ========================================= FIN draw ========================================
    ui_listen_for_events();
    ui_destroy(window, renderer, briques_texture, qblocks_texture);
    return EXIT_SUCCESS;
}