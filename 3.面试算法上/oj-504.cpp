/*************************************************************************
	> File Name: oj-504.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 06:18:48 PM CST
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;

string str;  // 读入的大整数
int n;       // 要删的次数（题中为s）

int main() {
    cin >> str >> n;
    for (int i = 0; i < n; i++) {
        // 默认删除最后一位数，因为此时最大数已在最后
        int ind = str.size() - 1; 
        for (int j = 0; j < str.size() - 1; j++) {
            if (str[j] > str[j + 1]) {
                ind = j;
                break;
            }
        }
        // str里的替换函数，即删除操作
        str.replace(ind, 1, "");
    }
    int flag = 0;
    // 处理前导0
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') {
            flag = 1;
        }
        if (flag == 1) {
            cout << str[i];
        }
    }
    cout << endl;


    return 0;
}
