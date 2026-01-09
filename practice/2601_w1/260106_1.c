#include <stdio.h>
#include <string.h>

void printarray(int *,int);

void scanarray(int *,int);

int getmax(int *,int);

void print_month(int *mp) {
    for (int i = 0; i < 12; i++)
    {
        printf("%5d",*(mp+i));
        if ((i+1)%5==0)
        {
            printf("\n");
        }
        
    }
    printf("\n");
}

void my_gets(char *str,int size) {
    int ch;
    int i=0;
    ch=getchar();
    while ((ch!='\n')&&(i<size-1))
    {
        str[i]=ch;
        i++;
        ch=getchar();
    }
    str[i]='\0';    
    
}

int main() {
    int arr1[5],arr2[7];
    int max1,max2;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    // scanarray(arr1,5);
    // scanarray(arr2,7);
    // printarray(arr1,5);
    // printarray(arr2,7);
    // max1=getmax(arr1,5);
    // max2=getmax(arr2,7);
    // printf("%d ",max1);
    // printf("%d\n",max2);
    print_month(month);

    char small,cap = 'I';

    if (cap>='A'&&cap<='Z')
    {
        small=cap+'a'-'A';
    }
    printf("%c\n",small);

    // char ch1,ch2;
    // scanf(" %c%c",&ch1,&ch2);
    // printf("[%c%c]\n",ch1,ch2);
    // ch1=getchar();
    // putchar(ch1);

    char str[9];
    // my_gets(str,9);
    // printf("%s",str);
    // getchar();
    // scanf("%s",str);
    // printf("[%s]\n",str);
    // fgets(str,sizeof(str),stdin);
    // printf("[%s]\n",str);

    // fputs("hello ",stdout);
    // puts(str);


    printf("%p\n","Hey");
    printf("%c\n",*("Hey"+1));

    char *good="apple";
    printf("%s\n",good);
    good="candy";
    // *(good+2)='c'; //Segmentation fault (core dumped) 에러 발생
    printf("%s\n",good);

    char ani[20];
    char why[80];
    printf("좋아하는 동물 : ");
    scanf("%s",ani);
    getchar();
    printf("좋아하는 이유 : ");
    fgets(why,sizeof(why),stdin);
    why[strlen(why)-1]='\0';
    printf("%s is %s\n",ani,why);
}

void scanarray(int *pa, int size) {
    printf("%d 개의 정수 입력: ",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",pa+i);
    }
}

void printarray(int *pa, int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ",*(pa+i));
    }
    printf("\n");
}

int getmax(int *pa, int size) {
    int max=*pa;
    for (int i = 0; i < size; i++)
    {
        if (max<*(pa+i))
        {
            max=*(pa+i);
        }
        
    }
    return max;    
}