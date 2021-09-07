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
    A() { x = 123; y = 0; }  // 需要初始化
    // 2、const方法，供编译器检查语法
    void say1() const {
        cout << y << endl;
        y += 1; 
        // x += 1;  // const方法里，变量只读
    }
    void say2() {
        x = 456;    
    }
    int x;
    // （y）逻辑上的const，记录say1方法被调用了多少次
    mutable int y;  
};

int main() {
    // 逻辑上的const
    const A a;
    a.say1();
    // a.say2();  // 1、const类型对象只能调用const方法
    a.say1();
    a.say1();
    return 0;
}
