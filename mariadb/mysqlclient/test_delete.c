#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main(int argc, char** argv)
{
    if(argc != 2) {
        fputs("usage: test_delete name\n", stdout);
        exit(0);
    }

    // initialize connection
    MYSQL* conn = NULL;
    
    if(!(conn = mysql_init(0)))
    {
        fprintf(stderr, "unable to initialize connection struct\n");
        exit(1);
    }

    // connect to the database
    if(mysql_real_connect(
         conn,                // Connection
         "10.81.182.195",     // Host
         "webdb",             // User account
         "webdb",             // User password
         "webdb",             // Default database
         3306,                // Port number
         NULL,                // Path to socket file
         0                    // Additional options
    ) == NULL)
    {
        // error & close connection
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }


    // execute SQL
    char sql[200];
    sprintf(sql, "delete from phonebook where name = '%s'", *(argv+1));

    if(mysql_query(conn, sql))
    {
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);   
    }

    // close connection
    mysql_close(conn);

    return 0;
}