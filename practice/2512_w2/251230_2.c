#include <stdio.h>

int main() {
    
    for (int i = 2; i < 10; i+=4)
    {
        for (int j = 1; j < 10; j++)
        {
            printf("%d * %d = %2d\t",i,j,i*j);
            printf("%d * %d = %2d\t",i+1,j,(i+1)*j);
            printf("%d * %d = %2d\t",i+2,j,(i+2)*j);
            printf("%d * %d = %2d\n",i+3,j,(i+3)*j);
        }
        printf("\n");
    }

    int sum=0;
    for (int i = 0; i < 10; i++)
    {
        sum+=i;
        if (sum%2==1)
        {
            
            continue;
        }
        sum/=2;
    }
    printf("%d\n",sum);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0;  j < 5;  j++)
        {
            if (i+j==4) printf("*");
            else if (i==j) printf("*");
            else printf(" ");            
        }
        printf("\n");
        
    }

    
}