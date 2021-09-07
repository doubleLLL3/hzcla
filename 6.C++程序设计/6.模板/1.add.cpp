/*************************************************************************
	> File Name: 1.add.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 21 Mar 2021 06:42:52 PM CST
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

class A {
public :
    A() = delete;
    A(int x) : x(x) {}
    A operator+(const A &a) {
        return A(x + a.x);
    }
    friend ostream &operator<<(ostream &, const A &);
private:
    int x;
};

ostream &operator<<(ostream &out, const A &a) {
    out << a.x;
    return out;
}

// 模板的声明 [而不是实现]
template<typename T, typename U>
decltype(T() + U()) add_0(T a, U b) {
// T() U()的临时匿名变量，必须使用默认构造函数
    return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
// T() U()的临时匿名变量，使用默认构造函数
    return *a + *b;
}

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
// T() U()的临时匿名变量，使用默认构造函数
    return a + b;
}

/*
double add(double a, double b) {
    return a + b;
}
*/

auto func(int a, int b) -> int {
    return a + b;
}

int main() {
    A a(3), b(5);
    cout << (a + b) << endl; 
    cout << add(a, b) << endl;
    cout << add(1, 2) << endl;
    cout << add(1.2, 2.5) << endl;
    cout << add(1.2, 2) << endl;  // 推导不出来
    cout << add<double>(1.2, 2) << endl; // 显示调用模板
    decltype(1 + 2) x;  // 以1 + 2的类型推导出类型
    cout << typeid(x).name() << endl;
    int n = 123, m = 456;
    int *p = &n, *q = &m;
    int **pp = &p, **qq = &q;
    cout << add(p, q) << endl;
    cout << add(pp, qq) << endl;

    return 0;
}
