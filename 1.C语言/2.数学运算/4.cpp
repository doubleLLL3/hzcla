/*************************************************************************
	> File Name: 4.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 15 Oct 2020 08:33:24 PM CST
 ************************************************************************/

#include <stdio.h>

int main () {
    // 简单运算
    int a = 7, b = 3, c;
    //c = a; // += -= *=
    a += 7;  // a= a + 7
    
    // 运算符优先级演示
    int *p = &a;
    (*p)--;  // a--, *p需要加括号提高运算优先级
    printf("a = %d, b = %d\n", a, b);
 
    // 交换变量值
    // 使用中间变量
    int temp = a;
    a = b;
    b = temp;
    printf("swap by temp: a = %d, b = %d\n", a, b);
    // 不使用中间变量，使用异或
    a ^= b;
    b ^= a;
    a ^= b;
    printf("swap by xor ^: a = %d, b = %d\n", a, b);
    return 0;
}
