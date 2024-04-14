#include <stdio.h>

int main()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = i; j < i + 10; j++)
        {
            printf("%d ", j+1);
        }

        printf("\n");
    }
    return 0;
}
