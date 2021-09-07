/*************************************************************************
	> File Name: 1.Animal.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 07 Mar 2021 02:31:58 PM CST
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
    Animal(string name) : name(name) {}
    virtual void run() = 0;
    virtual void getName() final {}
    virtual void fl1() {}
private :
    string name;
};

class Cat : public Animal {
public :
    Cat(string name) : Animal(name) {}
    void run() override final {
        cout << "I can run with four legs" << endl;
    }
    // void fll() override {}
};

class Tiger : public Cat {
public :
};

class People : public Animal {
public :
    People(string name) : Animal(name) {}
    void run() {
        cout << "I can run with two legs" << endl;
    }
};

class Bat : public Animal {
public :
    Bat(string name) : Animal(name) {}
    void run() {
        cout << "I can fly" << endl;
    }
};

class Horse : public Animal {
public :
    Horse() : Animal("Horse") {}
    void run() override {
        cout << "Horse, I can run with 4 legs" << endl;
    }
};

int main() {
    cout << "hello world" << endl;
    Horse h;
    return 0;
}
