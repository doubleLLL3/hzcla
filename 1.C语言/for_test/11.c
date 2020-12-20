/*************************************************************************
	> File Name: 11.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 04:28:12 PM CST
 ************************************************************************/

#include <stdio.h>
#define max_n 100

int prime[max_n + 5] = {0};
void init() {
    for (int i = 2; i < max_n; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        for (int j = i * 2; j < max_n; j += i) {
            prime[j] = 1;
        }
    }
}
int main() {
    init();
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}
