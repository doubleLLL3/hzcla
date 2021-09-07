/*************************************************************************
	> File Name: 2.vtable.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 07 Mar 2021 03:26:56 PM CST
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
    A() { this->x = 200; this->y = 400; }
    virtual void say(int x) {
        cout << "this->x : " << this->x << endl;
        cout << "Class A say : " << x << endl;
    }
    virtual void run() {
        cout << "Class A run" << endl;
    }
    void reg1() {
        cout << "reg 1 function" << endl;
    }
    void reg2() {
        cout << "reg 2 function" << endl;
    }
    void reg3() {
        cout << "reg 3 function" << endl;
    }
    int x, y;
};

class B : public A {
public :
    B() { x = 300; }
    void say(int x) override {
        cout << "Class B say : " << x << endl;
    }
};

class C : public A {
public :
    C() { x = 400; }
    void run() override {
        cout << "Class C run" << endl;
    }
};

#define TEST(a) test(a, #a)
void test(A &a, string class_name) {
    cout <<  "Object " << class_name << endl;
    a.say(123);
    a.run();
    cout << "========" << endl << endl;
    return ;
}

typedef void (*func)(void *, int);

int main() {
    A a;
    B b;
    C c;
    TEST(a);
    TEST(b);
    TEST(c);
    ((void **)(&b))[0] = ((void **)(&c))[0]; // 自己会丢掉吗??同学问题
    TEST(b);
    ((func **)(&b))[0][0](&b, 100);  // 需要传入this指针，才能正确换值！ 
    // this->x 访问的是b对象中的x，而不是A的x
    
    //cout << &A << endl;
    //cout << &A::say << endl;
    //void (*p = &A::say)();  // 没有this指针概念！
    // 成员方法指针
    void (A::*k)(int);  // p(A *, )
    k = &A::say;
    (a.*k)(123567);

    void (A::*p[3])();
    p[0] = &A::reg1;
    p[1] = &A::reg2;
    p[2] = &A::reg3;
    for (int i = 0; i < 10; i++) {
        (a.*p[rand() % 3])();
    }

    int A::*q;
    q = &A::x;
    cout << (a.*q) << endl;
    q = &A::y;
    cout << (a.*q) << endl;
    return 0;
}
