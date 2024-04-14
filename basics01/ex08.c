#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    srand(time(NULL));

    // int i = 0;
    // while(i < 1000)
    while(1)
    {
        int r_num = rand() % 100 + 1;
        printf("%d\n", r_num);

        if(r_num == 100) {
            break;
        }
        // i++;
   }

   return 0;
}