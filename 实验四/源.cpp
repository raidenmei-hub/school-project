# include <stdio.h>  
# include <math.h>
void scanf_clear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int gcd(int i, int j) {
    while (i && j) {
        (i > j) ? (i %= j) : (j %= i);
    }
    return i + j;
}
int main()
{
    //例1.1
   /* int m, i;
    scanf_s("%d", &m);
    for (i = 2; i<m; i++)
        if (m%i==0)
            break;
    if (m==i)
        printf("Yes\n");
    else
        printf("No\n");*/
    //例2.1
    /*int i, j, x = 0;
    for (i = 0; i < 2; i++)
    {
        x++;
        for (j = 0; j <= 3; j++)
        {
            if (j % 2)
                continue;
            x++;
        }
        x++;
    }
            printf("x = %d\n", x);*/
    //例2.2
    /*int i;
    for (i = 1; i <= 5; i++)
    {
        if (i % 2)
            printf("*");
        else
            continue;
        printf("#");
    }
    printf("$\n");*/
    //例3.1
    /*int ou_sum = 0, ji_sum = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2)
            ji_sum += i;
        else
            ou_sum += i;
    }
    printf("ou_sum=%d\nji_sum=%d\n", ou_sum, ji_sum);*/
    //阶乘
    /*for (int i = 1; i <= 10; i++) {
        int cheng = 1;
        for (int j = 1; j <= i; j++) {
            cheng *= j;
        }
        if (cheng >= 10000)
            break;
        printf("%d ", cheng);
    }*/
    //莲花数
    /*for (int i = 99; i < 1000; i++) {
        int temp = i;
        int arr[3];
        int j = 0;
        while (temp > 0) {
           arr[j] = temp % 10;
            temp = temp / 10;
            j++;
        }
        int sum=0;
        for (int m = 0; m < 3; m++) {
            sum += pow(arr[m],3);
        }
        if (i == sum) {
            printf("%d ", i);
        }
    }*/
    //最大公约数，最大公倍数；
    int a, b;
    printf("请输入两个整数：");
    while (1) {
        int result=scanf_s("%d%d", &a, &b);
        if ( result== 2) {
            int next_char = getchar();
            if (next_char == '\n'||next_char==EOF) {
                break;
            }
            else {
                printf("输入包含非法字符，请重新输入：");
                if (next_char != EOF) {
                    scanf_clear();
                }
            }
        }
        else if (result == 1) {
            printf("第二个数请输入整数：");
            scanf_clear();
        }
        else {
            printf("输入格式错误，请重新输入：");
            scanf_clear();
        }
    }
    printf("最大公约数为：%d\n", gcd(a, b));
    for (int i = 1;; i++) {
        if (i % a == 0 && i % b == 0) {
            printf("最小公倍数为：%d", i);
            break;
        }
    }
    return 0;
}