/*************************************************************************
	> File Name: 14.double_array_trie.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 23 Jan 2021 07:44:40 PM CST
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
#define MSG_LEVEL 1
#define DEBUG_LEVEL 1
#define INFO_LEVEL 2

#ifdef DEBUG
#define LOG(level, frm, args...) {\
    if (level >= MSG_LEVEL) {\
        printf(frm, ##args);\
    }\
}
#else
#define LOG(level, frm, args...)
#endif

#define LOG_DEBUG(args...) LOG(DEBUG_LEVEL, args)
#define LOG_INFO(args...) LOG(INFO_LEVEL, args)

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

typedef struct DANode {
    int base, check, fail;
} DANode;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));
    return p;
}

inline int code(char c) { return c - 'a'; }

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        cnt += 1;

        int ind = code(str[i]);
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;

}

void clear_trie(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear_trie(root->next[i]);
    }
    free(root);
    return ;
}

int get_base_value(Node *root, DANode *tree, int ind) {
    int base = 1, flag;
    do {
        base += 1;
        flag = 1;
        for (int i = 0; i < BASE && flag; i++) {
            if (root->next[i] == NULL) continue;
            if (tree[base + i].check) flag = 0;
        }
    } while (flag == 0);
}

int transform_double_array_trie(Node *root, DANode *tree, int ind) {
    if (root == NULL) return 0;
    if (root->flag) tree[ind].check = -tree[ind].check;  // 成词
    int base = get_base_value(root, tree, ind);
    tree[ind].base = base;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree[base + i].check = ind;
    }
    int max_ind = ind;
    for (int i = 0; i < BASE; i++) {
       int a =  transform_double_array_trie(root->next[i], tree, base + i);
        if (a > max_ind) max_ind = a;
    }
    return max_ind;
}

void dump_double_array_trie(DANode *tree, int n) {
    LOG_INFO("");
}

void build_ac_base_double_array_tree(DANode *tree, int max_ind) {
    int *que = (int *)malloc(sizeof(int) * (max_ind + 5));
    int head, tail;
    head = tail = 0;
    tree[1].fail = 0;
    for (int i = 0; i < BASE; i++) {
        int child_ind = tree[1].base + i;
        if (abs(tree[child_ind].check) != 1) continue; 
        tree[child_ind].fail = 1;
        que[tail++] = child_ind;
    }
    while (head < tail) {
        int p = que[head++];
        for (int i = 0; i < BASE; i++) {
            int c = tree[p].base + i,  k = tree[p].fail;
            if (abs(tree[c].check) != p) continue;
            while (k && abs(tree[tree[k].base + i].check) != k)  k = tree[k].fail;
            if (k == 0) k =1;
            if (abs(tree[tree[k].base + i].check) == k) k = tree[k].base + i;
            tree[c].fail = k;
            que[tail++] = c;
        }
    }
    free(tree);
    return ;
}

int main() {
    int n, cnt = 1;  // 
    char str[1000];
    scanf("%d", &n);
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    size_t tree_size = sizeof(DANode) * (cnt * BASE);
    DANode *tree = (DANode *)malloc(tree_size);  // 先开辟出这么多
    memset(tree, 0, tree_size);
    int max_ind = transform_double_array_trie(root, tree, 1); 
    size_t s1 = cnt * sizeof(Node);
    size_t s2 = max_ind * sizeof(DANode);
    printf("trie(%lu Byte), double array trie(%lu Byte)\n", s1, s2);
    printf("rate : %.2lf\n", 1.0 * s2 / s1);
    for (int i = 0; i <= max_ind; i++) {
        LOG_DEBUG()
        LOG_DEBUG("(%d | %d, %d)\t", i, tree[i].base, tree[i].check);
        if ((i + 1) % 4 == 0) LOG_DEBUG("\n");
    }
    LOG_DEBUG("\n");
    build_ac_base_double_array_tree(tree, max_ind);
    free(tree);
    clear_trie(root);

    return 0;
}
