/*************************************************************************
	> File Name: 2.avl.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 19 Dec 2020 03:47:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define H(n) (n->h)

typedef struct Node {
    int key, h;                                                         // h：AVL树的精髓
    struct Node *lchild, *rchild;
} Node;

// 虚拟空结点NIL：替代NULL，这样可以访问成员
Node __NIL;                                                             // NIL：NULL Is Legal
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0, NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;                                    // 左右子结点也都指向NIL
    return ;
}

// 初始化：类似二叉排序树
Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key= key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

// 更新树高
void update_height (Node *root) {
    root->h = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;  // max(左, 右) + 1
    return ;
}

// 左旋
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;      // 技巧：定义temp，记录根的右子结点 → 新的根结点temp
    root->rchild = temp->lchild;    // 将temp的左子树 [挂到] 旧的根结点root的右边 [root右边与temp失去连接]
    temp->lchild = root;            // 更新temp的左子树 [为] 旧的根结点root [temp与原来的左子树失去连接]
    update_height(root);            // 先更新root，再更新temp 【因为root在底下了】
    update_height(temp);            // 在小左旋时，树高会改变
    return temp;                    // 返回新的根结点
}

// 右旋：与左旋对称即可
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

// 平衡调整：返回Node*，同样可能改变根结点地址
Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root; // 平衡，不需要调整
    // 在这引入了虚拟空结点的定义：NIL
    //   否则，每次还得判断root相关是不是NULL，为了防止访问NULL的成员时出错
    if (root->lchild->h > root->rchild->h) {
    // 【L起手】
        // 判断是不是LR
        if (root->lchild->lchild->h < root->lchild->rchild->h) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);                      // LL、LR都需要大右旋
    } else {
    // 【R起手】
        // 判断是不是RL
        if (root->rchild->rchild->h < root->rchild->lchild->h) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);                       // RR、RL都需要大左旋
    }
}

// 增：插入 + 调整；返回Node *，因为根结点有可能改变
Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);            // 插入操作
    if (root->key == key) return root;
    if (key < root->key) {
        root->lchild = insert(root->lchild, key);
    } else {
        root->rchild = insert(root->rchild, key);
    }
    update_height(root);                                // 维护树高
    return maintain(root);                              // 回溯时，进行平衡调整
}

// 找前驱：仅针对度为2的结点
Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    // 判断NIL
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

// 删
Node *erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (key < root->key) {
        root->lchild = erase(root->lchild, key);
    } else if (key> root->key) {
        root->rchild = erase(root->rchild, key);
    } else {
        // 此时可以进行删了
        if (root->lchild == NIL || root->rchild == NIL) {
            // 判断NIL
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            free(root);
            return temp;                                // 此处不需要平衡调整，temp下都没有子结点
        } else {
            // 找前驱，替换，删前驱
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_height(root);
    return maintain(root);
}

// 销毁
void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root) {
    printf("(%d[%d], %d, %d)\n",
        root->key, root->h,
        root->lchild->key,
        root->rchild->key
    );
    return ;
}

// 前序遍历输出 [方便画树]
void output(Node *root) {
    if (root == NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch(op) {
            case 0: root = erase(root, val); break;
            case 1: root = insert(root, val); break;
        }
        output(root);
        printf("----------------------\n");
    }
    return 0;
}
