#ifndef STUFF_H
#define STUFF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct birthday {
    int year;
    int month;
    int date;
} birthday;

typedef struct stuff_information_character {
    char name[50];//姓名
    char sex[3];//性别
    long long idCard;//身份证号
    birthday bornDay;//出生日期
    long long phoneNumber;//手机号
    char nationality[20];//国籍
    char nation[20];//民族
} stuff_information_character;

typedef struct stuff {
    stuff_information_character Stuff;
    char id_c;//工号——字母
    int id_n;//工号——数字
    char position[20];//职位
    int ward_month;//月薪
    int age;//工龄
    struct stuff* next;
} stuff;

extern stuff* head;

void deleteEmployee(stuff* head);
void deleteEmployeeByFullId(char id_c, int id_n);
void deleteEmployeeByName(char* name);
void deleteEmployeeNode(stuff* prev, stuff* current);
void sortEmployees(stuff** head); 
void bubbleSort(stuff** arr, int length, int (*compare)(stuff*, stuff*), int order);
int compareByEmployeeId(stuff* a, stuff* b);
int compareByName(stuff* a, stuff* b);
int compareBySalary(stuff* a, stuff* b);
int compareByAge(stuff* a, stuff* b);
int compareByWorkAge(stuff* a, stuff* b);
void ScanStuff(stuff** head);
stuff* CreatStuff(stuff* head, char name[], char sex[], long long idCard, int year,
    int month, int date, long long phoneNumber, char nationality[],
    char nation[], char id_c, int id_n, char position[], int ward_month, int age);
void modifyEmp(stuff* head);
stuff* findEmp(stuff* head, char id_c, int id_n);
void queryStaff(stuff* head);
void statisticsEmployee(stuff* head);
void countTotalEmp();
void countSalaryRange();
void countWorkAge();
void calcAvgSalary();
void showEmployeeNamesAndIds(stuff* head);  
int menu();
int check(char sex[], long long idCard, int month, int date, long long phoneNumber, int age);

#endif
