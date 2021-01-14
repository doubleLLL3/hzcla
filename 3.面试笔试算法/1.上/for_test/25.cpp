/*************************************************************************
	> File Name: 25.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 28 Nov 2020 12:01:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int func(int *n1, int *n2) {
    n2[0] = n1[0];
    for (int i = 1; i <= n2[0]; i++) {
        n2[i] += n1[i];
        if (n2[i] > 9) {
            n2[i + 1] += n2[i] / 10;
            n2[i] %= 10;
            if (i == n2[0]) {
                n2[0]++;
            }
        }
    }
    return n2[0] == 1000;
}

int main() {
    int num[2][1100] = {{1, 1}, {1, 1}};
    int a = 0, b = 1;
    for (int i = 3; 1; i++) {
        if (func(num[a], num[b]) == 1) {
            cout << i << endl;
            break;
        }
        swap(a, b);
    }
    return 0;
}
