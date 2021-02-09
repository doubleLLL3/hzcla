#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <haizei/test.h>
#include <haizei/linklist.h>

// 带链表外骨骼的结构体存储
Function func_head, *func_tail = &func_head;
struct LinkNode *temp_next;
// 统计TEST通过情况
struct FunctionInfo haizei_test_info;
int RUN_ALL_TESTS() {
    // 使用链表节点node做循环条件：func_head里没有数据, p指向NULL即结束
    for (struct LinkNode *p = func_head.node.next; p; p = temp_next) {
        haizei_test_info.total = 0, haizei_test_info.success = 0;
        // 获得节点对应结构体的首地址
        Function *func = Head(p, Function, node);
        // 使用->间接访问结构体里的变量
        printf(GREEN("[====RUN====] ") RED_HL(RED_UL("%s\n")), func->str);
        func->func();
        printf("func: %p\n&(func->func): %p\n&(func->str): %p\n&(func->node): %p\n",
               func, &(func->func), &(func->str), &(func->node));
        printf("func->str的地址: %p\nstrdup的str地址: %p\n", 
              &(func->str), func->str);
        printf("func size: %lu\n", sizeof(func));
        temp_next = p->next;      // 释放func前存储下一个节点的地址
        free((void *)func->str);  // 释放strdup出来的空间，先将const *类型转为void *，避免free const *警告
        free(func);               // 释放colloc出来的func空间
        func = NULL;              // 拒绝func成为野指针
        // 需要先使用1.0 * 提升数据类型，否则小于1的int值会变为0
        // 使用1.0而不用100.0是为了防止溢出
        double rate = 1.0 * haizei_test_info.success / haizei_test_info.total * 100.0;
        printf(PURPLE("[  "));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(PURPLE("  ] ") "total : %d\t\tsuccess : %d\n",
              haizei_test_info.total,
              haizei_test_info.success
        );
    }
    return 0;
}
void add_function(TestFuncT func, const char *str) {
    // calloc、strdup的内存记得free释放
    Function *temp = (Function *)calloc(1, sizeof(Function));
    temp->func = func;
    temp->str = strdup(str);
    func_tail->node.next = &(temp->node);  // 尾插法
    func_tail = temp;
    return ;
}
