/*************************************************************************
	> File Name: 11.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 27 Nov 2020 10:49:17 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

long long num[50];

long long f(int n) {
    if (n == 1 || n == 2) return 1;
    if (num[n]) return num[n];
    return num[n] = f(n - 1) + f(n -2);
}

int main() {
    for (int i = 0; i <= 40; i++) {
        cout << i << " : " << f(i) << endl;
    }
    return 0; 
}
