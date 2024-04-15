#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phonebookdb.h"

void print_message(char* message)
{
	printf("전화번호부>> %s \n", message);
}

void print_usage()
{
	fputs("전화번호부>> (l)전체 항목 보기 (i)추가하기 (d)삭제 (q)종료 : ", stdout);
}

void list()
{
	print_message("전체항목");

	phone* phones = NULL;
	
	int cnt = phonebookdb_fetch_all(&phones);
	for(int i = 0; i < cnt; i++)
	{
		printf("[%d] 이름:%s, 전화번호:%s \n", cnt-i, (phones+i)->name, (phones+i)->tel);
	}

	free(phones);
}

void insert()
{
	print_message("추가하기");

	phone new_phone;

	fputs("이름: ", stdout);
	scanf("%s", new_phone.name);
	__fpurge(stdin);

	fputs("전화번호: ", stdout);
	scanf("%s", new_phone.tel);
	__fpurge(stdin);

	phonebookdb_insert(&new_phone);
	print_message("성공적으로 추가되었습니다.");
}

void del()
{
	print_message("삭제");

	char name[20];
	fputs("이름: ", stdout);
	scanf("%s", name);
	__fpurge(stdin);

	phonebookdb_delete_by_name(name);
}

void quit()
{
	exit(0);
}

void phonebook()
{
	while(1)
	{
		char command;

		print_usage();

		scanf("%c", &command); 
		__fpurge(stdin);

		switch( command )
		{
			case 'l' : 
				list();
				break;
			case 'i' :
				insert();
				break;
			case 'd' : 
				del();
				break;
			case 'q' :
				quit();
				break;
			default  :
				print_message("알 수 없는 명령입니다");
				break;
		}
	}
}