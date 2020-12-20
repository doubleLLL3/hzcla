/*************************************************************************
	> File Name: 12.hash_table.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 21 Nov 2020 08:15:26 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 字符串结点定义
typedef struct Node {
    char *str;    // 存储字符串首地址
    struct Node *next;
} Node;
// 哈希表的结构定义，与顺序表一致
typedef struct HashTable {
    Node **data;  // 拉链法，存储一个链表组成的顺序表，每一位存储一个链表首地址Node*
    int size;
} HashTable;
// 初始化结点：将字符串封装成结点，再插入到所在链表的头部head前
Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;  // 头插法
    return p;
}
// 初始化哈希表
HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;// 考虑哈希表的空间利用率50~90%，所以开辟空间扩大一倍
    h->data = (Node **)calloc(h->size, sizeof(Node *));        // calloc开辟，初始化为0
    return h;
}
// 哈希函数：BKDRHash，别人发明的
int BKDRHash(char *str) {
    int seed = 31, hash = 0;   // seed可以设置成任意素数
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];  // 一定是32位，int类型
    return hash & 0x7fffffff;  // 对于溢出产生的负数，按位与0111111...111将其变成正数
}
// 插入：向哈希表插入字符串
int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);                                  // 将字符串映射成数组下标
    int ind = hash % h->size;                                  // 哈希值%哈希表大小 得 下标
    h->data[ind] = init_node(str, h->data[ind]);               // 插入到所在位置的链表头部
    return 1;
}
// 查询：返回找到与否
int search(HashTable *h, char *str) {
    // 通过哈希值得到下标，定位到所在位置的链表头结点
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;              // 逐个比较是否相等
    return p != NULL;                                          // 返回查找成功与否的结果
}
// 回收结点
void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    // 逐个回收
    while (p) {
        q = p->next;           // 回收p前，先用q记录p->next
        free(p->str);          // strdup出来的需要free
        free(p);
        p = q;
    }
    return ;
}
// 回收哈希表
void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    // 先逐个释放哈希表每个位置的链表
    for (int i = 0; i < h->size; i++) {
        clear_node(h->data[i]);
    }
    // 再释放哈希表
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    #define max_n 100
    char str[max_n + 5] = {0};
    HashTable *h = init_hashtable(max_n + 5);
    while (~scanf("%d%s", &op, str)) {
        // 更新str是换地址还是覆盖判断\0即可？[个人理解] 覆盖，\0变了，所以不会与之前的冲突
        switch (op) {
            case 0:
                printf("insert %s to HashTable\n", str);
                insert(h, str);  // 插入输入的字符串str
                break;
            case 1:
                printf("search %s from HashTable result = %d\n", str, search(h, str));
        }
    }
    #undef max_n
    clear_hashtable(h);
    return 0;
}
