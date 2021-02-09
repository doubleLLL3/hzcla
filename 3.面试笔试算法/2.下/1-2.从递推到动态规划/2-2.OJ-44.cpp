/*************************************************************************
	> File Name: OJ-44.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 27 Dec 2020 08:19:35 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX_N 1000000
int dp;                                            // 实际上不需要开数组，因为每次只用到dp[i]的值
int len[MAX_N + 5];                                // 需要维护的单调数组

// 特殊二分：000000111111，找第一个1，即第一个>=x的值的索引
int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

int main() {
    int n, ans = 0, val;                           // ans：当前最大长度；val：一次读一个即可
    scanf("%d", &n);                               // 加速
    memset(len, 0x3f, sizeof(len));                // 先均设置为极大值 <cstring>
    len[0] = 0;                                    // 再将第0位设为极小值，保证单调性
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val);
        dp = binary_search(len, ans + 1, val);     // dp代表长度；+1代表加入一个元素后，长度最多增加1
        len[dp] = val;                             // 维护len数组，时刻保证【单调性】
        ans = max(dp, ans);                        // ans更新最大长度
    }
    printf("%d\n", ans);
    return 0;
}
