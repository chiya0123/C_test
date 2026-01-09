#include <stdio.h>
#define _println printf("\n");

void ass10();
void ass20();
int *sum(int,int);
void println(char *str) {
    printf("%s\n",str);
}

void swap_ptr(char **pa,char **pb) {
    char *pt;
    pt=*pa;
    *pa=*pb;
    *pb=pt;
}

int main() {
    int arr3d[2][3][4]={1,2,3,4,5,6,7,8,9,0,11,12,13,19,18,17,16,15,14,1,2,3,4};

    
    for (int i = 0; i < 3; i++)
    {
        ass10();
    }
    for (int i = 0; i < 3; i++)
    {
        ass20();
    }

    printf("%d\n",*sum(40,20));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                printf("%2d ",arr3d[i][j][k]);
            }
            _println
        }
        _println
    }

    // int arr[5][6] = {
    //     {1,2,3,4,5},
    //     {6,7,8,9,10},
    //     {11,12,13,14,15},
    //     {16,17,18,19,20}
    // };
    int arr[100][100] = {0};

    int co,ro;
    printf("입력할 행과 열의 수를 입력하세요(최대 100): ");
    scanf("%d %d", &co, &ro);
    for (int i = 0; i < co; i++)
    {
        for (int j = 0; j < ro; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    

    // for (int j = 0; j < 5; j++) {
    //     int sum=0;
    //     for (int i = 0; i < 4; i++) {
    //         sum+=arr[i][j];
    //     }
    //     arr[4][j]=sum; 
    // }
    // for (int i = 0; i < 5; i++) {
    //     int sum=0;
    //     for (int j = 0; j < 5; j++) {
    //         sum+=arr[i][j];
    //         printf("%3d ",arr[i][j]);
    //     }
    //     arr[i][5]=sum;
    //     printf("%3d \n",arr[i][5]);   
    // }
    // println("\n\n");


    // int SUMr[6]={0};
    for (int i = 0; i < co+1; i++) {
        for (int j = 0; j < ro; j++) {
            arr[i][ro]+=arr[i][j];
            // SUMr[j]+=arr[i][j];
            printf("%3d ",arr[i][j]);
            arr[co][j]+=arr[i][j];
            // arr[4][j]=SUMr[j];
        }
        printf("%3d \n",arr[i][ro]);   
    }
    _println _println 

    char *pa = "AAA";
    char *pb = "BBB";

    printf("pa: %s, pb: %s\n",pa,pb);
    swap_ptr(&pa,&pb);
    printf("pa: %s, pb: %s\n",pa,pb);
    
    
    
    
}

void ass10() {
    auto int a=0;

    a++;
    printf("%d\n",a);
}

void ass20() {
    static int a;
    a++;
    printf("%d\n",a);
}

int *sum(int a,int b) {
    static int s;
    s=a+b;
    return &s;
}