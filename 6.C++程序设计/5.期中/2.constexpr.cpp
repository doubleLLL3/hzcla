/*************************************************************************
	> File Name: 2.constexpr.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 19 Mar 2021 03:08:47 PM CST
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

int f0(int x) {
    return 2 * x;
}

constexpr int f(int x) {
    return 2 * x;
}

constexpr int func(int x) {
    if (x == 1) return 1;
    return x * func(x - 1);
}

class A {
public:
    constexpr A(int x) {}
};

int main() {
    int n;
    cin >> n;
    const int x = n + 123;
    //constexpr int y = n + 123;
    constexpr int y = 123;
    constexpr int y2 = f(123);
    constexpr int y3 = func(5);
    cout << "func(): " << y3 << endl;
    const A a(123);
    constexpr A b(123);
    /*
    const int x = 123;
    constexpr int y = 123;
    //x = 456;
    //y = 456;
    *(const_cast<int *>(&x)) = 456;
    *(const_cast<int *>(&y)) = 456;
    cout << &x << endl;
    cout << const_cast<int *>(&x) << endl;
    cout << x << endl;  // 编译期优化了 123
    cout << y << endl;  // 编译期优化了 123
    cout << *(&x) << endl;  // 没变化？
    cout << *(&y) << endl;  // 没变化？
    return 0;
    */
    const char *p = (const char *)&x;
}
