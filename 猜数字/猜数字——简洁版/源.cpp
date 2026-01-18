#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char answer[5], guess[5];
    int correct_num, correct_pos;

    srand((unsigned int)time(NULL));
    sprintf_s(answer, 5, "%04d", rand() % 10000);

    printf("数字猜谜游戏开始！\n");

    do {
        correct_num = correct_pos = 0;

        printf("请输入4位数字：");
        scanf_s("%4s", guess, 5);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (answer[i] == guess[j]) {
                    correct_num++;
                    break;
                }
            }
            if (answer[i] == guess[i]) correct_pos++;
        }

        printf("正确数字：%d个，正确位置：%d个\n", correct_num, correct_pos);
    } while (correct_pos != 4);

    printf("恭喜！正确答案是：%s\n", answer);
    return 0;
}