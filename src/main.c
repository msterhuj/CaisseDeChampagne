#include <SDL2/SDL.h>
#include "database/database.h"
#include "models/models.h"
#include "models/prototypes.c"
#include <SDL2/SDL_ttf.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture *briques_texture = NULL;
SDL_Texture *qblocks_texture = NULL;
sqlite3* db = NULL;
#include "ui/ui.h"

int main(int argc, char** argv) {

    db = open_database("database.db");
    sqlite3_close(db);

    // Init la lib
    ui_init();
    txt_init();
    window = ui_create_window();
    renderer = ui_create_renderer(window);

    SDL_RenderClear(renderer);

    // ========================================= START draw ========================================
    ui_create_scenery( 0 );

    ui_create_question_area(renderer, briques_texture);
    int nb = 2;
    ui_create_qbox(nb);

    int nb_qbox = nb;
    ui_create_qbox(nb);

    int box = 0;
    char string[] = "123456789 123456789 123456789 123456789 123456789 1234";
    write_qtext( nb_qbox, box, string );

    char dialog[] = "123456789 123456789 123456789 123456789 123456789 123456789 1";
    ui_create_txt_area( dialog );


    // ========================================= FIN draw ========================================
    ui_listen_for_events();
    ui_destroy(window, renderer, briques_texture, qblocks_texture);
    return EXIT_SUCCESS;
}