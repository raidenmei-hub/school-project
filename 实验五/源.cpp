#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main() {
	//平均成绩
	char buffer[256];
	/*fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = 0;
	int n_student = atoi(buffer);
	int* score = (int*)malloc(n_student * sizeof(int));
	if (score == NULL) {
		return 1;
	}
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = 0;
	char* take = strtok(buffer," \n");
	int i = 0;
	while (take != NULL && i < n_student) {
		score[i] = atoi(take);
		take = strtok(NULL, " \n");
		i++;
	}
	while(i < n_student) {
		score[i] = 0;
		i++;
	}
	int sum=0,average;
	for (int i = 0; i < n_student; i++) {
		sum += score[i];
	}
	average = sum / n_student;
	int count = 0;
	for (int i = 0; i < n_student; i++) {
		if (score[i] < average) {
			count++;
		}
	}
	printf("平均成绩为：%d\n低于平均成绩的学生有：%d", average, count);
	free(score);*/
	//100以内的素数
	/*int sushu[100];
	int count = 0;
	for (int i = 2; i <= 100; i++) {
		int is_prime = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime == 1) {
			sushu[count] = i;
			count++;
		}
	}
	for (int i = 0; i < count; i++) {
		printf("%d ", sushu[i]);
	}*/
	//字符串连接
	/*char str1[100];
	char str2[100];
	char result[200];
	fgets(str1, sizeof(str1), stdin);
	str1[strcspn(str1, "\n")] = 0;
	str1[sizeof(str1) - 1] = '\0';
	fgets(str2, sizeof(str2), stdin);
	str1[strcspn(str2, "\n")] = 0;
	str2[sizeof(str2) - 1] = '\0';
	int length1, length2;
	length1 = strlen(str1);
	length2 = strlen(str2);
	for (int i = 0; i < length1; i++) {
		result[i] = str1[i];
	}
	for (int i = 0; i < length2; i++) {
		result[length1 + i] = str2[i];
	}
	result[length1 + length2] = '\0';
	puts(result);*/
	//半析查找法
	char arr[256];
	int arr_int[256];
	int s, min = 0,high;
	fgets(arr, sizeof(arr), stdin);
	arr[strcspn(arr, "\n")] = 0;
	arr[sizeof(arr) - 1] = '\0';
	char* next_take = NULL;
	char* take = strtok_s(arr, " ",&next_take);
	int count = 0;
	while (take != NULL && count < 256) {
		arr_int[count] = atoi(take);
		count++;
		take = strtok_s(NULL, " ",&next_take);
	}
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = 0;
	s = atoi(buffer);
	high = count-1;
	int target=-1;
	int found = 0;
	while (min<=high) {
		int mid = (min + high) / 2;
		if (arr_int[mid] != s) {
			if (arr_int[mid] < s) {
				min = mid + 1;
			}
			else if (arr_int[mid] > s) {
				high = mid - 1;
			}
		}
		else if(arr_int[mid]==s){
			target = mid+1;
			found = 1;
			break;
		}
	}
	if (found == 1) {
		printf("%d在数组中的位置在%d", s, target);
	}
	return 0;
}