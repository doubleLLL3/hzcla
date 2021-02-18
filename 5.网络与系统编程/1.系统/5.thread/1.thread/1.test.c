/*************************************************************************
	> File Name: 1.test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 21 Jan 2021 07:45:22 PM CST
 ************************************************************************/

#include "common/head.h"

struct MyArg {
    char name[20];
    int age;
};

// 
void *print(void *arg) {
    struct MyArg in1;
    in1 = *(struct MyArg *)arg;
    struct MyArg *in;
    in = (struct MyArg*)arg;
    printf("In thread!\n");
    fflush(stdout);
    printf("%s is %d years old.\n", in->name, in->age);
    printf("%s is %d years old.\n", in1.name, in1.age);
}

int main() {
    pthread_t thread;
    char name[20];
    int age = 18;
    strcpy(name, "double");

    struct MyArg arg;
    strcpy(arg.name, name);
    arg.age = age;
    // NULL：默认属性
    pthread_create(&thread, NULL, print, &arg);
    usleep(1);  // 等待，保证上面线程可以跑，而不会因进程结束而直接被杀
    return 0;
}
