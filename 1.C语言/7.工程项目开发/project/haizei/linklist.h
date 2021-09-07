/*************************************************************************
	> File Name: linklist.h
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 07 Nov 2020 07:07:22 PM CST
 ************************************************************************/
#ifndef _LINKLIST_H
#define _LINKLIST_H

// 字段name在结构体T内的偏移量 地址转换成long整型即可
#define offset(T, name) (long)&(((T *)(NULL))->name)
// 通过指针p对应字段name在结构体T中的偏移量，计算指针p所在结构体T的首地址
#define Head(p, T, name) (T *)((char *)(p) - offset(T, name))

// 链表的结构定义
struct LinkNode {
    struct LinkNode *next;  // 指向下一个节点
};

#endif
