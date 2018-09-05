#include <stdio.h>
/*  */
// #define 后面不加分号
#define NUM 3

// 定义结构体
struct Student
{
    int id;         
    char name[20];  
    float score[3]; 
    float average;  
};

// 输入并计算平均值
void input(struct Student stu[])
{
    printf("请输入学号、姓名、三门课程的成绩\n");
    for(int i = 0; i < NUM; i++)
    {
        scanf("%d %s %f %f %f",&stu[i].id,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].average=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    }
}

// 获取数组中的最大值
struct Student getMax(struct Student stu[]){
    struct Student maxStu=stu[0];
    for(int i = 1; i < NUM; i++)
    {
        if(stu[i].average>maxStu.average)
        {
            maxStu=stu[i];
        }
    }
    return maxStu;
}

// 打印学生信息
void myPrintf(struct Student student)
{
    printf("%d,%s,%f,%f,%f,%f",student.id,student.name,student.score[0],student.score[1],student.score[2],student.average);
}

// main
int main(int argc, char const *argv[])
{
    struct Student stu[NUM],*p=stu;
    input(p);
    myPrintf(getMax(p));
    while(1){

    }
    return 0;
}
