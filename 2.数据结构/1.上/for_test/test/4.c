/*************************************************************************
	> File Name: 4.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 06 Dec 2020 10:42:37 AM CST
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>

#define max_n 10000000

int arr[max_n + 5] = {0, 1};

int func(int x) {
    int xx = x, flag = 1;
    while (x != 1 && flag == 1) {
        flag = 0;
        if (x % 2 == 0) x /= 2, flag = 1;
        if (x % 3 == 0) x /= 3, flag = 1;
        if (x % 5 == 0) x /= 5, flag = 1;
        if (x < max_n) {
            if (xx < max_n) arr[xx] = arr[x];
            return arr[x];
        }
    }
    if (x == 1) {
        if(xx <= max_n) arr[xx] = 1;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i < INT32_MAX; i++) {
        if (func(i)) cnt++;
        if (cnt == n) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
