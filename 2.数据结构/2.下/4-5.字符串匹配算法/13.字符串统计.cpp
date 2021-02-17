/*************************************************************************
	> File Name: 13.字符串统计.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 23 Jan 2021 04:33:29 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define BASE 26
#define MAX_N 20000

struct Node {
    int flag, *cnt;         // [trick 2] *cnt：供ans数组取地址
    int next[26], fail;     // [trick 1] 直接使用下标编号
} tree[MAX_N + 5];
int root = 1, cnt = 2, n;   // [trick 1] root：根结点编号，cnt：可用结点的编号
int q[MAX_N + 5], head = 0, tail = 0;
int *ans[MAX_N + 5];        // [trick 2] ans[i]：第i个单词出现的次数；int*：针对模式串重复情况
char str[100005];           // 文本串

// ”装模作样“
int getNewNode() { return cnt++; }

// [trick 2] 插入单词同时，返回对应答案的地址
int *insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNewNode();
        p = tree[p].next[ind];
    }
    tree[p].flag = 1;
    // [注意：模式串可能重复！] 如果cnt已经存在，则使用原有的即可
    if (tree[p].cnt == NULL) {
        tree[p].cnt = (int *)malloc(sizeof(int));
        *tree[p].cnt = 0;
    }
    return tree[p].cnt;
}

void build() {
    head = tail = 0;
    // 初始化根结点
    tree[root].fail = 0;
    // 提前处理根结点下一层子结点
    for (int i = 0; i < BASE; i++) {
        if (tree[root].next[i] == 0) {
            tree[root].next[i] = root;
            continue;
        }
        tree[tree[root].next[i]].fail = root;
        q[tail++] = tree[root].next[i];
    }
    // 处理其它子结点
    while (head < tail) {
        int p = q[head++];            // 取队首；出队
        for (int i = 0; i < BASE; i++) {
            // c：结点的next结点；k：结点的fail结点
            int c = tree[p].next[i], k = tree[p].fail;
            if (c == 0) {
                tree[p].next[i] = tree[k].next[i];
                continue;
            }
            k = tree[k].next[i];
            tree[c].fail = k;
            q[tail++] = c;            // 入队
        }
    }
    return ;
}

void match(const char *str)  {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a', q;
        p = tree[p].next[ind];        // 直接取即可 [路径压缩]
        q = p;
        while (q) {
            if (tree[q].flag) {
                *(tree[q].cnt) += 1;  // [trick 2] *：操作指针cnt的对应值
            }
            q = tree[q].fail;
        }
    }
    return ;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        ans[i] = insert(str);        // [trick 2]
    }
    scanf("%s", str);
    build();
    match(str);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, *ans[i]); // *：取指针ans[i]的对应值 
    }
    return 0;
}

