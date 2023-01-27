#include <stdio.h>
#include "mysql.h"

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "89.252.138.195";
    char *user = "salvador_halil";
    char *password = "Hn^bJr5Tc8*X";
    char *database = "salvador_ondergrup";

    conn = mysql_init(NULL);

    if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    printf("MySQL Tables in mysql database: \n");
    while((row = mysql_fetch_row(res)) != NULL) {
        printf("%s \n", row[0]);
    }

    mysql_query(conn, "INSERT INTO testtable (id, name, cyclecount) VALUES ('123123123231', 'OnderGrup Test Makinesi', '3670')");

    mysql_query(conn, "SELECT * FROM testtable");
    res = mysql_use_result(conn);
    while((row = mysql_fetch_row(res)) != NULL) {
        printf("%s %s\n", row[0], row[1]);
    }

    mysql_query(conn, "UPDATE testtable SET name = 'OnderGrup Test Makinesi' WHERE id = 0");
    mysql_query(conn, "DELETE FROM testtable WHERE id = 0");

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}
