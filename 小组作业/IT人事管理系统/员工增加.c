#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stuff.h"

void ScanStuff(stuff** head) {
    char name[50];
    char sex[3];
    long long idCard;
    int year, month, date;
    long long phoneNumber;
    char nationality[20];
    char nation[20];
    char id_c;
    int id_n;
    char position[20];
    int ward_month;
    int age;
    while (1) {
        printf("请输入新员工信息：\n");
        printf("格式：姓名 性别 身份证号 出生年 月 日 手机号 国籍 民族 工号字母 工号数字 职位 月薪 工龄\n");
        printf("示例：张三 男 123456789012345678 1990 1 1 13800138000 中国 汉 A 1001 工程师 8000 3\n");

        if (scanf("%49s %2s %lld %d %d %d %lld %19s %19s %c %d %19s %d %d",
            name, sex, &idCard, &year, &month, &date, &phoneNumber,
            nationality, nation, &id_c, &id_n, position, &ward_month, &age) != 14) {
            printf("输入格式错误！\n");
            // 清空输入缓冲区
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // 验证输入
        if (!check(sex, idCard, month, date, phoneNumber, age)) {
            printf("输入数据验证失败！\n");
            continue;
        }

        *head = CreatStuff(*head, name, sex, idCard, year, month, date,
            phoneNumber, nationality, nation, id_c, id_n,
            position, ward_month, age);

        if (*head != NULL) {
            printf("员工添加成功！\n");
            break;
        }
        else {
            printf("员工添加失败！\n");
        }
    }
}

stuff* CreatStuff(stuff* head, char name[], char sex[], long long idCard, int year,
    int month, int date, long long phoneNumber, char nationality[],
    char nation[], char id_c, int id_n, char position[], int ward_month, int age) {

    // 检查工号是否已存在
    stuff* current = head;
    while (current != NULL) {
        if (current->id_c == id_c && current->id_n == id_n) {
            printf("工号 %c%d 已存在！\n", id_c, id_n);
            return head;
        }
        current = current->next;
    }

    // 创建新节点
    stuff* newStuff = (stuff*)malloc(sizeof(stuff));
    if (newStuff == NULL) {
        printf("内存分配失败！\n");
        return head;
    }

    // 初始化数据
    strncpy(newStuff->Stuff.name, name, sizeof(newStuff->Stuff.name) - 1);
    newStuff->Stuff.name[sizeof(newStuff->Stuff.name) - 1] = '\0';

    strncpy(newStuff->Stuff.sex, sex, sizeof(newStuff->Stuff.sex) - 1);
    newStuff->Stuff.sex[sizeof(newStuff->Stuff.sex) - 1] = '\0';

    newStuff->Stuff.idCard = idCard;
    newStuff->Stuff.bornDay.year = year;
    newStuff->Stuff.bornDay.month = month;
    newStuff->Stuff.bornDay.date = date;
    newStuff->Stuff.phoneNumber = phoneNumber;

    strncpy(newStuff->Stuff.nationality, nationality, sizeof(newStuff->Stuff.nationality) - 1);
    newStuff->Stuff.nationality[sizeof(newStuff->Stuff.nationality) - 1] = '\0';

    strncpy(newStuff->Stuff.nation, nation, sizeof(newStuff->Stuff.nation) - 1);
    newStuff->Stuff.nation[sizeof(newStuff->Stuff.nation) - 1] = '\0';

    newStuff->id_c = toupper(id_c);  // 转换为大写
    newStuff->id_n = id_n;

    strncpy(newStuff->position, position, sizeof(newStuff->position) - 1);
    newStuff->position[sizeof(newStuff->position) - 1] = '\0';

    newStuff->ward_month = ward_month;
    newStuff->age = age;
    newStuff->next = NULL;

    // 添加到链表
    if (head == NULL) {
        return newStuff;
    }

    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newStuff;

    return head;
}