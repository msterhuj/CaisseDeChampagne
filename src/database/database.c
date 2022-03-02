#include <stdio.h>
#include <string.h>
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
    char *sql;
    char *sql_tmp;
    FILE *fp;

    fp = fopen(sql_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file: %s\n", sql_file);
        return -1;
    }

    sql = (char *) malloc(sizeof(char) * 1024);
    sql_tmp = (char *) malloc(sizeof(char) * 1024);
    while (fgets(sql_tmp, 1024, fp) != NULL) {
        strcat(sql, sql_tmp);

        if (strstr(sql, ";")) { // todo fix error of text on decoding
            rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
            if (rc != SQLITE_OK) {
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
                return -1;
            }
            sql[0] = '\0';
        }
    }


    fclose(fp);
    free(sql);
    free(sql_tmp);

    return 0;
}