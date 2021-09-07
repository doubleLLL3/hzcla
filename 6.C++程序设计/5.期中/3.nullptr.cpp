/*************************************************************************
	> File Name: 3.nullptr.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 19 Mar 2021 03:35:11 PM CST
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

void func(int x) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << x << endl;
    return ;
}

void func(int *x) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << x << endl;
    return ;
}

int main() {
    //cout << NULL << endl;
    //cout << nullptr << endl;
    int *P_NULL = NULL, *P_NULLPTR = nullptr;
    cout << P_NULL << endl;
    cout << P_NULLPTR << endl;
    
    //func(NULL);  // 本质上是一个整数0，还代表空地址，对编译器来说不知道了
    func(nullptr);
    cout << typeid(NULL).name() << endl;
    cout << typeid(nullptr).name() << endl;
    return 0;
}
