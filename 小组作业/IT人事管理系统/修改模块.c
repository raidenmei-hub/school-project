#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stuff.h"

// 按工号查找员工（修改功能依赖此函数）
stuff* findEmp(stuff* head, char id_c, int id_n) {
    stuff* p = head;
    while (p != NULL) {
        if (p->id_c == id_c && p->id_n == id_n) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 修改员工信息模块
void modifyEmp(stuff* head) {
    // 判断链表是否为空
    if (head == NULL) {
        printf("暂无员工信息，无法修改！\n");
        return;
    }

    // 输入要修改员工的工号
    char id_c;
    int id_n;
    printf("===== 员工信息修改 =====\n");
    printf("请输入工号前缀（单个字母）：");
    scanf(" %c", &id_c);
    printf("请输入工号后缀（数字）：");
    scanf("%d", &id_n);

    // 查找目标员工
    stuff* target = findEmp(head, id_c, id_n);
    if (target == NULL) {
        printf("未找到编号为 %c%d 的员工！\n", id_c, id_n);
        return;
    }

    // 展示找到的员工信息
    printf("\n找到员工信息如下：\n");
    printf("姓名：%s\n职位：%s\n月薪：%d\n工龄：%d\n",
           target->Stuff.name, target->position, target->ward_month, target->age);
    printf("手机号：%11lld", target->Stuff.phoneNumber);
  
    printf("\n");

    // 选择修改字段
    int choice;
    do {
        printf("\n===== 修改字段选项 =====\n");
        printf("1. 职位\n2. 月薪\n3. 工龄\n4. 手机号\n5. 退出修改\n");
        printf("请选择要修改的选项：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("请输入新职位：");
                scanf("%s", target->position);
                printf("职位修改成功！\n");
                break;
            case 2:
                printf("请输入新月薪：");
                scanf("%d", &target->ward_month);
                printf("月薪修改成功！\n");
                break;
            case 3:
                printf("请输入新工龄：");
                scanf("%d", &target->age);
                printf("工龄修改成功！\n");
                break;
            case 4:
                printf("请输入新手机号：");
                    if (scanf("%lld", &target->Stuff.phoneNumber) != 1) {
                        printf("输入有误，请重新输入手机号！\n");
                        // 清空输入缓冲区
                        int ch;
                        while ((ch = getchar()) != '\n' && ch != EOF);
                    }
                printf("手机号修改成功！\n");
                break;
            case 5:
                printf("已退出修改界面！\n");
                break;
            default:
                printf("无效选项，请重新输入！\n");
        }
    } while (choice != 5);
}