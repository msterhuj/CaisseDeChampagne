#include "models.h"

struct talk {
    int id;
    struct chapter *chapter;
    struct entity *entity; // The entity that is talking
    int type; // 0 fuild, 1 not best responce, 2 best responce
    char text[255];

    struct question *question; // nullable if nullable
};

// peatch dit bonjour

// mario dit : [question]