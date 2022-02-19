struct question {
    int id;
    int group_id;
    int points; // 0 good response but not the best; 1 best response; 2 bad response;
    char text[255];

    /* add reaction */
    Entity *entity;
    char reaction[255];
};