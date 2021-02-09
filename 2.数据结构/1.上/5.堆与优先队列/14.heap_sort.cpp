/*************************************************************************
	> File Name: 14.heap_sort.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 25 Nov 2020 08:39:55 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp; \
}

// n 数组大小；ind 调整开始的位置
void downUpdate(int *arr, int n, int ind) {
    // 类似出堆操作
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        // 【思维转换】想得到从小到大排序的数组，需要维护一个大顶堆
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp =r;
        if (ind == temp) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

// 【用数组建堆+堆排序】重点在排序算法
void heap_sort(int *arr, int n) {
    arr -= 1;  // 【巧】访问arr[1]其实取到的是arr[0]
    // 建堆过程 O(N)
    // 自上向下调整，从倒数第二层开始
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);  // 【封装】出堆操作也需要该策略
    }
    // 堆排序过程 O(NlogN)
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_n 20
    int *arr = (int *)malloc(sizeof(int) * max_n);
    for (int i = 0; i < max_n; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, max_n);
    heap_sort(arr, max_n);      // 堆排序 = 建堆 + 排序
    output(arr, max_n);
    free(arr);
    #undef max_n
    return 0;
}
