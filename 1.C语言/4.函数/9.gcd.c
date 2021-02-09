/*************************************************************************
	> File Name: 9.gcd.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 20 Oct 2020 08:07:13 PM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    //if (!b) return a;
    //return gcd(b , a % b);
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}
