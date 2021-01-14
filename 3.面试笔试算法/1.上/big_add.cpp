/*************************************************************************
	> File Name: big_add.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 28 Oct 2020 08:47:33 PM CST
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

int num1[105], num2[105], sum[105];
char s1[105], s2[105];

int main() {
    cin >> s1 >> s2;
    // num第0位存储大数的位数
    num1[0] = strlen(s1);
    num2[0] = strlen(s2);
    // 将字符串大数反转存储在num里，主要解决低位对齐问题
    for (int i = 0, j = num1[0]; i < num1[0]; i++, j--) {
        num1[j] = s1[i] - '0';
    }
    for (int i = 0, j = num2[0]; i < num2[0]; i++, j--) {
        num2[j] = s2[i] - '0';
    }
    sum[0] = max(num1[0], num2[0]); // 结果sum的第0位存储最大的位数
    // 依次加在数组对应索引里
    for (int i = 1; i <= sum[0]; i++) {
        sum[i] = num1[i] + num2[i];
    }
    // 处理进位
    //for (int i = 1; i <= sum[0]; i++) {
    // 可以直接不处理最高位~因为倒着输出一开始输出两位数即可
    for (int i = 1; i < sum[0]; i++) {
        if (sum[i] > 9) {
            sum[i + 1] += sum[i] / 10;  // 对于两个数相加，++也可以
            sum[i] %= 10;  // 对于两个数相加，减10也可以
            // 如果是最后一位进位，需要把位数sum[0] + 1
            /*if (i == sum[0]) {
                sum[0]++;
            }*/
        }
    }
    // 数是倒着存的，倒着输出
    for (int i = sum[0]; i > 0; i--) {
        cout << sum[i];
    }
    cout << endl;
    return 0;
}
