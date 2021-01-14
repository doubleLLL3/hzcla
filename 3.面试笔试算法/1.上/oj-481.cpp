/*************************************************************************
	> File Name: oj-481.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 03:56:25 PM CST
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int r, ans[15][2];

void p(int n) {
    int a1 = 0, a2 = 0;  // 记录两队总比分
    for (int i = 1; i < n; i++) {
        a1 += ans[i][0];
        a2 += ans[i][1];
        cout << ans[i][0] << ":" << ans[i][1] << endl;
    }
    cout << a1 << ":" << a2 << endl;
}
int main() {
    cin >> r;  // 读入半径
    for (int i = 1; i <= 10; i++) {
        int num1[10] = {0}, num2[10] = {0};
        // 读入本轮冰壶分布情况
        for (int j = 0; j < 8; j++) {
            cin >> num1[j];
            // 读入-1时停止比赛
            if (num1[j] == -1) {
                p(i);  // 输出前i - 1轮得分，当前进行到第i轮
                return 0;
            }
        }
        for (int j = 0; j < 8; j++) {
            cin >> num2[j];
        }
        // 只有8个数，排序消耗不大
        sort(num1, num1 + 8);
        sort(num2, num2 + 8);
        if (num1[0] < num2[0]) {
            for (int j = 0; j < 8; j++) {
                // 不得分的情况
                if (num1[j] > r || num1[j] >= num2[0]) break;
                ans[i][0]++;
            }
        } else {
            for (int j = 0; j < 8; j++) {
                if (num2[j] > r || num2[j] >= num1[0]) break;
                ans[i][1]++;
            }
        }
    }
    p(11);  // 此时比完10轮，到第11轮了
    return 0;
}
