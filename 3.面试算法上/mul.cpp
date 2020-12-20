/*************************************************************************
	> File Name: mul.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 30 Oct 2020 06:29:28 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // 定义
    char s1[1005], s2[1005];
    int n1[1005] = {0}, n2[1005] = {0}, ans[1005] = {0};  // ans：答案数组
    // ↑有坑，只能定义为int类型，不能定义为char类型，因为下面的乘积累加过程可能超过范围
    cin >> s1 >> s2;
    n1[0] = strlen(s1), n2[0] = strlen(s2);
    ans[0] = n1[0] + n2[0] - 1;  // ans长度以小的为准，少了再加
    // 输入处理：翻转后存值
    for (int i = 1, j = n1[0] - 1; i <= n1[0]; i++, j--) {
        n1[i] = s1[j] - '0';
    }
    for (int i = 1, j = n2[0] - 1; i <= n2[0]; i++, j--) {
        n2[i] = s2[j] - '0';
    }
    // 运算：乘积结果
    for (int i = 1; i <= n1[0]; i++) {
        for (int j =1; j <= n2[0]; j++) {
            ans[i + j -1] += n1[i] * n2[j];
        }
    }
    // 处理进位
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] > 9) {
            ans[i +1] += ans[i] / 10;
            ans[i] %= 10;
            if (i == ans[0]) {
                ans[0]++;
            }
        }
    }
    for (int i = ans[0]; i > 0; i --) {
        cout << ans[i];
    }
    cout << endl;
}
