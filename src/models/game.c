#include "models.h"

struct game {
    int id;
    struct player *player;
    struct chapter *chapter;
    int finished;
    char position[255];
};