/*************************************************************************
	> File Name: OJ-222.cpp
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
} tree[MAX_N << 2]; 
int arr[MAX_N + 5];  

// 更新最大值
void update(int ind) {
    tree[ind].max_num = max(tree[ind << 1].max_num, tree[ind << 1 | 1].max_num);
    return ;
}

// 建树
void build_tree(int ind, int l, int r) {
    // 此时是一个单点
    if (l == r) {
        tree[ind].max_num = arr[l];  
        return ;
    }
    int mid = (l + r) >> 1;          
    build_tree(ind << 1, l, mid);
    build_tree(ind << 1 | 1, mid + 1, r);
    update(ind);                     // 【建立当前结点】
    return ;
}

// 单点修改【额外传入当前结点所维护的区间范围l ~ r】
void modify(int ind, int l, int r, int k, int val) {
    // 找到了单点
    if (l == r) {
        tree[ind].max_num = val;     
        return ;
    }
    // 如果没有找到，分治
    int mid = (l + r) >> 1;
    if (k <= mid) {
        modify(ind << 1, l, mid, k, val);
    } else {
        modify(ind << 1 | 1, mid + 1, r, k, val);
    }
    update(ind);                     // 更新 [值被修改了]
    return ;
}

// 查询最大值【额外传入当前结点所维护的区间范围l ~ r】
int query(int ind, int l, int r, int x, int y) {
    // 只有当前区间被包含在查询区间 x ~ y 内部时，才返回最大值
    if (l >= x && r <= y) {
        return tree[ind].max_num;
    }
    int ans = INT_MIN;               
    int mid = (l + r) >> 1;
    //【两个if，两边分别判断】
    // 左子树中继续查询
    if (mid >= x) {
        ans = max(ans, query(ind << 1, l, mid, x, y));      // 与ans比较
    }
    // 右子树中继续查询
    if (mid < y) {
        ans = max(ans, query(ind << 1 | 1, mid + 1, r, x, y));
    }
    return ans;
}

int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);             
    // 读入m个操作
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: modify(1, 1, n, b, c); break;
            case 2: {
                if (b > c) {
                    printf("-2147483648\n");
                    break;
                }
                printf("%d\n", query(1, 1, n, b, c));
            } break;
        }
    }
    return 0;
}
