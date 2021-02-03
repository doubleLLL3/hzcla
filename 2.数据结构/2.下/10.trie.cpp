/*************************************************************************
	> File Name: 10.trie.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 13 Jan 2021 09:15:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 26

typedef struct Node {
    int flag;                 // 当前结点前[含]的字符串是否独立成词
    struct Node *next[BASE];  // 可理解为指向BASE个结点的边：某边有指向的结点则代表该字母存在
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;                          // 默认不成词
    memset(p->next, 0, sizeof(p->next));  // 可理解为：26条边初始没有指向的结点，即赋值为空
    return p;
}

// 插入一个单词：不会改变根结点地址，返回void
void insert(Node *p, const char *s) {
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';             // 对应哪一条边 / 结点 [子集合] 2种理解
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();  // 申请一个结点接收边 [如果不存在]
        p = p->next[i];                                         // 走动到下一结点
    }
    p->flag = 1;                                                // 标记成词
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

// 字符串排序 [深度优先遍历] 
// 【妙】k：当前字母是单词的第k位 [层数]，s：存储单词的字符串
void output(Node *root, int k, char *s) {
    s[k] = 0;                             // 末尾先放置'\0'字符 [随时准备输出，插入时未放置'\0']
    if (root->flag) {
        printf("%s\n", s);
    }
    // 依次遍历BASE个分支
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        s[k] = 'a' + i;
        output(root->next[i], k + 1, s);
    }
    return ;
}

int main() {
    int n;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    output(root, 0, str);
    clear(root);
    return 0;
}
