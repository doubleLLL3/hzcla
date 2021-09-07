/*************************************************************************
	> File Name: 1.test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 21 Jan 2021 09:02:46 PM CST
 ************************************************************************/

#include "common/head.h"
#include "./thread_pool.h"

#define THREAD 5
#define QUEUE 50

void *do_work(void *arg) {
    pthread_detach(pthread_self());       // 分离自己，从而不需要其它线程join
    struct task_queue *taskQueue = (struct task_queue *)arg;
    // 时刻待命：输出字符串
    while (1) {
        char *str = task_queue_pop(taskQueue);
        printf("<%ld> : %s\n", pthread_self(), str);
    }
}

int main() {
    pthread_t tid[THREAD];
    struct task_queue taskQueue;
    task_queue_init(&taskQueue, QUEUE);
    char buff[QUEUE][1024] = {0};         // 使用二维是为了避免线程处理数据时，外部改变了数据 
    // 创建THRED个线程 [传入任务队列]
    for (int i = 0; i < THREAD; i++) {
        pthread_create(&tid[i], NULL, do_work, (void *)&taskQueue);
    }
    
    // 开始布置任务
    int sub = 0;
    while (1) {
        FILE *fp = fopen("./1.test.c", "r");  // 不能用w，否则文件就没了
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }
        while (fgets(buff[sub], 1024, fp) != NULL) {
            task_queue_push(&taskQueue, buff[sub++]);
            if (sub == QUEUE) {
                sub = 0;
            }
            // 如果任务队列已满
            if (taskQueue.total == taskQueue.size) {
                while (1) {
                    // 当有线程取走了任务 [pop]
                    if (taskQueue.total < taskQueue.size) {
                        break;
                    }
                    usleep(10000);        // 避免while太耗CPU资源
                }
            }
        }
        fclose(fp);
    }
    return 0;
}
