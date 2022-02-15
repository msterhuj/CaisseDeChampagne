#include <stdio.h>
#include "sqlite3.h"

/**
 * @brief Create db file is not exist and open db file
 * @param db_name
 * @return sqlite3*
 */
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

/**
 * @brief delete db file
 * @param db_name
 */
void delete_database(char *db_name) {
    remove(db_name);
}

/**
 * @brief exec sql script on db file
 * @param db
 * @param sql_file
 * @return void
 */
int exec_sql_file(sqlite3 *db, char *sql_file) {
    char *zErrMsg = 0;
    int rc;
    FILE *fp;
    char *sql;
    size_t size;

    fp = fopen(sql_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file: %s\n", sql_file);
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    sql = malloc(size + 1);
    if (sql == NULL) {
        fprintf(stderr, "Can't allocate memory\n");
        return -1;
    }

    if (fread(sql, 1, size, fp) != size) {
        fprintf(stderr, "Can't read file: %s\n", sql_file);
        return -1;
    }

    sql[size] = '\0';

    rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return -1;
    }

    fclose(fp);
    free(sql);

    return 0;
}