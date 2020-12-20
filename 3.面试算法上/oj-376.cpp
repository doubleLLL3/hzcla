/*************************************************************************
	> File Name: oj-376.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 06:42:28 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int ans, n, m, mark[1005];  // 标记数组mark

int main() {
    cin >> m >> n;
    queue<int> que;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;  // 读单词编号
        // 如果单词在内存里，没有操作
        // 如果单词不在内存里
        if (mark[t] == 0) {
            ans++;  // 需要去外存查找，ans + 1
            // 得先判断内存是否已满
            if (que.size() == m) {
                // 踢掉mark数组、队列里的最早存的单词
                mark[que.front()] = 0;
                que.pop(); 
            }
            // 无论内存是否已满，都需要在队列里存单词、打标记
            que.push(t);
            mark[t] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
