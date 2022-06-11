#include <stdio.h>
#include <string.h>

struct User {
    char name[100];
    int id;
    int school_year;
};

struct Subject {
    char code[10];
    int section;
};

int main(void){
    char user[100];
    struct Subject temp;
    struct Subject timetable[10];
    int sub_num=0;
    
    printf("Hello, this is registration priority calculator.\n\n");

    printf("What's your name? ");
    scanf("%s", user);

    printf("\n");

    printf("Hello, %s. How many subjects will you register in this semester? ", user.name);
    scanf("%d", &sub_num);
    for(int i=0; i<sub_num; i++){
        printf("%d번째 과목의 과목 코드를 입력해주세요 : ", i+1);
        scanf("%s", temp.code);
        printf("수강하려는 분반을 입력해주세요 : ");
        scanf("%d", &temp.section);
        timetable[i] = temp;
        printf("\n");
    }

    FILE *fp = fopen("timetable.txt", "w");
    for(int i=0; i<sub_num; i++){
        fprintf(fp, "%s-%d\n", timetable[i].code, timetable[i].section);
    }
    fclose(fp);

    return 0;
}