/*
    이동로봇의 배터리 선정
    E=V*C*eta*(1-R)
    P=V*I/eta
    t=E/P
    d=v*t
*/

#include <stdio.h>

int main() {

    double I,vel,R,V,C,eta;
    double E,P,t,d;

    printf("평균전류(A): ");
    scanf("%lf",&I);
    printf("평균속도(km/h): ");
    scanf("%lf",&vel);
    printf("예비율: ");
    scanf("%lf",&R);
    printf("공칭전압(V): ");
    scanf("%lf",&V);
    printf("용량(Ah): ");
    scanf("%lf",&C);
    printf("시스템 효율: ");
    scanf("%lf",&eta);

    E=V*C*eta*(1-R);
    P=V*I/eta;
    t=E/P;
    d=vel*t;

    printf("사용가능 에너지: %.3lfWh\n",E);
    printf("소비 전력: %.3lfW\n",P);
    printf("주행 시간: %.3lf시간\n",t);
    printf("주행 거리: %.3lfkm\n",d);

    double C_goal=P*3/(V*eta*(1-R));
    printf("3시간 이상 주행하기 위해선 %.3lfAh이상의 용량을 가진 배터리를 사용해야 합니다.\n",C_goal);
}