/*************************************************************************
	> File Name: 7.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 03:36:18 PM CST
 ************************************************************************/

#include <stdio.h>
typedef long long ll;
ll Hex(ll n) {
    return n * (2 * n - 1);
}
ll Pen(ll n) {
    return n * (3 * n - 1) / 2;
}

ll binary_search(ll (*fun)(ll), ll ans) {
    ll head = 1, tail = ans, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (fun(mid) == ans) return mid;
        if (fun(mid) < ans) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    ll n = 143;
    while (1) {
        n += 1;
        ll x = Hex(n);
        if (binary_search(Pen, x) == -1) continue;
        printf("%lld\n", x);
        break;
    }

    return 0;
}
