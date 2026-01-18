#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"student.h"
int male = 0;//初始化男生人数
int female = 0;//初始化女生人数
int count = 0;//初始化学生人数
Student* head = NULL;//初始化链表头
//学生信息检查
int CheckData(char sex[],int year, int month, int date) {
	if (year < 2025 && (month >= 1 && month <= 12) && (date >= 1 && date <= 31)&&(strcmp(sex,"男")==0||strcmp(sex,"女")==0)) {
		return 1;
	}
	else return 0;
}
//学生信息显示
void PrintStudentList(Student* head) {
	if (head == NULL) {
		printf("学生列表为空\n");
		return;
	}

	Student* current = head;
	int count = 1;

	while (current != NULL) {
		printf("%d. 姓名：%s, 性别：%s, 出生日期：%d年%d月%d日\n",
			count, current->name, current->sex,
			current->year, current->month, current->date);
		current = current->next;
		count++;
	}
}
//链表释放
void FreeHead(Student* head) {
	while (head != NULL) {
		Student* current = head;
		head = head->next;
		free(current);
	}
}
int main() {
	char name[50] = { 0 };
	char sex[3] = { 0 };
	int year=0;
	int month=0;
	int date=0;
	printf("请输入学生的姓名，性别，出生年，月，日（按空格隔开，年月日均只为数字，按 # 结束）	\n");
	char buffer[256];
	int modifying = 1;
	while (modifying) {
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)//输入学生信息 
		{
			break;
		}
		buffer[strcspn(buffer, "\n")] = 0;
		//遇到#结束输入
		if (strchr(buffer, '#')) {
			buffer[strcspn(buffer, "#")] = 0;
			if (strlen(buffer) > 0) {
				if (sscanf(buffer, "%s %s %d %d %d", name, sex, &year, &month, &date) == 5&&CheckData(sex,year,month,date)==1) {
					head = CreateStudent(head, name, sex, year, month, date);
					modifying = 0;
				}
				else {
					printf("学生信息输入格式错误，请重新输入\n");
					continue;
				}
			}
				break;
		}
		else if (strlen(buffer) > 0) {
			if (sscanf(buffer, "%s %s %d %d %d", name, sex, &year, &month, &date) == 5 && CheckData(sex,year, month, date) == 1){
				head = CreateStudent(head, name, sex, year, month, date);
			}
			else {
				printf("学生信息输入格式错误，请重新输入\n");
			}
		}
	}
	int FemaleYear[256];
	int MaleYear[256];
	int Year[256];
	Student* current = head;
	while (current != NULL) {
		if (strcmp(current->sex,"男")==0) {
			MaleYear[male]=2025-(current->year);
			male++;
		}
		if (strcmp(current->sex, "女") == 0) {
			FemaleYear[female] =2025-( current->year);
			female++;
		}
		Year[count] = 2025-(current->year);
		count++;
		current = current->next;
	}
	//操作界面显示
	printf("请选择操作：1.显示学生信息  2.显示最大女生  3.显示最大男生  4.显示最大学生  0.退出\n");
	modifying = 1;
	while (modifying) {
		int choice=0;
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = 0;
		choice = atoi(buffer);
		switch (choice) {
		case 1:
			PrintStudentList(head);
			break;
		case 2:
			femaleMax(FemaleYear);
			break;
		case 3:
			maleMax(MaleYear);
			break;
		case 4:
			Max(Year);
			break;
		case 0:
			modifying = 0;
			break;
		default:
			printf("错误操作，请重新输入\n");
			break;
		}
	}
	FreeHead(head);
	return 0;
}
