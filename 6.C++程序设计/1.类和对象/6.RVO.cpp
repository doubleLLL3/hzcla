/*************************************************************************
	> File Name: 6.RVO.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 28 Feb 2021 06:34:48 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Data {
public :
    Data() {
        cout << "Data : default constructor" << endl;
    }
    Data(const Data &a) {
        cout << "Data : copy constructor" << endl;
    }
};

class A {
public : 
    A() {
        cout << this << " : default constructor" << endl;
    }
    A(int x) : x(x) {
        cout << this << " : transform constructor" << endl;
    }
    A &operator=(const A &a) {
        cout << this << " : operator=" << endl;
        return *this;
    }
    int x;
    Data d;
};

A func() {
    A temp(69);
    cout << "&temp = " << &temp << endl;
    return temp;
}

int main() {
    A a = func();   // 通过func()返回值，类似拷贝构造的形式初始化a
    cout << "&a = " << &a << endl;
    cout << a.x << endl;
    
    cout << endl << "============" << endl << endl;

    a = func();     // 赋值运算，也存在一次优化
    return 0;
}
