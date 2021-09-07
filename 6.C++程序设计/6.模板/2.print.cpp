/*************************************************************************
	> File Name: 2.print.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 21 Mar 2021 07:26:10 PM CST
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

template<typename T>
class PRINT_0 {
public :
    PRINT_0 &operator()(T a) {
        cout << a << endl;
        return *this;
    }
};

class PRINT {
public :
    template<typename T>
    PRINT &operator()(T a) {
        cout << a << endl;
        return *this;
    }
};

int main() {
    PRINT_0<int> print_int;  // 需要通过<>确定类型
    print_int(123);
    print_int(456);
    PRINT_0<string> print_string;
    print_string("hello");

    PRINT print;
    print(123)("hello");

    return 0;
}
