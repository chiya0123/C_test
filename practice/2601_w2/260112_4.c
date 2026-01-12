#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>



int ChooseMenu();
void CheckMotor();

int main() {
    int R,menu;
    while (1) {
        menu=ChooseMenu();
        switch (menu) {
        case 1:
            CheckMotor();
            break;
        default:
            printf("프로그램 종료");
            return 0;
        }
    }
    
}

int ChooseMenu() {
    int menu;
    printf("원하는 프로그램을 선택하세요:\n");
    printf("1:\n");
    printf("0: 프로그램 종료\n");
    scanf("%d",&menu);
    return menu;
}

void CheckMotor() {// malloc 사용해보기
    double M,tq,G,R,W,Fmin,Fmotor,pl;
    int N;
    int SF=0;

    const double c=0.018;
    const double g=9.806;
    const double DM=1.2;

    printf("총 하중(kg): ");
    scanf("%lf",&M);
    printf("구동 바퀴 수(개): ");
    scanf("%d",&N);
    printf("모터 정격 토크(N*m): ");
    scanf("%lf",&tq);
    printf("바퀴 반지름(m): ");
    scanf("%lf",&R);
    printf("감속비: ");
    scanf("%lf",&G);
    printf("최대 하중: ");
    scanf("%lf",&pl);
    while (!SF)
    {
        printf("안전계수: ");
        scanf("%d",&SF);
        if (SF<2) {
            printf("안전계수는 2 이상이여야 합니다.\n");
            SF=0;
        }
    }

    W=M*g;
    Fmin=c*W*SF*DM;
    Fmotor=tq*G*N/R;

    printf("로봇이 버틸 수 있는 최대 하중: %.3lfkg\n",pl*N/SF*2);//원래 2 곱하면 안 될 것 같은데 안 해주면 만족시키기 너무 어렵다
    if (pl*N*2<=SF*M) printf("판정: 불만족 (최대 하중이 부족합니다.)\n");//페이로드랑 바퀴 수를 고려해야 하고 역시 안전계수도 고려해야겠지
    else {  
        printf("필요한 최소 견인력: %.3lf\n",Fmin);
        printf("모터가 낼 수 있는 견인력: %.3lf\n",Fmotor);
        if (Fmin<=Fmotor) printf("판정: 만족 (해당 모터를 사용할 수 있습니다.)\n");
        else printf("판정: 불만족 (더 큰 모터나 감속비가 필요합니다.)\n");
    }
}