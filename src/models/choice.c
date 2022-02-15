#include "models.h"

struct choice {
    int id;
    int type; // 0 intro; 1 advice; 2 choice;
    int points; // 0 bad response; 1 good response but not the best; 2 best response
    struct question *question;
};