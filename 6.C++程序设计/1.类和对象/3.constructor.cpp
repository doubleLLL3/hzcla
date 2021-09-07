/*************************************************************************
	> File Name: 3.constructor.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 28 Feb 2021 02:33:53 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Data {
public :
    // Data() {}  // 当默认构造因为有参构造的添加被删除后，显式地写它，才有默认构造函数

    // 4）思考
    // 添加有参构造时，编译器帮其添加的默认构造就被删除了
    Data(int x, int y) : x(x), y(y) {
        // 使用初始化列表👆（构造行为都应该放在这，而不是在"{}"内）
        cout << "data : " << this << endl;
    }
    // 友元函数
    friend ostream &operator<<(ostream &out, const Data &d);  // 需声明在类内部，也是为了安全
private :
    int x, y;
};

class A {
public :
    // 1-1）默认构造函数
    A() : q(p), p(3, 4) {
    // 初始化列表的顺序：与成员在类中的声明顺序一致
    //  q(p)：调用Data类的拷贝构造（编译器帮其添加的）
    //  p(3, 4)：显示调用Data类的有参构造，不写的话则默认调用其默认构造（已被删除）
        cout << this << " : constructor" << endl;
        cout << "p : " << &p << endl;
        cout << "q : " << &q << endl;
    }
    // 2）转换构造函数
    A(int x) : q(x,  x), p(3, 4) {
        cout << this << " : transform constructor" << endl;
    }
    // 3）拷贝构造函数，需要传引用与const
    //  A(A a) {}                       // 会报错：不传引用的话，则会无限调用拷贝构造
    //  A(A &a) {}                      // 会报错：不使用const的话，则不兼容const类型对象的拷贝构造
    A(const A &a) : q(a.q), p(3, 4) {
        cout << this << " : copy constructor" << endl;
    }
    // 赋值运算符重载，体现出调用赋值运算符
    A &operator=(const A &a) {
        cout << this << " : operator=" << endl;
        return *this;
    }
    // 1-2）析构函数的探讨
    ~A() {
        cout << this << " : destructor" << endl;
    }
private:
    Data p, q;                          // 构造顺序与声明顺序强相关，所以构造q时可以使用p
};

// 左值引用举例
void add_one(int &x) {
    x += 1;
    return ;
}

ostream &operator<<(ostream &out, const Data &d) {
    out << "(" << d.x << ", " << d.y << ")";
    return out;
}

int main() {
    cout << "——1-1）析构顺序的探讨——" << endl;
    A a;
    /* 1-1）析构顺序的探讨 */
    A b;
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    /* 2）转换构造函数 */
    cout << "——2）转换构造函数——" << endl;
    A c = 1;    // 等价于A c(1)，不会调用赋值运算符，c = 1 才会调用
    a = 123;
    /* a = 123 过程解析 [涉及赋值运算符重载]
     *  1 转换构造（int型的123通过转换构造函数转换成临时的A类型对象x）
     *  2 赋值（临时的匿名对象x赋值给对象a）
     *  3 析构（临时对象x析构）
     */
    /* 3）拷贝构造函数 */
    cout << "——3）拷贝构造函数——" << endl;
    A d(a);     // 等价于A d = a，不会调用赋值运算符，d = a 才会调用
    
    // +左值引用举例（后续学习）
    cout << "——+ 左值引用举例——" << endl;
    int n = 3;
    cout << "n = " << n << endl;
    add_one(n);
    cout << "n = " << n << endl;
    // 如果add_one()函数接收的是
    //  1)int x，则输出的n值不变
    //  2)int &x，则输出的n值改变

    // +示范友元函数的使用
    cout << "——+ 友元函数示范——" << endl;
    Data dt(10, 9);
    cout << dt << endl;

    /* 1-1）析构顺序的探讨 */
    cout << "——1-1）析构顺序的探讨——" << endl;
    cout << "end of main" << endl;
    return 0;
    // 此时进行析构操作
}
