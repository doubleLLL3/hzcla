/*************************************************************************
	> File Name: euler4.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 28 Oct 2020 06:47:39 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int is_palindrome(int x) {
    int t = 0;  // 只翻转一半。比下面快
    if (x % 10 == 0) return 0;  // 注意末尾为0的情况，比如941490会被误判
    while (t < x) {
        t = t * 10 + x % 10;
        x /= 10;
    }
    return t == x || t / 10 == x;  // 考虑奇数位情况
    /*
    int t = 0, raw = x;
    while (x) {
        t = t * 10 + x % 10;
        x /= 10;
    }
    return t == raw;
    */
}

int main() {
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        // j从i开始，可避免重复 
        for (int j = i; j < 1000; j++) {
            int t = i * j;
            // 先判断回文数，再判断大小。
            /*if (is_palindrome(t)) {
                ans = max(t, ans);  // C++自带max
            }*/
            // 先判断大小，再判断回文数。比上面快
            t > ans && is_palindrome(t) && (ans = t);
            /*if (t > ans) {
                if (is_palindrome(t)) {
                    ans = t;
                }
            }*/
        }
    }
    cout << ans << endl;
    return 0;
}
