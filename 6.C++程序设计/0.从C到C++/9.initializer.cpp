/*************************************************************************
	> File Name: 8.const.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 27 Feb 2021 03:55:55 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public : 
    //A() { x = 123; y = 0; }  // 1、赋值运算符
    A() : x(123), y(x + 1) {}  // 2、构造函数（初始化列表），先x，后y
    void say1() const {
        cout << y << endl;
        y += 1;
    }
    void say2() {
        x = 456;    
    }
    int x;
    mutable int y;
};

int main() {
    const A a;
    a.say1();
    a.say1();
    a.say1();
    return 0;
}
