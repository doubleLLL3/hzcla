/*************************************************************************
	> File Name: 21.OJ-333.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 12 Jan 2021 08:00:40 PM CST
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
#define MAX_N 500000
#define L(ind) (ind << 1)
#define R(ind) (ind << 1 | 1)
#define SUM(ind) tree[ind].sum
#define INMAX(ind) tree[ind].inmax
#define LMAX(ind) tree[ind].lmax
#define RMAX(ind) tree[ind].rmax
// 6个方便操作的宏

struct Data{
    int sum, inmax, lmax, rmax;                                  // 0、存sum，大大方便操作
} _tree[(MAX_N << 2) + 5];
// 设置一个地址偏移，统一右移一个单位 
// <多出两个操作空间tree[-1]、tree[0]，实际对应_tree[0]、_tree[1]，线段树从_tree[2]存起>
Data *tree = _tree + 1;  
int n, m, flag;
int val[MAX_N + 5];

// 1、向上更新 传入三个参数：本身下标及左、右子树的下标；需要更新：所有字段
void UP(int a, int b, int c) {
    SUM(a) = SUM(b) + SUM(c);
    LMAX(a) = max(LMAX(b), SUM(b) + LMAX(c));                    // L：左L or 左S+右L
    RMAX(a) = max(RMAX(c), SUM(c) + RMAX(b));                    // R：右R or 右S+左R 
    INMAX(a) = max(max(INMAX(b), INMAX(c)), RMAX(b) + LMAX(c));  // IN：左IN or 右IN or 左R+右L
    return ;
}

// 建立线段树
void build(int ind, int l, int r) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = val[l];  // 到达叶结点
        return ;
    }
    int mid = (l + r) >> 1;
    build(L(ind), l, mid);                                       // 左子树
    build(R(ind), mid + 1, r);                                   // 右子树
    UP(ind, L(ind), R(ind));                                     // 向上更新
    return ;
}

void modify(int ind, int l, int r, int i, int x) {
    // 找到了具体要修改的位置下标
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = x;
        return ;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
        modify(L(ind), l, mid, i, x);
    } else {
        modify(R(ind), mid + 1, r, i, x);
    }
    // 向上更新
    UP(ind, L(ind), R(ind));
    return ;
}

// 查询 [PS：待查询区间x、y一直不变]
void query(int ind, int l, int r, int x, int y) {
    // 2、从左到右多个小答案，两两合并为最终答案
    if (x <= l && r <= y) {
        // 2-1、flag = 1：第一次查到结果，初始化tree[0] [此结点原本没使用]
        //      <此处flag判断可用l == x代替，即第一次结果，最左边的>
        if (flag) {
            tree[0] = tree[ind]; 
            flag = 0;
        } else {
            // 2-2、将当前存的结果tree[0]、此次的结果tree[ind]整合，暂存到tree[-1]中
            //      再迁移到tree[0]
            UP(-1, 0, ind); 
            tree[0] = tree[-1];
        }
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        query(L(ind), l, mid, x, y);
    }
    if (y > mid) {
        query(R(ind), mid + 1, r, x, y);
    }
    return ;
}

void solve() {
    //ios::sync_with_stdio(false);         // 关闭同步流 [60->80]
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", val + i);
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        switch (k) {
            // 查询：区间最大连续子段和
            case 1: {
                if (x > y) swap(x, y);     // 题意
                flag = 1;
                query(1, 1, n, x, y);
                printf("%d\n", INMAX(0));  // 0号位存答案
            } break;
            // 修改：单点
            case 2: {
                modify(1, 1, n, x, y);
            } break;
        }
    }
}

int main() {
    solve();
    return 0;
}
