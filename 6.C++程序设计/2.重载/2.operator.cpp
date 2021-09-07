/*************************************************************************
	> File Name: 2.operator.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 28 Feb 2021 09:02:37 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Point {
public :
    Point();
    Point(int, int);
    Point operator+(const Point &); // "+"的类内重载
    Point &operator+=(int);
    // 为什么+=返回引用，而+不返回引用？理解两种加法的逻辑：
    //  1、(a + b) + c;   中括号内会产生新的对象，不影响原对象
    //  2、(a += 2) += 2; 中括号内的返回值直接作用在a上；
    //                      并且连用+=时，才可以保证后面的+=可以改变a
    
    // [] 数组对象化
    int operator[](string);

    // 供->示例
    int getX() { return this->x; }
    int getY() { return this->y; }
private :
    int x, y;
    // 友元函数：为类外函数声明
    friend Point operator+(const Point &, const Point &); 
    friend ostream &operator<<(ostream &, const Point &);  
};

class ADD {
public :
    ADD(int c) : c(c) {}
    // () 函数对象化
    int operator()(int a, int b) {
        return a + b + c;
    }
private :
    int c;
};

class PPoint {
public :
    PPoint(Point *p) : p(p) {}
    // -> 指针对象化；无参，返回地址
    Point *operator->() { return p; }
private :
    Point *p;
};

Point::Point() : Point(0, 0) {}     // 委托构造（委托下面的有参构造函数）
Point::Point(int x, int y) : x(x), y(y) {}

// "+"运算符重载
//  方式一：类外重载（需声明为友元函数）
Point operator+(const Point &a, const Point &b) {
    // a："+"左边的对象，b："+"右边的对象
    cout << "outer operator+" << endl;
    Point c(a.x + b.x, a.y + b.y);
    return c;
}

//  方式二：类内重载
//  1、记得通过类名声明限定域，Point::
//  2、只需一个参数，因为存在this指针->当前对象
//  3、优先级：高于类外重载❗️开发者更先看到这个
Point Point::operator+(const Point &a) {
    cout << "inner operator+" << endl;
    Point c(x + a.x, y + a.y);      // 可以省略this指针
    return c;
}

// "+="运算符重载
Point &Point::operator+=(int n) {
    x += n, y += n;
    return *this;                   // 返回当前对象
}

// []
int Point::operator[](string s) {
    if (s == "x") return x;
    if (s == "y") return y;
    return 0;
}

// 输出Point类对象：类外重载
ostream &operator<<(ostream &out, const Point &a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
    Point a(3, 4);
    Point b(7, 9);

    // 1）"+" 重载
    cout << "——\"+\" 重载——" << endl;
    Point c = a + b;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    
    // 2）"+=" 重载
    cout << "——\"+=\" 重载——" << endl;
    a += 2;
    cout << a << endl;

    // 3）[] 数组对象：a表现得像一个数组，但实际上是一个对象
    cout << "——[]——" << endl;
    cout << a["x"] << endl;  
    cout << a["y"] << endl;
    
    // 4）() 函数对象：add表现得像一个函数，但实际上是一个对象
    cout << "——()——" << endl;
    ADD add(5);
    cout << add(6, 7) << endl; 

    // 5）-> 指针对象：p表现得像一个指针，但实际上是一个对象
    cout << "——->——" << endl;
    PPoint p = &a;                  // p指向Point类型对象的地址
    cout << "(" << p->getX() << ", " << p->getY() << ")" << endl;

    return 0;
}
