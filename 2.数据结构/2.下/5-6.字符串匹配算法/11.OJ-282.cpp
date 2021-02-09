/*************************************************************************
	> File Name: 11.OJ-282.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 13 Jan 2021 09:56:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
#define BASE 31
struct Node {
    Node *next[2];                   // 两个结点指针：0、1 [二进制数字定长，不需要成词flag]
} tree[MAX_N * BASE + 5];            // 直接开辟好所有结点空间
int cnt = 0;                         // cnt：待使用的下一个结点下标

Node *getNode() {
    return &tree[cnt++];             // 顺序使用结点，返回其地址即可 [如此简单]
}

// 以二进制形式插入数字
void insert(Node *root, int x) {
    // 从高位到低位：i << 30->0 —— 数字第31->1位
    for (int i = 30; i >= 0; i--) {
        int ind = !!(x & (1 << i));  // 判断第i + 1位是否为1，再逻辑归一化：0、1 [next下标]
        // 是否已存在需要的结点
        if (root->next[ind] == NULL) root->next[ind] = getNode();
        root = root->next[ind];      // 往下走
    }
    return ;
}

// 与x能求得的最大异或值
int query(Node *root, int x) {
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int ind = !(x & (1 << i));   // 取出x第i + 1位的值，并取非 [找该位不同的边]
        if (root->next[ind]) {
            // 存在该位不同的数字集合
            ans |= (1 << i);         // 答案在该位为1 [熟练位运算]
            root = root->next[ind];  // 往值为ind的边往下走
        } else {
            root = root->next[!ind]; // !ind
        }
    }
    return ans;
}

int n;
int val[MAX_N + 5];                  // 输入数组

int main() {
    cin >> n;
    int ans = 0, a;
    // 初始化字典树，并插入一个数供后续query
    Node *root = getNode();
    cin >> a, n--;
    insert(root, a);
    // 先查询再插入 [不用和自己异或]
    while (n--) {
        cin >> a;
        ans = max(query(root, a), ans);
        insert(root, a);
    }
    cout << ans << endl;
    return 0;
}
