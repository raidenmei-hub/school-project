#include<stdio.h>
#include<math.h>
int main() {
	//实验二题1：
	/*int a, b;
	float x, y;
	char c1, c2;
	scanf_s("a=%db=%d", &a, &b);
	scanf_s("%f%e", &x, &y);
	scanf_s(" %c%c", &c1,1,&c2,1);
	printf("a=%d,b=%d,x=%f,y=%f,c1=%c,c2=%c\n", a, b, x, y, c1, c2);*/
	//实验二题2：
	/*int i = 8, j = 10;
	int m, n;

	m = ++i;
	n = j++;
	printf(" i = %d \n", i);
	printf(" m = %d \n", m);
	printf(" j = %d \n", j);
	printf(" n = %d \n", n);*/
	/*int i = 8, j = 10;
	printf(" %d，%d\n", i++,--j);*/
	//实验二题4I
	/*char daxie[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
		xiaoxie[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' },
		shuru,
		jilu[100];
	int i, count=0,found=0,j=0;
	while (count <= 100) {
		printf("请输入需要查询小写的字母：");
		scanf_s(" %c", &shuru, 1);
		if ((65 > shuru) || (shuru > 90 && shuru < 96) || (shuru > 123)) {
			printf("请输入字母！\n");
			continue;
		}
		int repeat = 0;
		for (int n = 0; n < j; n++) {
			if (jilu[n] == shuru) {
				repeat = 1;
				break;
			}
		}
		if (repeat == 1) {
			printf("该字母小写已在前面显示，请重新输入\n");
			continue;
		}
		for (i = 0; i < 26; i++) {
			if (daxie[i] == shuru) {
				found = 1;
				break;
			}
		}
		printf("小写字母为：%c\n", xiaoxie[i]);
		jilu[j] = shuru;
		j++;
		count++;
	}
	printf("超过程序内存");*/
	//实验二题4II
	/*float r, h;
	double c, s, S, Vq, Vz;
	printf("圆半径为：");
	scanf_s("%f", &r);
	printf("圆柱高为：");
	scanf_s("%f", &h);
	c = 2 * 3.14 * r;
	s = 3.14 * r * r;
	S = 4 * 3.14 * r * r;
	Vq = 4 * 3.14 * r * r * r / 3;
	Vz = s * h;
	printf("圆周长为：%.2f\n圆面积为：%.2f\n圆球表面积为：%.2f\n圆球体积为：%.2f\n圆柱体积为：%.2f", c, s, S, Vq, Vz);*/
	//实验二题4III
	/*int x;
	printf("请输入一个三位数：");
	scanf_s("%d", &x);
	printf("该数的百位数为%d，该数的十位数为%d，该数的个位数为%d", x / 100, (x / 10) % 10, x % 10);*/
	double a, b, c,n[3];
	double C,S;
	printf("请输入一个三角形的三边长：");
	scanf_s("%lf%lf%lf", &a, &b, &c);
	n[0] = a + b;
	n[1] = a + c;
	n[2] = b + c;
	for (int i = 0; i <= 2; i++) {
		if (a >= n[i] || b >= n[i] || c >= n[i]) {
			printf("该三角形不存在");
			return 0;
		}
	}
	C = a + b + c;
	S = pow((1 - ((a * a + b * b - c * c) / (2 * a * b)) * ((a * a + b * b - c * c) / (2 * a * b))), 0.5) * a * b / 2;
	printf("该三角形周长为：%.2f，面积为%.2f", C, S);
	return 0;
}