/*************************************************************************
	> File Name: 6.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 27 Nov 2020 10:36:50 PM CST
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
}
