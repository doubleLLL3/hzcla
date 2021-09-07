/*************************************************************************
	> File Name: 1.overload.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 28 Feb 2021 08:46:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

// 与👇冲突，尽管输出和实现不一样，可合并
/*
double func(int x) {
    cout << "func(int x)";
    return x * 2;
}
*/

// 与👆冲突，函数参数存在默认值，可合并
int func(int x, int y = 2) {
    cout << "func(int x, int y = 2) = ";
    return x * y;
}

double func(double x) {
    cout << "func(double x) = ";
    return x * x;
}

float func(float x) {
    cout << "func(float x) = ";
    return x * x * 2;
}

int main() {
    cout << "func(2) = "<< func(2) << endl;
    cout << "func(2, 4) = " << func(2, 4) << endl;
    cout << "func(2.3) = " << func(2.3) << endl;               // 小数默认为double类型
    cout << "func((float)2.3) =" << func((float)2.3) << endl;  // 可通过(float)2.3转换为float类型
    return 0;
}
