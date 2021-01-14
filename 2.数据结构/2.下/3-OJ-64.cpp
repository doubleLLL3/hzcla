/*************************************************************************
	> File Name: HZOJ-64.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 20 Dec 2020 03:56:11 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int key;
    int color;  
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

int has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;                                  // 没有红孩子，不需要调整
    int flag = 0;                                                           // 判断情况2的类型：无冲突、冲突在左、冲突在右
    if (root->lchild->color == 0 && root->rchild->color == 0) goto insert_end;
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;  // 左子树中发生冲突
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;  // 右子树中发生冲突
    if (flag == 0) return root;
    if (flag == 1) {
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root); 
    } else {
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
insert_end:
    root->color = 0;
    root->lchild->color = root->rchild->color = 1;
    return root;
}

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

Node *erase_maintain(Node *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    if (has_red_child(root)) {
        int flag = 0;                        // 记录旋转方向
        root->color = 0;                     // 原根结点改成红色
        if (root->lchild->color == 0) {
            root = right_rotate(root), flag = 1;
        } else {
            root = left_rotate(root), flag = 2;
        }
        root->color = 1;                      // 新根结点改为黑色
        if (flag == 1) root->rchild = erase_maintain(root->rchild);
        else root->lchild = erase_maintain(root->lchild);
        return root;
    }
    if ((root->lchild->color == 2 && !has_red_child(root->rchild)) ||
        (root->rchild->color == 2 && !has_red_child(root->lchild))) {
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            root->color += 1;
            return root;
        }
    if (root->lchild->color == 2) {
        root->lchild->color -= 1;                   // 解决双黑[可提前]
        if (root->rchild->rchild->color != 0) {
            root->rchild->color = 0;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = 1;
        }
        root = left_rotate(root);                   // 大左旋(LR、LL均有)
        root->color = root->lchild->color;          // 新根结点的颜色等于原根结点的颜色
    } else {
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
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;  // 可处理2种情况
            free(root);
            return temp;
        } else {
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

void print(Node *root) {
    printf("%d %d %d %d\n",
          root->key, root->color,
          root->lchild->key,
          root->rchild->key
    );
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    print(root);
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
            case 3: output(root);
        }
    }
    return 0;
}
