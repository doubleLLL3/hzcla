/*************************************************************************
	> File Name: test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 31 Dec 2020 06:44:57 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    int fd;                               // 文件描述符
    char buff[512] = {0};                 // 一般取512、1024等
    ssize_t nread;
    if ((fd = open("./a.txt", O_CREAT | O_RDONLY)) < 0) {
        // 可创建 | 只读
        perror("open");                   // perror 打印系统错误信息
        exit(1);
    }
    // 如果nread大于0 [nread表示读取的字节数]，则一直读
    while ((nread = read(fd, buff, sizeof(buff) - 1)) > 0) {
        // count：最大为buff的size大小512，但在这里-1
        // 是为了避免乱码，最后一位一直保持为'\0'
        buff[nread] = '\0';               // 针对最后一次输入不满511字节的情况
        printf("【read %ld】\n%s", nread, buff);
        //memset(buff, 0, sizeof(buff));  // 初始化buff，也是针对最后一次输入不满511字节的情况
    }
    // 良好的习惯 [不close的话，关闭程序时才被释放]
    close(fd);
    return 0;
}
