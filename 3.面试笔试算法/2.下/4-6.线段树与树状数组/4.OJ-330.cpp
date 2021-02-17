/*************************************************************************
	> File Name: 17.OJ-330.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 12 Jan 2021 11:26:37 AM CST
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
#define MAX_N 100000
long long c[2][MAX_N + 5];  // 两个树状数组：X、k * X [均与差分数组相关]
#define lowbit(x) (x & -x)  // lowbit

// 1-1、单点修改 [k：指定维护第k个树状数组]
void add(long long k, long long i, long long x, long long n) {
    while (i <= n) {
        c[k][i] += x;
        i += lowbit(i);
    }
    return ;
}

// 2-1、差分数组的前缀和 [等价于单点查询]
long long query(long long k, long long i) {
    long long sum = 0;
    while (i) {
        sum += c[k][i];
        i -= lowbit(i);
    }
    return sum;
}

// 1-2、整合的单点修改 [同时维护2个差分数组，两者是相关联的！]
void modify(long long i, long long x, long long n) {
    add(0, i, x, n);
    add(1, i, i * x, n);
    return ;
}

// 2-2、原序列的前缀和 [<==2个差分数组的前缀和]
long long S(long long i) {
    return (i + 1) * query(0, i) - query(1, i);
}

int main() {
    long long n, m, l, r, d;
    //char s;                    // 直接用char字符方式时，使用scanf读取字符要注意[换行符]的存在
    char s[10];                  // 用字符数组读 [scanf时不会有换行符的干扰]
    scanf("%lld%lld", &n, &m);
    // 0、存储差分数组 [2个]
    for (long long i = 1, pre = 0, a; i <= n; i++) {
        scanf("%lld", &a);
        modify(i, a - pre, n);   // a - pre = 当前值 - 前一位值 [原序列]
        pre = a;                 // 记得更新pre值
    }
    for (long long i = 0; i < m; i++) {
        scanf("%s", s);
        /* 
         * -> char方式：每次需要吞掉上一次的换行符 [如果使用scanf读取char，而不是cin时]
        getchar();             
        scanf("%c", &s);
        switch (s) {
        */
        switch (s[0]) {
            // 1-3、区间修改 => 两次单点修改
            case 'C': {
                scanf("%lld%lld%lld", &l, &r, &d);
                modify(l, d, n);
                modify(r + 1, -d, n);
            } break;
            // 2-3、区间查询 => 前缀和相减
            case 'Q': {
                scanf("%lld%lld", &l, &r);
                printf("%lld\n", S(r) - S(l - 1));
            } break;
        }
    }
    return 0;
}
