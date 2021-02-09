/*************************************************************************
	> File Name: 13.LC-剑指56-出现数字3次.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 31 Jan 2021 03:47:08 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0, a1, b1;
        for (int i = 0, c; i < nums.size(); i++) {
            c = nums[i];
            a1 = (a & ~b & ~c) | (~a & b & c) | (a & b & ~c) | (a & ~b & c);
            b1 = (~a & b & ~c) | (~a & ~b & c) | (a & b & ~c) | (a & ~b & c);
            a = a1;
            b = b1;
        }
        return b;
    }

};

int main() {
    Solution S;
    int n; 
    vector<int>  v;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    cout << S.singleNumber(v) << endl;
    return 0;
}
