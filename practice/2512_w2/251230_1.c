// 두 개의 바퀴를 가진 로봇이 직선주행할 때 생기는 좌우 오차
// N 바퀴를 돌면 바퀴가 돈 거리는 2ㅠRN


#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

int main() {
    double r, W, e_L, e_R, L;

    printf("바퀴 반지름(m): ");
    scanf("%lf", &r);
    printf("트랙 폭(m): ");
    scanf("%lf", &W);
    printf("좌측 바퀴 변형률(%%): ");
    scanf("%lf", &e_L);
    printf("우측 바퀴 변형률(%%): ");
    scanf("%lf", &e_R);
    printf("목표 거리(m): ");
    scanf("%lf", &L);
    
    double r_L, r_R, R_c, angle, drift;

    r_L=r*(1+e_L/100);
    r_R=r*(1+e_R/100);

    if (fabs(r_L-r_R)<1e-9) {
        printf("바퀴의 크기가 같습니다.");
        return 0;
    }
    

    double N=L/(2*M_PI*r);
    double D_L=2*M_PI*r_L*N;
    double D_R=2*M_PI*r_R*N;

    R_c=W*(D_R+D_L)/(2*fabs(D_R-D_L));
    angle=L/R_c;

    drift=R_c*(1-cos(angle));

    printf("좌우 바퀴 반경: %.5lfm/ %lfm\n",r_L,r_R);
    printf("곡률 반경 :%.3lf\n",R_c);
    printf("편류각: %.3lf\n",angle*180/M_PI);
    printf("편류거리: %.5lf\n",drift);
    
}