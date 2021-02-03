/*************************************************************************
	> File Name: 1.server.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 21 Jan 2021 06:38:14 PM CST
 ************************************************************************/

#include "common/head.h"
#include "chat.h"

struct Msg *share_memory = NULL;  // 不写也行？

int main() {
    int shmid;
    key_t key = ftok(".", 202101);
    if ((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0600)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((share_memory = (struct Msg*)shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        exit(1);
    }
    memset(share_memory, 0, sizeof(struct Msg));
    // 初始化线程互斥锁
    pthread_mutexattr_t m_attr;
    pthread_mutexattr_init(&m_attr);
    pthread_mutexattr_setpshared(&m_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&share_memory->mutex, &m_attr);

    pthread_condattr_t c_attr;
    pthread_condattr_init(&c_attr);
    pthread_condattr_setpshared(&c_attr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&share_memory->cond, &c_attr);
    
    while (1) {
        pthread_mutex_lock(&share_memory->mutex);
        printf("Server got the mutex!\n");
        pthread_cond_wait(&share_memory->cond, &share_memory->mutex);
        printf("Server got the cond signal");
        printf("<%s> : %s.\n", share_memory->name, share_memory->msg);
        // 后添加
        //memset(share_memory->msg, 0, sizeof(share_memory->msg));
        pthread_mutex_unlock(&share_memory->mutex);
    }
    return 0;
}
