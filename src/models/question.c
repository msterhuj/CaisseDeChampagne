struct question {
    int id;
    struct talk *talk; // many to one talk
    int points; // 0 good response but not the best; 1 best response; 2 bad response;
    char text[255];

    /* add reaction */
    struct Entity *entity;
    char reaction[255];
};