/*************************************************************************
	> File Name: euler14.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 28 Oct 2020 08:22:41 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

// 记忆数组：存的是某个数对应的序列长度
int num[10000000];  // 为什么给1000万？因为其生成的项可能超过100万，该值可调整

int func(long long n) {
    if (n == 1) return 1;  // n为1时，序列长度为1
    if (n < 10000000 && num[n]) return num[n];
    int t;  // 这里要用t记录一下，因为存的时候还要判断n是否存的进数组
    if (n % 2 == 0) {
        t = func(n / 2) + 1;  // + 1代表：序列长度 + 1，不需要用额外的计数器
    } else {
        t =  func(3 * n + 1) + 1;
    }
    // 必须根据n判断是否存储t
    if (n < 1000000) {
        num[n] = t;
    }
    return t;
}

int main() {
    int ans = 1;
    int max_len = 1;
    for (int i = 2; i <= 1000000; i++) {
        // 每次都还计算fun(ans)的值
        /*if (func(ans) < func(i)) {
            ans = i;
        }*/
        // 如果把func(ans)存一下，更快：0.483→0.131，范围2~100000
        int len = func(i);  // 避免重复func，把func(i)也存一下
        if (max_len < len) {
            ans = i;
            max_len = len;
        }
    }
    cout << ans << endl;
    return 0;
}
