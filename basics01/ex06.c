#include <stdio.h>
#include <stdbool.h>

int main()
{
    for(int num = 2; num <=100; num++)
    {
        bool b_primary = true;
        for(int i = 2; i < num; i++)
        {
            if(num % i == 0)
            {
                b_primary = false;
                break;
            }
        }

        if(b_primary)
        {
            printf("%d\n", num);
        }
    }
    return 0;
}
