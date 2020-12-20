/*************************************************************************
	> File Name: oj-485.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 04:47:00 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int n, num[105], ans, sum, avg;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >>num[i];
        sum += num[i];  // 边读边求和
    }
    avg = sum / n;  // 得到平均数
    // 最后一堆牌不用考虑，必定满足条件
    for (int i = 0; i < n - 1; i++) {
        if (num[i] != avg) {
            ans++;
            // 无论加减
            num[i + 1] += num[i] - avg;
            // 可写可不写，这个不影响答案
            num[i] = avg; 
        }
    }
    cout << ans << endl;
    return 0;
}
