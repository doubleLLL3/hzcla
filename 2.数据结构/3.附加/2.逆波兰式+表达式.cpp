/*************************************************************************
	> File Name: 1.逆波兰式.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 24 Jan 2021 02:14:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 0x3f3f3f3f

int calc(const char *str, int l, int r) {
    int pos = -1, pri = INF - 1, temp = 0;
    for (int i = l; i <= r; i++) {
        int cur = INF;
        switch (str[i]) {
            case '(': temp += 100; break;
            case ')': temp -= 100; break;
            case '+': 
            case '-': cur = temp + 1; break;
            case '*':
            case '/': cur = temp + 2; break;
            case '^': cur = temp + 3; break;
        }
        if (cur <= pri) {
            pos = i, pri = cur;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        printf("%d", num);
        return num;
    }
    int a = calc(str, l, pos - 1);
    printf(" ");
    int b = calc(str, pos + 1, r);
    printf(" %c", str[pos]);
    switch (str[pos]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return int(pow(a, b)); // pow函数返回int
    }
    return 0;                            // 其实到不了
}

char str[10000];

int main() {
    while (~scanf("%[^\n]s", str)) {
        getchar();
        int val = calc(str, 0, strlen(str) - 1);
        printf("\n");
        printf("%s = %d\n", str, val);
    }
    return 0;
}
