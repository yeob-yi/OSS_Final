#include <stdio.h>
#include <string.h>

struct Subject {
    char code[10];
    int section;
    int pre_register_num;
    int max_num;
    double competitive;
    int rank;
};

int main(void){
    FILE *fp = fopen("pre_register_num.txt", "r");
    int sub_num=0;
    int i, j;
    int rank;
    struct Subject classes[10];

    while(!feof(fp)){
        struct Subject temp;
        fscanf(fp, "%s %d %d %d", temp.code, &temp.section, &temp.pre_register_num, &temp.max_num);
        temp.competitive = temp.pre_register_num*1.0/temp.max_num;
        temp.competitive = ((int)(temp.competitive*10000))*0.0001;
        temp.rank=0;
        classes[sub_num] = temp;
        sub_num++;
    }
    sub_num--;

    fclose(fp);

    for(i=0; i<sub_num; i++){
        classes[i].rank += sub_num;
        for(j=0; j<sub_num; j++){
            if(i==j) continue;
            else if(classes[i].competitive<=classes[j].competitive){
                classes[j].rank--;
            }
        }
    }

    printf("priority  subject_code  section  current_num  max_num  competitive\n");
    // printf("a  ~b~  ~c~  ~d~  ~e~");
    for(i=0; i<sub_num; i++){
        for(j=0; j<sub_num; j++){
            if(classes[j].rank == i+1){
                printf("   %d       %s        %d           %d       %d         %.2f\n", classes[j].rank, classes[j].code, classes[j].section, classes[j].pre_register_num, classes[j].max_num, classes[j].competitive);
            }
        }
    }
}