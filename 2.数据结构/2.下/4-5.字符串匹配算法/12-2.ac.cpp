/*************************************************************************
	> File Name: 12.ac.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 23 Jan 2021 03:05:18 PM CST
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

#define BASE 26

typedef struct Node {
    int flag, tag[BASE];     // 【优化相关】tag 此结点是否原生 -> 0：ac优化 1：trie原生
    const char *str;
    struct Node *next[BASE], *fail;
} Node;
int node_cnt = 0; 

Node *getNewNode() {
    node_cnt += 1;
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
        root->tag[ind] = 1;                  // 标记next[ind]为原生结点
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
    // 提前处理：root的下一层 【优化版必须】
    for (int i = 0; i < BASE; i++) {
        // 【优化】
        if (root->next[i] == NULL) {
            root->next[i] = root;            // 单独处理root的next
            continue;
        }
        // [普通版]
        // if (root->next[i] == NULL) continue;  
        root->next[i]->fail = root;
        q[tail++] = root->next[i];
    }
    while (head < tail) {
        Node *p = q[head++];
        for (int i = 0; i < BASE; i++) {
            Node *c = p->next[i], *k = p->fail;
            // 【优化】 
            if (c == NULL) {
                // 1) 直接指向p'对应的next结点 [具有传递性，不可能为NULL，最坏指向root]
                p->next[i] = k->next[i];
                continue;
            }
            k = k->next[i];  // 2) 因为提前处理，p非root，k不可能为NULL；层序遍历，k->next[i]也不可能为NULL
            // [普通版]
            /*
            if (c == NULL) continue;
            while (k && k->next[i] == NULL) k = k->fail;
            if (k == NULL) k = root;
            if (k->next[i]) k = k->next[i];
            */
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
        p = p->next[ind];    // 【优化】可直接得到下一状态
        q = p;
        while (q) {
            if (q->flag == 1) printf("find: %s\n", q->str);
            q = q->fail;
        }
    }
    return ;
}

void clear(Node *root)  {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        // 只clear原生的边，否则会重复free
        if (root->tag[i]) clear(root->next[i]);
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
    clear(root);
    return 0;
}
