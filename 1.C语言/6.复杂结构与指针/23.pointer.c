/*************************************************************************
	> File Name: 23.pointer.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 31 Oct 2020 03:17:20 PM CST
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data {
    int a;
    double b;
    char c;
};
#define offset(T, a) (long)(&(((T *)(NULL))->a))
//#define offset(T, a) ({\
    T temp;\
    (char *)(&temp.a) - (char *)(&temp);\
})
#define ppchar char *
typedef char * pchar; 

// main函数
void output(int argc, char *argv[], char **env) {
    printf("argc = %d\n", argc);  // 参数个数
    // 获取二维字符数组argv的值
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);  // 使用%s输出每个字符串
    }
    // 获取环境变量，通过env[i]是否为空地址来作为停止条件
    for (int i = 0; env[i]; i++) {
        //printf("env[%d] = %s\n", i, env[i]);  // 打印所有环境变量
        // 判断某个环境变量前5个字符是否是USER=
        if (!strncmp(env[i], "USER=", 5)) {
            // 判断是否是某个用户
            if (!strcmp(env[i] + 5, "hz")) {
                printf("Welcome haizei Liu\n");
            } else {
                printf("You are not the User! please gun!\n");
                exit(0);  // 直接结束当前进程，<stdlib.h>
            }
        }
    }
    return;
}
int main(int argc, char *argv[], char **env) {
    output(argc, argv, env);
    //return 0; 

    int num = 0x0626364;  // 注意小端机字节序，对照ASCII码
    printf("%s\n", (char*)(&num));  // 注意字符串要以'\0'结尾，如果没有则不安全
    // 输出结构体中变量的地址偏移量
    printf("%ld\n", offset(struct Data, a));  // struct Data是一个类型，所以offset要用宏定义
    printf("%ld\n", offset(struct Data, b));  // 地址对应的是long int类型
    printf("%ld\n", offset(struct Data, c));
    // #define和typedef的区别 
    ppchar p1, p2;
    pchar p3, p4;
    printf("p1 = %lu, p2 = %lu\n", sizeof(p1), sizeof(p2));  // 8 1 -> 宏是简单替换，p2是char变量
    printf("p3 = %lu, p4 = %lu\n", sizeof(p3), sizeof(p4));  // 8 8
    return 0;
}
