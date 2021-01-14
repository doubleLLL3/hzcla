/*************************************************************************
	> File Name: 2.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 27 Nov 2020 10:05:24 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 1, c = 2, sum = 0;
    while (c <= 4000000) {
        if (c % 2 == 0) {
            sum += c;
        }
        c = b + c;
        b = c - b;
    }
    cout << sum << endl;
}
