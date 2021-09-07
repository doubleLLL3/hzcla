/*************************************************************************
	> File Name: 5.bind_order.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 20 Mar 2021 11:23:28 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

void func1(int &x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}

// 可以绑定任意类型
void func1(const int &x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}

void func1(int &&x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}

void func1(const int &&x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}

//ostream &operator<<(ostream &out, const A &) {}

int main() {
    int n;
    const int y = 123;
    func1(n);  // func1(int &)
    func1(y);  // func1(const int &)
    func1(123 + 456);  // func1(int &&)
    return 0;
}
