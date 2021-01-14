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
    int retval;

    /* Watch stdin (fd 0) to see when it has input. */

    FD_ZERO(&rfds);  // 清空set
    FD_SET(0, &rfds);  // 把0号文件加到rfds中

    /* Wait up to five seconds. */

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Don't rely on the value of tv now! */

    if (retval == -1)
        perror("select()");
    else if (retval) {
        
        printf("Data is available now.\n");
        /* FD_ISSET(0, &rfds) will be true. */
    } else
        printf("No data within five seconds.\n");

    exit(EXIT_SUCCESS);
}
