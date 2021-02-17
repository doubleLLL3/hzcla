/*************************************************************************
	> File Name: 14.double_array_trie.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 23 Jan 2021 07:44:40 PM CST
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <cstring>

#define BASE 26
#define Trie 1
#define AC 2

// 带等级的日志信息
#define MSG_LEVEL 1
#define DEBUG_LEVEL 1
#define INFO_LEVEL 2

#define LOG(level, frm, args...) {\
    if (level >= MSG_LEVEL) {\
        printf(frm, ##args);\
    }\
}
#define LOG_DEBUG(args...) LOG(DEBUG_LEVEL, args)
#define LOG_INFO(args...) LOG(INFO_LEVEL, args)

// Trie基本单位
typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

// DAT基本单位 [+ac]
typedef struct DANode {
    int base, check, fail;  // +fail：等价关系
} DANode;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));
    return p;
}

// inline：内联函数，有些类似宏定义
inline int code(char c) { return c - 'a'; }

// 插入：建立Trie
int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = code(str[i]);
        if (p->next[ind] == NULL) {
            cnt += 1;
            p->next[ind] = getNewNode();
        }
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

// 确定base值：粗暴方式
int get_base_value(Node *root, DANode *tree, int ind) {
    int base = 1, flag;
    do {
        base += 1;
        flag = 1;
        // 拟定一个base值，测试所需下标是否已被使用
        for (int i = 0; i < BASE && flag; i++) {
            if (root->next[i] == NULL) continue;
            if (tree[base + i].check) {
                flag = 0;
                break;                                   // 已有爸爸，测试下一个base
            }
        }
    } while (flag == 0);
    return base;
}

// 转换为DAT。返回值：存在的最大下标值
int transform_double_array_trie(Node *root, DANode *tree, int ind) {
    if (root == NULL) return 0;
    if (root->flag) tree[ind].check = -tree[ind].check;  // 若成词，check取负
    int base = get_base_value(root, tree, ind);
    tree[ind].base = base;
    // 依次标记存在的子结点的check
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree[base + i].check = ind;
    }
    int max_ind = ind;
    // 依次确定子结点的base值
    for (int i = 0; i < BASE; i++) {
        int now =  transform_double_array_trie(root->next[i], tree, base + i);
        if (now > max_ind) max_ind = now;                // 更新最大的下标
    }
    return max_ind;
}

// 输出双数组的base和check信息
void dump_double_array_trie(DANode *tree, int n, int type) {
    if (type == 1) {
    // Trie
        LOG_INFO("Based on Trie:\n");
        LOG_INFO("%d\n", n);
        for (int i = 0; i <= n; i++) {
            LOG_INFO("%d %d\n", tree[i].base, tree[i].check);
        }
    } else {
    // AC
        LOG_INFO("Based on AC:\n");
        LOG_INFO("%d\n", n);
        for (int i = 0; i <= n; i++) {
            LOG_INFO("%d %d %d\n", tree[i].base, tree[i].check, tree[i].fail);
        }
    }
    return ;
}

// 转换为基于AC的DAT：增加fail关系
void build_ac_base_double_array_tree(DANode *tree, int max_ind) {
    int *que = (int *)malloc(sizeof(int) * (max_ind + 5));
    int head, tail;
    head = tail = 0;
    tree[1].fail = 0;
    for (int i = 0; i < BASE; i++) {
        int child_ind = tree[1].base + i;
        if (abs(tree[child_ind].check) != 1) continue;   // 子结点的check指向的是根结点自己
        tree[child_ind].fail = 1;
        que[tail++] = child_ind;
    }
    while (head < tail) {
        int p = que[head++];
        for (int i = 0; i < BASE; i++) {
            int c = tree[p].base + i,  k = tree[p].fail;
            if (abs(tree[c].check) != p) continue;       // 子结点的check指向的是自己
            while (k && abs(tree[tree[k].base + i].check) != k)  k = tree[k].fail;
            if (k == 0) k =1;
            if (abs(tree[tree[k].base + i].check) == k) k = tree[k].base + i;
            tree[c].fail = k;
            que[tail++] = c;
        }
    }
    free(que);
    return ;
}

int main() {
    int n, cnt = 1;                                      // cnt：结点数，DAT开辟空间时可参考
    char str[1000];
    scanf("%d", &n);
    // 【一】建立Trie
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    // 【二】转化为DAT
    size_t tree_size = sizeof(DANode) * (cnt * BASE);    // DAT最多需要的存储空间
    DANode *tree = (DANode *)malloc(tree_size);
    memset(tree, 0, tree_size);
    int max_ind = transform_double_array_trie(root, tree, 1);  // 1：根结点下标
    //      比较Trie、DAT的空间大小
    size_t s1 = cnt * sizeof(Node);
    size_t s2 = max_ind * (sizeof(DANode) - sizeof(DANode().fail));
    LOG_DEBUG("trie(%lu bytes), double array trie(%lu byte)\n", s1, s2);
    LOG_DEBUG("rate : %.2lf\n", 1.0 * s2 / s1);
    LOG_DEBUG("-----------------------------------------\n");
    //      输出DAT信息 (索引 | base值, check值)
    for (int i = 0; i <= max_ind; i++) {
        LOG_DEBUG("(%d | %d, %d)\t", i, tree[i].base, tree[i].check);
        if ((i + 1) % 4 == 0) LOG_DEBUG("\n");           // 每行输出4个结果
    }
    LOG_DEBUG("\n-----------------------------------------\n");
    dump_double_array_trie(tree, max_ind, Trie);
    LOG_INFO("-----------------------------------------\n");
    // 【三】转换为基于AC的DAT
    build_ac_base_double_array_tree(tree, max_ind);
    dump_double_array_trie(tree, max_ind, AC);
    free(tree);
    clear_trie(root);
    return 0;
}
