#include <stdio.h>
#include"stuff.h"

void showEmployeeNamesAndIds(stuff* head) {
    if (head == NULL) {
        printf("当前没有员工数据。\n");
        return;
    }

    printf("所有员工（仅显示姓名与工号）：\n");
    int count = 0;

    stuff* current = head;
    while (current != NULL) {
        count++;
        printf("%d. 姓名: %s  |  工号: %c%d\n",
            count,
            current->Stuff.name,
            current->id_c,
            current->id_n);
        current = current->next;
    }

    printf("共显示 %d 名员工。\n", count);
}