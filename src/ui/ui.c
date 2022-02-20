// ======= Fonctions liées à la création de l'UI =======

#include <SDL2/SDL.h>

// --- INIT ---
void ui_init() {
    if (SDL_Init( SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error on sdl : %s", SDL_GetError());
        exit(1);
    } else {
        SDL_Quit();
    }
}


// create a new window and return its pointer
SDL_Window *ui_create_window() {
    SDL_Window *window = SDL_CreateWindow("CaisseDeChampagne", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512, 512, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        //exit(1);
        SDL_Quit();
    }
    return window;
}


// create a new renderer and return its pointer
SDL_Renderer *ui_create_renderer(SDL_Window *window) {
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
        //exit(1);
        SDL_Quit();
    }
    return renderer;
}


// --- CREATE QUESTION AREA ---
void ui_create_question_area(SDL_Renderer *renderer, SDL_Texture *briques_texture){
    // define area
    SDL_Rect question_area = {
            .x = 0,
            .y = 334,
            .w = 512,
            .h = 178
    };

    // apply texture on question_area
    SDL_Surface *tmp = NULL;
    tmp = SDL_LoadBMP( "D:/Adrian/Documents/Projet C/C/CaisseDeChampagne/src/texture/briques.bmp" );
    if( tmp == NULL ){
        printf( "Erreur SDL_LoadBMP : %s\n", SDL_GetError() );
    }
    briques_texture = SDL_CreateTextureFromSurface( renderer, tmp );

    SDL_FreeSurface( tmp );
    if( briques_texture == NULL ){
        printf( "Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError() );
    }
    SDL_RenderCopy( renderer, briques_texture, NULL, &question_area );

    SDL_RenderPresent(renderer);
}


// --- CREATE QUESTION BLOCKS ---
void ui_create_qbox(SDL_Renderer *renderer, SDL_Texture *qblocks_texture, int nb){
    // define the blocks
    int x_array[4];
    int y_array[4];
    int w, h;

    SDL_Surface *tmp = NULL;

    switch (nb) {
        default:
        case 1:
            x_array[0] = 10 ;
            y_array[0] = 344 ;

            w = 492;
            h = 158;
            tmp = SDL_LoadBMP( "D:/Adrian/Documents/Projet C/C/CaisseDeChampagne/src/texture/q1.bmp" );

            break;

        case 2:
            x_array[0] = 10;
            y_array[0] = 344;

            x_array[1] = 261;
            y_array[1] = 344 ;

            w = 241;
            h = 158;
            tmp = SDL_LoadBMP( "D:/Adrian/Documents/Projet C/C/CaisseDeChampagne/src/texture/q2.bmp" );

            break;

        case 3:
            x_array[0] = 10;
            y_array[0] = 344;

            x_array[1] = 261;
            y_array[1] = 344;

            x_array[2] = 135;
            y_array[2] = 428;

            w = 241;
            h = 74;
            tmp = SDL_LoadBMP( "D:/Adrian/Documents/Projet C/C/CaisseDeChampagne/src/texture/q3.bmp" );

            break;

        case 4:
            x_array[0] = 10;
            y_array[0] = 344;

            x_array[1] = 261;
            y_array[1] = 344;

            x_array[2] = 10;
            y_array[2] = 428;

            x_array[3] = 261;
            y_array[3] = 428;

            w = 241;
            h = 74;
            tmp = SDL_LoadBMP( "D:/Adrian/Documents/Projet C/C/CaisseDeChampagne/src/texture/q3.bmp" );

            break;
    }


    if( tmp == NULL ){
        printf( "Erreur SDL_LoadBMP : %s\n", SDL_GetError() );
    }
    qblocks_texture = SDL_CreateTextureFromSurface( renderer, tmp );

    SDL_FreeSurface( tmp );
    if( qblocks_texture == NULL ){
        printf( "Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError() );
    }


    for( int i = 0; i < nb; ++i ){
        SDL_Rect qblock = {
                .x = x_array[i],
                .y = y_array[i],
                .w = w,
                .h = h
        };

        SDL_RenderCopy( renderer, qblocks_texture, NULL, &qblock );
        SDL_RenderPresent(renderer);
    }
}


// --- DESTROY ---
void ui_destroy(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *briques_texture, SDL_Texture *qblocks_texture) {
    if(NULL != briques_texture){
        SDL_DestroyTexture(briques_texture);
    }
    if(NULL != qblocks_texture){
        SDL_DestroyTexture(qblocks_texture);
    }
    if(NULL != renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if(NULL != window) {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}