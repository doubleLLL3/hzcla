/*************************************************************************
	> File Name: euler2.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 28 Oct 2020 06:37:16 PM CST
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
        //a = b;
        b = c - b;
    }
    cout << sum << endl;
    return 0;
}
