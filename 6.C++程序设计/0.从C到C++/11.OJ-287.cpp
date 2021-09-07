/*************************************************************************
	> File Name: 13.OJ-287.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 27 Feb 2021 05:31:39 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

// 方式一
struct CMP {
    bool operator()(int a, int b) {
        return a > b;       // 实现最小堆
    }
};

// 方式三
template<typename T>
struct CMP2 {
    bool operator()(T a, T b) {
        return b < a;
    }
};

int main() {
    priority_queue<int, vector<int>, CMP> q;              // 方式一：CMP是类型
    // vector：实现的基本数据结构；CMP：重载()运算符，改变比较规则
    
    // priority_queue<int, vector<int>, greater<int>> q;  // 方式二：greater是模板类
    // priority_queue<int, vector<int>, CMP2<int>> q;     // 方式三：CMP2是自定义模板类
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        q.push(a);
    }
    int sum = 0;            // sum：记录总消耗
    for (int i = 1; i < n; i++) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        sum += a + b;
        q.push(a + b);      // 合并果子后再入队
    }
    cout << sum << endl;
    return 0;
}
