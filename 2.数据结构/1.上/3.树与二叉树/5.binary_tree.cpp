/*************************************************************************
	> File Name: 5.binary_tree.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 19 Nov 2020 07:26:33 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 结点定义
typedef struct Node {
    int data;                      // 数值
    struct Node *lchild, *rchild;  // 左、右孩子
} Node;
// 二叉树定义
typedef struct Tree {
    Node *root;  // 根结点
    int n;       // 结点个数
} Tree;
// 初始化一个结点
Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}
// 初始化一棵树
Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}
// 清空一个结点
void clearNode(Node *node) {
    if (node == NULL) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}
// 清空一棵二叉树
void clear(Tree *tree) {
    if (tree == NULL) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}
// 插入结点，返回当前二叉树的根结点
Node *insert_node(Node *root, int val, int *flag) {
    if (root == NULL) {
        *flag = 1;                       // 插入成功
        return getNewNode(val);          // 直接创建根结点
    } 
    if (root->data == val) return root;  // 如果重复，不做操作
    // <则向左子树插入，>则向右子树插入
    if (val < root->data) root->lchild = insert_node(root->lchild, val, flag);
    else root->rchild = insert_node(root->rchild, val, flag);
    return root;
}
// 构建二叉查找[排序、搜索]树：左孩子<根<右孩子 BSTree
void insert(Tree *tree, int val) {
    int flag = 0;                                      // 反映插入状态
    tree->root = insert_node(tree->root, val, &flag);  // flag 传出参数
    tree->n += flag;
    return ;
}
// 前序遍历内部：根→左→右
void pre_order_node(Node *node) {
    if (node == NULL) return;  // 为空时不做操作
    printf("%d ", node->data);
    pre_order_node(node->lchild);
    pre_order_node(node->rchild);
    return ;
}
// 前序遍历
void pre_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("pre_order : ");
    pre_order_node(tree->root);// 从根进入
    printf("\n");
    return ;
}
// 中序遍历内部：左→根→右
void in_order_node(Node *node) {
    if (node == NULL) return;
    in_order_node(node->lchild);
    printf("%d ", node->data);
    in_order_node(node->rchild);
    return ;
}
// 中序遍历
void in_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return ;
}
// 后序遍历内部：左→右→根
void post_order_node(Node *node) {
    if (node == NULL) return;
    post_order_node(node->lchild);
    post_order_node(node->rchild);
    printf("%d ", node->data);
    return ;
}
// 后序遍历
void post_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("post_order : ");
    post_order_node(tree->root);
    printf("\n");
    return ;
}
// 打印结点，按广义表形式
void output_node(Node *root) {
    if (root == NULL) return ;
    printf("%d", root->data);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    output_node(root->lchild);
    printf(", ");
    output_node(root->rchild);
    printf(")");
}
// 打印二叉树
void output(Tree *tree) {
    if (tree == NULL) return ;
    printf("tree(%d) : ", tree->n);
    output_node(tree->root);  // 沿着根结点打印
    printf("\n");
    return ;
}
int main() {
    srand(time(0));
    Tree *tree = getNewTree();
    #define max_op 10
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    // 三种遍历方式
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    #undef max_op
    clear(tree);
    return 0;
}
