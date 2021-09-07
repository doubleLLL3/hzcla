/*************************************************************************
	> File Name: 14.OJ-256.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 27 Feb 2021 07:10:26 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

// 数据类型：大整数，使用vector存储
class BigInt : public vector<int> {
public :
    BigInt(int x);
    void operator*=(int x);
    void operator/=(int x);
    BigInt operator/(int x);
    bool operator<(const BigInt &) const;                  //  注意末尾添加const，否则不生效
    bool operator>(const BigInt &) const;                  //  同上
private :
    void process_digit();
};

// 重载<<，用于输出 注意：高位在尾部
ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

// 构造函数
BigInt::BigInt(int x) {
    push_back(x);                                          // 用的是vector类型，可以直接push_back；高位在后
    process_digit();
}

// 处理进位
void BigInt::process_digit() {
    for (int i = 0; i < size(); i++) {
        if (at(i) < 10) continue;
        if (i + 1 == size()) push_back(0);                 // 最高位产生了进位，在尾部添加0
        at(i + 1) += at(i) / 10;
        at(i) %= 10;
    }
    while (size() > 1 && at(size() - 1) == 0) pop_back();  // ↓ 处理除法可能在尾部高位产生的前导0
    return ;
}

// 重载*=
void BigInt::operator*=(int x) {
    for (int i = 0; i < size(); i++) at(i) *= x;
    process_digit();
    return ;
}

// 重载/=
void BigInt::operator/=(int x) {
    int y = 0;  // y：余数
    for (int i = size() - 1; i >= 0; i--) {
        // 从尾部最高位开始遍历
        y = y * 10 + at(i);
        at(i) = y / x;                                     // ↑ 一开始可能为0，产生前导0
        y %= x;
    }
    process_digit();
    return ;
}

// 重载/
BigInt BigInt::operator/(int x) {
    BigInt ret(*this);
    ret /= x;
    return ret;
}

// 重载<，max方法需要，注意方法末尾的const
bool BigInt::operator<(const BigInt &a) const {
    if (size() - a.size()) return size() < a.size();       // 先比较长度
    for (int i = size() - 1; i >= 0; i--) {
        if (at(i) - a[i]) return at(i) < a[i];             // 从高位到低位依次比较
    }
    return false;                                          // 两数相等，<不成立
}
/*
// 重载>
bool BigInt::operator>(const BigInt &a) const {
    return a < (*this);
}
*/
int main() {
    vector<PII> arr;                                       // PII：pair类型，左、右手数字
    int n;
    cin >> n;
    for (int i = 0, a, b; i <= n; i++) {
        cin >> a >> b;
        arr.push_back(PII(a, b));
    }
    // 算法：基于微扰的思想，设计排序规则
    // 左、右手数字乘积小的人在前，保证最大值会最小；国王一直站在最前
    sort(arr.begin() + 1, arr.end(), 
         [](const PII &x, const PII &y) { 
             return x.first * x.second < y.first * y.second;
         }
    ); 
    // p：A(i - 1)，即排在该大臣前面的所有人的左手上的数的乘积
    BigInt p = arr[0].first, ans = 0;                      // 大整数：p、ans
    for (int i = 1; i <= n; i++) {
        BigInt temp = p / arr[i].second;                   // 大整数：temp
        ans = max(ans, temp);
        p *= arr[i].first;
    }
    cout << ans << endl;
    return 0;
}
