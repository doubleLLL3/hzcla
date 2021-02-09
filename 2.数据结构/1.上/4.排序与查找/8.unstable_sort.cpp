/*************************************************************************
	> File Name: 8.unstable_sort.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 21 Nov 2020 04:13:06 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 选择排序可能存在自己与自己交换的情况，所以不能用异或操作
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
    printf("\n");\
    free(num);\
}
void select_sort(int *num, int n) {
    // 最后一个元素不用排了 0 ~ n - 2
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        // 从i + 1到n - 1区间，找最小值，记录下标
        for (int j = i + 1; j < n; j++) {
            if (num[ind] > num[j]) ind = j;
        }
        swap(num[i], num[ind]);  // 交换
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (l >= r) return ;                  // ==的情况，也可以直接返回 
    // x、y 左、右指针；z 提取基准值，即最左边元素，此时num[x]可存其他值
    int x = l, y = r, z = num[x];         // 【可优化】
    // 下面每一步都要保证x < y，因为每一步都对x或y进行了++或--操作
    while (x < y) {
        while (x < y && num[y] >= z) y--; // 循环找<基准值的元素；x < y的条件需保证，因为y还在减
        if (x < y) num[x++] = num[y];     // 存值到左指针位置，右移左指针
        while (x < y && num[x] <= z) x++; // 循环找>基准值的元素；x < y的条件同理需保证
        if (x < y) num[y--] = num[x];     // 存值到右指针位置，左移右指针
        // 【自行修改】两个与基准值的比较都加上==情况，减少交换，并尽量保证稳定[尽管快排不稳定]
    }
    num[x] = z;                           // 最后放入基准值到空位
    quick_sort(num, l, x - 1);            // 递归排左、排右【可优化】
    quick_sort(num, x + 1, r);
    return ;
}
// 要学会这个随机生成数组的方法
void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    //for (int i = 0; i < n; i++) num[i] = n - i;
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

int main() {
    srand(time(0));
    #define max_n 20
    int arr[max_n];
    randint(arr, max_n);
    TEST(arr, max_n, select_sort, num, max_n);
    TEST(arr, max_n, quick_sort, num, 0, max_n - 1);
    return 0;
}
