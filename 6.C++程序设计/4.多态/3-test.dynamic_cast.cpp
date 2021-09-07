/*************************************************************************
	> File Name: 3.dynamic_cast.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 07 Mar 2021 04:37:38 PM CST
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
    A() {
        cout << "A constructor" << endl;
    }
    //virtual void say() {
    //    cout << "Class A" << endl;
    //}
    virtual ~A() {
        cout << "A destructor" << endl;
    }
};

class B : public A {
public :
    B() {
        cout << "B constructor" << endl;
    }
    //void say() override {
    //    cout << "Class B" << endl;
    //}
    virtual ~B() {
        cout << "B destructor" << endl;
    }
};

class C : public A {
public :
    C() {
        cout << "C constructor" << endl;
    }
    //void say() override {
    //    cout << "Class C" << endl;
    //}
    virtual ~C() {
        cout << "C destructor" << endl;
    }
};

int main() {
    srand(time(0));
    A *p;
    switch (rand() % 2) {
        case 0: p = new B(); break;
        case 1: p = new C(); break;
    }
    ((void **)(&p))[0] = nullptr;
    cout << dynamic_cast<void *>(p) << endl;
    cout << dynamic_cast<C *>(p) << endl;
    return 0;
}
