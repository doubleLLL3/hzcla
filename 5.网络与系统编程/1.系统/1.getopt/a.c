/*************************************************************************
	> File Name: a.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 29 Dec 2020 08:08:21 PM CST
 ************************************************************************/

#include <stdio.h>
void input();  // 声明
extern int age;
int main() {
    input();
    printf("double is %d years old!\n", age);
    return 0;
}
