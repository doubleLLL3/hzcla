/*************************************************************************
	> File Name: 8.factorial.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 17 Oct 2020 08:50:14 PM CST
 ************************************************************************/

#include <stdio.h>

int fac(int n) {
    if (!n) return 1;
    if (n == 1) return 1;
    return n * fac(n - 1);
}
int main() {
    int n;
    while(scanf("%d", &n) != -1) {
        printf("fac(%d) = %d\n", n, fac(n));
    }
    return 0;
}
