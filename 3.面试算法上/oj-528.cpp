/*************************************************************************
	> File Name: oj-528.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 20 Nov 2020 06:53:34 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int now, step;  // now 编号
};

int n, x, y, check[105], arr[105][105];

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    queue<node> que;
    que.push((node){x, 0});
    check[x] = 1;   // 起点去重，不用再搜自己
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        // 遍历now的关系圈
        for (int i = 1; i <= n; i++) {
            // now和i认识 && 之前没搜过
            if (arr[temp.now][i] == 1 && check[i] == 0) {
                // 终点？
                if (i == y) {
                    cout << temp.step << endl; // 中间人数，所以不需要+1
                    return 0;
                }
                que.push((node){i, temp.step + 1});
                check[i] = 1;  //【去重】
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
