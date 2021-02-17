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
    int flag; 
    const char *str;                      // 对于成词结点，存储对应的字符串 [const]
    struct Node *next[BASE], *fail;       // fail：等价匹配关系！
} Node;
int node_cnt = 0;                         // 记录结点数量 [用于建队列，trick]

Node *getNewNode() {
    node_cnt += 1;
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));  // next，初始为无指向结点
    p->fail = NULL;                       // fail，初始指向NULL
    return p;
}

// 插入操作：借鉴Trie
void insert(Node *root, const char *str) {
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (root->next[ind] == NULL) root->next[ind] = getNewNode();
        root = root->next[ind];
    }
    root->flag = 1;
    root->str = strdup(str);              // 要复制过来用，后面str值可能会改变
    return ;
}

// 在Trie上建立AC自动机
void build_ac(Node *root) {
    // 1、申请存放结点地址的队列 [大小最大为结点数量]
    Node **q = (Node **)malloc(sizeof(Node *) * (node_cnt + 5));  
    int head = 0, tail = 0;
    root->fail = NULL;                                          // 根结点的fail为NULL
    q[tail++] = root;                                           // 入队
    // 2、用队首结点的fail信息，初始化所有子结点的fail
    while (head < tail) {
        Node *p = q[head++];                                    // 出队：当前结点
        for (int i = 0; i < BASE; i++) {
            // 0] 定义变量。c：某子结点，k：当前结点的fail结点 [等价关系]
            Node *c = p->next[i], *k = p->fail;
            // 1] 如果c不存在，就不需要找c的等价匹配关系了
            if (c == NULL) continue;
            // 2] 如果k存在，但k对应子结点不存在，就往上找等价关系
            while (k && k->next[i] == NULL) k = k->fail;        // 终点是根结点的fail：NULL
            // 3] 没有找到除root外c的等价关系 [则默认为root]
            if (k == NULL) k = root;
            // 3] 找到了除root外c的等价关系
            else if (k->next[i]) k = k->next[i];
            // 【注意上一行】 
            //  1) 如果直接使用if，则初始需要入队根结点的所有子结点(条件A)，并将它们的fail默认指向root
            //      否则 [未考虑第一次循环p为root的情况]
            //          会让root的子结点的fail都指向子结点自己 [因为root->next[i]必然指向子结点自己]，
            //          从而导致后面的子结点也都指向自己，最终在匹配时陷入死循环
            //      而基于条件A
            //          在k==NULL成立时，说明上面while循环中k->next[i]一直是NULL，包括root->next[i]
            //          故不会满足上一行判断
            //  2) 如果使用else if，就不用考虑root的子结点了，也就没这么多事了
            // 4] 给c的fail赋值等价关系
            c->fail = k;
            q[tail++] = c;                                      // 入队：下一结点
        }
    }
    free(q);
    return ;
}

// 多模匹配过程
void match(Node *root, const char *text) {
    Node *p = root, *q;                                         // p：当前结点位置 [当前状态]，q：
    // 遍历文本串
    for (int i = 0; text[i]; i++) {
        0 && printf("input %c\n", text[i]);
        // 1、状态转移
        int ind = text[i] - 'a';                                // 要找的匹配边
        while (p && p->next[ind] == NULL)  p = p->fail;         // 循环，找可成功匹配点 【可优化】
        if (p == NULL) p = root;
        if (p->next[ind]) p = p->next[ind];
        // 2、取词
        q = p;                                                  // 借助q回溯，不改变p的位置
        while (q) {
            if (q->flag == 1) printf("find: %s\n", q->str);
            q = q->fail;
        }
        // 【注意】 不仅要判断当前结点的成词情况，还要考虑等价结点的
        // if (p->flag == 1) printf("%s\n", p->str);            // 所以会漏判
    }
    return ;
}

void clear(Node *root)  {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
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
    // 建立好Trie后，再建立fail指针 -> AC自动机
    build_ac(root);
    printf("ac built!\n");
    scanf("%s", str);                                           // 读入文本串
    match(root, str);
    clear(root);
    return 0;
}
