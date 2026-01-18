#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stuff.h"

// 删除员工功能
void deleteEmployee(stuff* head) {
    if (head == NULL) {
        printf("当前没有员工信息，无法删除！\n");
        return;
    }

    int choice;
    printf("===== 删除员工方式 =====\n");
    printf("1. 按工号删除\n");
    printf("2. 按姓名删除\n");
    printf("请选择删除方式: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // 按工号删除
        char id_c;
        int id_n;

        printf("请输入要删除员工的工号字母部分: ");
        scanf(" %c", &id_c);
        printf("请输入要删除员工的工号数字部分: ");
        scanf("%d", &id_n);

        deleteEmployeeByFullId(id_c, id_n);
    }
    else if (choice == 2) {
        // 按姓名删除
        char name[50];
        printf("请输入要删除员工的姓名: ");
        scanf("%s", name);

        deleteEmployeeByName(name);
    }
    else {
        printf("无效的选择！\n");
    }
}

// 按完整工号删除员工
void deleteEmployeeByFullId(char id_c, int id_n) {
    if (head == NULL) {
        printf("链表为空，无法删除！\n");
        return;
    }

    stuff* current = head;
    stuff* prev = NULL;
    int found = 0;

    // 如果是头节点
    if (head->id_c == id_c && head->id_n == id_n) {
        stuff* temp = head;
        head = head->next;
        printf("成功删除员工: %s (工号: %c%d)\n", temp->Stuff.name, temp->id_c, temp->id_n);
        free(temp);
        found = 1;
    }
    else {
        // 遍历链表查找
        while (current != NULL) {
            if (current->id_c == id_c && current->id_n == id_n) {
                deleteEmployeeNode(prev, current);
                found = 1;
                break;
            }
            prev = current;
            current = current->next;
        }
    }

    if (!found) {
        printf("未找到工号为 %c%d 的员工！\n", id_c, id_n);
    }
}

// 按姓名删除员工
void deleteEmployeeByName(char* name) {
    if (head == NULL) {
        printf("链表为空，无法删除！\n");
        return;
    }

    stuff* current = head;
    stuff* prev = NULL;
    int found = 0;

    // 处理头节点匹配的情况
    while (current != NULL && strcmp(current->Stuff.name, name) == 0) {
        stuff* temp = current;
        current = current->next;
        printf("成功删除员工: %s (工号: %c%d)\n", temp->Stuff.name, temp->id_c, temp->id_n);
        free(temp);
        found = 1;
        head = current; // 更新头指针
    }

    // 处理中间和尾部节点
    while (current != NULL) {
        if (strcmp(current->Stuff.name, name) == 0) {
            stuff* temp = current;
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            current = current->next;
            printf("成功删除员工: %s (工号: %c%d)\n", temp->Stuff.name, temp->id_c, temp->id_n);
            free(temp);
            found = 1;
        }
        else {
            prev = current;
            current = current->next;
        }
    }

    if (!found) {
        printf("未找到姓名为 %s 的员工！\n", name);
    }
}

// 删除指定节点（辅助函数）
void deleteEmployeeNode(stuff* prev, stuff* current) {
    if (prev == NULL) {
        // 删除头节点
        head = current->next;
    }
    else {
        prev->next = current->next;
    }
    printf("成功删除员工: %s (工号: %c%d)\n", current->Stuff.name, current->id_c, current->id_n);
    free(current);
}