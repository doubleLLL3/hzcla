/*************************************************************************
	> File Name: HZOJ-223.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 26 Dec 2020 08:26:56 PM CST
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
#define MAX_N 10000
#define define_mid long long mid = (l + r) >> 1
int flag = 0;

struct {
    long long sum, tag;   // 存储和值sum、懒标记tag
} tree[MAX_N << 2];
long long arr[MAX_N + 5]; // 一维区间的数组

// 向上更新
void update(long long ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
    return ;
}

// 下沉标记
void down(long long ind, long long l, long long r) {
    if (tree[ind].tag) {
        long long val = tree[ind].tag;
        define_mid;
        // 修改左、右子树的和值、懒标记
        tree[ind << 1].sum += val * (mid - l + 1);  // 【用于向上更新】
        tree[ind << 1].tag += val;
        tree[ind << 1 | 1].sum += val * (r - mid);
        tree[ind << 1 | 1].tag += val;
        // 清除懒标记     
        tree[ind].tag = 0;  
    }
    return ;
}

// 建树
void build_tree(long long ind, long long l, long long r) {
    if (l == r) {
        tree[ind].sum = arr[l];                     // 注意区分树的索引和数组的索引
        return ;
    }
    define_mid;                                     // 使用宏
    build_tree(ind << 1, l, mid);                   // 建立左子树
    build_tree(ind << 1 | 1, mid + 1, r);           // 建立右子树
    update(ind);                                    //【向上更新】发生在子树信息改变完以后
    return ;
}

// 区间修改
void modify(long long ind, long long l, long long r, long long x, long long y, long long val) {
    flag && printf("modify(%lld, %lld, %lld) : %lld, %lld, %lld, %lld\n",
                    x, y, val, ind, l, r, tree[ind].sum
    );
    if (x <= l && r <= y) {
        tree[ind].sum += val * (r - l + 1);         // 记录好和值【用于向上更新】
        tree[ind].tag += val;                       // 打上懒标记【可叠加】
        return ;
    }
    down(ind, l, r);    // 下沉标记【不只是区间查询的时候，必须有！否则在向上更新时可能引发问题】
    define_mid;
    if (mid >= x) {
        modify(ind << 1, l, mid, x, y, val);
    }
    if (mid < y) {
        modify(ind << 1 | 1, mid + 1, r, x, y, val);
    }
    update(ind);                                    // 更新根结点信息
    return ;
}

// 区间查询 [类似基础版线段树]
long long query(long long ind, long long l, long long r, long long x, long long y) {
    flag && printf("query(%lld, %lld) : %lld, %lld, %lld, %lld\n",
                    x, y, ind, l, r, tree[ind].sum
    );  
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    down(ind, l, r);                                // 下沉标记
    define_mid;
    long long ans = 0;
    // 计算和值，使用 +=
    if (mid >= x) {
        ans += query(ind << 1, l, mid, x, y);
    }
    if (mid < y) {
        ans += query(ind << 1 | 1, mid + 1, r, x, y);
    }
    return ans;
}

int main() {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", arr + i);                     // 读入一维数组
    }
    build_tree(1, 1, n);                            // 建立线段树
    long long a, b, c, d;                           // 还需要读入的值
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        switch (a) {
            case 1: {
                scanf("%lld", &d);
                modify(1, 1, n, b, c, d);           // 根结点维护的区间范围：1 ~ n
            } break;
            case 2: {
                if (b > c) {
                    printf("0\n");
                    break;
                }
                printf("%lld\n", query(1, 1, n, b, c));
            } break;
        }
    }
    return 0;
}
