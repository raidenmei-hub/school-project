#include<stdio.h>
#include<stdlib.h>
int main() {
	int n;
	printf("请输入杨辉三角层数");
	if (scanf_s("%d", &n) != 1 || n <= 0) {
		printf("输入错误");
		return 1;
	}
	int** yanghuisanjiao = (int**)malloc(n * sizeof(int*));
	if (yanghuisanjiao == NULL) { // 检查分配是否成功
		printf("内存分配失败\n");
		return 1;
	}
	for (int i = 0; i < n; i++) {
		yanghuisanjiao[i] = (int*)malloc((i+1) * sizeof(int));
		if (yanghuisanjiao[i] == NULL) { // 检查分配是否成功
			printf("内存分配失败\n");
			for (int j = 0; j < i; j++) {
				free(yanghuisanjiao[j]);
			}
			free(yanghuisanjiao);
			return 1;
		}
	}
	yanghuisanjiao[0][0] = 1;
	for (int i = 1; i < n; i++) {
		yanghuisanjiao[i][0] = 1;
		for (int j = 1; j < i; j++) {
			// 移除对 yanghuisanjiao[i-1] 是否为 NULL 的检查，因为前面已确保分配成功
			yanghuisanjiao[i][j] = yanghuisanjiao[i - 1][j - 1] + yanghuisanjiao[i - 1][j];
		}
		yanghuisanjiao[i][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - i - 1; k++) {
			printf("   ");
		}
		for (int j = 0; j <= i; j++) {
			printf("%d ", yanghuisanjiao[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		free(yanghuisanjiao[i]);
	}
	free(yanghuisanjiao);
	return 0;
}