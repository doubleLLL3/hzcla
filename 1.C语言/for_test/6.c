/*************************************************************************
	> File Name: 6.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 03:28:34 PM CST
 ************************************************************************/

#include <stdio.h>

int rev_num(int n, int base) {
    if (n < 0) return 0;
    int raw = n, rev = 0;
    while (n) {
        rev = rev * base + n % base;
        n /= 10;
    }
    return raw == rev;
}

int main() {
    int n, base;
    while (~scanf("%d%d", &n, &base)) {
        printf("%d is rev_num based %d? : %s\n", n, base, rev_num(n, base) ? "Yes" : "No");
    }

    return 0;
}
