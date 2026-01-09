/*
    IR 센서를 이용한 라인트레이서 경로 추정 프로그램 예시 
    가정: 센서는 1개일 때 90도, 2개일 때 0/180도, 3개 이상(n)일 때 180*k/(n-1) 도에 위치
*/

#include <stdio.h>
#include <math.h>

void getint(int NUM[],int n) {
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&NUM[i]);
    }    
}

void IRssdgt(int ss[],int digit[],int n,int thh) {
    for (int i = 0; i < n; i++)
    {
        (ss[i]>thh)?(digit[i]=0):(digit[i]=1);//검은색을 1로
    }
    
}

int aoverb(int a,int b) { //b의 n제곱 계산
    int n=1;
    for (int i = 0; i < a; i++)
    {
        n*=b;
    }
    return n;
}

double findway(int digit[],int n) {
    double unit=180/(n-1);
    int sum=0;
    int num=0;
    for (int i = 0; i < n; i++)
    {
        if (digit[i]==1) {
            sum+=i*unit;
            num++;
        }
    }
    if (num==0) return -1;
    double angle;
    angle=sum/(double)num;
    return angle;
}

int main() {
    int N,threshold;
    int sensor[20],ss_digit[20];
    printf("센서 수: ");
    scanf("%d",&N);
    printf("각 센서 값(왼쪽 부터): ");
    getint(sensor,N);
    printf("임계값: ");
    scanf("%d",&threshold);

    IRssdgt(sensor,ss_digit,N,threshold);
    printf("추정 각도 : %.2lf\n",findway(ss_digit,N));



}