#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int* p;
    int i = 10;

    p = &i;
    printf("%x:%x\n", &i, p);
    printf("%d:%d\n", i, *p);

    i = 20;
    printf("%d:%d\n", i, *p);

    *p = 30;
    printf("%d:%d\n", i, *p);

    char* str = "hello world";
    printf("%s\n", str);

    char str2[strlen(str)+1];
    strcpy(str2, str);
    printf("%s\n", str2);

    char* str3 = str2;
    printf("%s, %c, %c\n", str2, str2[4], *(str2+4));

    for(; *str3 != (char)0 ; str3++) {
        printf("%c", *str3);
    }

    printf("\n--->%d\n", NULL == (char*)0);

    char s[10] = "hello";
    //write(0, s, strlen(s));
    printf("%s, %d, %d, %d\n", s, strlen(s), sizeof(s), s[6]);
}