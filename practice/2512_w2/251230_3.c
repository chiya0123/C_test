#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double avg(int,int);
double DegtoRad(double);
double RadtoDeg(double);
double changeangleunit(double, char);

int getnum(void) {
    int n;
    printf("정수 입력: ");
    scanf("%d",&n);
    return n;
}

void printchar(char C, int N) {
    for (int i = 0; i < N; i++)
    {
        printf("%c",C);
    }
    printf("\n");   
}

int main() {
    int a, b;
    int ary[5];

    ary[1]=12;


    a=getnum();
    b=getnum();
    printf("평균: %lf\n",avg(a,b));
    printf("%lf\n",changeangleunit(M_PI_4, 'd'));
    
}

double avg(int x,int y) {
    int hap=x+y;
    double mean=hap/2.0;
    return mean;
}

double DegtoRad(double degree) {
    double radian;
    radian=degree*M_PI/180;
    return radian;
}


double RadtoDeg(double radian) {
    double degree;
    degree=radian*180/M_PI;
    return degree;
}

double changeangleunit(double theta, char C) {
    double angle;
    if (C=='d'||C=='D'||C=='1') angle=theta*180/M_PI;//라디안을 디그리로
    else angle=theta*M_PI/180;    
    return angle;
}