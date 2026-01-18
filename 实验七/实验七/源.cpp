#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
int GCD(int m, int n) {
	while (m, n) {
		(m > n) ? (m %= n) : (n %= m);
		return m + n;
	}
}
int lcm = 0,gcd;
int small;
int LCM(int m, int n) {
	if (lcm == 0) {
		lcm = (m > n) ? m : n;
		small = (m < n) ? m : n;
	}
	if (lcm % small == 0) {
		return lcm;
	}
	else {
		lcm += (m > n) ? m : n;
			return LCM(m,n);
	}
}
/*int Fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	else {
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}*/
/*int M(int m) {
	if (m % 3 == 0 || m % 5 == 0) {
		return 1;
	}
	else
		return 0;
}*/
//void ex(int, int);
/*void func(int a, int b)
{
	int temp = a;
	a = b; b = temp;
}*/
//int func2(int, int);
/*int func1(int a, int b)
{
	int c;
	a += a;
	b += b;
	c = func2(a, b);
	return(c * c);
}
int func2(int a, int b)
{
	int c;
	c = a * b % 3;
	return (c);
}*/
int main()
{
	//ex函数
	/*int a = 1, b = 2;
	ex(a, b);
	printf("a = %d, b = %d\n", a, b);*/
	//func函数
	/*int x, y;
	x = 10; y = 20;
	func(x, y);
	printf(" % d, % d\n", x, y);*/
	//func1，func2
	/*int x = 7, y = 17;
	printf("%d\n", func1(x, y));*/
	//找100到200中能被3整除的数
	/*for (int i = 100; i <= 200; i++) {
		if (M(i) == 1 && i % 3 == 0) {
			printf("%d ", i);
		}
	}*/
	//斐波那契数列前n项
	/*int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("%d ", Fibonacci(i));
	}*/
	//最大公约数，最小公倍数
	int m, n;
	scanf("%d%d", &m, &n);
	gcd = GCD(m, n);
	lcm = LCM(m, n);
	printf("gcd=%d,lcm=%d", gcd, lcm);
	return 0;
	}
/*void ex(int x, int y)
{
	x++;
	++y;
	printf("x = %d, y = %d\n", x, y);
}*/
