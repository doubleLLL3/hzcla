/*************************************************************************
	> File Name: 2.test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 31 Dec 2020 07:40:15 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    FILE *fp = NULL;           // fp文件指针、fd文件描述符
    if ((fp = fopen("./a.txt", "r")) == NULL) {
        // 返回NULL说明打开出错
        perror("fopen");       // 返回错误信息，如文件不存在
        exit(1);               // 非正常退出，return 1
    }
    while (1) {
        char buff[512] = {0};  // 使用while循环，buffer在每轮循环都会初始化为0 [等价于memset 0]
        size_t nread = fread(buff, 1, sizeof(buff) - 1, fp);
        printf("%s", buff);
        // 使用nread判断终止循环时机【EOF或错误】
        if (nread < sizeof(buff) - 1) {
        //if (nread <= 0) {    // 不准确，0 <= nread < sizeof(buff) - 1时就是遇到了EOF或错误
            break;
        }
    }
    fclose(fp);  // 记得
    return 0;
}
