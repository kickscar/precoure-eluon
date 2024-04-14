#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main()
{
    // Initialize Connection
    MYSQL* conn = NULL;
    
    if(!(conn = mysql_init(0)))
    {
        fprintf(stderr, "unable to initialize connection struct\n");
        exit(1);
    }

    // Connect to the database
    if(!mysql_real_connect(
         conn,                // Connection
         "10.81.182.195",     // Host
         "webdb",             // User account
         "webdb",             // User password
         "webdb",             // Default database
         3306,                // Port number
         NULL,                // Path to socket file
         0                    // Additional options
    ))
    {
        // Report the failed-connection error & close the handle
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
   }

   printf("Connection Success\n");

   // Close the Connection
   mysql_close(conn);

   return 0;
}