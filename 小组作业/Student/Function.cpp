#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "student.h"
extern Student* head;
extern int male, female, count;
Student* CreateStudent(Student* head, char name[], char sex[], int year, int month, int date) {
	struct Student* Nstudent = (struct Student*)malloc(sizeof(struct Student));//建立动态内存，设立链表
	if (Nstudent == NULL) {
			return head;
	}
	//将各个数据给予链表成员
	strncpy(Nstudent->name, name, sizeof(Nstudent->name) - 1);
	Nstudent->name[sizeof(Nstudent->name) - 1] = '\0';
	strncpy(Nstudent->sex, sex, sizeof(Nstudent->sex) - 1);
	Nstudent->sex[sizeof(Nstudent->sex) - 1] = '\0';
	Nstudent->year = year;
	Nstudent->month = month;
	Nstudent->date = date;
	Nstudent->next = NULL;
	//将链表以“火车式”排序方式排序
	if (head == NULL) {
		return Nstudent;
	}
	Student* current = head;
	while (current->next != NULL) {
		current=current->next;
	}
	current->next = Nstudent;
	return head;
}
//最大年龄的女生
void femaleMax(int arr[]) {
	int max = arr[0];
	for (int i = 1; i < female; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	Student* current = head;
	while (current != NULL) {
		if (2025-(current->year) == max) {
			printf("年龄最大的女生是:%s\n", current->name);
			return;
		}
		current = current->next;
	}
}
//最大年龄的男生
void maleMax(int arr[]) {
	int max = arr[0];
	for (int i = 1; i < male; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	Student* current = head;
	while (current != NULL) {
		if (2025 - (current->year) == max) {
			printf("年龄最大的男生是:%s\n", current->name);
			return;
		}
		current = current->next;
	}
}
//最大年龄的学生
void Max(int arr[]) {
	int max = arr[0];
	for (int i = 0; i < count; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	Student* current = head;
	while (current != NULL) {
		if (2025 - (current->year) == max) {
			printf("年龄最大的学生是:%s\n", current->name);
			return;
		}
		current = current->next;
	}
}