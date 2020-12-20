/*************************************************************************
	> File Name: oj-240.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 02:18:36 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
// 【边长数组】
int num[10] = {0, 1};   // 忽略第0位
char mmap[1000][1000];  // 大于3 ^ 6 = 729即可 
// 初始化等比数组
void init() {
    for (int i = 2; i <= 7; i++) {
        num[i] = num[i - 1] * 3;
    }
}
// 【存图形数组】
void func(int x, int y, int n) {
    if (n == 1) {
        mmap[x][y] = 'X';
        return ;
    }
    // 5个小图形 func(., ., n - 1)
    // num[n] 图形n对应的边长
    // 5个的顺序不重要
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] /3 * 2, y + num[n] / 3 * 2, n - 1);
}
int main() {
    init();
    func(1, 1, 7);  // 直接存好数组即可
    int t;
    while (cin >> t) {
        if (t == -1) break;
        // 根据输入t得到边长num[t]，再输出边长大小的图形即可
        for (int i = 1; i <= num[t]; i++) {
            for (int j = 1; j <= num[t]; j++) {
                if (mmap[i][j] == 'X') {
                    cout << 'X';
                } else {
                    // 注意对于非X输出空格；也可以在存数组时存好空格
                    cout << ' ';
                }
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}
