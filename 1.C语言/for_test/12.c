/*************************************************************************
	> File Name: 12.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 04:51:27 PM CST
 ************************************************************************/

#include <stdio.h>
#define max_n 200000

int prime[max_n + 5];
void init() {
    for (int i = 2; i < max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] >= max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }

}

int main() {
    init();
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    printf("10001：%d\n", prime[10001]);
    return 0;
}
