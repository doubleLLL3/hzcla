/*************************************************************************
	> File Name: 1.add.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 19 Jan 2021 06:41:20 PM CST
 ************************************************************************/

#include "common/head.h"
#define INS 5

// 共享的信息
struct Msg {
    int now, sum;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

struct Msg *share_memory;  // 共享信息的地址

void do_add(int x) {
    while (1) {
        if (++share_memory->now > 100) break;
        share_memory->sum += share_memory->now;
        printf("<%d> now = %d, sum = %d\n", x, share_memory->now, share_memory->sum);
        usleep(100);
    }
    shmdt(share_memory);                                // 分离共享内存
    exit(0);
}

int main() {
    pid_t pid;
    int x = 0, shmid;
    // 提前约定好共享内存的位置
    key_t key = ftok(".", 2021);                        // 1.获得key
    if ((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | IPC_EXCL | 0600)) < 0) {
        // 需要设置权限，0600的第一个 [0] 表示该数字是8进制
        perror("shmget");
        exit(1);
    }                                                   // 2.获得唯一id [通过id也能在子进程中找到共享内存]
    share_memory = (struct Msg*)shmat(shmid, NULL, 0);  // 使用结构体指针指向共享地址
    if (share_memory == (void *)-1) {
        perror("share_memory");
        exit(1);
    }                                                   // 3.获得共享内存在[该进程中]的地址
    // 创建INS个子进程
    for (int i = 1; i <= INS; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
        }
        x = i;                                          // 标识孩子编号
        if (pid == 0) break;
    }
    if (pid == 0) {
        // 子进程做累加计算
        do_add(x);
    } else {
        // 父进程等待孩子终止
        for (int i = 1; i <= INS; i++) {
            wait(NULL);
        }
        printf("share_memory->sum = %d\n", share_memory->sum);
        shmdt(share_memory);                            // 分离共享内存
        shmctl(shmid, IPC_RMID, NULL);                  // 销毁共享内存
    }
    return 0;
}

