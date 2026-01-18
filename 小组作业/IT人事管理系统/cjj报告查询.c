#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include"stuff.h"

// 函数：查询员工信息
void queryStaff(stuff* head) {
    if (head == NULL) {
        printf("当前链表为空，没有员工信息可查询。\n");
        return;
    }

    int choice;
    printf("===== 查询员工方式 =====\n");
    printf("1. 按工号查询（字母 + 数字）\n");
    printf("2. 按姓名查询\n");
    printf("3. 按职位查询\n");
    printf("请选择查询方式: ");
    scanf("%d", &choice);

    char searchKey[50];  // 用于存放查询关键字
    int found = 0;       // 标记是否找到

    if (choice == 1) {
        // 按工号查询（分为字母和数字两部分）
        char idChar;
        int idNum;

        printf("请输入工号的字母部分（如 A）: ");
        scanf(" %c", &idChar);   // 注意空格，避免读取回车
        printf("请输入工号的数字部分（如 1001）: ");
        scanf("%d", &idNum);

        struct stuff* current = head;
        while (current != NULL) {
            if (current->id_c == idChar && current->id_n == idNum) {
                printf("\n找到员工信息：\n");
                printf("工号字母: %c\n", current->id_c);
                printf("工号数字: %d\n", current->id_n);
                printf("姓名: %s\n", current->Stuff.name);
                printf("性别: %s\n", current->Stuff.sex);
                printf("身份证号: %I64d\n", current->Stuff.idCard);
                printf("出生日期: %d年%d月%d日\n", 
                       current->Stuff.bornDay.year,
                       current->Stuff.bornDay.month,
                       current->Stuff.bornDay.date);
                printf("职位: %s\n", current->position);
                printf("月薪: %d\n", current->ward_month);
                printf("工龄: %d\n", current->age);
                printf("国籍: %s\n", current->Stuff.nationality);
                printf("民族: %s\n", current->Stuff.nation);
                printf("-----------------------------\n");
                found = 1;
            }
            current = current->next;
        }
    }
    else if (choice == 2) {
        // 按姓名查询
        printf("请输入要查询的姓名: ");
        scanf("%s", searchKey);

        stuff* current = head;
        while (current != NULL) {
            if (strcmp(current->Stuff.name, searchKey) == 0) {
                printf("\n找到员工信息：\n");
                printf("工号字母: %c\n", current->id_c);
                printf("工号数字: %d\n", current->id_n);
                printf("姓名: %s\n", current->Stuff.name);
                printf("性别: %s\n", current->Stuff.sex);
                printf("身份证号: %I64d\n", current->Stuff.idCard);
                printf("出生日期: %d年%d月%d日\n", 
                       current->Stuff.bornDay.year,
                       current->Stuff.bornDay.month,
                       current->Stuff.bornDay.date);
                printf("职位: %s\n", current->position);
                printf("月薪: %d\n", current->ward_month);
                printf("工龄: %d\n", current->age);
                printf("国籍: %s\n", current->Stuff.nationality);
                printf("民族: %s\n", current->Stuff.nation);
                printf("-----------------------------\n");
                found = 1;
            }
            current = current->next;
        }
    }
    else if (choice == 3) {
        // 按职位查询
        printf("请输入要查询的职位: ");
        // 使用scanf时，确保searchKey有足够空间，并且输入不会溢出
        // scanf("%19s", searchKey); // 原代码
        // 修正：手动清空searchKey，确保零终止符
        memset(searchKey, 0, sizeof(searchKey));
        scanf("%19s", searchKey); // 最多输入19个字符，留1个给'\0'

        struct stuff* current = head;
        while (current != NULL) {
            if (strcmp(current->position, searchKey) == 0) {
                printf("\n找到员工信息：\n");
                printf("工号字母: %c\n", current->id_c);
                printf("工号数字: %d\n", current->id_n);
                printf("姓名: %s\n", current->Stuff.name);
                printf("性别: %s\n", current->Stuff.sex);
                printf("身份证号: %I64d\n", current->Stuff.idCard);
                printf("出生日期: %d年%d月%d日\n", 
                       current->Stuff.bornDay.year,
                       current->Stuff.bornDay.month,
                       current->Stuff.bornDay.date);
                printf("职位: %s\n", current->position);
                printf("月薪: %d\n", current->ward_month);
                printf("工龄: %d\n", current->age);
                printf("国籍: %s\n", current->Stuff.nationality);
                printf("民族: %s\n", current->Stuff.nation);
                printf("-----------------------------\n");
                found = 1;
            }
            current = current->next;
        }
    }
    else {
        printf("无效的查询方式！\n");
        return;
    }

    if (!found) {
        printf("未找到匹配的员工信息。\n");
    }
}