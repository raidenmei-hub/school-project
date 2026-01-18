#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	//对角线求和
	/*int a[3][3], sum = 0;
	int i, j;
	printf("enter data:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			scanf("%3d", &a[i][j]);
	}
	for (i = 0; i < 3; i++)
		sum += a[i][i];
	printf("sum=%6d\n", sum);*/
	//字符统计
	/*int i, j, upp, low, dig, spa, oth;
	char text[3][80];
	upp = low = dig = spa = oth = 0;
	for (i = 0; i < 3; i++)
	{
		printf("please input line %d:\n", i + 1);
		fgets(text[i], sizeof(text[i]), stdin);
		for (j = 0; j < 80 && text[i][j] != '\0'; j++)
		{
			if (text[i][j] >= 'A' && text[i][j] <= 'Z')
				upp++;
			else if (text[i][j] >= 'a' && text[i][j]<='z')
				low++;
			else if (text[i][j]>='0'&&text[i][j]<='9')
				dig++;
			else if (text[i][j] == ' ')
				spa++;
			else
				oth++;
		}
	}
	printf("\nupper case: %d\n", upp);
	printf("lower case: %d\n", low);
	printf("digit     : %d\n", dig);
	printf("space     : %d\n", spa);
	printf("other     : %d\n", oth);*/
	//输出第一行第一列;
	/*int a[3][3], i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (i==0||j==0)
				printf("%d", a[i][j]);

		printf("\n");
	}*/
	//十行杨辉三角
	/*int arr[10][10];
	arr[0][0] = 1;
	for (int i = 1; i < 10; i++) {
		arr[i][0] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
		arr[i][i] = 1;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}*/
	//最小值寻找
	int arr[4][5];
	int address_i, address_j;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int min = arr[0][0];
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
				address_i = i;
				address_j = j;
			}
		}
	}
	printf("min=%d,位置在arr[%d][%d]", min, address_i, address_j);
	//输出大写字母
	/*char str[256];
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = 0;
	char* scr = str;
	char daxie[256];
	char* dest = daxie;
	int count = 0;
	while (*scr != '\0') {
		if (*scr >= 'A' && *scr <= 'Z') {
			*dest = *scr;
			dest++;
		}
		scr++;
	}
	*dest = '\0';
	puts(daxie);*/
	//小于平均值的数
	/*char buffer[256];
	int count = 0;
	int arr[5][5];
	while (count < 25) {
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = 0;
		char* take = strtok(buffer, " ");
		for (int i = 0; i < 5; i++) {
			int j = 0;
			while (take != NULL && j < 5) {
				int num = atoi(take);
				if (num >= 10 && num <= 100) {
					arr[i][j] = num;
					count++;
				}
				take = strtok(NULL, " ");
				j++;
			}
		}
		if (count < 25) {
			printf("错误，请重新输入：\n");
			count = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					arr[i][j] = 0;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			sum += arr[i][j];
		}
	}
	int average = sum / 25;
	int arr_low[25];
	count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] < average) {
				arr_low[count] = arr[i][j];
				count++;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		printf("%d ", arr_low[i]);
	}*/
	return 0;
}