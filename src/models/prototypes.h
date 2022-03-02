#ifndef CAISSEDECHAMPAGNE_PROTOTYPES_H
#define CAISSEDECHAMPAGNE_PROTOTYPES_H
struct chapter;
struct game;
struct question;
struct talk;

struct chapter *fetch_one_chapter(sqlite3 *db, int *id);
struct chapter *fetch_all_chapters(sqlite3 *db);

struct game *new_game(struct chapter *chapter);
struct game *save_game(sqlite3 *db, struct game *game);
struct game *update_game_score(sqlite3 *db, struct game *game);

struct question *fetch_questions_for_talk(sqlite3 *db, struct talk *talk);

struct talk *fetch_all_talks_for_chapter(sqlite3 *db, struct chapter *chapter);
#endif //CAISSEDECHAMPAGNE_PROTOTYPES_H
