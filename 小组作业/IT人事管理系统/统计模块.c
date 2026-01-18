#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "stuff.h"

// 统计模块主函数
void statisticsEmployee(stuff* head) {
    if (head == NULL) {
        printf("暂无员工信息，无法统计！\n");
        return;
    }

    int choice;
    do {
        printf("\n===== 员工信息统计菜单 =====\n");
        printf("1. 统计员工总数\n");
        printf("2. 统计薪资区间分布\n");
        printf("3. 统计工龄分布\n");
        printf("4. 计算员工平均月薪\n");
        printf("0. 退出统计\n");
        printf("请选择统计项：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                countTotalEmp();
                break;
            case 2:
                countSalaryRange();
                break;
            case 3:
                countWorkAge();
                break;
            case 4:
                calcAvgSalary();
                break;
            case 0:
                printf("退出统计模块！\n");
                break;
            default:
                printf("无效选项，请重新选择！\n");
        }
    } while (choice != 0);
}

// 1. 统计员工总数
void countTotalEmp() {
    int count = 0;
    stuff *p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    printf("当前员工总数：%d 人\n", count);
}

// 2. 统计薪资区间分布（按5k以下、5k-10k、10k-20k、20k以上划分）
void countSalaryRange() {
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0; // 对应四个薪资区间
    stuff *p = head;
    while (p != NULL) {
        int salary = p->ward_month;
        if (salary < 5000) {
            s1++;
        } else if (salary >= 5000 && salary < 10000) {
            s2++;
        } else if (salary >= 10000 && salary < 20000) {
            s3++;
        } else {
            s4++;
        }
        p = p->next;
    }
    printf("薪资区间分布统计：\n");
    printf("5000元以下：%d 人\n", s1);
    printf("5000-10000元：%d 人\n", s2);
    printf("10000-20000元：%d 人\n", s3);
    printf("20000元以上：%d 人\n", s4);
}

// 3. 统计工龄分布（按1年以下、1-3年、3-5年、5年以上划分）
void countWorkAge() {
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0; // 对应四个工龄区间
    stuff *p = head;
    while (p != NULL) {
        int age = p->age;
        if (age < 1) {
            a1++;
        } else if (age >= 1 && age < 3) {
            a2++;
        } else if (age >= 3 && age < 5) {
            a3++;
        } else {
            a4++;
        }
        p = p->next;
    }
    printf("工龄分布统计：\n");
    printf("1年以下：%d 人\n", a1);
    printf("1-3年：%d 人\n", a2);
    printf("3-5年：%d 人\n", a3);
    printf("5年以上：%d 人\n", a4);
}

// 4. 计算员工平均月薪
void calcAvgSalary() {
    int total = 0, count = 0;
    stuff *p = head;
    while (p != NULL) {
        total += p->ward_month;
        count++;
        p = p->next;
    }
    if (count == 0) {
        printf("无员工数据，无法计算！\n");
        return;
    }
    float avg = (float)total / count;
    printf("员工平均月薪：%.2f 元\n", avg);
}