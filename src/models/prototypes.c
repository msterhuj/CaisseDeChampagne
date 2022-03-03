// ======= Prototypes des fonctions =======
#include <SDL2/SDL.h>

// ------- UI -------
void ui_init();
SDL_Window *ui_create_window();
SDL_Renderer *ui_create_renderer();
void ui_create_scenery(int scenery);
void ui_create_question_area();
void ui_create_qbox(int nb);
void ui_listen_for_events();
void ui_destroy();


// ------- STRING -------
void write_qtext(int nb_qbox, int box, char* content);
void ui_create_txt_area(char* dialog);