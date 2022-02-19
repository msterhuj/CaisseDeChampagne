#include "models.h"

struct talk {
    int id;
    struct chapter *chapter;
    struct entity *entity; // The entity that is talking
    char text[255];

    int question_group_id; // nullable if nullable
};
typedef struct Talk Talk;