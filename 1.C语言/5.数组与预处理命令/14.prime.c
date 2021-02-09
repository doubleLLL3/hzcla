/*************************************************************************
	> File Name: 14.prime.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 24 Oct 2020 03:50:32 PM CST
 ************************************************************************/

#include <stdio.h>
#define max_n 200000

int prime[max_n + 5];
void init() {
    // i 枚举的M值
    for (int i = 2; i <= max_n; i++) {
        // 打标记
        if (!prime[i]) prime[++prime[0]] = i;
        // 在已有的素数里枚举p值
        for (int j = 1; j <= prime[0]; j++) {
            // 如果打标记的合数已经超出范围了，break
            if (i * prime[j] > max_n) break;
            // prime[j]: p值 i: M值
            prime[prime[j] * i] = 1;
            // ☆如果素数p已经是M的因子了
            // 即小于等于M的最小素因子，是N的最小素因子，break
            if (i % prime[j] == 0) break;
        }
    }

    return ;
}

int main() {
    init();
    // 列出范围内的所有素数
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    // 输出第10001位素数
    printf("%d\n", prime[10001]);
    return 0;
}
