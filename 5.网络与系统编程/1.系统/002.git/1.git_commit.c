/*************************************************************************
	> File Name: 1.git_commit.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 17 Jan 2021 10:16:01 AM CST
 ************************************************************************/

#include "head.h"
#define MAX_LENGTH 512

// 输入消息
void input_msg() {
    pid_t pid;
    int status;
    // 父进程复制一个子进程
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        // 将子进程替换为vim进程
        execlp("vim", "vim", "COMMIT_MSG", NULL);
    } else {
        wait(&status);  // 监控子进程状态
        // 父进程提示vim出错
        if (WEXITSTATUS(status)) printf("vim error!\n");
    }
    return ;
}

// 读取消息
void read_msg() {
    int fd, flag = 0;                    // flag：是否读取到了有效消息
    char buff[MAX_LENGTH] = {0};         // 最多读取MAX_LENGTH字节消息
    ssize_t nread;
    // 如果无法打开消息文件，友好提示
    if ((fd = open("COMMIT_MSG", O_RDONLY)) < 0) {
        printf("aborting commit due to msg file can't open.\n");
        exit(1);
    }
    // 读取消息文件
    if ((nread = read(fd, buff, sizeof(buff) - 1)) > 0) {
        char *line;
        // 分行判断消息是否有效
        line = strtok(buff, "\n");
        while (line != NULL) {
            // 如果不是无效消息 [不是注释]
            if (line[0] != '#') {
                flag || printf("msg:");  // 第一次打印有效消息时打印消息前缀："msg:"
                flag = 1;
                printf(" %s", line);
            }
            line = strtok(NULL, "\n");   // 不断调用直到遇到buff的'\0'
        }
        flag && printf("\n");
    }
    // 如果没有读到有效消息，友好提示
    if (!flag) {
        printf("aborting commit due to empty commit msg.\n");
    }
    close(fd);
    return ;
}

// 删除消息文件
void remove_file() {
    pid_t pid;
    int status;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        execlp("rm", "rm", "COMMIT_MSG", NULL);
    } else {
        wait(&status);
        // 父进程提示rm失败 [rm进程也会有提示]
        if (WEXITSTATUS(status)) printf("remove msg file error!\n");
    }
    return ;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        // 1.无选项：需要vim输入msg
        input_msg();
        read_msg();
        remove_file();  // 如果可以到这步，消息文件已产生
    }
    int opt;
    while ((opt = getopt(argc, argv, "m:")) != -1) {
        switch (opt) {
            case 'm': {
                // 2.有-m及选项参数：打印参数
                printf("msg: %s\n", optarg);
            } break;
            default: {
                // 3.选项不合法：友好提示
                fprintf(stderr, "Usage: %s [-m msg]\n", argv[0]);
                exit(1);
            }
        }
    }
    return 0;
}
