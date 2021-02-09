/*************************************************************************
	> File Name: 2.list.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 12 Nov 2020 06:16:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)
// 链表结点结构体
typedef struct ListNode {
    int data;
    struct ListNode *next;  // 自己的别名还没生效
} ListNode;
// 链表整体
typedef struct List {
    ListNode head;  // 虚拟头结点，第一个结点的前一个结点
    int length;     // 链表长度
} List;
// 可以先声明函数，函数定义放后面
ListNode *getNewNode(int);    // 初始化结点，返回结点首地址
List *getLinkList();          // 初始化链表，返回链表首地址
void clear_node(ListNode *);  // 销毁结点
void clear(List *);           // 清空链表
int insert(List *, int, int);
int erase(List *, int);
void output(List *);
void reverse(List *);         // 翻转链表~

int main() {
    srand(time(0));
    #define max_op 20
    List *l = getLinkList();
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;  // 让测试数据更完备
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1: {
                printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf("erase a item at %d from List = %d\n", ind, erase(l, ind));
            } break;
            case 3: {
                printf(GREEN("reverse the list!\n"));
                reverse(l);
            } break;
        }
        output(l), printf("\n");
    }
    #undef max_op
    clear(l);
    return 0;
}

ListNode *getNewNode(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

List *getLinkList() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;  // 定义第一个结点为NULL
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;  // 插入范围：0 ~ l->length
    ListNode *p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;  // 从虚拟头结点向后走ind步
    // 安全的操作顺序
    node->next = p->next;
    p->next =  node;
    l->length += 1;  // 记得长度加一
    return 1;
}

int erase(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while (ind--) p = p->next;  // 好技巧
    q = p->next;  // 用q记录一下待删结点，待会需要free
    p->next = q->next;
    free(q);
    l->length -= 1;
    return 1;
}

void reverse(List *l) {
    if (l == NULL) return ;
    ListNode *p = l->head.next, *q;  // q记录p->next
    l->head.next = NULL;            // 先将虚拟头结点指向NULL
    while (p) {
        q = p->next;                 // 不要失去p->next的地址
        p->next = l->head.next;      // 注意顺序，双指向，不丢失
        l->head.next = p;
        p = q;
    }
    return ;
}

void output(List *l) {
    if (l == NULL) return ;
    printf("List(%d) = [", l->length);
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL]\n");  // 最后指向空地址
    return ;
}

void clear_node(ListNode *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear(List *l) {
    if (l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);  // 最后释放整个链表
    return ;
}
