#include <stdio.h>

int max(int, int, int);

int main() {

    int num1 = 0, num2 = 0, num3 = 0;

    fputs("세 수 입력: ", stdout);
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("최대값: %d\n", max(num1, num2, num3));

    return 0;
}

int max(int num1, int num2, int num3) {
    return num2;
}