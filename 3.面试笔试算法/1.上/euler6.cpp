/*************************************************************************
	> File Name: euler6.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 28 Oct 2020 06:58:09 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int sum = 0, psum = 0;
    for (int i = 0; i <= 100; i++) {
        sum += i;
        psum += i * i;
    }
    cout << sum * sum - psum << endl;

    return 0;
}
