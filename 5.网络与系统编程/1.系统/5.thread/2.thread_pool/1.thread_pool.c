/*************************************************************************
	> File Name: 1.thread_pool.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 21 Jan 2021 08:44:52 PM CST
 ************************************************************************/

#include "common/head.h"
#include "./thread_pool.h"

void task_queue_init(struct task_queue *taskQueue, int size) {
    taskQueue->size = size;
    taskQueue->total = 0;
    taskQueue->head = taskQueue->tail = 0;
    pthread_mutex_init(&taskQueue->mutex, NULL);
    pthread_cond_init(&taskQueue->cond, NULL);
    taskQueue->data = calloc(size, sizeof(void *));
    return ;
}

void task_queue_push(struct task_queue *taskQueue, char *str) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue->total == taskQueue->size) {
        pthread_mutex_unlock(&taskQueue->mutex);
        printf("task queue is full!\n");
        return ;
    } 
    printf("<push> : %s\n", str);
    taskQueue->data[taskQueue->tail] = str;
    taskQueue->total++;
    if (++taskQueue->tail == taskQueue->size) {
        printf("task queue reach end!\n");
        taskQueue->tail = 0;
    }
    pthread_cond_signal(&taskQueue->cond);
    pthread_mutex_unlock(&taskQueue->mutex);
}

char *task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    while (taskQueue->total == 0) {
        printf("task queue is empty!\n");
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
    }
    char *str = taskQueue->data[taskQueue->head];
    printf("<pop> : %s\n", str);
    taskQueue->total--;
    if (++taskQueue->head == taskQueue->size) {
        printf("task queue reach end!\n");
        taskQueue->head = 0;
    }
    pthread_mutex_unlock(&taskQueue->mutex);
    return str;
}
