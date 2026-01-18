#include <stdio.h>
#include <string.h>
#include<math.h>
#include"stuff.h"
int check(
    char sex[],//性别
    long long idCard,//身份证号（改为long long）
    int month,
    int date,
    long long phoneNumber,//手机号（改为long long）
    int age) {

    // 身份证号检验（18位）
    int idCardDigits = 0;
    long long temp = idCard;
    while (temp > 0) {
        temp /= 10;
        idCardDigits++;
    }

    // 手机号检验（11位）
    int phoneDigits = 0;
    temp = phoneNumber;
    while (temp > 0) {
        temp /= 10;
        phoneDigits++;
    }

    if (//性别检验
        (strcmp(sex, "男") == 0 || strcmp(sex, "女") == 0)
        //身份证号检验（18位）
        && (idCardDigits == 18)
        //月份检验
        && (month >= 1 && month <= 12)
        //日期检验
        && (date >= 1 && date <= 31)
        //手机号检验（11位）
        && (phoneDigits == 11)
        //工龄检验
        && (age >= 0 && age <= 60)) {
        return 1;
    }
    else return 0;
}