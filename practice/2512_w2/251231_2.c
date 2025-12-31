#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 표준 정규 분포(평균 0, 표준편차 1) 난수 생성 함수
double generateGaussian() {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    
    // 박스-뮬러 변환 공식
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

int rand100() { //-50~50의 값을 생성하는 함수
    int n= rand()%41-20;
    return n;
}

int main() {
    srand(time(NULL));

    int inputspeed[10];
    int randomspeed[100];
    // printf("속도를 입력하세요:");
    // for (int i = 0; i < 10; i++)
    // {
    //     printf(" %d ",i);
    //     scanf("%d",&inputspeed[i]);
    // }
    for (int i = 0; i < 100; i++)
    {
        randomspeed[i]=generateGaussian()*20+20;
    }
    
    int vd;
    int pacc=0,nacc=0;
    // for (int i = 0; i < 9; i++)
    // {
    //     if (i==0) vd=inputspeed[i];
    //     else vd=inputspeed[i]-inputspeed[i-1];
    //     if (vd>=10) pacc++;
    //     if (vd<=-10) nacc++;
    // }
    // printf("직접 입력-급가속: %d회 급감속: %d회\n",pacc,nacc);
    // pacc=0,nacc=0;
    for (int i = 0; i < 99; i++)
    {
        if (i==0) vd=inputspeed[i];
        else vd=inputspeed[i]-inputspeed[i-1];
        if (vd>=10) pacc++;
        if (vd<=-10) nacc++;
    }
    printf("랜덤 입력-급가속: %d회 급감속: %d회\n",pacc,nacc);

    //

    int anthorrandomspeed[1000000];
    int pcnt=0,ncnt=0;
    pacc=0,nacc=0;
    anthorrandomspeed[0]=fabs(rand100());
    int dv2=anthorrandomspeed[0];
    printf("%d: %d\n",0,anthorrandomspeed[0]);
    for (int i = 1; i < 1000000; i++){
        if (dv2>0) {
            pcnt++;
            ncnt=0;
        }
        else if (dv2<0) {
            ncnt++;
            pcnt=0;
        }
        else if (ncnt>0) {
            ncnt++;
            pcnt=0;
        }
        else {
            pcnt++;
            ncnt=0;
        }
        int temp=0;
        if (pcnt>10||ncnt>10) {
            dv2=rand100();
            temp=1;
        }
        else if (pcnt>0) {
            dv2=fabs(rand100());
        }
        else if (ncnt>0) {
            dv2=-fabs(rand100());
        }
        
        anthorrandomspeed[i]=anthorrandomspeed[i-1]+dv2;
        if (anthorrandomspeed[i]<=0) {//속도가 음수가 나오지 않게 하는 코드
            dv2=0-anthorrandomspeed[i-1];
            anthorrandomspeed[i]=0;
            if (anthorrandomspeed[i-1]==0) {
                printf("속도가 0이 되었습니다. 운행을 정지합니다.\n");
                break;
            }
            
        }
        if (dv2>=15) pacc++;
        if (dv2<=-15) nacc++;

        if (ncnt==1) printf("방향 변경(-)\n");
        else if (pcnt==1) printf("방향 변경(+)\n");

        printf("%d: %d\n",i,anthorrandomspeed[i]);
    }
    printf("보정 속도-급가속: %d회 급감속: %d회\n",pacc,nacc);
}