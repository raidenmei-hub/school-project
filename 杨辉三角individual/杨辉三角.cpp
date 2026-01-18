#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("请输入杨辉三角的层数：");
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("输入错误，请输入一个正整数。\n");
        return 1;
    }

    // 分配内存
    int** triangle = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
    }

    // 初始化杨辉三角
    triangle[0][0] = 1;  // 第一行第一个元素为1

    // 构建杨辉三角
    for (int i = 1; i < n; i++) {
        triangle[i][0] = 1;  // 每行首元素为1
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle[i][i] = 1;  // 每行尾元素为1
    }

    // 输出杨辉三角（等边三角形排列）
    for (int i = 0; i < n; i++) {
        // 打印前导空格（使数字居中对齐）
        for (int k = 0; k < n - i - 1; k++) {
            printf("   ");  // 每个数字占 3 个字符宽度
        }
        // 打印当前行的数字
        for (int j = 0; j <= i; j++) {
            printf("%-6d", triangle[i][j]);  // 每个数字占 6 个字符宽度
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(triangle[i]);
    }
    free(triangle);

    return 0;
}
