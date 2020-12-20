/*************************************************************************
	> File Name: 13.priority_queue.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 25 Nov 2020 07:28:16 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

// 结构定义：与顺序表类似
typedef struct priority_queue {
    int *data;      // 记录连续存储空间的首地址
    int cnt, size;
} priority_queue;

// 结构操作
// 初始化
priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));     // 建议从1号开始标号，方便计算
    q->cnt = 0;
    q->size = n;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

// 取名top更符合堆顶的描述
int top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;                    // 已满
    q->data[++(q->cnt)] = val;                          // 尾部插入
    int ind = q->cnt;                                   // ind【要调整的结点索引】
    // 交换条件：父结点的索引[ind >> 1]大于等于1；该结点大于父结点[大顶堆]
    while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];                     // 直接覆盖掉堆顶，数量减1
    int ind = 1;                                        // ind【要调整的结点索引】
    // 交换条件：左孩子索引[ind << 1]小于等于元素数量
    while ((ind << 1) <= q->cnt) {
        // 使用三个变量记录三元组
        int temp = ind, l = ind << 1, r = ind << 1 | 1; //右孩子索引计算：<< 1 | 1【左移后最后一位肯定为0】
        if (q->data[l] > q->data[temp]) temp = l;       // 先与左孩子比较，temp记录大值的索引
        // 先判断右孩子是否存在，再用temp记录大值的索引
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r; 
        if (temp == ind) break;                         // 当前结点就是三元组里最大的，结束调整
        swap(q->data[ind], q->data[temp]);              // 否则交换
        ind = temp;                                     // 更新要调整的结点索引ind
    }
    return 1;
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    priority_queue *q = init(max_op);
    // 入堆
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        push(q, val);                                   // 默认插入都成功
        printf("insert %d to the priority_queue!\n", val);
    }
    // 出堆【大顶堆，输出从大到小排列的序列】
    for (int i = 0; i < max_op; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    #undef max_op
    clear(q);
    return 0;
}
