/*************************************************************************
	> File Name: 7.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 17 Oct 2020 07:33:14 PM CST
 ************************************************************************/

#include <stdio.h>

int rev_num(int n, int base) {
    if (n < 0) return 0;
    int x = n, temp = 0;
    while (x) {
        temp = temp * base + x % base;
        x /= base;
    }
    return temp == n;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", rev_num(n, 10) ? "YES": "NO");
    int x = n, digit = 0;
    while (x) {
        x /= 10;
        digit += 1;
    }
    x = n;
    int digit2 = 0;
    do {
        x /= 10;
        digit2 += 1;
    } while(x);
    printf("%d has %d (while) / %d (do...while) digits.\n", n, digit, digit2);
    return 0;

}
