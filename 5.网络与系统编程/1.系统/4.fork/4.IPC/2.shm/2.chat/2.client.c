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
                exit(1); // 不能用0？
        }
    }

    key_t key = ftok(".", 202101);
    if  ((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0600)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((share_memory = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        exit(1);
    }

    while (1) {
        char msg[1024] = {0};
        scanf("%[^\n]s", msg);
        getchar();
        if (!strlen(msg)) continue;
        // 后添加：等server端收到消息再
        while (1) {
            if (!strlen(share_memory->msg)) {
                pthread_mutex_lock(&share_memory->mutex);
                break;
            }
        }
        //pthread_mutex_lock(&share_memory->mutex);
        printf("Sending: %s...\n", msg);
        strcpy(share_memory->msg, msg);
        strcpy(share_memory->name, name);
        pthread_cond_signal(&share_memory->cond);
        pthread_mutex_unlock(&share_memory->mutex);
        printf("Client signal the cond\n");
    }

    return 0;
}
