struct question {
    int id;
    struct talk *talk; // many to one talk
    int points; // 0 good response but not the best; 1 best response; 2 bad response;
    char content[255];

    /* add reaction */

    char sprite[255]; // name of sprite (list of sprites defined in config.yml)
    char reply[255];
};

/**
 * @brief Return list of questions for a talk
 * @param db
 * @param talk
 * @return
 */
struct question *fetch_questions_for_talk(sqlite3 *db, struct talk *talk) {
    sqlite3_stmt *stmt;
    struct question *questions = malloc(sizeof(struct question));

    int rc = sqlite3_prepare_v2(db, "SELECT * FROM questions WHERE talk_id = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return NULL;
    }
    sqlite3_bind_int(stmt, 1, talk->id);

    int i = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        questions[i].id = sqlite3_column_int(stmt, 0);
        questions[i].talk = talk;
        questions[i].points = sqlite3_column_int(stmt, 2);
        strcpy(questions[i].content, (char *) sqlite3_column_text(stmt, 3));
        strcpy(questions[i].sprite, (char *) sqlite3_column_text(stmt, 4));
        strcpy(questions[i].reply, (char *) sqlite3_column_text(stmt, 5));
        i++;
    }
    sqlite3_finalize(stmt);
    return questions;
}