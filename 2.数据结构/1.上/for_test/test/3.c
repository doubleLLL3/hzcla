/*************************************************************************
	> File Name: 3.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 06 Dec 2020 09:42:59 AM CST
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int n, arr[100000];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    for (int i = 2; i <= n; i++) {
        int ans = INT32_MAX, ind, now = arr[i];
        for (int j = 1; j < i; j++) {
            int temp = abs(now - arr[j]);
            if (temp < ans) {
                ans = temp;
                ind = j;
            } else if (temp == ans) {
                ind = (arr[j] > arr[ind] ? ind : j);
            }
        }
        printf("%d %d\n", ans, ind);
    }
    return 0;
}
