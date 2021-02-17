/*************************************************************************
	> File Name: 9.OJ-275.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 13 Jan 2021 06:58:46 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
#define P 10007          // 模数
#define base 13          // 位权
long long K[MAX_N + 5];  // base数组：K[i] = base ^ i % P
long long H[MAX_N + 5];  // 基于哈希的前缀和数组：H[i] = (H[i - 1] + s[i] * K[i]) % P
long long inv[P];        // 逆元数组
char s[MAX_N + 5];

// [初始化] 逆元数组、base数组、前缀和 [注意取余操作，以及每个数组的范围]
void init() {
    inv[1] = 1;
    for (long long i = 2; i < P; i++) {
        // 求逆元 [正数]
        inv[i] = ((-(P / i) * inv[P % i]) % P + P) % P;
    }
    K[0] = 1;
    for (long long i = 1; i <= MAX_N; i++) {
        K[i] = (K[i - 1] * base) % P;
    }
    H[0] = 0;
    for (long long i = 1; s[i]; i++) {
        H[i] = (H[i - 1] + s[i] * K[i]) % P;
    }
    return ;
}

// [哈希操作] 字符串->哈希值
long long getH(long long l, long long r) {
    // 注意保持哈希值为正 [H数组不是单调递增的]
    return ((H[r] - H[l - 1]) % P * inv[K[l]] % P + P) % P;
}

// [暴力匹配] 顺序比较一轮即可，2个字符串等长
long long isSame(long long i, long long j, long long n) {
    for (long long k = 0; k < n; k++) {
        if (s[i + k] - s[j + k]) return false;
    }
    return true;
}

int main() {
    scanf("%s", s + 1);                 // 从1开始读
    long long m, l1, l2, r1, r2;
    init();
    scanf("%lld", &m);
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
        long long val1 = getH(l1, r1);  // 区间1对应的哈希值
        long long val2 = getH(l2, r2);  // 区间2对应的哈希值
        long long n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;
        if (n1 - n2 || val1 - val2) {
            // 长度或哈希值之一不相等相等
            printf("No\n");
        } else {
            // 否则，再进行暴力匹配
            if (isSame(l1, l2, n1)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
