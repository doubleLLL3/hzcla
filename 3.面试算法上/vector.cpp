/*************************************************************************
	> File Name: vector.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 11 Nov 2020 07:25:51 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 一维
    vector<int> v;  // leetcode里一般默认用这个结构而不是数组
    for (int i = 105; i <= 110; i++) {
        v.push_back(i);
        cout << v.size() << endl;
    }
    // 访问：使用[]，实际上是重载了这个运算符[]；还可以使用迭代器
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    // 二维
    vector<vector<int> > v2;  // 记得> >处加空格
    // 3种插入方式
    // 方式1：先插入空vector，再给第一行赋值
    v2.push_back(vector<int>());
    for (int i = 66; i <= 70; i++) {
        v2[0].push_back(i);
    }
    // 方式2：直接插入临时vector
    v2.push_back(vector<int>{5, 2, 3, 4, 5});  // 需要c++11
    v2.push_back(vector<int>(5, 0));           // 添加5个0
    // 方式3：先建立vector，手动添加元素
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(4);
    v2.push_back(v3);
    // 打印 v.size()、v[i].size()用法
    for (int i = 0; i < v2.size(); i++) {
        for (int j = 0; j < v2[i].size(); j++) {
            cout << v2[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
