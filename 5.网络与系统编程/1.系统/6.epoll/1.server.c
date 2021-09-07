/*************************************************************************
	> File Name: 1.server.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 26 Jan 2021 08:50:30 PM CST
 ************************************************************************/

#include "common/head.h" 
#define MAX_EVENTS 10

int main(int argc, char **argv) {
    int server_listen, sockfd, port, epollfd;  // socket * 2：一个持续监听用、一个通信用
    struct epoll_event ev, events[MAX_EVENTS];
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }
    // 0、获取输入：port
    port = atoi(argv[1]);             // const char *str -> int
    // 1、调用接口：在指定端口创建一个监听态的快递员
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }
    if ((epollfd = epoll_create(1)) < 0) {
        perror("epoll_create");
        exit(1);
    }
    ev.events = EPOLLIN;
    ev.data.fd = server_listen;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev) < 0) {
        perror("epoll_ctl");
        exit(1);
    }

    for (;;) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds < 0) {
            perror("epoll_wait");
            exit(1);
        }
        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == server_listen) {
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
                    perror("accept");
                    exit(1);
                }
                printf("<LogIn> : %s login...\n", inet_ntoa(client.sin_addr));
                make_nonblock(sockfd);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = sockfd;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) < 0) {
                    perror("epoll_ctl");
                    exit(1);
                }
            } else {
                //do_use_fd(events[i].data.fd);
                char buff[1024] = {0};
                int rsize = 0, fd = events[i].data.fd;
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                getpeername(fd, (struct sockaddr *)&client, &len);
                if ((rsize = recv(fd, buff, sizeof(buff), 0)) <= 0) {
                    printf("<LogOut> : %s logout...\n", inet_ntoa(client.sin_addr));
                    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                } else {
                    printf("<%s> : %s..\n", inet_ntoa(client.sin_addr), buff);
                    send(fd, buff, strlen(buff), 0);
                }
            }
        }

    }
    return 0;
}
