#include <stdio.h>
#include <string.h>

int main() {

    char ch1=100;

    char fruit0[20];
    char fruit1[20];
    char fruit2[30]="good ";

    int lint=-123126;
    unsigned long unlong=-1;
    long long llint=9223372036854775807; //long 과 long long 크기가 같다

    const double X=-1.0;
    // X=1.3; X는 읽기 전용으로 에러 발생
    printf("X는 변경 불가능한 %.2lf이다.\n",X);

    printf("문자 %c의 아스키 코드 : %d\n",ch1, ch1);

    printf("양수와 과일을 입력하세요 :");
    scanf("%d %s", &lint, fruit1);
    lint*=X;
    printf("긴 정수 출력 \nllong:%lld 최댓값 %lu\n", llint, unlong/2);
    printf("정수 출력 예시\n음수 : %d , unsigned : %u \n",lint, lint);

    strcpy(fruit0,"strawberry");
    printf("과일을 입력하세요 : ");
    scanf("%s", &fruit2[5]);
    printf("과일 : %s, %s, %s\n", fruit0, fruit1, fruit2);


}
