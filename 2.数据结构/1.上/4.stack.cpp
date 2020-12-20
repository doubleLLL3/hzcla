/*************************************************************************
	> File Name: 4.stack.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 17 Nov 2020 07:45:16 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)
typedef struct Stack {
    int *data;
    int size, top;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack)); // malloc栈的空间
    s->data = (int *)malloc(sizeof(int) * n);  // malloc栈的数据域的空间
    s->size = n;
    s->top = -1;                               // 空栈的top指向-1
    return s;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}
// 输出栈顶元素
int top(Stack *s) {
   return s->data[s->top];
}
// 判空，看top即可
int empty(Stack *s) {
    return s->top == -1;
}

int expand(Stack *s) {
    int extr_size = s->size;
    int *p;
    while (extr_size) {
        // 可以采用realloc，顺序是正常的，不像循环队列
        p = (int *)realloc(s->data, sizeof(int) * (s->size + extr_size));
        if (p) break;
        extr_size >>= 1;
    }
    if (p == NULL) return 0;
    // 扩容成功则更改栈的数据域data和size，top不变
    // 不需要释放s->data的地址，因为realloc成功会考虑free原地址
    s->data = p;
    s->size += extr_size;
    //free(p);  // 不可以！会把要用的地址free掉
    return 1;
}
// 入栈
int push(Stack *s, int val) {
    if (s == NULL) return 0;     // 当前栈不存在
    // 栈满否？
    if (s->top == s->size - 1) {
        if (!expand(s)) return 0;// 添加扩容操作
        printf(GREEN("expand successfully! Stack->size = (%d)\n"), s->size);
    }
    s->data[++(s->top)] = val;  // 直接插入即可
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;  // 栈不存在
    if (empty(s)) return 0;   // 栈为空
    s->top -= 1;              // top - 1即可 
    return 1;
}

void output(Stack *s) {
    if (s == NULL) return ;
    printf("[");
    // 输出不是出栈，站在上帝视角看看而已
    for (int i = 0; i <= s->top; i++) {
        i && printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return ;
}
int main() {
    srand(time(0));
    #define max_op 20
    Stack *s = init(4);
    int flag;
    for (int i = 0; i < max_op; i++) {
        // 对于栈，不需要随机生成索引值了
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to the Stcak = %d\n", val, push(s, val));
            } break;
            case 3: {
                // 取top()前先判空，因为top=-1的存在
                flag = !empty(s);
                // 下面分两行写，和系统栈有关，top()和pop()的执行顺序
                flag && printf("pop %d from the Stack\n", top(s));
                printf("result = %d\n", pop(s));  // pop里有判空，不需要flag控制
                // 先执行pop，再执行top
                //flag && printf("pop %d from the Stack = %d\n", top(s), pop(s));
            } break;
        }
        output(s), printf("\n");
    }
    #undef max_op
    clear(s);
    return 0;
}
