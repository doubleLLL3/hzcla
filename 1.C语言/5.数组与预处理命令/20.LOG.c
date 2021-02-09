/*************************************************************************
	> File Name: 19.LOG.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 27 Oct 2020 07:54:26 PM CST
 ************************************************************************/
#include <stdio.h>

//#define DEBUG  // 可以主动定义；还可以在编译时使用gcc -D定义
#ifdef DEBUG
#define log(frm, args...) {\
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n");\
}
#else
#define log(frm, arg...)
#endif

#define contact(a, b) a##b // 若为ab，不是将a、b替换后连接，而是直接替换成字符串ab，相当于变量名ab


int main() {
    // 实现一个LOG函数
    int a = 123;
    log("%d", a);
    log("hello kaikeba");

    // 宏中"##"连接符的使用
    int abcdef = 0;
    //int abc, def;  // 不定义abc、def也可以，预处理会直接替换掉
    contact(abc, def) = 112233;
    log("%d", abcdef);
    return 0;
}
