/*************************************************************************
	> File Name: 2.test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 21 Jan 2021 09:02:46 PM CST
 ************************************************************************/

#include "common/head.h"
#include "./thread_pool.h"

#define THREAD 5
#define QUEUE 50

void *do_work(void *arg) {
    pthread_detach(pthread_self());
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while (1) {
        char *str = task_queue_pop(taskQueue);
        printf("<%ld> : %s !\n", pthread_self(), str);
    }
}

int main() {
    pthread_t tid[THREAD];
    struct task_queue taskQueue;
    task_queue_init(&taskQueue, QUEUE);
    char buff[QUEUE][1024] = {0};
    
    for (int i = 0; i < THREAD; i++) {
        pthread_create(&tid[i], NULL, do_work, (void *)&taskQueue);
    }

    int sub = 0;
    while (1) {
        FILE *fp = fopen("./2.test.c", "r");  // no w
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }
        while (fgets(buff[sub++], 1024, fp) != NULL) {
            task_queue_push(&taskQueue, buff[sub]);
            if (sub == QUEUE) {
                sub = 0;
            }
            if (taskQueue.total == taskQueue.size) {
                while (1) {
                    // 有可能线程在pop
                    if (taskQueue.total < taskQueue.size) {
                        break;
                    }
                    usleep(10000);
                }
            }
        }
        fclose(fp);
    }

    return 0;

}
