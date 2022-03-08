#include "library.h"

int main() {
    MYSQL *con = mysql_init(NULL);

    char info[4][50]; // host, user, passwd, db
    printf("Enter host, username, password, and database, each followed by a newline: ");
    scanf("%s\n%s\n%s\n%s", info[0], info[1], info[2], info[3]);

    if(mysql_real_connect(con, info[0], info[1], info[2], info[3], 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    // TODO: menu

    mysql_close(con);
}

void finish_with_error(MYSQL *con) {
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

void add_book(MYSQL *con) {
    char info[3][500]; //title, author, publish year
    printf("Enter title, author, pubish year, each followed by a newline: ");
    scanf("%s\n%s\n%s", info[0], info[1], info[2]);

    char sql_statement[1500];
    sprintf(sql_statement, "INSERT INTO book VALUES('%s', '%s', '%d')", info[0], info[1], atoi(info[2]));

    if(mysql_query(con, sql_statement) != 0) {
        finish_with_error(con);
    }

    printf("Book %s entered into database.\n", info[0]);
}

void remove_book(MYSQL *con, char title[]) {
    char sql_statement[1500];
    sprintf(sql_statement, "DELETE FROM book WHERE title='%s'", title);

    if(mysql_query(con, sql_statement) != 0) {
        finish_with_error(con);
    }

    printf("Book %s removed from database.\n", title);
}

void view_books(MYSQL *con) {
    printf("to be completed...\n");
}