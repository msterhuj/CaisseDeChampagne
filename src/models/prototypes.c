// ======= Prototypes des fonctions =======
#include <SDL2/SDL.h>

// ------- UI -------
void ui_init();
SDL_Window *ui_create_window();
SDL_Renderer *ui_create_renderer(SDL_Window *window);
void ui_create_question_area(SDL_Renderer *renderer, SDL_Texture *briques_texture);
void ui_create_qbox(SDL_Renderer *renderer, SDL_Texture *qblocks_texture, int nb);
void ui_listen_for_events();
void ui_destroy(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, SDL_Texture *qblocks_texture);


