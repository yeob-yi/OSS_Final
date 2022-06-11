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

    printf("Hello, %s. How many subjects will you register in this semester? ", user);
    scanf("%d", &sub_num);
    for(int i=0; i<sub_num; i++){
	    if(i==0) printf("Input the code of 1st subject : ");
        else if(i==1) printf("Input the code of 2nd subject : ");
        else if(i==2) printf("Input the code of 3rd subject : ");
        else printf("Input the code of %dth subject : ", i+1);
        scanf("%s", temp.code);
        printf("Input the section that you want to take : ");
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
