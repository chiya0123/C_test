#include <stdio.h>

int main() {
    int a=5, b=5;
    int pre, post, res;
    pre=++a/2;
    post=b++%2;
    res=(a++==++b);
    printf("전위 연산 결과(몫) :%d\t후위 연산 결과(나머지) :%d\n전위 연산과 후위 연산의 순서는 %d(0:다르다, 1:같다)\n",pre, post, res);

    res=(a==(double)7.0&&a==(int)7.9);
    printf("정수와 실수는 %d\n",res);

    res=(a++,--b);//콤마는 뒤의 것을 저장
    printf("%d\n",res);

    long long dlong=1;
    long slong=1;

    printf("큰 정수를 이용할 때는 ");
    (sizeof(dlong)>sizeof(slong))?printf("long long\n"):printf("long\n");

    int abt=6;//0000 0110
    int bbt=10;//0000 1010

    printf("AND: %d XOR: %d OR: %d NOT: %d\n",abt&bbt, abt^bbt, abt|bbt, ~abt);
    printf("좌로 밀고(%d) 우로 밀고(%d)\n",abt<<2, bbt>>1);//0001 1000=24, 0101=6

}