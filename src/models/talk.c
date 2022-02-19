struct talk {
    int id;
    struct chapter *chapter;
    struct entity *entity; // The entity that is talking
    char text[255];

    // question id one to many
};