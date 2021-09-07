/*************************************************************************
	> File Name: 8.default_delete.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 28 Feb 2021 08:02:37 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    // A() = delete;            // 禁用该函数：这个类不能进行默认构造
    // A(const A &) = default;  // 使用默认：使用编译器的默认规则 
                                //  👆没有功能上的意义，但这是C++的设计哲学
    A() = default;
private:
    A(const A &) = delete;
    A &operator=(A &a);
    const A &operator=(const A &a) const;
};

int main() {
    A a;
    A b;
    // 不能进行拷贝，即无法使用 A b = a; 以及 b = a;
    return 0;
}
