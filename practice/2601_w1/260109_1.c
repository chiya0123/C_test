#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _INTRO_SIZE_ 100


typedef struct{
    char ch1;
    short num;
    char ch2;
    int score;
    double grade;
    char ch3;
}std;

struct std2 {
    char ch1;
    char ch2;
    short num;
    int score;
    double grade;
    char ch3;
};

struct profile {
    char name[20];
    int age;
    double height;
    char *intro;
};

struct score {
    struct profile user;
    int score;
    
};

typedef struct vision {
    double left;
    double right;
}vstype;

vstype exchange(vstype);

struct list {
    int num;
    struct list *next;    
};


int main() {
    std st1;  
    struct std2 st2;
    struct profile you;   
    struct score youscore;
    vstype rovi[5];

    printf("%ld %ld\n",sizeof(st1),&st1.ch3-&st1.ch1+sizeof(st1.ch3));
    printf("%ld %ld\n",sizeof(st2),&st2.ch3-&st2.ch1+sizeof(st2.ch3));
    //구조체의 크기 확인 (패딩 바이트)

    strcpy(you.name,"당신");
    you.intro=(char *)malloc(_INTRO_SIZE_);
    printf("자기 소개 입력(한글 %d자 이하로 입력): ",_INTRO_SIZE_/3);
    fgets(you.intro,_INTRO_SIZE_,stdin);
    youscore.user=you;
    youscore.score=80;
    struct score *py=&youscore;

    strcpy(you.name,"나");
    
    printf("%s의 점수는 %d점\n",youscore.user.name,py->score);
    printf("자기 소개 : %s",py->user.intro);
    free(you.intro);

    rovi[0].left=8.3;
    rovi[0].right=2.7;

    rovi[0]=exchange(rovi[0]);
    printf("좌 : %.3lf 우 : %.3lf\n",rovi[0].left,rovi[0].right);

    struct list a={10,0},b={20,0},c={30,0};
    struct list *head=&a, *current;

    a.next=&b;
    b.next=&c;
    printf("%d\n",head->next->next->num);
    

}

vstype exchange(vstype aa) {
    double tmp=aa.left;
    aa.left=aa.right;
    aa.right=tmp;
    return aa;
}