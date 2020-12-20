/*************************************************************************
	> File Name: 9.quick_sort.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 21 Nov 2020 04:42:59 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = \n", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}
void quick_sort(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, z = num[x];  // z存了基准值，此时num[x]可用
    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
}
void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
    return ;
}

void randint(int *num, int n) {
    for (int i = 0; i < n; i++) num[i] = n - i;
    //while (n--) num[n] = rand() % 100;
    return ;
}

int main() {
    srand(time(0));
    #define max_n 100000
    int arr[max_n];
    randint(arr, max_n);
    quick_sort(arr, 0, max_n - 1);
    output(arr, max_n);
    //TEST(arr, max_n, quick_sort, num, 0, max_n - 1);
    return 0;
}
