#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include "phonebookdb.h"

const char* host = "192.168.0.205";
const int port = 3306;
const char* user = "webdb";
const char* password = "webdb";
const char* db = "webdb";

MYSQL* eluondb_connect()
{
    MYSQL* conn = NULL;

    if((conn = mysql_init(0)) == NULL)
    {
        fprintf(stderr, "unable to initialize connection struct\n");
        return conn;
    }

    if(mysql_real_connect(conn, host, user, password, db, port, NULL, 0) == NULL)
    {
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        return conn;
    }

    return conn;
}

int phonebookdb_fetch_all(phone** phones)
{
    MYSQL* conn = eluondb_connect();

    if(conn == NULL)
    {
        fprintf(stderr, "unable to initialize connection struct\n");
        return -1;
    }

    char* sql = "select name, tel from phonebook";
    if(mysql_query(conn, sql))
    {
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    MYSQL_RES* res = mysql_store_result(conn);
    if(res == NULL)
    {
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    int num_rows = mysql_num_rows(res);

    *phones = (phone*)malloc(num_rows * sizeof(phone));
    for(int i = 0; i < num_rows; i++)
    {
        MYSQL_ROW row = mysql_fetch_row(res);

        phone* it = *phones + i;
        strcpy(it->name, row[0] ? row[0] : "NULL");
        strcpy(it->tel, row[1] ? row[1] : "NULL");
    }

    mysql_free_result(res);
    mysql_close(conn);

    return num_rows;    
}

int phonebookdb_insert(phone* phone)
{
    MYSQL* conn = eluondb_connect();

    if(conn == NULL)
    {
        fprintf(stderr, "unable to initialize connection struct\n");
        return -1;
    }

    char sql[200];
    sprintf(sql, "insert into phonebook values(null, '%s', '%s')", phone->name, phone->tel);
    
    if(mysql_query(conn, sql))
    {
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    mysql_close(conn); 

    return 0;
}

int phonebookdb_delete_by_name(char* name)
{
    MYSQL* conn = eluondb_connect();

    if(conn == NULL)
    {
        fprintf(stderr, "unable to initialize connection struct\n");
        return -1;
    }

    char sql[200];
    sprintf(sql, "delete from phonebook where name = '%s'", name);
    
    if(mysql_query(conn, sql))
    {
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    mysql_close(conn); 

    return 0;
}