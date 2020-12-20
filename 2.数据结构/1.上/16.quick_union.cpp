/*************************************************************************
	> File Name: 16.quick_union.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 27 Nov 2020 08:48:51 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

// 类似数组
typedef struct UnionSet {
    int *father;                                       // 基于代表元素
    //int *size;                                         // 【size】结点所在集合的结点个数
    int n;
} UnionSet;

// 初始化
UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));  // 题意从1开始编号
    //u->size = (int *)malloc(sizeof(int) * (n + 1));    // 每一个元素都对应一个size
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;                              // 初始个体独立，都写成自己的索引
        //u->size[i] = 1;                                // size初始化为1
    }
    return u;
}

// 【查找】返回元素的最终代表元素
int find(UnionSet *u, int x) {
    // 如果代表元素就是自己，什么也不做；否则，就让【它和前面所有的代表元素】的代表元素都指向【根代表元素】
    return u->father[x] = (u->father[x] == x ? x : find(u, u->father[x]));
}

// 【合并】两个元素a、b
int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);              // 先找到a、b的代表元素，存到变量里
    if (fa == fb) return 0;                            // 如果已经连通
    //if (u->size[fa] < u->size[fb]) swap(fa, fb);       // 保证fa是size大的那个代表元素
    u->father[fb] = fa;                                // 谁是父亲无所谓~ 
    //u->size[fa] += u->size[fb];                        // fa的size增加了fb的size大小，fb不需要修改size
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
    //free(u->size);
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
