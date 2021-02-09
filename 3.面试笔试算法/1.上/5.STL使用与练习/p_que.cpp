/*************************************************************************
	> File Name: p_que.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 11 Nov 2020 07:46:11 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>  // 也是在<queue>里
using namespace std;

struct node {
    int x, y;
    double z;
    // 切记重载小于号！
    bool operator< (const node &b) const {
        return this->x < b.x;  // 完成按x从大到小输出
    }
};

int main() {
    // 整型队列
    priority_queue<int> que;
    que.push(10);
    que.push(20);
    que.push(5);
    que.push(7);
    que.push(222);
    que.push(3);
    while (!que.empty()) {
        cout << que.top() << endl;  // 默认是最大堆
        que.pop();
    }
    // 自定义结构型队列
    priority_queue<node> que2;
    que2.push((node){1, 2, 2.2});
    que2.push((node){100, 101, 3.3});
    que2.push((node){10, 1, 0.3});
    cout << endl;
    while (!que2.empty()) {
        cout << que2.top().x << endl;
        que2.pop();
    }
    
    

    return 0;
}
