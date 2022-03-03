// ======= Fonctions liées à la création de l'UI =======

#include <SDL2/SDL.h>

// ------- Appel des variables globales -------
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* briques_texture;
extern SDL_Texture* qblocks_texture;
extern SDL_Texture* scenery_texture;
extern sqlite3* db;




// --- DESTROY ---
void ui_destroy() {
    if(scenery_texture != NULL){
        SDL_DestroyTexture(scenery_texture);
    }
    if(briques_texture != NULL){
        SDL_DestroyTexture(briques_texture);
    }
    if(qblocks_texture != NULL){
        SDL_DestroyTexture(qblocks_texture);
    }
    if(renderer != NULL){
        SDL_DestroyRenderer(renderer);
    }
    if(window != NULL){
        SDL_DestroyWindow(window);
    }

    TTF_Quit();
    SDL_Quit();
}


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
void ui_create_qbox(int nb){
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


// --- WRITE INTO QUESTION BLOCKS ---
void write_qtext( int nb_qbox, int box, char* content ){
    /* margins (for aesthetic purpose)
        right and left = 28px
        top and bottom = 26px   */

    int margin_x = 26;
    int margin_y = 10;
    int w, h;
    int *arrayX, *arrayY;

    // Tableaux de coordonnées
    int arrayX_1box[] = {10};
    int arrayY_1box[] = {344};

    int arrayX_2box[] = {10, 261};
    int arrayY_2box[] = {344, 344};

    int arrayX_3box[] = {10, 261, 135};
    int arrayY_3box[] = {344, 344, 428};

    int arrayX_4box[] = {10, 261, 10, 261};
    int arrayY_4box[] = {344, 344, 428, 428};

    switch (nb_qbox){
        default:
        case 1:
            arrayX = arrayX_1box;
            arrayY = arrayY_1box;
            w = 492 - ( margin_x*2 );
            h = 158 - ( margin_y*2 );
            break;

        case 2:
            arrayX = arrayX_2box;
            arrayY = arrayY_2box;
            w = 241 - ( margin_x*2 );
            h = 158 - ( margin_y*2 );
            break;

        case 3:
            arrayX = arrayX_3box;
            arrayY = arrayY_3box;
            w = 241 - ( margin_x*2 );
            h = 74 - ( margin_y*2 );
            break;

        case 4:
            arrayX = arrayX_4box;
            arrayY = arrayY_4box;
            w = 241 - ( margin_x*2 );
            h = 74 - ( margin_y*2 );
            break;
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

    // Font parameters
    TTF_Font* font = TTF_OpenFont( "consola.ttf", 14 );
    TTF_SetFontStyle( font, TTF_STYLE_BOLD);
    SDL_Color color = { 0, 0, 0 };


    SDL_Surface * surface = TTF_RenderText_Blended( font, content, color );
    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, surface );

    SDL_QueryTexture( texture, NULL, NULL, &w, &h );
    int x = *(arrayX + box) + margin_x;
    int y = *(arrayY + box) + 2*margin_y;
    SDL_Rect txt_area = { x, y, w, h };

    SDL_RenderCopy( renderer, texture, NULL, &txt_area );
    SDL_RenderPresent( renderer );


    SDL_DestroyTexture( texture );
    SDL_FreeSurface( surface );
    TTF_CloseFont( font );
}


void ui_create_txt_area(char* dialog){
    // --- Create box ---

    // qarea start at y = 334
    SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_BLEND );
    SDL_SetRenderDrawColor( renderer,  255, 255, 255, 200 );

    int h = 60; // hauteur de la box
    int w = 512;
    SDL_Rect dialog_area = {
            .x = 0,
            .y = 334 - h,
            .w = w,
            .h = h
    };

    SDL_RenderFillRect( renderer, &dialog_area );
    SDL_RenderPresent( renderer );


    // --- Add text ---
    TTF_Font* font = TTF_OpenFont( "consola.ttf", 14 );
    TTF_SetFontStyle( font, TTF_STYLE_BOLD);
    SDL_Color color = { 0, 0, 0 };

    SDL_Surface * surface = TTF_RenderText_Blended( font, dialog, color );
    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, surface );

    SDL_QueryTexture( texture, NULL, NULL, &w, &h );
    int x = 10;
    int y = 334 - h;
    SDL_Rect txt_area = { x, y, w, h };

    SDL_RenderCopy( renderer, texture, NULL, &txt_area );
    SDL_RenderPresent( renderer );


    SDL_DestroyTexture( texture );
    SDL_FreeSurface( surface );
    TTF_CloseFont( font );

}