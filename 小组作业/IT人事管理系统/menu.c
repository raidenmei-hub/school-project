#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 菜单函数
// 功能：显示操作菜单，接收用户输入，返回选择的数字
// 返回值：用户选择的数字，如 1（查询）、0（退出）等
int menu() {
    int choice;

    // 打印菜单
    printf("\n");
    printf("==============================\n");
    printf("    IT企业人事信息管理系统\n");
    printf("==============================\n");
    printf(" 1. 查询员工\n");
    printf(" 2. 添加员工\n");
    printf(" 3. 删除员工\n");
    printf(" 4. 修改员工\n");
    printf(" 5. 统计信息\n");
    printf(" 6. 排序员工\n");
    printf(" 7. 显示所有员工\n");
    printf(" 0. 退出系统\n");
    printf("==============================\n");
    printf(" 请选择操作（输入数字 0~7）: ");

    // 获取用户输入
    if (scanf("%d", &choice) != 1) {
        // 输入的不是数字，清除输入缓冲区
        while (getchar() != '\n');  // 清掉错误的输入
        printf(" 输入错误，请输入数字！\n");
        return -1;  // 表示非法输入
    }

    // 检查是否在合理范围内（可以根据你的功能调整范围，比如 0~7）
    if (choice < 0 || choice > 7) {
        printf(" 输入错误，请输入 0~7 之间的数字！\n");
        return -1;  // 表示非法输入
    }

    return choice;  // 返回用户选择
}