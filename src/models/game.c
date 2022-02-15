#include "models.h"

struct game {
    int id;
    int player_id;
    int chapter_id;
    struct chapter *chapter;
    int finished;
    char position[255];
};