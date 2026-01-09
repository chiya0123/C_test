#include <stdio.h>
#include <math.h>

typedef struct position{
    int x;
    int y;
}position;

typedef struct polar{
    double r;
    double theta;
}polar;


void move(position *p, int dx, int dy);

int main() {
    position robot={0,0};
    position *probo=&robot;

    move(probo,5,3);
    move(probo,-2,+4);
    printf("로봇의 최종 위치:(%d, %d)\n",probo->x,probo->y);

    //확장 과제: 이동한 거리를 각도와 거리로 나타내기
}

void move(position *p, int dx, int dy) {
    p->x+=dx;
    p->y+=dy;
}