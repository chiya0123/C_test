#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp, *fp11;
    int tec=0,senerr=0,molerr=0;
    char line[100];
    char errlin[5][100];
    int erco[5]={0};
    int ch;
    int flag=0;

    fp=fopen("log.txt","r");
    fp11=fopen("log.txt","r");

    if (fp==NULL) return 1;
    if (fp11==NULL) return 1;

    while (1) {
        ch=fgetc(fp);
        if (ch==EOF) {
            break;
        }
        if (ch=='E') {
            tec++;
            flag=8;
        }
        if (flag==1)
        {
            if (ch=='S') {
                senerr++;
            }
            else if (ch=='M') {
                molerr++;
            }
        }
        if (flag) {
            flag--;
        }
    }

    int erstco=0;
    while (fgets(line,sizeof(line),fp11)) {
        if (strstr(line,"[ERROR]")) {
            int isnew=0;
            for (int i = 0; i < erstco+1; i++) {
                if (strcmp(errlin[i],line)==0) {
                    erco[i]++;
                    isnew=0;
                    break;
                }
                isnew=i+1;
            }
            if (isnew) {
                strcmp(errlin[isnew-1],line);
                erstco++;
                erco[isnew-1]++;
            }
        }
    }

    int sum=0;
    for (int i = 0; i < erstco; i++)
    {   
        char *po=strstr(errlin[i],"ERROR")+7;        
        printf("%s",po);//po == &errlin[i][8]
        printf(" X %d 회\n",erco[i]);
        sum+=erco[i];
    }
    printf("전체 에러 수: %d\n\n\n",sum);
    
    


    printf("전체 에러 수: %d\n",tec);
    printf("모터 과부하 수: %d\n",molerr);
    printf("센서 문제 수: %d\n",senerr);

    fclose(fp);
    fclose(fp11);

}