/*************************************************************************
	> File Name: OJ-222-lr.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 26 Dec 2020 07:27:21 PM CST
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
#include <climits>
using namespace std;
#define MAX_N 10000

struct {
    int max_num;     // 只需要存储最大值
    int l, r;        // 当前结点所代表的区间范围【其实没有必要存储】
} tree[MAX_N << 2];  // 完全二叉树需4n个结点空间
int arr[MAX_N + 5];  // 读入的数组

// 更新最大值
void update(int ind) {
    tree[ind].max_num = max(tree[ind << 1].max_num, tree[ind << 1 | 1].max_num);
    return ;
}

// 建树
void build_tree(int ind, int l, int r) {
    tree[ind].l = l, tree[ind].r = r;
    // 此时是一个单点
    if (l == r) {
        tree[ind].max_num = arr[l];  // 更新最大值
        return ;
    }
    int mid = (l + r) >> 1;          // 分裂的中值索引
    build_tree(ind << 1, l, mid);
    build_tree(ind << 1 | 1, mid + 1, r);
    update(ind);                     // 【建立当前结点】
    return ;
}

// 单点修改
void modify(int ind, int k, int val) {
    // 找到了单点
    if (tree[ind].l == tree[ind].r) {
        tree[ind].max_num = val;     // 修改最大值即可
        return ;
    }
    // 如果没有找到，分治
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    if (k <= mid) {
        modify(ind << 1, k, val);
    } else {
        modify(ind << 1 | 1, k, val);
    }
    update(ind);                     // 更新 [值被修改了]
    return ;
}

// 查询最大值
int query(int ind, int x, int y) {
    // 只有当前区间被包含在查询区间 x ~ y 内部时，才返回最大值
    if (tree[ind].l >= x && tree[ind].r <= y) {
        return tree[ind].max_num;
    }
    int ans = INT_MIN;               // <climits>
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    //【两个if，两边分别判断】
    // 左子树中继续查询
    if (mid >= x) {
        ans = max(ans, query(ind << 1, x, y));      // 与ans比较
        // 区间仍为x ~ y，而不可以是x ~ mid [因为若y < mid，则会扩大区间，下面同理]
    }
    // 右子树中继续查询
    if (mid < y) {
        ans = max(ans, query(ind << 1 | 1, x, y));
    }
    return ans;
}

int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);             // 线段树的根结点索引从1开始[完全二叉树]，范围为1 ~ n
    // 读入m个操作
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: modify(1, b, c); break;
            case 2: {
                if (b > c) {
                    printf("-2147483648\n");
                    break;
                }
                printf("%d\n", query(1, b, c));
            } break;
        }
    }
    return 0;
}
