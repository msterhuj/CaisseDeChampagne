#include <stdlib.h>

struct game {
    int id;
    struct chapter *chapter;
    int score;
};

/**
 * @brief Creates a new game.
 * @param struct chapter
 * @return
 */
struct game *new_game(struct chapter *chapter) {
    struct game *game = malloc(sizeof(struct game));
    game->chapter = chapter;
    game->score = 0;
    return game;
}

/**
 * @brief Create a game to the database.
 * @param db
 * @param game
 * @return
 */
struct game *save_game(sqlite3 *db, struct game *game) {
    char *query = "INSERT INTO games (chapter_id, score) VALUES (?, ?)";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, game->chapter->id);
    sqlite3_bind_int(stmt, 2, game->score);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return game;
}

struct game *update_game_score(sqlite3 *db, struct game *game) {
    char *query = "UPDATE games SET score = ? WHERE id = ?";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, game->score);
    sqlite3_bind_int(stmt, 2, game->id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return game;
}