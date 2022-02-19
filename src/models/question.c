struct question {
    int id;
    struct talk *talk; // many to one talk
    int points; // 0 good response but not the best; 1 best response; 2 bad response;
    char content[255];

    /* add reaction */
    //
    char sprite[255]; // name of sprite (list of sprites defined in config.yml)
    char reply[255];
};