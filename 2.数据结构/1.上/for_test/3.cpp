/*************************************************************************
	> File Name: 3.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 05 Dec 2020 09:56:14 AM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;
    q->cnt = 0;
    return q;
}

int front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->cnt == 0;
}

int expand(Queue *q) {
    // 扩容成功后
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        p[j] = q->data[(i + j) % q->length];
    }
    free(q->data);
    q->data = p;
    // 更新队列里的信息
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->length) {
        if (!expand(q)) return 0;
        printf(GREEN("expand successful! Queue->size(%d)\n"), q->length);
    }
    q->data[q->tail++] = val;
    if (q->tail == q->length) q->tail = 0;
    q->cnt++;
    return 1;
}

int pop(Queu *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->length) q->head = 0;
    q->cnt--;
    return 1;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

