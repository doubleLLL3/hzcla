/*************************************************************************
	> File Name: 3.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 27 Nov 2020 10:10:09 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int func(int x) {
    if (x % 10 == 0) return 0;
    int r = 0;
    while (r < x) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return x == r || r / 10 == x;
} 

int main() {
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int t = i * j;
            if (t > ans) {
                if (func(t)) {
                    ans = t;
                }
            }
        }
    }
    cout << ans <<endl;
    return 0;
}
