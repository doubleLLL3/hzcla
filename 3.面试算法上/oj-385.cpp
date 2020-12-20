/*************************************************************************
	> File Name: oj-385.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 07:51:24 PM CST
 ************************************************************************/
#include <queue>
#include <cstdio>  // 避免输入超时
using namespace std;
struct person {
    int t, c;     // t 到达时间；c 国籍
};
int n, con, mark[100005];  // con 目前国家数量；mark 记录不同国家的人数
int main() {
    queue<person> que;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int at, pcnt;     // at 到达时间；pcnt 人数
        scanf("%d%d", &at, &pcnt);
        // 先赶人
        // 队列不空&&有很早之前的人存在，一个人一个人地出队
        while (!que.empty() && at - que.front().t >= 86400) {
            mark[que.front().c]--;
            // 如果这个国家的人减到0了，国家数量--
            if (mark[que.front().c] == 0) {
                con--;
            }
            que.pop();
        }
        for (int j = 0; j < pcnt; j++) {
            int temp;  // 用临时变量存新来的人的国籍
            scanf("%d", &temp);
            que.push((person){at, temp});  // person{at, temp}
            mark[temp]++;
            // 如果人数刚到1，则国家数量++
            if (mark[temp] == 1) {
                con++;
            }
        }
        printf("%d\n", con);  // 输出当前国家数量
    }
    return 0;
}
