/*************************************************************************
	> File Name: 1.test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 21 Jan 2021 07:45:22 PM CST
 ************************************************************************/

#include "common/head.h"
int flag = 0;  // 每次prinf是否刷新缓冲区

struct MyArg {
    char name[20];
    int age;
};

// 传入结构体参数arg的地址 [注意：地址对应的值可能会改变]
void *print(void *arg) {
    printf("In thread!\n");
    flag && fflush(stdout);
    // 【方式二】用变量取值 [比下者稍安全，但仍存在隐患——地址对应值已改变]
    struct MyArg in1;
    in1 = *(struct MyArg *)arg;
    printf("%s is %d years old.\n", in1.name, in1.age);
    flag && fflush(stdout);
    // 【方式一】用指针取地址
    struct MyArg *in;
    in = (struct MyArg*)arg;
    printf("%s is %d years old.\n", in->name, in->age);
    flag && fflush(stdout);
    // 可维护一个指针数组，保证地址值不改变；或使用锁，保证方式二拷贝正确
}

int main() {
    pthread_t thread;
    char name[20];
    int age = 18;
    struct MyArg arg;
    strcpy(name, "double");
    // 1、使用结构体封装多个变量：name、age
    strcpy(arg.name, name);
    arg.age = age;
    // 2、创建新线程：NULL 默认属性，arg 函数参数 [如果没有参数可使用NULL]
    pthread_create(&thread, NULL, print, &arg);
    // 3、等待，防止主线程return让子线程直接死亡
    usleep(1000);  
    return 0;
}
