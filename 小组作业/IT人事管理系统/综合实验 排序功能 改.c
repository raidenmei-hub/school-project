#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stuff.h"

// 排序模块实现
void sortEmployees(stuff** head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("员工数据不足，无需排序！\n");
        return;
    }

    int sortChoice, orderChoice;
    printf("===== 员工信息排序 =====\n");
    printf("1. 按工号排序\n");
    printf("2. 按姓名排序\n");
    printf("3. 按工资排序\n");
    printf("4. 按工龄排序\n");
    printf("请选择排序方式: ");
    scanf("%d", &sortChoice);

    printf("选择排序顺序:\n");
    printf("1. 升序排列\n");
    printf("2. 降序排列\n");
    printf("请选择: ");
    scanf("%d", &orderChoice);

    // 获取链表长度
    int length = 0;
    stuff* current = *head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    // 创建节点指针数组
    stuff** arr = (stuff**)malloc(length * sizeof(stuff*));
    if (arr == NULL) {
        printf("内存分配失败！\n");
        return;
    }

    current = *head;
    for (int i = 0; i < length; i++) {
        arr[i] = current;
        current = current->next;
    }

    // 选择比较函数
    int (*compareFunc)(stuff*, stuff*) = NULL;
    switch (sortChoice) {
    case 1: compareFunc = compareByEmployeeId; break;
    case 2: compareFunc = compareByName; break;
    case 3: compareFunc = compareBySalary; break;
    case 4: compareFunc = compareByWorkAge; break;
    default:
        printf("无效的排序选择！\n");
        free(arr);
        return;
    }

    // 执行排序
    bubbleSort(arr, length, compareFunc, orderChoice);

    // 重建链表
    *head = arr[0];
    current = *head;
    for (int i = 1; i < length; i++) {
        current->next = arr[i];
        current = arr[i];
    }
    current->next = NULL;

    printf("排序完成！\n");
    showEmployeeNamesAndIds(*head);
    free(arr);
}

// 冒泡排序算法
void bubbleSort(stuff** arr, int length, int (*compare)(stuff*, stuff*), int order) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            int shouldSwap = 0;
            if (order == 1) { // 升序
                shouldSwap = compare(arr[j], arr[j + 1]) > 0;
            }
            else { // 降序
                shouldSwap = compare(arr[j], arr[j + 1]) < 0;
            }

            if (shouldSwap) {
                stuff* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 比较函数：按工号排序
int compareByEmployeeId(stuff* a, stuff* b) {
    // 先比较字母部分
    if (a->id_c != b->id_c) {
        return a->id_c - b->id_c;
    }
    // 字母相同再比较数字部分
    return a->id_n - b->id_n;
}

// 比较函数：按姓名排序
int compareByName(stuff* a, stuff* b) {
    return strcmp(a->Stuff.name, b->Stuff.name);
}

// 比较函数：按工资排序
int compareBySalary(stuff* a, stuff* b) {
    return a->ward_month - b->ward_month;
}

// 比较函数：按年龄排序
int compareByAge(stuff* a, stuff* b) {
    return a->age - b->age;
}

// 比较函数：按工龄排序
int compareByWorkAge(stuff* a, stuff* b) {
    // 这里假设age字段存储的是工龄，如果不是需要调整
    return a->age - b->age;
}