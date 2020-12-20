/*************************************************************************
	> File Name: oj-479.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 02:26:06 PM CST
 ************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int a11[6000][2], a21[3000][2], ind1, ind2;

void p() {
    // 先输出11分制下的结果
    for (int i = 0; i <= ind1; i++) {
        cout << a11[i][0] << ":" << a11[i][1] << endl;
    }
    cout << endl; 
    for (int i = 0; i <= ind2; i++) {
        cout << a21[i][0] << ":" << a21[i][1] << endl;
    }
}

int main() {
    char s[30];  // 每行最多25个字符
    // cin >> 遇到换行会停止输入，当读到EOF时，cin返回1停止while
    while (cin >> s) {
        for (int i = 0; s[i]; i++) {
            // 比赛是否结束？
            if (s[i] == 'E') {
                p();  // 最后输出结果
                return 0;
            }
            // 给不同的选手加分
            if (s[i] == 'W') {
                a11[ind1][0]++;
                a21[ind2][0]++;
            } else {
                a11[ind1][1]++;
                a21[ind2][1]++;
            }
            // 是否结束该局？必有一个人分数大于11或21，且分差大于2
            if ((a11[ind1][0] >= 11 || a11[ind1][1] >= 11) && abs(a11[ind1][0] - a11[ind1][1]) >= 2) {
                ind1++;
            }
            if ((a21[ind2][0] >= 21 || a21[ind2][1] >= 21) && abs(a21[ind2][0] - a21[ind2][1]) >= 2) {
                ind2++;
            }
        }
    }
}
