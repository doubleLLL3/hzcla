/*************************************************************************
	> File Name: oj-477.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 02:09:02 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int ans = 0, last = -1;  // last 上一个元音位置 
    char s[105];
    cin >> s;
    // s[i]为'\0'结束
    for (int i = 0; s[i]; i++) {
        // 判断当前字符是不是元音
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            if (last != -1) {
                ans = max(ans, i - last);
            }
            last = i;
        }
    }
    cout << ans << endl;

    return 0;
}
