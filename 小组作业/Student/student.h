//头文件
#ifndef STUDENT_H
#define STUDENT_H
extern int male;
extern int female;
extern int count;
typedef struct Student
{
	char name[50];
	char sex[3];
	int year;
	int month;
	int date;
	struct Student* next;//建立链表
}Student;
extern Student* head;//用于所有文件的链表头
Student* CreateStudent(Student* head, char name[], char sex[], int year, int month, int date);//创建学生数组
void femaleMax(int arr[]);//寻找最大女生数组
void maleMax(int arr[]);//寻找最大男生数组
void Max(int arr[]);//寻找最大学生数组
#endif 

