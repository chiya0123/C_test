#include <stdio.h>

typedef struct num2 {
    int x;
    int y;
}Num2;

Num2 swap(int x, int y) {
    Num2 root;
    root.x=y;
    root.y=x;

    return root;
}


int main() {
    int a,b,sum;
    double avg;
    a=12;
    int *aadrs;
    const int *badrs=&b;
    // *badrs=17; //에러발생, badrs는 읽기 전용 (const int *)
    b=16; //이건 문제 없다.
    int *sadrs=&sum;
    double *avadrs=&avg;
    aadrs=&a;
    char ch;
    char *chadrs=&ch;
    

    printf("%u, %u\n",&a,badrs);
    printf("%d %d\n",a,*badrs);
    printf("%ld %ld\n",sizeof(chadrs),sizeof(&a));

    int c=25;
    int *const cadrs=&c;
    badrs=&c; //이건 가능
    // cadrs=&b; //불가능, cadrs의 값 변경 불가 (int *const)
    *cadrs=19; //문제 없다.


    *sadrs=*aadrs+*badrs;
    *avadrs=*sadrs/2.0;

    printf("두 정수의 값 : %d, %d\n",a,*badrs);
    printf("두 정수의 합 : %d\n",*sadrs);
    printf("두 정수의 평균 : %.2lf\n", *avadrs);

    int n=10;
    int *p1=&n;
    double dbn;
    double *p2=&dbn;

    // p2=p1; //이러한 변환은 권장되지 않음(정상 작동x)
    *p2=(double)*p1;
    printf("%lf\n",*p2);

    int x,y;
    x=10, y=20;
    printf("%d %d\n", x,y);

    Num2 swxy=swap(x,y); //이건 안 배웠는데 그냥 해본거
    
    x=swxy.x;
    y=swxy.y;
    printf("%d %d\n\n", x,y);

    int arr[5];
    int *aradrs;
    aradrs=arr;
    *(aradrs)=20;
    for (int i = 1; i < 5; i++)
    {
        *(aradrs+i)=*(aradrs)*i;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",aradrs[i]);
    }
    printf("%ld, %ld\n",aradrs++,aradrs);
    printf("%ld\n",aradrs-arr);
}


