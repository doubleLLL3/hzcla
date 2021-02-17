/*************************************************************************
	> File Name: 7.string_match.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 13 Jan 2021 09:48:39 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

// [BF-1]——通俗版。s：文本串，t：模式串
int brute_force_1(const char *s, const char *t) {
    // 1、从文本串第i位开始匹配 [i从0开始]
    for (int i = 0; s[i]; i++) {
        int flag = 1;                           // 匹配成功标志
        for (int j = 0; t[j]; j++) {
            // 2、正在匹配各自偏移j位
            if (s[i + j] && s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;                     // 返回成功匹配的首位索引
    }
    return -1;                                  // 没找到
}
// [BF-2]——简洁版
int brute_force_2(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;            
        // 利用flag做终止条件
        for (int j = 0; t[j] && flag; j++) {
            flag = (s[i + j] && s[i + j] == t[j]);
        }
        if (flag) return i;     
    }
    return -1;      
}

// [KMP-1-NEXT]——获取next数组
void getNext_1(const char *t, int *next) {
    next[0] = -1;                                 // 初始化，第0位没有对应的前缀
    int j = -1;                                   // j：上一位的next值
    for (int i = 1; t[i]; i++) {
        // 停止条件：j == -1 或者 对应相等
        while (j != -1 && t[j + 1] - t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }
    return ;
}

// [KMP-1]——普通版，易理解
int kmp_1(const char *s, const char *t) {
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * (n + 1));
    getNext_1(t, next);
    // 1、遍历文本串每一位 j：当前成功匹配到了模式串的第j位
    for (int i = 0, j = -1; s[i]; i++) {
        // 2、类似获取next数组过程
        while (j != -1 && s[i] - t[j + 1]) j = next[j];
        if (s[i] == t[j + 1]) j += 1;             // 成功匹配了1位
        if (t[j + 1] == 0) return i - n + 1;      // 下一位为'\0'字符，匹配成功
    }
    free(next);                                   // 释放动态开辟的空间
    return -1;
}

// [KMP-2-NEXT]——获取next值  j：代表一个状态，input：要匹配的字符
int getNext_2(const char *t, int &j, char input, int *next) {
    while (j != -1 && t[j + 1] != input) j = next[j];
    if (t[j + 1] == input) j += 1;
    return j;
}

// [KMP-2]——状态机版，基于状态机的思想 [高级]
int kmp_2(const char *s, const char *t) {
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * (n + 1)); 
    next[0] = -1;                                            // 初始化next[0]
    // 1、可理解为：状态机的状态转移过程
    for (int i = 1, j = -1; t[i]; i++) next[i] = getNext_2(t, j, t[i], next);
    for (int i = 0, j = -1; s[i]; i++) {
        // 2、同获取next数组过程；喂入一个s[i]，状态机改变一下状态
        if (getNext_2(t, j, s[i], next) != n - 1) continue;  // 未完全匹配
        return i - n + 1;
    }
    free(next);                                 
    return -1;
}

// [SUNDAY]
int sunday(const char *s, const char *t) {
    int offset[256];                                  // 256：扩展ASCII码数，用来标记字符
    int n = strlen(t), m = strlen(s);
    for (int i = 0; i < 256; i++) offset[i] = n + 1;  // 初始化：都没有出现
    // 1、记录字符出现的位置 [倒数]
    //  [PS] 后面相同字符的位置会覆盖前面的
    for (int i = 0; t[i]; i++) offset[t[i]] = n - i;  //  字符t[i]出现在倒数第 n - i 位
    // 2、当在母串首位为s[i]时失配，查找黄金对齐点位字符s[i + n]对应offset
    //  [PS] i + n <= m：剩余足够匹配
    for (int i = 0; i + n <= m; i += offset[s[i + n]]) {
        // 3、类似BF
        int flag = 1;
        for (int j = 0; t[j] && flag; j++) {
            flag = (s[i + j] == t[j]);
        }
        if (flag) return i;
    }
    return -1;
}

// [SHIFT-AND]
int shift_and(const char *s, const char *t) {
    int d[256] = {0}, n = 0;                              // d：编码数组，n：记录模式串长度
    for (int i = 0; t[i]; n++, i++) d[t[i]] |= (1 << i);  // 建立d
    int p = 0;                                            // 初始化状态p
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & d[s[i]];                       // 转移过程
        // p的第n位为1，匹配成功
        if (p & (1 << (n - 1))) return i - n + 1;         // 匹配完成
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (scanf("%s%s", s, t) != EOF) {
        printf("brute_force-1(%s, %s) = %d\n", s, t, brute_force_1(s, t));
        printf("brute_force-2(%s, %s) = %d\n", s, t, brute_force_2(s, t));
        printf("kmp-1(%s, %s) = %d\n", s, t, kmp_1(s, t));
        printf("kmp-2(%s, %s) = %d\n", s, t, kmp_2(s, t));
        printf("sunday(%s, %s) = %d\n", s, t, sunday(s, t));
        printf("shift_and(%s, %s) = %d\n", s, t, shift_and(s, t));
        printf("--------------------------------\n");
    }
    return 0;
}
