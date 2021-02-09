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
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}
void quick_sort(int *num, int l, int r) {
    // 【优化】减少递归的使用，增加循环
    // 此处变成了循环判断 l < r
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];  // 【优化】基准值选中间值
        do {
            // 【优化】两个指针都找两个值，直接交换
            // 【关键】x <= y，不能用<，要将x、y错开；num[] < z，不能用<=，经过基准值要停下
            while (x <= y && num[x] < z) x++; 
            while (x <= y && num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                x++, y--;
            }
        } while (x <= y);       // <=，与上面一致，但可以用<；此处do...while和while没区别
        quick_sort(num, x, r);  // 一直排靠右的x ~ r区间
        r = y;                  // 【关键】缩小右边界，此前y + 1 ~ r已经排好
    }
    return ;
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
    //num[0] = 2;
    //num[1] = 1;
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
    //TEST(arr, max_n, quick_sort, num, 0, max_n - 1);  // 注意，arr、num，num是在宏里拷贝了一份
    return 0;
}
