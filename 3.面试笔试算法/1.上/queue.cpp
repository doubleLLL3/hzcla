/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Nov 2020 07:14:49 PM CST
 ************************************************************************/

#include<iostream>
#include <queue>  // 队列的头文件
using namespace std;

struct node {
    int x, y;
};

int main() {
    // 声明定义整型队列que
    queue<int> que;
    // 入队
    for (int i = 9; i > 4; i--) {
        que.push(i);
    }
    // 判空
    while (!que.empty()) {
        // 等同于while (que.size())
        // 队首元素、元素个数
        cout << "que.front() = " << que.front() << "\tque.size() = " << que.size() << endl;
        // 出队
        que.pop();
    }

    // 声明定义自定义结构型队列que2
    queue<node> que2;
    // 两种入队方式
    // 方式一：定义对象+手动初始化
    node a;
    a.x = a.y = 6;
    que2.push(a);
    // 方式二：临时构造/初始化列表
    que2.push((node){7, 8});
    cout << que2.front().x << endl;
    que2.pop();
    node temp = que2.front();
    cout  << temp.x << " " << temp.y << endl;
    return 0;
}
