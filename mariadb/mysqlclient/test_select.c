#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main()
{
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
    char* sql = "select no, name, tel from phonebook";
    if(mysql_query(conn, sql))
    {
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if(result == NULL)
    {
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // fetch row
    int num_fields = mysql_num_fields(result);

    // MYSQL_ROW row;
    // while((row = mysql_fetch_row(result)))
    // {
    //     for(int i = 0; i < num_fields; i++)
    //     {
    //         printf("%s ", row[i] ? row[i] : "NULL");
    //     }
    //     printf("\n");
    // }

    int num_rows = mysql_num_rows(result);
    for(int i = 0; i < num_rows; i++)
    {
        MYSQL_ROW row = mysql_fetch_row(result);
        for(int j = 0; j < num_fields; j++)
        {
            printf("%s ", row[j] ? row[j] : "NULL");
        }
        printf("\n");   
    }
    mysql_free_result(result);

    // close connection
    mysql_close(conn);

    return 0;
}