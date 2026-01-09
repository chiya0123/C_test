#include <stdio.h>
#include <string.h>

void cpynstr(char s1[], char s2[], int n);
void addnstr(char s1[], char s2[], int n);
void cpystr(char s1[], char s2[]);
void addstr(char s1[], char s2[]);
int lenstr(char str[]);
int cmpnstr(char s1[], char s2[], int n);
int cmpstr(char s1[], char s2[]);


int main() {
    char str1[80]="orange";
    char str2[80]="strawberry";
    char *sp1=str1;
    char *sp2="jam";

    printf("최초 문자열(%d) : %s\n",lenstr(str1),str1);
    printf("문자열 비교 : %d\n", cmpstr(str1,str2));
    cpystr(str1,str2);
    printf("바뀐 문자열 : %s\n",str1);
    addstr(str1,sp2);
    printf("바뀐 문자열 : %s\n",str1);

}


int lenstr(char str[]) {
    int n=0;
    while (1) {
        if (str[n]=='\0') return n;
        n++;
    }
}

void cpynstr(char s1[], char s2[], int n) {
    int l1=n;
    int l2=lenstr(s2);
    int i=0;
    for (; i < l2; i++) {
        if (i>l1-1) break;
        s1[i]=s2[i];
    }
    s1[i]='\0';    
}

void cpystr(char s1[], char s2[]) {
    cpynstr(s1,s2,1000000);
}

void addnstr(char s1[], char s2[], int n) {
    int l1=lenstr(s1);
    int l2=lenstr(s2);
    int i=l1;
    for (; i < l1+l2; i++) {
        if (i > n-1) break;
        s1[i]=s2[i-l1];
    }
    s1[i]='\0';      
}

void addstr(char s1[], char s2[]) {
    addnstr(s1,s2,1000000);
}

int cmpnstr(char s1[], char s2[], int n) {
    int l1=lenstr(s1);
    int l2=lenstr(s2);
    int c;
    for (int i = 0; (l1 > l2)?(i < l1):(i < l2); i++){
        c=s1[i]-s2[i];
        if (c) break;
        if (i>=n) break;             
    }
    return c;
    
}

int cmpstr(char s1[], char s2[]) {
    cmpnstr(s1,s2,lenstr(s1)+lenstr(s2));
}