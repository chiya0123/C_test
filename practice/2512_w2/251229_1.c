#include <stdio.h>

int main() {

    int a=0, b=0;

    printf("두 정수 입력");
    scanf("%d %d", &a, &b);

    if (a>10) {
        if (b==40) {
            a-=30;
            b=10;
        }
        else b=40;        
    }
    else if (a>0) {
        b=b+5;
        a*=3;
    }
    else b=b*3-5;
    
    switch (b) {
    case 40 :
        printf("A:%d\n",a);
        break;
    case 10 :
        printf("뭐가 좋을까\n");
        break;
    default:
        printf("B:%d\n",b);
        break;
    }
    
}