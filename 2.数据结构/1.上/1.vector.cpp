/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Nov 2020 06:49:59 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>  // 需要动态申请内存
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)

// 类型重命名Vec
typedef struct Vector {
    int *data;        // 数据首地址，演示int型顺序表
    int size, length; // size：容量 length：元素个数
} Vec;
// 初始化
Vec* init(int n) {
    Vec *v = (Vec *)malloc(sizeof(Vec));       // 给顺序表结构开辟空间
    v->data = (int *)malloc(sizeof(int) * n);  // 给数据开辟空间
    v->size = n;
    v->length = 0;
    return v;
}
// 扩容
int expand(Vec *v) {
    int extr_size = v->size;
    // return v->data = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));  // 危险！失败会找不到原数据地址
    // 先不主动释放，realloc成功之后再覆盖
    int *p;
    while (extr_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));
        if (p) break;  // 如果开辟失败，p为NULL，接着减小扩容再试一次
        extr_size >>= 1;
    }
    if (extr_size == 0) return 0;  // 或者判断p == NULL
    v->data = p;                   // 转移空间地址，realloc成功原空间会被自动free
    v->size += extr_size;
    return 1;
}
// 插入
int insert(Vec *v, int val, int ind) {
    if (v == NULL) return 0;                   // 空的情况
    if (ind < 0 || ind > v->length) return 0;  // 索引为负或者大于length，而在length位可以插入
    // 满员时需要扩容！
    if (v->length == v->size) {
        if (!expand(v)) return 0;
        printf(GREEN("Succeed to expand! The Vector size now is %d\n"), v->size);
    }
    // 从最后一位的后一位开始获得右移的值
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    // 在插入位上赋值，并length + 1
    v->data[ind] = val;
    ++v->length;
    return 1;  // 返回操作状态
}
// 删除
int erase(Vec *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    // 从ind + 1开始，向前一位覆盖
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length--;
    return 1;
}
// 打印顺序表
void output(Vec *v) {
    if (v == NULL) return ;
    printf("Vector: [");
    for (int i = 0; i < v->length; i++) {
        i && printf(", ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
}
// 销毁
void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);  // 从结构体里到外free，避免内存泄漏
    free(v);
    v = NULL;
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Vec *v = init(2);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int ind = rand() % (v->length + 3) - 1;  // 模拟下标合理、为负[-1]、过大[l/l+1]三种情况
        int op = rand() % 4;                     // 决定如何操作
        switch (op) {
            case 1:
            case 2:
            case 0: {
                printf("insert %d at [%d] to Vector : %s\n", val, ind, insert(v, val, ind) ? "success" : RED("error"));
            } break;
            case 3: {
                printf("erase a item at [%d] from Vector : %s\n", ind, erase(v, ind) ? "success" : RED("error"));
            } break;
        }
        output(v);
        printf("\n");
    }
    clear(v);
    #undef max_op
    return 0;
}
