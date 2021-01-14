/*************************************************************************
	> File Name: vim 8.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 27 Nov 2020 10:38:59 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
typedef long long ll;
char num[1005];
ll ans, zero_cnt, now = 1;

int main() {
    cin >> num;
    for (int i = 0; i < 1000; i++) {
        for (int i = 0; i < 1000; i++) {
            if (i < 13) {
                now *= num[i] - '0';
            } else {
                if (num[i] == '0') {
                    zero_cnt++;
                } else {
                    now *= num[i] - '0';
                }
                if (num[i - 13] == '0') {
                    zero_cnt--;
                } else {
                    now /= num[i - 13] - '0';
                }
            }
            if (!zero_cnt) {
                ans = max(ans, now);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
