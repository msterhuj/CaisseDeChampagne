#include <stdio.h>
#include <stdlib.h>

struct chapter {
    int id;
    char name[50];
    int finished;
};

/**
 * @brief Get chapter by id
 * @param db
 * @param id
 * @return chapter struct pointer
 */
struct chapter *fetch_one_chapter(sqlite3 *db, int *id) {
    sqlite3_stmt *stmt;
    int rc;
    struct chapter *chapter;

    rc = sqlite3_prepare_v2(db, "SELECT * FROM chapters WHERE id = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return NULL;
    }

    sqlite3_bind_int(stmt, 1, *id);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        chapter = malloc(sizeof(struct chapter));
        chapter->id = sqlite3_column_int(stmt, 0);
        strcpy(chapter->name, (char *)sqlite3_column_text(stmt, 1));
        chapter->finished = sqlite3_column_int(stmt, 2);
    }

    sqlite3_finalize(stmt);

    return chapter;
}

/**
 * @brief Return list of all chapter
 * @param sqlite3 *db
 * @return struct chapter[] *
 */
struct chapter *fetch_all_chapters(sqlite3 *db) {
    sqlite3_stmt *stmt;
    struct chapter *chapters = malloc(sizeof(struct chapter));
    int rc = sqlite3_prepare_v2(db, "SELECT * FROM chapter", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch all chapters: %s\n", sqlite3_errmsg(db));
        return NULL;
    }
    int i = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        chapters[i].id = sqlite3_column_int(stmt, 0);
        strcpy(chapters[i].name, (char *)sqlite3_column_text(stmt, 1));
        chapters[i].finished = sqlite3_column_int(stmt, 2);
        i++;
    }
    sqlite3_finalize(stmt);
    return chapters;
}