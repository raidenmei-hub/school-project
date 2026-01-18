#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// 函数声明
int isValidInput(const char* input);
void checkGuess(const char* answer, const char* guess, int* correct_num, int* correct_pos);

int main() {
    char answer[5], guess[5];
    int attempts = 0, correct_num, correct_pos;

    // 初始化
    srand((unsigned int)time(NULL));
    sprintf_s(answer, 5, "%04d", rand() % 10000);

    printf("🎯 数字猜谜游戏开始！\n");
    printf("规则：猜一个4位数字，会提示数字正确数和位置正确数\n\n");

    // 游戏主循环
    while (1) {
        attempts++;
        correct_num = correct_pos = 0;

        // 输入验证循环
        while (1) {
            printf("第%d次尝试：请输入4位数字：", attempts);
            if (scanf_s("%4s", guess, 5) != 1) {
                printf("输入错误！请重新输入。\n");
                while (getchar() != '\n'); // 清空输入缓冲区
                continue;
            }

            if (isValidInput(guess)) break;
            printf("请输入有效的4位数字！\n");
        }

        // 检查猜测结果
        checkGuess(answer, guess, &correct_num, &correct_pos);

        printf("结果：%d个数字正确，%d个位置正确\n\n", correct_num, correct_pos);

        // 检查是否猜中
        if (correct_pos == 4) {
            printf("🎉 恭喜！你在第%d次尝试中猜对了！\n", attempts);
            printf("正确答案是：%s\n", answer);
            break;
        }

        // 尝试次数限制
        if (attempts >= 10) {
            printf("💔 很遗憾，机会用完了！正确答案是：%s\n", answer);
            break;
        }
    }

    return 0;
}

// 验证输入是否为4位数字
int isValidInput(const char* input) {
    if (strlen(input) != 4) return 0;

    for (int i = 0; i < 4; i++) {
        if (!isdigit(input[i])) return 0;
    }
    return 1;
}

// 检查猜测结果
void checkGuess(const char* answer, const char* guess, int* correct_num, int* correct_pos) {
    int answer_used[4] = { 0 }, guess_used[4] = { 0 };

    // 先检查位置正确的数字
    for (int i = 0; i < 4; i++) {
        if (answer[i] == guess[i]) {
            (*correct_pos)++;
            answer_used[i] = guess_used[i] = 1;
        }
    }

    // 再检查数字正确但位置不对的
    for (int i = 0; i < 4; i++) {
        if (answer_used[i]) continue; // 已匹配的位置跳过

        for (int j = 0; j < 4; j++) {
            if (!guess_used[j] && answer[i] == guess[j]) {
                (*correct_num)++;
                guess_used[j] = 1;
                break;
            }
        }
    }
}