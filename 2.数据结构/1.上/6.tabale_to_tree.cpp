/*************************************************************************
	> File Name: 6.tabale_to_tree.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 19 Nov 2020 08:24:00 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 需要栈和二叉树
// 结点定义
typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;
// 二叉树定义
typedef struct Tree {
    Node *root;
    int n;
} Tree;
// 栈的定义
typedef struct Stack {
    Node **data;  // 存储【Node*】
    int top, size;
} Stack;
// 初始化一个结点
Node *getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;  // 左右孩子指向NULL
    return p;
}
// 初始化一棵二叉树
Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}
// 初始化一个栈
Stack *init_stack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
    s->top = -1;
    s->size = n;
    return s;
}
// 返回栈顶
Node *top(Stack *s) {
    return s->data[s->top];
}
// 判空
int empty(Stack *s) {
    return s->top == -1;
}
// 入栈
int push(Stack *s, Node *val) {
    if (s == NULL) return 0;
    if (s->top == s->size - 1) return 0;  // 栈满？
    s->data[++(s->top)] = val;
    return 1;
}
// 弹栈
int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}
// 回收栈
void clear_stack(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}
// 回收结点
void clear_node(Node *node) {
    if (node == NULL) return ;
    clear_node(node->lchild);  // 递归回收
    clear_node(node->rchild);
    free(node);
    return ;
}
// 回收树
void clear_tree(Tree *tree) {
    if (tree == NULL) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}
// 广义表👉二叉树
Node *build(const char *str, int *node_num) {
    // 初始化一个栈，栈的大小等于字符串长度，肯定够用
    Stack *s = init_stack(strlen(str)); 
    int flag = 0;
    Node *temp = NULL, *p = NULL;  // temp ；p
    while (str[0]) {
        switch (str[0]) {
            // 前面肯定是一个结点
            case '(': {
                push(s, temp);
                flag = 0;     // 控制下一个结点是左孩子
            } break;
            case ')': {
                p = top(s);   // 先用p记录栈顶元素，作为【函数返回】
                pop(s);
            } break; 
            case ',': {
                flag = 1;     // 控制下一个结点是右孩子
            } break;
            case ' ': break;  // 对于空格，直接略去
            // 遇到字符 
            default: {
                // 封装成结点指针
                temp = getNewNode(str[0]);
                // 把当前结点与上一结点建立联系
                // 先判断栈空
                if (!empty(s) && flag == 0) {
                    top(s)->lchild = temp;
                } else if (!empty(s) && flag == 1) {
                    top(s)->rchild = temp;
                }
                ++(*node_num);  // 来一个字符，结点数+1
            } break;
        }
        ++str;  // 改变str的地址，str[0]也会++
    }
    clear_stack(s);            // 栈用毕
    if (temp && !p) p = temp;  // 特判：字符串为'A'，而不是'A()'
    return p;
}
// 三种遍历方式：只需两种就可以确定一棵二叉树
void pre_order_node(Node *root) {
    if (root == NULL) return ;
    printf("%c ", root->data);
    pre_order_node(root->lchild);
    pre_order_node(root->rchild);
    return ;
}
void pre_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("pre_order : ");
    pre_order_node(tree->root);
    printf("\n");
    return ;
}
void in_order_node(Node *root) {
    if (root == NULL) return ;
    in_order_node(root->lchild);
    printf("%c ", root->data);
    in_order_node(root->rchild);
    return ;
}
void in_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return ;
}
void post_order_node(Node *root) {
    if (root == NULL) return ;
    post_order_node(root->lchild);
    post_order_node(root->rchild);
    printf("%c ", root->data);
    return ;
}
void post_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("post_order : ");
    post_order_node(tree->root);
    printf("\n");
    return ;
}
int main() {
    char str[1000] = {0};
    int node_num = 0;  // 记录树的结点数
    // 读取除回车符的所有字符，不把空格当分隔符
    scanf("%[^\n]s", str);
    Tree *tree = getNewTree();
    tree->root = build(str, &node_num);  // node_num 传出参数
    tree->n = node_num;
    // 调用3种遍历
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    // 回收树
    clear_tree(tree);  
    return 0;
}
