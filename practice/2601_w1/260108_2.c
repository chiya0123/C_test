#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int limval(int,int,int);
double needpi(double, double);

/*
    가장 가까운 장애물의 각도와 거리를 출력하는 프로그램;
*/

int main() {
    int Lidata[360];
    int *pbl;
    int modata=720;
    pbl=(int *)malloc(modata*sizeof(int));
    if (pbl==NULL) {
        printf("error!");
        return 1;
    }
    
    int nearangle=0;
    srand(time(NULL));
    //그림 시작
    FILE *gp = popen("gnuplot -persistent", "w");
    if (gp == NULL) {
        printf("Gnuplot을 찾을 수 없습니다.\n");
        return 1;
    }
    fprintf(gp, "set multiplot layout 1, 2\n");
    fprintf(gp, "set polar\n");             // 극좌표 모드 활성화
    // fprintf(gp, "set grid polar\n");        // 극좌표 그리드 표시
    fprintf(gp, "set size square\n"); // 각 플롯을 정사각형 비율로 고정
    //

    Lidata[0]=rand()%500;
    pbl[0]=rand()%500;
    fprintf(gp, "plot '-' with lines lc rgb 'blue'\n");
    for (int i = 1; i < modata; i++)
    {
        pbl[i]=limval(0,pbl[i-1]+rand()%21-10,500);
        if (pbl[nearangle]>pbl[i]) nearangle=i;

        fprintf(gp, "%lf %d\n", i*M_PI*2/(double)modata, pbl[i]);
        // fprintf(gp, "%d %d\n", i, 0);
        
    }
    fprintf(gp, "%d %d\n", 0, pbl[0]);
    fprintf(gp, "e\n");
    printf("가장 가까운 장애물은 %d도에 위치해 있으며 거리는 %dcm입니다.\n",nearangle*360/modata,pbl[nearangle]);
    free(pbl);

    int box_sz_wi=rand()%500;
    int box_sz_le=box_sz_wi+rand()%500;
    double box_angle=rand()%180*M_PI/180-90;
    int box_cen_x=rand()%1000-500;
    int box_cen_y=rand()%1000-500;
    nearangle=0;
    // fprintf(gp, "plot '-' with lines lc rgb 'red'\n");
    fprintf(gp, "plot '-' with lines lc rgb 'red', '-' with lines lc rgb 'green'\n");
    for (int i = 1; i < 360; i++)
    {
        Lidata[i]=rand()%500;

        if (Lidata[nearangle]>Lidata[i]) nearangle=i;
        fprintf(gp, "%lf %d\n", i*M_PI*2/360, Lidata[i]);
    }
    // printf("가장 가까운 장애물은 %d도에 위치해 있으며 거리는 %dcm입니다.\n",nearangle,Lidata[nearangle]);
    fprintf(gp, "e\n"); 
    fprintf(gp, "\n");
    fprintf(gp, "%lf %f\n",atan2(box_cen_y,box_cen_x)+needpi(box_cen_x,box_cen_y),
            sqrt(box_cen_x*box_cen_x+box_cen_y*box_cen_y));
    double t_x=box_cen_x-box_sz_wi/2*cos(box_angle)-box_sz_le/2*sin(box_angle);
    double t_y=box_cen_y-box_sz_wi/2*sin(box_angle)+box_sz_le/2*cos(box_angle);
    fprintf(gp, "%lf %f\n",atan2(t_y,t_x)+needpi(t_x,t_y),
            sqrt(t_x*t_x+t_y*t_y));
    t_x=box_cen_x+box_sz_wi/2*cos(box_angle)-box_sz_le/2*sin(box_angle);
    t_y=box_cen_y+box_sz_wi/2*sin(box_angle)+box_sz_le/2*cos(box_angle);
    fprintf(gp, "%lf %f\n",atan2(t_y,t_x)+needpi(t_x,t_y),
            sqrt(t_x*t_x+t_y*t_y));
    t_x=box_cen_x+box_sz_wi/2*cos(box_angle)+box_sz_le/2*sin(box_angle);
    t_y=box_cen_y+box_sz_wi/2*sin(box_angle)-box_sz_le/2*cos(box_angle);
    fprintf(gp, "%lf %f\n",atan2(t_y,t_x)+needpi(t_x,t_y),
            sqrt(t_x*t_x+t_y*t_y));
    t_x=box_cen_x-box_sz_wi/2*cos(box_angle)+box_sz_le/2*sin(box_angle);
    t_y=box_cen_y-box_sz_wi/2*sin(box_angle)-box_sz_le/2*cos(box_angle);
    fprintf(gp, "%lf %f\n",atan2(t_y,t_x)+needpi(t_x,t_y),
            sqrt(t_x*t_x+t_y*t_y));
    t_x=box_cen_x-box_sz_wi/2*cos(box_angle)-box_sz_le/2*sin(box_angle);
    t_y=box_cen_y-box_sz_wi/2*sin(box_angle)+box_sz_le/2*cos(box_angle);
    fprintf(gp, "%lf %f\n",atan2(t_y,t_x)+needpi(t_x,t_y),
            sqrt(t_x*t_x+t_y*t_y));
    fprintf(gp, "e\n"); 
    fprintf(gp, "unset multiplot\n");
    // fflush(gp);
    pclose(gp);
}

int limval(int min, int val, int max) {
    if (min>val) return min;
    else if (max<val) return max;
    else return val;
}
double needpi(double x, double y) {
    if (x) return 0.0;
    else return M_PI;
}