#include <stdio.h>
#include "sqlite3.h"

// open sqlite3 database and return a pointer to it
sqlite3 *open_database(char *db_name) {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open(db_name, &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return NULL;
    }

    return db;
}