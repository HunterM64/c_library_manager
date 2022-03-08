#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con);
void add_book(MYSQL *con);
void remove_book(MYSQL *con, char title[]);
void view_books(MYSQL *con);
