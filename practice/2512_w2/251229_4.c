
// math.h를 사용하는 예제

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>


int main() {
    const double radtodeg=M_PI/180;
    const double g = 9.806;

    double m,Tq_m,G,r,c;
    int N;
    int SF=0;

    double Tq_t, sinval, F_cal, F_req, theta, grade, theta_max;

    printf("전체 질량(kg): ");
    scanf("%lf",&m);
    printf("바퀴 갯수(개): ");
    scanf("%d",&N);
    printf("모터 토크(N*m): ");
    scanf("%lf",&Tq_m);
    printf("감속비: ");
    scanf("%lf",&G);
    printf("바퀴 반지름(m): ");
    scanf("%lf",&r);
    printf("구름계수: ");
    scanf("%lf",&c);
    printf("경사의 각도(도): ");
    scanf("%lf",&theta);

    while (!SF)
    {
        printf("안전계수: ");
        scanf("%d",&SF);
        if (SF<2) {
            printf("안전계수는 2 이상이여야 합니다.\n");
            SF=0;
        }
    }

    if (m*N*Tq_m*r<=0) {
        printf("입력한 값을 확인해주세요");
        return 0;
    }
    

    Tq_t=N*Tq_m*G;
    F_cal=Tq_t/r;
    sinval=(F_cal/SF-c*m*g)/(m*g);
    (sinval>1)?(sinval=1):((sinval<0)?(sinval=0):(0));
    theta_max=asin(sinval)*radtodeg;
    grade=tan(theta/radtodeg)*100;
    F_req=m*g*(c+sin(theta*radtodeg));

    printf("최대 견인력: %.3lf\n",F_cal);
    printf("필요 견인력: %.3lf\n",F_req);
    printf("등판 가능 최대 경사 : %.3lf\n",theta_max);
    printf("등판율: %.3lf\n",grade);


}