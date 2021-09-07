/*************************************************************************
    > File Name: 1.Cat.cpp
    > Author: Double
    > Mail: doubleliu3@gmail.com
    > Created Time: Sat 06 Mar 2021 07:04:00 PM CST
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

class Animal {
public :
    //Animal() = delete;  // 子类会报错，子类构造时需要父类的显示构造函数
    Animal(string name = "mimi") : name(name) {
        cout << "Animal default construtor" << endl;
    }
    Animal(const Animal &a) : name(a.name) {
        cout << "Animal copy constructor" << endl;
    }
    Animal &operator=(const Animal &a) {
        this->name = a.name;
        return *this;
    }
    void say() {
        cout << "my name is " << name << endl;
    }
    void rename(string name) {
        this->name = name;
    }
    ~Animal() {
        cout << "Animal destructor" << endl;
    }
//private :
//    string name;
protected :  // can be access by child
    string name;
};

class Cat : public Animal {
public :
    Cat() : Animal("Cat MIMI") {
        cout << "Cat default constructor" << endl;
    }
    Cat(const Cat &c) : Animal(c) {
        cout << "Cat copy constructor" << endl;
    } 
    Cat &operator=(const Cat &c) {
        this->Animal::operator=(c);
        return *this;
    }
    void say1() {
        cout << "miaomiaomiao, my name is " << name << endl;
    }
    ~Cat() {
        cout << "Cat destructor" << endl;
    }
};

class Tigger : public Cat {
public :
    void say2() {
        cout << "houhouhuo, my name is " << name << endl;
    }
};

class A {
public :
    A() : x(123) {
        cout << "A x : " << &x << endl;  // 这是什么地址？？
    }
    int x;
};

class B : virtual public A {
public :
    void setX(int x) { 
        cout << "B set x, &x = : " << &this->x << endl; 
        this->x = x; 
        return ;
    }
};

class C : virtual public A {
public :
    int getX() { 
        cout << "C get x, &x = : " << &x << endl; 
        return x; 
    }
};

class D : public B, public C {};

class Father {
public :
    Father(const Father &f) = default;
};

class Son : private Father {
public :
    Son(const Son &s) : Father(s) {}
};

int main() {
    D d;
    cout << "&d = " << &d << endl;
    cout << "get X : " << d.getX() << endl;
    d.setX(12345);
    cout << "get X : " << d.getX() << endl;

    cout << sizeof(Animal) << " " << sizeof(Cat) << endl;
    Cat c;
    Cat a = c;  // copy
    a.say1();   // not copy superclass 
    c.say1();

    Animal *p = &c;
    p->say();

    return 0;
}
