/*************************************************************************
	> File Name: 1.select.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 05 Jan 2021 07:56:42 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    fd_set rfds;
    struct timeval tv;
    int ret;
    // 观察0号文件的读状态
    FD_ZERO(&rfds);    // 先清空集合rfds，排除陌生文件
    FD_SET(0, &rfds);  // 把0号文件添加到集合中
    // 最多等待 5 s 0 ms
    tv.tv_sec = 5;  
    tv.tv_usec = 0;
    // select监控0号文件是否可读，只等待tv时间，监控一次
    ret = select(1, &rfds, NULL, NULL, &tv);

    if (ret == -1)
        perror("select()");
    else if (ret) {
        //char buff[512] = {0};
        //scanf("%s", buff);            // 收走数据
        printf("Data is available now.\n");
        // 此时FD_ISSET(0, &rdfs) == 1
    } else
        printf("No data within five seconds.\n");
    return 0;
}
