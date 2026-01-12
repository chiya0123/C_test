#include <stdio.h>
#include <string.h>

typedef struct ipadcnt{
    char adr[50];
    int cnt;
    int time[24];
}ipadcnt;//44 개

int main() {
    int pingcnt=0;
    FILE *fp;
    char line[220];
    char *sttip,*tipp;
    ipadcnt iplist[50]={0};
    char tmpip[50];
    char *timeptr;


    fp=fopen("fast.log","r");
    if (fp==NULL) return 1;

    int ipmoco=0;//ip 갯수

    while (fgets(line,sizeof(line),fp)) {
        if (sttip=strstr(line,"Ping!")) {
            pingcnt++;
            timeptr=strstr(line,"2025-")+5;
            int inttime=(*timeptr++-'0')*10+(*timeptr-'0');
            sttip+=68;
            int isnew=0;
            if (strstr(sttip,"IPv6")) {
                sttip+=13;
                strncpy(tmpip,sttip,45);
                tipp=strstr(tmpip," ");
                tipp-=4;
                *tipp='\0';
            }
            else {
                sttip+=8;
                strncpy(tmpip,sttip,18);
                tipp=strstr(tmpip," ");
                tipp-=2;
                *tipp='\0';
            }
            // printf("%s\n",tmpip);

            
            for (int i = 0; i < ipmoco+1; i++) {
                if (strcmp(iplist[i].adr,tmpip)==0) {
                    iplist[i].cnt++;
                    isnew=0;
                    iplist[i].time[inttime]++;
                    break;
                }
                isnew=i+1;
            }
            if (isnew) {
                strcpy(iplist[isnew-1].adr,tmpip);
                ipmoco++;
                iplist[isnew-1].cnt++;
                iplist[isnew-1].time[inttime]++;
            }
        }
    }


    int timexi[24]={0};
    printf("전체 핑 갯수: %d\n",pingcnt);
    for (int i = 0; i < ipmoco; i++) {           
        printf("%s",iplist[i].adr);
        printf(" X %d 회\n",iplist[i].cnt);
        for (int j = 0; j < 24; j++){
            timexi[j]+=iplist[i].time[j];
        }
        
    }

    printf("\n시간대 별 핑 종류\n");
    for (int j = 0; j < 24; j++) {
        if (timexi[j]) {
            int maxipmo=0;
            printf("%02d시의 요청이 많은 IP : ",j);
            for (int i = 0; i < ipmoco; i++) {
                if (maxipmo<iplist[i].time[j]) {
                    maxipmo=iplist[i].time[j];
                }
            }
            printf("%d 회\n",maxipmo);
            for (int i = 0; i < ipmoco; i++) {
                if (maxipmo==iplist[i].time[j]) {
                    printf("%s\n",iplist[i].adr);
                }
                
            }
            
            
        }
        
    }
    

}