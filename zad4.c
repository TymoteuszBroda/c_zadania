#include <stdlib.h>

struct Student
{
    char name[20];
    float grade;
};

void sortStudent(struct Student *student, int size)
{
    struct Student temp;
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (student[j].grade < student[j + 1].grade)
            {
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            } 
        } 
    }
}


int main()
{
    int studentCount = 999;
    struct Student student[studentCount];

    for(int i=0; i<studentCount; i++)
    {
        snprintf(student[i].name, sizeof(student[i].name), "Student%d", i+1);
        student[i].grade = (float)2.0 + (float)(rand() % 8);
    }

    sortStudent(student, studentCount);
    printf("student:\n");
    for(int i =0; i<studentCount;i++)
    {
        printf("Student: %s, grade: %.2f.\n",student[i].name, student[i].grade);
    }
    return 0;
}