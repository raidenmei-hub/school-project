#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main() {
	int beicai,count_number=0,count_address=0;
	char beicai1[5], cai[5];
	srand((unsigned int)time(NULL));
	beicai = rand() % 10000;
	sprintf_s(beicai1,5, "%04d", beicai);
	while (count_address != 4) {
		count_address = 0;
		count_number = 0;
		printf("请输入数字：");
		scanf_s("%s", cai,5);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (beicai1[i] == cai[j]) {
					count_number++;
					break;
				}
			}
			if (beicai1[i] == cai[i]) {
				count_address++;
			}
		}
		printf("有%d个数字正确\n", count_number);
		printf("有%d个数字位置正确\n", count_address);
	}
	printf("恭喜！猜测正确！");
	return 0;
}