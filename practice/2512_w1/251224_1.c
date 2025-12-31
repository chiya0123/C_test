#include <stdio.h>



int main() {
    
    printf("0000개 있습니다.\r%4d\n",0x110);
    printf("0000개 있습니다.\r%4d\n",0110);

    printf("   *****\n");
    printf(" ****\t\b\b****\n");
    printf("***\t\b\b\b*\t***\n");
    printf(" ****\t\b\b****\n");
    printf("   *****\n");

    printf("%.5lf\n",2.41e-3);
    printf("%.3le\n",0.0001567);

    printf("%c는 문자, %s는 문자열\n",'A',"Alpha");
}