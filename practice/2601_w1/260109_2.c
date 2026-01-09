#include <stdio.h>

typedef struct {
    int id;
    char name[10];
    int kor;
    int eng;
    int math;
    int sum;
    double avg;
    char grade;
}stud;

stud getdata(stud);
stud cpystud(stud);

int main() {
    stud student[5];
    for (int i = 0; i < 5; i++) {
        student[i]=getdata(student[i]);
    }
    printf("정렬 전 데이터\n");
    for (int i = 0; i < 5; i++) {
        stud *ps=&student[i];
        printf("%5d %s %4d %4d %4d %4d %4.1lf  %c\n",
            ps->id,ps->name,ps->kor,ps->eng,ps->math,ps->sum,ps->avg,ps->grade);
    }

    // 선택 정렬
    int label[5]={0,1,2,3,4};
    for (int i = 0; i < 4; i++){
        for (int j = i+1; j < 5; j++) {
            if (student[label[i]].sum<student[label[j]].sum) {
                int tmp=label[i];
                label[i]=label[j];
                label[j]=tmp;
            }   
        }
    }

    // 참고용 버블 정렬
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4-i; j++) {
    //         if (score[j]<score[j+1]) {
    //             int tmp=score[j+1];
    //             score[j+1]=score[j];
    //             score[j]=tmp;
    //         }
    //     }
    // }

    // 참고용 삽입 정렬
    // for (int i = 1; i < 5; i++) {
    //     int key=score[i];
    //     int j = i-1;
    //     for (; j >= 0; j--) {
    //         if (score[j]<key) {
    //             score[j+1]=score[j];             
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     score[j+1]=key;
        
    // }
    
    printf("정렬 후 데이터\n");
    for (int i = 0; i < 5; i++) {
        stud *ps=&student[label[i]];
        printf("%5d %s %4d %4d %4d %4d %4.1lf  %c\n",
            ps->id,ps->name,ps->kor,ps->eng,ps->math,ps->sum,ps->avg,ps->grade);
    }
    
}

stud getdata(stud s) {
    printf("학번 : ");
    scanf("%d",&s.id);
    printf("이름 : ");
    scanf("%s",s.name);
    printf("국어, 영어, 수학 점수 : ");
    scanf("%d %d %d",&s.kor,&s.eng,&s.math);
    s.sum=s.kor+s.eng+s.math;
    s.avg=s.sum/3.0;
    switch (s.sum/30) {
    case 10:
    case 9:
        s.grade='A';
        break;
    case 8:
        s.grade='B';
        break;
    case 7:
        s.grade='C';
        break;
    default:
        s.grade='F';
        break;
    }
    return s;
}