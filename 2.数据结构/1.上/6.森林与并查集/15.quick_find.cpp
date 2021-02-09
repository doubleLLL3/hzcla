/*************************************************************************
	> File Name: 15.quick_find.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 27 Nov 2020 08:40:00 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// 类似数组
typedef struct UnionSet {
    int *color;                                       // 基于染色
    int n;
} UnionSet;

// 初始化
UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->color = (int *)malloc(sizeof(int) * (n + 1));  // 题意从1开始编号
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->color[i] = i;                              // 初始个体独立，都写成自己的索引
    }
    return u;
}

// 【查找】返回元素的颜色
int find(UnionSet *u, int x) {
    return u->color[x];
}

// 【合并】两个元素a、b
int merge(UnionSet *u, int a, int b) {
    if (find(u, a) == find(u, b)) return 0;           // 如果已经连通
    int color_a = u->color[a];                        // 用变量保存a的颜色，待会a的颜色需要改变
    // 【把与a连通的所有元素的颜色改成b的颜色】
    for (int i = 1; i <= u->n; i++) {
        if (u->color[i] - color_a) continue;          // 对偶逻辑，减少缩进；-代替!=
        u->color[i] = u->color[b];
    }
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->color);
    free(u);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            // 合并
            case 1: merge(u, b, c); break;
            // 判断连通
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No");
                    break;
        }
    }
    clear(u);
    return 0;
}
