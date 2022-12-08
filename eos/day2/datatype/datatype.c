
#include<stdio.h>
#include<string.h>

typedef struct student{
        char name[20];
        char course[10];
        int id;
    }st_t;

int main()
{
    st_t stu1 = {"Hiya Pandey", "Embedded", 2};
    st_t stu2;
    strcpy(stu2.name, "Sahil Usmani");
    strcpy(stu2.course, "Embedded");
    stu2.id = 12;
    printf("Student Name: %s\n",stu1.name);
    printf("Course Name: %s\n",stu1.course);
    printf("Student ID: %d\n",stu1.id);

    printf("Student Name: %s\n",stu2.name);
    printf("Course Name: %s\n",stu2.course);
    printf("Student ID: %d\n",stu2.id);

    return 0;
}