#include <mysql/mysql.h>
#include <stdio.h>

int main() {
    printf("The MySQL client version is: %s\n", mysql_get_client_info());
}