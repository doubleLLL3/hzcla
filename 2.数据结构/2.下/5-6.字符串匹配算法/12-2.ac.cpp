/*************************************************************************
	> File Name: 12.ac.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 23 Jan 2021 03:05:18 PM CST
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
#include <cstring>
using namespace std;

#define BASE 26

typedef struct Node {
    int flag, tag[BASE];  // tag：是否原生/优化加上的：1：trie，0：ac
    const char *str;
    struct Node *next[BASE], *fail;
} Node;
int node_cnt = 0; 

Node *getNewNode() {
    node_cnt++;
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));
    p->fail = NULL;  
    return p;
}

void insert(Node *root, const char *str) {
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (root->next[ind] == NULL) root->next[ind] = getNewNode();
        root->tag[ind] = 1;
        root = root->next[ind];
    }
    root->flag = 1;
    root->str = strdup(str);
    return ;
}

void build_ac(Node *root) {
    Node **q = (Node **)malloc(sizeof(Node *) * (node_cnt + 5));
    int head = 0, tail = 0;
    root->fail = NULL;
    // 不放root，放root下一层
    for (int i = 0; i < BASE; i++) {
        // 优化
        if (root->next[i] == NULL) {
            root->next[i] = root;
            continue;
        }
        // if (root->next[i] == NULL) continue;  // 原
        root->next[i]->fail = root;
        q[tail++] = root->next[i];
    }
    while (head < tail) {
        Node *p = q[head++];
        for (int i = 0; i < BASE; i++) {
            Node *c = p->next[i], *k = p->fail;
            // 优化 
            if (c == NULL) {
                p->next[i] = k->next[i];  // 直接指向fail的next
                continue;
            }
            //if (c == NULL) continue;
            // 是否也可以去掉
            while (k && k->next[i] == NULL) k = k->fail;
            if (k == NULL) k = root;
            if (k->next[i]) k = k->next[i];  // 可以if，不用else if
            c->fail = k;
            q[tail++] = c;
        }
    }
    free(q);
    return ;
}

void match(Node *root, const char *text) {
    Node *p = root, *q;
    for (int i = 0; text[i]; i++) {
        0 && printf("input %c\n", text[i]);
        int ind = text[i] - 'a';
        // 优化
        p = p->next[ind];
        q = p;
        while (q) {
            if (q->flag == 1) printf("find: %s\n", q->str);
            q = q->fail;
        }
        //if (p->flag == 1) printf("%s\n", p->str);
    }
    return ;
}

void clear(Node *root)  {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        if (root->tag[i]) clear(root->next[i]);  // 判断是字典树的边时再向下clear
    }
    free(root);
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
    build_ac(root);
    printf("build ac!\n");
    scanf("%s", str);
    match(root, str);
    return 0;
}
