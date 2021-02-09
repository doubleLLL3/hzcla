/*************************************************************************
	> File Name: 11.binary_search.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 21 Nov 2020 07:25:49 PM CST
 ************************************************************************/
#include <stdio.h>
#define P(func) {\
    printf("%s \t= %d\n", #func, func);\
}
// 朴素二分：1 3 5 7 9...
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}
// 特殊二分：111111100000
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;  // 虚拟头指针：-1
    while (head < tail) {
        mid = (head + tail + 1) >> 1;  // +1 避免出现死循环：10
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;                       // 返回-1表示没找到
}
// 特殊二分：0000000111111
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;       // 虚拟尾指针：n
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;      // 返回-1表示没找到
}

int main() {
    int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 17, 19, 21};
    int arr2[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int arr4[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    P(binary_search1(arr1, 10, 7));
    P(binary_search2(arr2, 10));
    P(binary_search3(arr3, 10));
    P(binary_search2(arr4, 10));  // -1
    P(binary_search3(arr4, 10));  // -1
    return 0;
}
