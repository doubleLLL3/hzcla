/*************************************************************************
	> File Name: 3.red_black_tree.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 20 Dec 2020 03:56:11 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int key;
    int color;  // 0：红；1：黑；2：双黑
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = 0;
    p->lchild = p->rchild = NIL;
    return p;
}

// 有/无 至少一个红孩子
int has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

// 左旋：同AVL树
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

// 右旋
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

// 插入调整
Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;                                  // 没有红孩子，不需要调整
    int flag = 0;                                                           // 判断情况2的类型：无冲突、冲突在左、冲突在右
    // 情况一：不管冲不冲突[只要是黑红红，而不管红下面有没有红]，直接👉红黑黑
    if (root->lchild->color == 0 && root->rchild->color == 0) goto insert_end;
        // goto语句 [平时不建议用；不能跳过变量定义，如flag]
    // 情况二：需判断冲突发生在左子树，还是右子树，使用flag标识
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;  // 左子树中发生冲突
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;  // 右子树中发生冲突
    // 无冲突：不调整
    if (flag == 0) return root;
    // 有冲突：旋转[同AVL] + 染色
    if (flag == 1) {
        // LR、LL
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root); 
    } else {
        // RL、RR
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
// 染色：采用红色上浮方式，亦可红色下沉 [此时需区分情况一和情况二]
insert_end:
    root->color = 0;
    root->lchild->color = root->rchild->color = 1;
    return root;
}

// 插入：封装一层
Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key); // 此时插入结点
    if (root->key == key) return root;
    if (key < root->key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);            // 回溯过程中进行调整
}

// 插入 + 染头 [必须的，保证2nd条件；黑结点的来源]
Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = 1;                         // 手动染头【最上头的根结点】
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

// 删除调整
Node *erase_maintain(Node *root) {
    // 没有双黑子结点 不需要调整
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    // 有双黑子结点 开始分情况调整
    // 【特殊情况】 双黑子结点的兄弟结点为红色 → 调整成黑色
    if (has_red_child(root)) {
        int flag = 0;                        // 记录旋转方向
        root->color = 0;                     // 原根结点改成红色
        // 红色在左边/右边 👉 右旋/左旋
        if (root->lchild->color == 0) {
            root = right_rotate(root), flag = 1;
        } else {
            root = left_rotate(root), flag = 2;
        }
        root->color = 1;                      // 新根结点改为黑色
        // 右旋/左旋 👉 双黑结点的父结点分别在右/左子树中
        if (flag == 1) root->rchild = erase_maintain(root->rchild);
        else root->lchild = erase_maintain(root->lchild);
        return root;
    }
    // 【三种情况】双黑子结点点的兄弟结点为黑色
    // [情况一] 双黑子结点的兄弟结点下，没有红孩子
    if ((root->lchild->color == 2 && !has_red_child(root->rchild)) ||
        (root->rchild->color == 2 && !has_red_child(root->lchild))) {
            // 左右子结点减少1重黑(解决了双黑)，根结点增加1重黑
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            root->color += 1;
            return root;
        }
    // [情况二、三] 此时兄弟结点一定有红孩子
    if (root->lchild->color == 2) {
    // LR、LL
        root->lchild->color -= 1;                   // 解决双黑 [顺序无讲究]
        // 非红：可能是黑，可能是双重黑(NIL结点是共用的)
        if (root->rchild->rchild->color != 0) {
            // 原兄弟结点染为红色，小右旋，新兄弟结点染为黑色
            root->rchild->color = 0;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = 1;
        }
        root = left_rotate(root);                   // 大左旋(LR、LL均有)
        root->color = root->lchild->color;          // 新根结点的颜色等于原根结点的颜色
    } else {
    // RL、RR
        root->rchild->color -= 1;
        if (root->lchild->lchild->color != 0) {
            root->lchild->color = 0;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = 1;
        }
        root = right_rotate(root);
        root->color = root->rchild->color;
    }
    root->lchild->color = root->rchild->color = 1;  // 两个新的子结点强制变成黑色
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (key < root->key) {
        root->lchild = __erase(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            // 度为0或1 [度为0的结点的删除👉双重黑]
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;  // 可处理2种情况
            free(root);
            return temp;
        } else {
            // 度为2 [👉度为0或1]
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = 1;  // 强制染黑头
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

// (根结点的颜色 | 根结点的值, 左孩子的值, 右孩子的值)
void print(Node *root) {
    printf("(%d| %d, %d, %d)\n",
          root->color, root->key,
          root->lchild->key,
          root->rchild->key
    );
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root =NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch(op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        output(root);
        printf("-------------\n");
    }
    return 0;
}
