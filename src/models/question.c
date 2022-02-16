struct question {
    int id;
    int group;
    int points; // 0 nothing; 1 good response but not the best; 2 best response; 3 bad response;
    char text[255];

    /* add reaction */
    // entity reaction id
    // entity reaction text
};