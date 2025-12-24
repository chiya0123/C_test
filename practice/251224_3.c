#include <stdio.h>

int main() {
    int a=5, b=5;
    int pre, post, res;
    pre=++a/2;
    post=b++%2;
    res=(a++==++b);
    printf("전위 연산 결과(몫) :%d\t후위 연산 결과(나머지) :%d\n전위 연산과 후위 연산의 순서는 %d(0:다르다, 1:같다)\n",pre, post, res);

    res=((double)a==7.0&&a==(int)7.0);
    printf("정수와 실수는 %d\n",res);

    long long dlong=1;
    long slong=1;

    (sizeof(dlong)>sizeof(slong))?printf("long long\n"):printf("long\n");

}