/*************************************************************************
	> File Name: 2.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 06 Dec 2020 10:01:30 AM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
    int *father;
    int length;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
    }
    u->length = n;
    return u;
}

int find(UnionSet *u, int x) {
    if (u->father[x] == x) return x;
    return u->father[x] = find(u, u->father[x]);
}

void merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    u->father[fa] = fb;
    return ;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
    free(u);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    UnionSet *u = init(n);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1) {
            merge(u, b, c);
        } else if (a == 2) {
            printf("%s\n", ((find(u, b) == find(u, c)) ? "Yes" : "No"));
        }
    }
    return 0;
}
