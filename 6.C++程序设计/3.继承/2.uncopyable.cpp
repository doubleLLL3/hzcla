/*************************************************************************
	> File Name: 2.uncopyable.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 06 Mar 2021 08:38:55 PM CST
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

class Uncopyable {
public :
    Uncopyable() = default;
    Uncopyable(const Uncopyable &) = delete;
    Uncopyable &operator=(const Uncopyable &) = delete;
};

class A : public Uncopyable {};
class B : public Uncopyable {};
class C : public Uncopyable {};

int main() { 
    A a;
    return 0;
}
