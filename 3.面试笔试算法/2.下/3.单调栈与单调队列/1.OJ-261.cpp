/*************************************************************************
	> File Name: 9.OJ-261.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 10 Jan 2021 02:26:14 PM CST
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
#include <cinttypes>
using namespace std;

class NewStruct {
public:
    NewStruct() {
        sum[0] = 0;
        ans[0] = INT64_MIN;                        // 极小值
    }
    void insert(long long x) {
        s1.push(x);
        int ind = s1.size(); 
        long long val1 = x + sum[ind - 1];         // 新的前缀和 [要保证ind-1有值，下同]
        long long val2 = max(ans[ind - 1], val1);  // 当前最大前缀和
        sum[ind] = val1;                           // 更新前缀和
        ans[ind] = val2;                           // 更新最大前缀和
        return ;
    }
    void del() {
        if (s1.empty()) return ;                   // 判空
        s1.pop();
        return ;
    }
    // s1->s2 [del]
    void move_left() {
        if (s1.empty()) return ; 
        s2.push(s1.top());
        del();                                     // 同del
        return ;
    }
    // s2->s1 [insert]
    void move_right() {
        if (s2.empty()) return ;
        insert(s2.top());                          // 同insert
        s2.pop();
        return ;
    }
    long long query(long long k) {
        if (k > s1.size() + s2.size()) return ans[s1.size() + s2.size()];  // k可能超过整个长度
        return ans[k];
    }
private:
    stack<long long> s1, s2;
    long long sum[1005];            // 维护s1中的前缀和 [如果用vector，需要提前开辟好空间]
    long long ans[1005];            // 最大值
};

int main() {
    long long N;
    cin >> N;
    string op;
    int val;
    NewStruct s;
    for (long long i = 0; i < N; i++) {
        cin >> op;
        switch(op[0]) {
            // 依次调用方法即可
            case 'I': cin >> val; s.insert(val); break;
            case 'D': s.del(); break;
            case 'L': s.move_left(); break;
            case 'R': s.move_right(); break;
            case 'Q': {
                cin >> val;
                cout << s.query(val) << endl;
            }
        }
    }
}
