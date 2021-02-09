/*************************************************************************
	> File Name: 7.stable_sort.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 21 Nov 2020 03:05:47 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define swap(a, b) {\
    a ^= b; b ^= a; a ^= b;\
}
#define TEST(arr, n, func, args...) {           /*args... 变参宏*/\
    int *num = (int *)malloc(sizeof(int) * n);  /*拷贝一份，让排序不影响原数组*/\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}
// 插入排序
void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        // 从第i个元素往前面已排序区比较，只要比前一个元素小，就交换，实现插入的效果
        // 必须一个一个交换，这样才能保证已排序区的顺序！
        for (int j  = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}
// 冒泡排序
void bubble_sort(int *num, int n) {
    int times = 1;  // 优化：记录交换情况，可提前结束
    for (int i = 1; i < n && times; i++) {
        times = 0;
        // 从第1个元素开始，到第【n - i】个元素
        for (int j = 0; j < n - i; j++) {
            // 保证右边元素大于左边元素
            if (num[j] <= num[j + 1]) continue;  // 对偶原则，减少缩进
            swap(num[j], num[j + 1]);
            times++;
        }
    }
    return ;
}
// 归并排序
void merge_sort(int *num, int l, int r) {
    // 递归出口，边界条件：剩余元素<=2
    if (r - l <= 1) {
        // 剩余2个元素
        if (r - l == 1 && num[r] < num[l]) {
            swap(num[r], num[l]);
        }
        return ;
    }
    // 一分为二，调用递归
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    // 合并，此时num的l ~ mid和mid + 1 ~ r区间是有序的
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;  // p1、p2、k：3个数组的头指针
    // 当两段数组至少有一个还有元素时
    while (p1 <= mid || p2 <= r) {
        // 第二个数组没有元素||(第一段数组还有元素&&小于第二段数组对应元素)
        // 【注意】num[p1] <= num[p2]包含【==】情况
        // 因为，第一段数组优先第二段数组，保证稳定性
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];  // 结合++操作
        } else {
            temp[k++] = num[p2++];
        }
    }
    // 拷贝排好序的数组到目前归并的数组首地址&num[l]，共r - l + 1个元素
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}
void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;  // n--
    return ;
}
void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", num[i]);
    }
    printf("]\n");
    return ;
}
int main() {
    srand(time(0));
    #define max_n 20
    int arr[max_n];
    randint(arr, max_n);  // 初始化数组
    // 实现TEST宏
    TEST(arr, max_n, insert_sort, num, max_n);
    TEST(arr, max_n, bubble_sort, num, max_n);
    TEST(arr, max_n, merge_sort, num, 0, max_n - 1);
    #undef max_n
    return 0;
}

