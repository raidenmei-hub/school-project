#include<stdio.h>
int main() {
	int count = 0;
	//题2.1
	/*
	int i,count=0;
	while (count <= 5) {
		printf("请输入一个整数:");
		scanf_s("%d", &i);
		//判断奇数
		if (i % 2 != 0) {
			printf("该数是奇数\n");
		}
		//判断偶数
		else if (i % 2 == 0) {
			printf("该数是偶数\n");
		}
		count++;
	}*/
	//题2.2
	//x<1,1<=x<10,x>=10
	/*float x, y, count = 0;
	while (count <= 5) {
		printf("请输入x的值:");
		scanf_s("%f", & x);
		if (x < 1) {
			y = x;
			printf("y=%.2f\n", y);
		}
		if (x >= 1 && x < 10) {
			y = 2*x - 1;
			printf("y=%.2f\n", y);
		}
		if (x >= 10) {
			y = 3*x - 11;
			printf("y=%.2f\n", y);
		}
		count++;
	}
	*/
	//题2.3
	/*int month;
	while (count <= 4) {
		printf("请输入月份：");
		scanf_s("%d", &month);
		//if形式
		/*if (month == 12 || (month >= 1 && month <= 2)) {
			printf("该月份为冬季\n");
		}
		else if (month >= 3 && month <= 5) {
			printf("该月份为春季\n");
		}
		else if (month >= 6 && month <= 8) {
			printf("该月份为夏季\n");
		}
		else if (month >= 9 && month <= 11) {
			printf("该月份为秋季\n");*/
			//switch形式
			/*switch (month) {
			case 12:
			case 1:
			case 2:
				printf("该月份为冬季\n");
				break;
			case 3:
			case 4:
			case 5:
				printf("该月份为春季\n");
				break;
			case 6:
			case 7:
			case 8:
				printf("该月份为夏季\n");
				break;
			case 9:
			case 10:
			case 11:
				printf("该月份为秋季\n");
				break;
			default:
				break;
			}
				count++;
			}*/
			int score, n;
			printf("请输入一个成绩：");
			/**********FOUND**********/
			scanf_s("%d", &score);
			/**********FOUND**********/
			if (score < 0 && score>100)
				printf("您的输入应在0-100之间，该数超出了范围。\n");
			else
			{
				n = score / 10;
				/**********FOUND**********/
				switch (score)
				{
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					printf("不及格！\n");
					break;
				case 6:
					printf("及格！\n");
					break;
				case 7:
					printf("中等！\n");
					break;
				case 8:
					printf("良好！\n");
					break;
				case 9:
					/**********FOUND**********/
					case 10:
							printf("优秀！\n");
							break;
					}
				printf("执行条件n=%d\n", n);
				}
	//题4.1
	/*int i = 7, j = 7;
	if (i != 1) {
		printf("一级if语句运行成功\n");
		if (j == 2) {
			i = i + j;
			printf("i=i+j=%d\n", i);
			printf("二级if语句运行成功\n");
		}
		else {
			i =i - j;
			printf("i=i-j=%d\n", i);
			printf("二级if语句运行成功\n");
		}
	}
	printf("i=%d\n", i);*/
	return 0;
}