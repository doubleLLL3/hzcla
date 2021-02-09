/*************************************************************************
	> File Name: 18.binary_search.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 24 Oct 2020 08:50:33 PM CST
 ************************************************************************/
#include <stdio.h>

// 递归版
// 递归的函数参数里包含递归的左右范围：l、r
int binary_search(int *arr, int l, int r, int x) {
    if (l > r) return -1;  // 终止条件
    // 缩小查找范围，与迭代方式类似
    int mid = (l + r) >> 1;
    if (arr[mid] == x) return mid;
    if (arr[mid] < x) l = mid + 1;
    else r = mid - 1;
    // 缩小范围再进入函数
    return binary_search(arr, l, r, x);
}

int main() {
    int arr[100], n;
    // 自己定义数组大小和值
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    int x;
    while (~scanf("%d", &x)) {
        int ans = binary_search(arr, 0 , n - 1, x);
        printf("find %d = arr[%d]\n", x, ans);
    }
    return 0;
}
