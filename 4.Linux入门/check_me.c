/*************************************************************************
	> File Name: check_me.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Wed 12 Aug 2020 11:03:09 AM CST
 ************************************************************************/
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <pwd.h>

#define VER "1.1"

struct CheckUserInfo {
    char name[20];
    char dir[512];
};


int recv_and_print(int fd) {
    char buff[512] = {0};
    int ret = recv(fd, buff, sizeof(buff), 0);
    if (ret <= 0) {
        close(fd);
        return -1;
    }
    printf("%s", buff);
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s ip port!\n", argv[0]);
        exit(1);
    }
    char ip[20] = {0};
    struct CheckUserInfo userinfo;
    bzero(&userinfo, sizeof(userinfo));
    
    struct passwd *pwd;
    pwd = getpwuid(getuid());
    strcpy(userinfo.name, pwd->pw_name);
    getcwd(userinfo.dir, sizeof(userinfo.dir));
    
    if (!strcmp(userinfo.name, "root")) {
        printf("Do not run this with root!\n");
        exit(1);
    }

    int port, fd, stu_port;
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    if (connect(fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect()");
        exit(1);
    }
    //1. 发送版本控制
    send(fd, VER, sizeof(VER), 0);
    //2. 接受版本控制信息
    if (recv_and_print(fd) < 0) exit(1);
    //3. 发送本地用户信息
    send(fd, (void *)&userinfo, sizeof(userinfo), 0); 
    //4. 接受欢迎信息，等到用户输入port号
    if (recv_and_print(fd) < 0) exit(1);
    scanf("%d", &stu_port);
    send(fd, &stu_port, sizeof(int), 0);
    if (recv_and_print(fd) < 0) exit(1);
    if (recv_and_print(fd) < 0) exit(1);
    if (recv_and_print(fd) < 0) exit(1);
    if (recv_and_print(fd) < 0) exit(1);
    if (recv_and_print(fd) < 0) exit(1);
    return 0;
}
