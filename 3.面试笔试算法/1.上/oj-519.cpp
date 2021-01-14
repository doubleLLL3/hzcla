/*************************************************************************
	> File Name: oj-519.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Nov 2020 06:16:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    long long ans = 0, left, right;  // 注意变量过多易导致重名问题
    cin >> left >> right;
    // 循环1：枚举一堆数
    for (int i = 0; i < 10; i++) {
        // 循环2：枚举一个数
        for (int j = 0; j < 10; j++) {
            // 如果相等直接continue
            if (i == j) {
                continue;
            }
            // 循环3：枚举数长 10^16数长是17
            for (int k = 3; k <= 17; k++) {
                // 循环4：枚举位置 1 ~ k
                for (int l = 1; l <= k; l++) {
                    // 如果一堆数对应的i为0，一个数j又不在第1位
                    if (i == 0 && l != 1) {
                        break;
                    }
                    // 如果一个数j为0，而它又在第1位
                    if (j == 0 && l == 1) {
                        continue;
                    }
                    long long t = 0;
                    // 循环5：构造优雅数，根据i、j、k、l已经可以得到该数了
                    for (int m = 1; m <= k; m++) {
                        if (m == l) {
                            t = t * 10 + j;
                        } else {
                            t = t * 10 + i;
                        }
                    }
                    if (left <= t && t <= right) {
                        ans++;
                    }
                }   
            }
        }
        
    }
    cout << ans <<endl;
    return 0;
}
