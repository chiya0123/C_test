
#include <stdio.h>

int main() {

    int score[3];
    int sum=0;
    double avg;
    int count=sizeof(score)/sizeof(score[0]);

    for (int i = 0; i < count; i++)
    {
        printf("점수를 입력하세요.");
        scanf("%d",&score[i]);
        sum+=score[i];
    }

    avg=sum/(double)count;
    printf("평균%lf\n",avg);
    
    char str[60]="fruitbasket";

    printf("초기 문자열: %s\n",str);
    printf("문자열 입력: ");
    scanf("%s",str);
    printf("입력 후 문자열 : %s\n",str);
    printf("문자열 입력: ");
    fgets(str,60,stdin);
    puts("입력 된 문자열 : ");
    puts(str);
    for (int i = 0; i < 12; i++) printf("%d ",str[i]);
    printf("\n");

}