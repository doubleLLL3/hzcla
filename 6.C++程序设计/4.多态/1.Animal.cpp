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
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
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

int main() {
    #define MAX_N 10
    srand(time(0));
    Animal **zoo = new Animal*[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        switch (rand() % 3) {
            case 0: zoo[i] = new Cat("cat"); break;
            case 1: zoo[i] = new People("people"); break;
            case 2: zoo[i] = new Bat("bat"); break;
        }
    }
    for (int i = 0; i < MAX_N; i++) zoo[i]->run();
    return 0;

    Cat a("Tom");
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
    return 0;
}
