/*************************************************************************
	> File Name: HZOJ-41.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 27 Dec 2020 06:23:16 PM CST
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

class BigInt : public vector<int> {
public :
    BigInt() {
        push_back(0);
    }
    BigInt(int x) {
        push_back(x);
        process_digit();
    }
    BigInt operator*(int x) {
        BigInt ret(*this);
        ret *= x;
        return ret;
    }
    void operator*=(int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        process_digit();
        return ;
    }
    void operator+=(const BigInt &num) {
        for (int i = 0; i < num.size(); i++) {
            if (i == size()) push_back(num[i]);
            else at(i) += num[i];
        }
        process_digit();
        return ;
    }
    BigInt operator+(const BigInt &num) {
        BigInt ret(*this);
        ret += num;
        return ret;
    }
    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

ostream &operator<<(ostream &out, const BigInt &num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        out << num[i];
    }
    return out;
}

int main() {
    int n, k;
    cin >> n >> k;
    BigInt f[3] = {0};
    // 前三项不符合通用公式，需自行推算
    f[1] = k;
    f[2] = k * (k - 1);
    f[0] = k * (k - 1) * (k - 2);  // 存放f(3)的值
    for (int i = 4; i <= n; i++) {
        // 【模3的使用】滚动数组
        f[i % 3] = f[(i - 1) % 3] * (k - 2) + f[(i - 2) % 3] * (k - 1);
    }
    cout << f[n % 3] << endl;
    return 0;
}
