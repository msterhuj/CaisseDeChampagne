#include <stdio.h>
#include <stdlib.h>

struct talk {
    int id;
    struct chapter *chapter;
    char sprite[255]; // name of sprite (list of sprites defined in config.yml)
    char content[255];

    // question id one to many
};

struct talk *fetch_all_talks_for_chapter(sqlite3 *db, struct chapter *chapter) {
    sqlite3_stmt *stmt;

    struct talk *talks = malloc(sizeof(struct talk));
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM talks WHERE chapter_id = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return NULL;
    }
    int i = 0;
    sqlite3_bind_int(stmt, 1, chapter->id);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        struct talk *talk = malloc(sizeof(struct talk));
        talk->id = sqlite3_column_int(stmt, 0);
        talk->chapter = chapter;
        strcpy(talk->sprite, (char *)sqlite3_column_text(stmt, 1));
        strcpy(talk->content, (char *)sqlite3_column_text(stmt, 2));
        talks[i] = *talk;
        i++;
    }
    sqlite3_finalize(stmt);
    return talks;
}