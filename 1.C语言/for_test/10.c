/*************************************************************************
	> File Name: 10.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 04:16:34 PM CST
 ************************************************************************/

#include <stdio.h>

int fac(int n) {
    if (!n) return 1;
    return n * fac(n - 1);
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        printf("fac(%d) = %d\n", n, fac(n));
    }
    return 0;
}
