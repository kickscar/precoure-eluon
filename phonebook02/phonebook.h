typedef struct phone
{
	char name[20];
	char tel[20];
	int  used;
	struct phone* next;
} phone;

void phonebook();