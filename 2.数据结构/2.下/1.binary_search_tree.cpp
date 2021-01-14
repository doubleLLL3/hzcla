/*************************************************************************
	> File Name: 1.binary_search_tree.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 19 Dec 2020 10:00:49 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define KEY(n) (n ? n->key : -1)                                    // -1：表示NULL
#define SIZE(n) (n ? n->size : 0)
#define L(n) (n ? n->lchild : NULL)

// 底层是二叉树，增加了size字段
typedef struct Node {
    int key, size;                                                  // size 结点所在子树的结点数量
    struct Node *lchild, *rchild;
} Node;

// 初始化：返回存储key值的结点Node结构
Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->size = 1;
    p->lchild = p->rchild = NULL;
    return p;
}

// 更新size
void update_size(Node *root) {
    root->size = SIZE(root->lchild) + SIZE(root->rchild) + 1;
    return ;
}

// 查找：返回int——有/无
int search(Node *root, int val) {
    if (root == NULL) return 0;                                    
    if (root->key == val) return 1;                                 // 递归应考虑边界条件
    if (val < root->key) return search(root->lchild, val);
    return search(root->rchild, val);
}

// 排名：查找排名第k的元素，返回元素值 [假设k合理]
int search_k(Node *root, int k) {
    if (root == NULL) return -1;
    if (k == SIZE(L(root)) + 1) return root->key;                   // 边界条件
    if (k < SIZE(L(root)) + 1) {
        return search_k(root->lchild, k);
    }
    return search_k(root->rchild, k - SIZE(L(root)) - 1);           // 更新要找的k
    // SIZE(L())的写法有点像函数式编程
}

// 插入：因为根结点有可能改变，所以返回根结点的地址
Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);                       // 成功插入
    if (root->key == key) return root;                              // 不重复插入
    if (key < root->key) root->lchild = insert(root->lchild, key);  // 同样可能修改根结点
    else root->rchild = insert(root->rchild, key);
    update_size(root);
    return root;
}

// 前驱：只是查找【度为2】的结点前驱
Node *predecessor(Node *root) {
    Node *temp = root->lchild;                                      // 先到左子树
    while (temp->rchild) temp = temp->rchild;                       // 再一直找右子结点
    return temp;
}

// 删除：同样可能修改根结点
Node *erase(Node *root, int key) {
    if (root == NULL) return NULL;
    if (key < root->key) {
        root->lchild = erase(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = erase(root->rchild, key);
    } else {
        // 【找到了待删除的结点】
        if (root->lchild == NULL || root->rchild == NULL) {
            // 度为0和度为1时 [都可以这样操作]
            //   找到唯一子结点 [度为0时为NULL]
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);                                             // 防止内存泄漏
            return temp;  // 只有这里是返回temp[其他情况都返回root]，因为要free root
        } else {
            // 度为2时 [找前驱，覆盖根结点的值，删前驱->度最多为1]
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_size(root);                                              // 只需修改root的，temp的不变
    return root;
}

// 销毁
void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

// 结点展示方式
void print(Node *root) {
    printf("(%d[%d], %d, %d)\n",                                    // 打印结点所在子树的结点数量
           KEY(root), SIZE(root), 
           KEY(root->lchild), KEY(root->rchild)
    );
    return ;
}

// 中序遍历
void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    print(root);
    output(root->rchild);
    return ;
}

// Top-k
void output_k(Node *root, int k) {
    if (k == 0 || root == NULL) return ;
    if (k < SIZE(L(root)) + 1) {
        // 直接输出左子树中前k位元素
        output_k(root->lchild, k);
    } else {
        // 输出左子树所有元素 + 根结点 + 右子树部分元素
        output(root->lchild);
        print(root);
        output_k(root->rchild, k - SIZE(L(root)) - 1);
    }
    return ;
}

int main() {
    int op, val;
    Node *root = NULL;  // 记得先定义根结点
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: printf("search %d, result : %d\n------------\n", val, search(root,val)); break;
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: {
                printf("search k = %d, result : %d\n",
                       val, search_k(root, val));
                printf("------------\n");
            } break;
            case 4: 
                printf("output top-%d element.\n", val);
                output_k(root, val);
                printf("------------\n");
                break;
        }
        // 插入或删除后输出树形结构
        if (op == 1 || op == 2) {
            output(root);
            printf("------------\n");
        }
    }
    return 0;
}
