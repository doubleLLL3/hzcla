/*************************************************************************
	> File Name: euler11.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 28 Oct 2020 07:50:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

// 定义方向数组，只需要4个方向：右、右下、下、左下
int dirx[4] = {0, 1, 1, 1};
int diry[4] = {1, 1, 0, -1};
int num[30][30], ans;

int main() {
    // 输入数据，从(5, 5)开始
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            cin >> num[i][j];
        }
    }
    // 遍历数组分别得到4个方向的乘积
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            // 看四个方向的乘积
            for (int k = 0; k < 4; k++) {
                // 取当前数值
                int t = num[i][j];
                // 乘相邻的3位数
                for (int l = 1; l < 4; l++) {
                    int x = i + dirx[k] * l;
                    int y = j + diry[k] * l;
                    t *= num[x][y];
                }
                ans = max(ans, t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
