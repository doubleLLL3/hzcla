/*************************************************************************
	> File Name: oj-569.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 08:15:34 PM CST
 ************************************************************************/
#include <stack>
#include <iostream>
#include <cstdio>
using namespace std;
struct node {
    double s, ws;  // s 盐的质量；ws 总质量 都定义的double类型，方便算浓度
};
int main() {
    double ws0, c0, s0;   // 初始质量，初始浓度，初始的盐质量
    cin >> ws0 >> c0;
    s0 = ws0 * c0 / 100;  // 求出初始的盐，注意%号转换
    int n;
    cin >> n;
    stack<node> sta;      // 建立栈
    for (int i = 0; i < n; i++) {
        char t;  // 读操作字符
        cin >> t;
        // 加溶液操作
        if (t == 'P') {
            double wst, ct, st;  // 读此次操作的溶液信息
            cin >> wst >> ct;
            st = wst * ct / 100; // 同样，求盐的质量
            ws0 += wst;
            s0 += st;
            sta.push((node){st, wst});
        } else {
        // 撤销操作
            if (sta.size()) {
                // 先减，再弹栈
                ws0 -= sta.top().ws;
                s0 -= sta.top().s;
                sta.pop();
            }
        }
        printf("%d %.5f\n", (int)ws0, s0 / ws0 * 100);  // 保留5位小数
    }
    return 0;
}
