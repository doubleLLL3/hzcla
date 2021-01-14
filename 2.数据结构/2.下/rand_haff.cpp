/*************************************************************************
	> File Name: rand_haff.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 26 Dec 2020 04:54:11 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    srand(time(0));
    // 26个字符
    int arr[26], sum =0;
    // 随机生成出现次数：0 ~ 999
    for (int i = 0; i < 26; i++) {
        arr[i] = rand() % 1000;
        sum += arr[i];
    }
    printf("26\n");
    // 转换成概率
    for (int i = 0; i < 26; i++) {
        printf("%c %lf\n", i + 'A', 1.0 * arr[i] / sum);
    }
    return 0;
}
