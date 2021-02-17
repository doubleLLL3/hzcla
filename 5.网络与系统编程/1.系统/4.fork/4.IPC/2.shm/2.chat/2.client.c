/*************************************************************************
	> File Name: 2.client.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 21 Jan 2021 06:49:35 PM CST
 ************************************************************************/

#include "common/head.h"
#include "chat.h"

struct Msg *share_memory = NULL;

int main(int argc, char **argv) {
    int opt, shmid;
    char name[20] = {0};
    while ((opt = getopt(argc, argv, "n:")) != -1) {
        switch (opt) {
            case 'n': 
                strcpy(name, optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -n name\n", argv[0]);
                exit(1);
        }
    }
    key_t key = ftok(".", 202101);
    if  ((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0600)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((share_memory = shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    while (1) {
        char msg[1024] = {0};
        scanf("%[^\n]s", msg);                          // 可读入空格，但注意getchar收掉回车
        getchar();
        if (!strlen(msg)) continue;                     // 如果消息为空
        // 等服务端收到消息并置空后，再加锁 [防止客户端抢锁，导致服务端不能收到信号]
        while (1) {
            if (!strlen(share_memory->msg)) {
                pthread_mutex_lock(&share_memory->mutex);  // [隐患：可能被阻塞]
                break;
            }
        }
        printf("Sending: %s...\n", msg);
        strcpy(share_memory->msg, msg);                 // 给共享内存赋值
        strcpy(share_memory->name, name);
        pthread_cond_signal(&share_memory->cond);       // 发信号
        pthread_mutex_unlock(&share_memory->mutex);     // 或者放在上一行
        printf("Client signal the cond\n");
    }
    return 0;
}
