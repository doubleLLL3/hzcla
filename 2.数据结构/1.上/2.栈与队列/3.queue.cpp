/*************************************************************************
	> File Name: 3.queue.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 12 Nov 2020 08:20:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"  // a不要加#
#define GREEN(a) COLOR(a, 32)

typedef struct Queue {
    int *data;  // 使用指针变量定义队列的数据域
    int head, tail, length, cnt;
} Queue;

Queue* init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;  // 方式二：tail指向最后一个元素的【下一个】地址
    q->cnt = 0;             // 方便循环队列判空~
    return q;
}

int front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    // return q->head == q->tail;
    return q->cnt == 0;
}
// 扩容操作
int expand(Queue *q) {
    int extr_size = q->length;
    int *p;
    while (extr_size) {
        // 循环队列
        p = (int *)malloc(sizeof(int) * (q->length + extr_size));
        if (p) break;  // 如果p不为空，说明扩容成功！
        extr_size >>= 1;
    }
    if (p == NULL) return 0;  // 等价于 if (extr_size == 0)
    // 扩容成功后，转移数据，【调整指针】
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        p[j] = q->data[(i + j) % q->length];  // 【精髓】取余操作
    }
    free(q->data);            // 此时释放原来的数据
    // 更新队列的里的信息，除了cnt都要变
    q->data = p;
    q->length += extr_size;
    q->head = 0;
    q->tail = q->cnt;
    return 1;
}
// 入队
int push(Queue *q, int val) {
    if (q == NULL) return 0;                // 队列不存在
    if (q->cnt == q->length) {
        if (!expand(q)) return 0;           // +触发扩容操作
        printf(GREEN("expand successfully! Queue->size(%d)\n"), q->length);
    }
    q->data[q->tail++] = val;
    if (q->tail == q->length) q->tail = 0;  // 直接置0即可，取模运算慢
    q->cnt++;
    return 1;
}
// 出队
int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;  // 队列为空
    q->head++;               // 不需要free，因为没有为一个元素单独开辟空间
    if (q->head == q->length) q->head = 0;   // head也可能越界
    q->cnt--;
    return 1;
}

void clear(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return ;
}

void output(Queue *q) {
    if (q == NULL) return ;
    printf("Queue : [");
    for (int i = q->head, j = 0; j < q->cnt; i++, j++) {
        j && printf(", ");  // 添加一个变量j，用来控制该格式
        printf("%d", q->data[i % q->length]);  // 取模得到真实的位置
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Queue *q = init(2);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to the Queue! ", val);
                printf("result = %d\n", push(q, val));
            } break;
            case 3: {
                printf("pop %d from the Queue! ", front(q));
                printf("result = %d\n", pop(q));
            } break;
        }
        output(q), printf("\n");
    }
    #undef max_op
    clear(q);
    return 0;
}
