#include <stdio.h>

int main() {
    FILE *fp1,*fp2;
    int ch;

    fp1=fopen("a.txt","r");
    if (fp1==NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }
    printf("파일이 열렸습니다.\n");
    while (1)
    {
        ch=fgetc(fp1);
        if (ch==EOF)
        {
            break;
        }
        putchar(ch);
        
    }
    fp2=fopen("b.txt","a");
    if (fp2==NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }
    fprintf(fp2,"griffe\n");
    fclose(fp1);
    fclose(fp2);

}
