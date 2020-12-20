/*************************************************************************
	> File Name: 5.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 05 Dec 2020 04:40:55 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) {\
    a ^= b; b ^= a, a ^= b;\
}

void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[r] < num[l]) {
            swap(num[r], num[l]);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);

    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p1 > mid || (p2 <= r && num[p2] > num[p1])) {
            temp[k++] = num[p2++];
        } else {
            temp[k++] = num[p1++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return ;
}
