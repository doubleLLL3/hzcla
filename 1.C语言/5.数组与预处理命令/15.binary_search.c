/*************************************************************************
	> File Name: 15.binary_search.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 24 Oct 2020 04:55:58 PM CST
 ************************************************************************/
#include <stdio.h>
#include <math.h>

int f_int(int x) {
    return x * x;
}

double f_double(double x) {
    return x * x;
}

// 二分查找于double函数：实现sqrt函数，连续问题
double binary_search_f_d(double (*arr)(double), double x) { 
    // 二分区间：0 ~ x，对大于1的值求根
    double head = 0, tail = x, mid;
    // 对于属于0~1区间的x，开根号后会大于x，调整区间的tail
    if (x < 1.0) tail = 1.0; 
    // double类型判等：使用EPSL，该值可以调小，提高精度
    #define EPSL 1e-7 
    while (tail - head > EPSL) {
        mid = (head + tail) / 2.0;  // 不是int型，不用右移1位代替除以2
        if (arr(mid) < x) head = mid;  // 注意不是mid + 1，因为 mid ~ mid + 1 之间可能有解
        else tail = mid;
    }
    #undef EPSL
    return head;
}

// 二分查找于int函数：离散问题
int binary_search_f_i(int (*arr)(int), int n, int x) {
    // head 头指针 tail 尾指针
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr(mid) == x) return mid;
        if (arr(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

// 二分查找于数组：离散问题
// 需传递数组指针arr、数组长度n、要查找的数x
int binary_search(int *arr, int n, int x) {
    // head 头指针 tail 尾指针
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;  // 编程技巧
}

int main() {
    // 二分查找于数组、int函数
    /*
    int num[10];
    for (int i = 0; i < 10; i++) num[i] = i * i;
    // 0 1 2 3  4  5 ...
    // 0 1 4 9 16 25 ...
    int x1;
    while (~scanf("%d", &x1)) {
        int ans = binary_search(num, 10, x1);
        printf("arr: %d * %d = %d\n", ans, ans, ans * ans);
        int ans_f = binary_search_f_i(f_int, 100, x1);  // 范围n可以更灵活地设置
        printf("f_int: %d * %d = %d\n", ans_f, ans_f, ans_f * ans_f);
    }
    */

    // 二分查找于double函数，实现sqrt函数
    double x2;
    while (~scanf("%lf", &x2)) {
        double ans = binary_search_f_d(f_double, x2);
        printf("sqrt(%g) = %g\n", x2, sqrt(x2));
        printf("my_sqrt(%g) = %g\n", x2, ans);
    }
    return 0;
}
