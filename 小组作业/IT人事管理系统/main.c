#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"stuff.h"
stuff* head = NULL;

int main() {
    int userChoice;

    while (1) {
        userChoice = menu();
        switch (userChoice) {
        case 1: queryStaff(head); break;  // 如果ScanStuff也需要修改
        case 2: ScanStuff(&head); break;
        case 3: deleteEmployee(head); break;
        case 4:modifyEmp(head) ; break;
        case 5: statisticsEmployee(head); break;
        case 6: sortEmployees(&head); break;  // 传递head的地址
        case 7: showEmployeeNamesAndIds(head); break;
        case 0:
            printf("再见！\n");
            while (head != NULL) {
                stuff* temp = head;
                head = head->next;
                free(temp);
            }
            exit(0);
            break;
        default: printf("无效选择，请重新输入！\n");
        }
    }
    return 0;
}