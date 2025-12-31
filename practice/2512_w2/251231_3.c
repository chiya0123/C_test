#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int rand1() { //0~1의 값을 생성하는 함수
    double n= (rand()%20)/10.0;
    return (int)n;
}

int main() {
    srand(time(NULL));

    int battery=40;
    int warn=0;
    int charge=0;
    for (int i = 0; i < 500; i++){
        battery=battery-(1-2*charge)*rand1();
        if (battery>=35) {
            warn=0;
            if (rand1()) charge=0;
        }
        if (battery<=30){
            warn=1;
            if (rand1()+rand1()+rand1()>=battery/3) charge=1;
        }
        if (battery>100) battery=100;
        if (battery<0) battery=0;        
        
        printf("%3d",battery);
        (warn)?(printf(" 경고\n")):(printf("\n"));
        
    }
    
}