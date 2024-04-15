typedef struct phone
{
    unsigned long no;
	char name[20];
	char tel[20];
} phone;

int phonebookdb_fetch_all(phone**);
int phonebookdb_insert(phone*);
int phonebookdb_delete_by_name(char*);