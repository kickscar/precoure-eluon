#include <stdio.h>

int main() {

    int kor = 0, eng = 0, math = 0;

    fputs("성적 입력: ", stdout);
    scanf("%d %d %d", &kor, &eng, &math);

    printf("%d, %d, %d\n", kor, eng, math);

    return 0;
}