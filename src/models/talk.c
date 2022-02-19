struct talk {
    int id;
    struct chapter *chapter;
    char sprite[255]; // name of sprite (list of sprites defined in config.yml)
    char content[255];

    // question id one to many
};