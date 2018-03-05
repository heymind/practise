#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[21];
    char id[21];
    int scores[5];
    double average;
    int sum; 
};
int main(){
    struct Student student = {.sum=0};
    fgets(student.name,21,stdin);
    scanf("%s",student.id);
    for(int i=0;i<5;i++) scanf("%d",&student.scores[i]);
    for(int i=0;i<5;i++) student.sum += student.scores[i];
    student.average = (double)student.sum / 5;
    for(int i=0;i<5-1;i++)
        for(int j=i+1;j<5;j++)
            if(student.scores[i]<student.scores[j]){
                int x = student.scores[i];
                student.scores[i] = student.scores[j];
                student.scores[j] = x;
            }
    printf("%s%s\n%d %d %d %d %d\n%.2f %d\n",student.name,student.id,student.scores[0],
    student.scores[1],
    student.scores[2],
    student.scores[3],
    student.scores[4],
    student.average,student.sum
    );
    return 0;
}