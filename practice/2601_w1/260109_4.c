#include <stdio.h>

typedef struct {
    double left;
    double right;
}Wheelspd;

typedef struct {
    double lin;
    double ang;
}Robotspd;

Robotspd computespeed(Wheelspd w, double wr, double wd);

int main() {
    double R,L;
    Wheelspd Wsp;
    Robotspd Rsp;
    printf("왼쪽 바퀴 속도(rad/s): "); //입력받는 값이 선속도인 코드 시도해보기
    scanf("%lf",&Wsp.left);
    printf("오른쪽 바퀴 속도(rad/s): ");
    scanf("%lf",&Wsp.right);
    printf("바퀴 반지름(m): ");
    scanf("%lf",&R);
    printf("바퀴 간 거리(m): ");
    scanf("%lf",&L);
    Rsp=computespeed(Wsp,R,L);
    printf("선속도: %.2lf m/s\n", Rsp.lin);
    printf("각속도: %.2lf rad/s\n", Rsp.ang);

}

Robotspd computespeed(Wheelspd w, double wr, double wd) {
    Robotspd speed;
    speed.lin=wr*(w.left+w.right)/2;
    speed.ang=wr*(w.right-w.left)/wd;
    return speed;
}
