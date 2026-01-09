#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int,int);

int main() {
    int a,b;
    int (*fp)(int, int);

    a=10;
    b=20;
    fp=sum;
    int res=fp(a,b);
    printf("%d\n",res);

    void *vp;
    double d=3.6;

    vp=&d;
    printf("%.2lf\n",*(double *)vp);
    vp=&a;
    printf("%d\n",*(int *)vp);

    int *pi;
    pi= (int *)malloc(sizeof(int));

    if (pi==NULL)
    {
        printf("메모리 할당 실패");
        return 1;
    }
    

    *pi=10;
    printf("malloc 사용해보기 : %d\n",*pi);

    free(pi);
    int size=5;
    int n;
    int count=0;

    // int *pi;
    pi=(int *)calloc(size,sizeof(int));

    while (1)
    {
        printf("양수 입력 : \n");
        scanf("%d",&n);
        if (n<=0) break;
        if (count==size)
        {
            size+=5;
            pi=(int *)realloc(pi,size*sizeof(int));
        }
        pi[count++]=n;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%5d",pi[i]);
    }
    free(pi);

    char tmp[80];
    char *str[3];
    for (int i = 0; i < 3; i++)
    {
        printf("문자열 입력: ");
        fgets(tmp,80,stdin);
        tmp[strlen(tmp)-1]='\0';
        str[i]= (char *)malloc(strlen(tmp)+1);
        strcpy(str,tmp);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n",str[i]);
        free(str[i]);
    }
    

    
    

}

int sum(int a, int b) {
    return a+b;
}