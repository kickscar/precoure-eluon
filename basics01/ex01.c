#include <stdio.h>

int main() {

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }
    
    printf("\n");

    int i = 9;

    if(i % 2 == 0)
    {
        printf("even!\n");
    }
    else
    {
        printf("odd!\n");
    }

    return 0;
}