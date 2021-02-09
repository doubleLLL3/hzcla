/*************************************************************************
	> File Name: oj-516.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 08:23:15 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int n, num[100005], wcnt;  // 回来扫的时候，记录W数，顺便把O也找了
long long ans;
char str[100005];

int main() {
    cin >> n >> &str[1];  // 避免越界；数组下标[]优先级最高
    // 前缀和统计：C
    for (int i = 1; i <= n; i++) {
        if (str[i] == 'C') {
            num[i] = num[i - 1] + 1;
        } else {
            num[i] = num[i - 1];
        }
    }
    // 后缀和统计：W；顺道统计答案，找O
    for (int i = n; i > 0; i--) {
        if (str[i] == 'W') {
            wcnt++;
        }
        if (str[i] == 'O') {
            ans += (long long)num[i - 1] * wcnt;  // long long强转，避免越界
        }
    }
    cout << ans << endl;
    return 0;
}
