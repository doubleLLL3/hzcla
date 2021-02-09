/*************************************************************************
	> File Name: 4.haffman.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 26 Dec 2020 04:48:00 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

// 定义树结点：哈夫曼编码需要基于树
typedef struct Node {
    char ch;            // 当前结点代表的字符
    double p;           // 当前结点的概率值
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char ch, double per) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->p = per; 
    p->lchild = p->rchild = NULL;
    return p;
}

// 合并结点【建立关系的关键】
Node *combineNode(Node *a, Node *b) {
    Node *p = getNewNode(0, a->p + b->p);
    p->lchild = a;
    p->rchild = b;
    return p;
}

// 找到最小值，放在第n位上
void pick_min(Node **arr, int n) {
    for (int j = n - 1; j >= 0; --j) {
        if (arr[j]->p < arr[n]->p) {
            swap(arr[n], arr[j]);
        }
    }
    return ;
}

// 建树，返回树的根结点地址
Node *getHaffmanTree(Node **arr, int n) {
    // n个结点需要合并n - 1次才能形成一棵树
    for (int i = 1; i < n; i++) {
        // 先找两个概率最小的结点地址【可用堆优化】
        pick_min(arr, n - i);           // 最后一位存放最小值
        pick_min(arr, n - i - 1);       // 倒数第2位存放次小值
        // 更新倒数第2位的概率参加后续的合并 [每轮循环比较的范围缩小1]
        arr[n - i - 1] = combineNode(arr[n - i], arr[n - i - 1]);
    }
    return arr[0];                      // 根结点存在arr[0]中，结点之间的关系已建立
}

// 递归，提取字符的编码
void __output_encode(Node *root, char *str, int k) {
    str[k] = 0;                         // 即字符串终止符：'\0'
    // 如果是叶子结点，则对应一个字符
    if (root->lchild == NULL && root->rchild == NULL) {
        printf("%c %s\n", root->ch, str);
        return ;
    }
    // 左0、右1
    str[k] = '0';
    __output_encode(root->lchild, str, k + 1);
    str[k] = '1';
    __output_encode(root->rchild, str, k + 1);
    return ;
}

// 输出编码
void output_encode(Node *root) {
    char str[100];                      // 编码数组
    __output_encode(root, str,  0);     // k代表在第k位上添加01编码
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {
    int n;                              // 有n个字符
    Node **arr;                         // 存储的是字符结点组成的数组
    scanf("%d", &n);
    arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        char ch[10];                    // 建议使用字符串的形式读入，减少出错率
        double p;
        scanf("%s%lf", ch, &p);
        arr[i] = getNewNode(ch[0], p);
    }
    Node *root = getHaffmanTree(arr, n);// 建立哈夫曼树
    output_encode(root);                // 输出每个字符的编码
    clear(root);
    free(arr);
    return 0;
}
