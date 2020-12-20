/*************************************************************************
	> File Name: 1.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 06 Dec 2020 09:21:13 AM CST
 ************************************************************************/
#include <stdio.h>

int main() {
    int x, m, cnt = 0;
    char ans[35];
    scanf("%d%d", &x, &m);
    while (x) {
        ans[cnt++] = x % m + '0';
        x /= m;
    }
    ans[cnt] = '\0';
    for (int i = cnt - 1, j = 0; j < cnt; i--, j++) {
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}

