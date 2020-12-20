/*************************************************************************
	> File Name: 17.array.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 24 Oct 2020 07:42:18 PM CST
 ************************************************************************/
#include <stdio.h>
#define max_n 100 

// int num[max_n + 5];  // 占用的是内存，在函数外定义一定是干净的，清空为了0值

void func(int *num) {
    printf("num = %p, num + 1 = %p\n", num, num + 1);
    return ;
}

void func2(int (*num)[100]) {
   printf("num2 = %p, num2 + 1 = %p\n", num, num + 1);
}

void func3(int (*num)[100][32]) {
   printf("num3 = %p, num3 + 1 = %p\n", num, num + 1);
}

int main() {
    // 声明、初始化
    int arr[max_n + 5];  // 占用的是栈，值可能是不干净的，随机
    int arr2[100][100];
    int arr3[100][100][32];
    /*for (int i = 0; i < max_n; i++) {
        scanf("%d", arr + i);  // arr + i 等价于 &arr[i]
    }*/
    
    // 占用大小、地址
    printf("sizeof(arr) = %lu\n", sizeof(arr));
    printf("&arr = %p, &arr[0] = %p\n", arr, &arr[0]);
    printf("arr + 1 = %p, arr + 2 = %p\n", arr + 1, arr + 2); 
    char *p = (char *)arr;
    printf("p + 1 = %p, p + 2 = %p\n", p + 1, p + 2);
    
    // 传参
    func(arr);  // 传入一维数组地址！arr代表的就是数组首地址
    printf("arr = %p. arr + 1 = %p\n", arr, arr + 1);
    func2(arr2);
    func3(arr3);
    int **q;
    printf("q = %p, q + 1 = %p\n", q, q + 1);  // q指向的是nil？？？ 就是0x0

    return 0;
}
