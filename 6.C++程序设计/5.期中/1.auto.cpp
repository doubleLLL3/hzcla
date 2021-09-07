/*************************************************************************
	> File Name: 1.auto.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 19 Mar 2021 02:09:43 PM CST
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
#include <typeinfo>
using namespace std;

class Base {
public: 
    static int x;
private:

};

auto Base::x = 123;

void func(auto x, auto y) {}

void func(auto x, double y) {}

int main() {
    func(1, 2);
    func(1.2, 1.2);
    //auto a;
    int x;
    auto y = 12.13;
    Base b;
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(b).name() << endl;
    if (typeid(y).hash_code() == typeid(float).hash_code()) {
        cout << "float type" << endl;
    }
    if (typeid(y).hash_code() == typeid(double).hash_code()) {
        cout << "double type" << endl;
    }
    //auto int z = 123;
    map<int, int> arr;
    for (int i = 0; i < 10; i++) {
        arr[rand() % 100] = rand();
    }
    //map<int, int>::iterator iter = arr.begin();
    auto iter = arr.begin();
    while (iter != arr.end()) {
        cout << iter->first << " " << iter->second << endl;
        iter++;
    }
    for (auto x : arr) {
        cout << iter->first << " " << iter->second << endl;
    }
    
    cout << sizeof(x) << endl;
    cout << sizeof(y) << endl;
    return 0;
}
