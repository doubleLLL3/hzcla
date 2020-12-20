/*************************************************************************
	> File Name: EP45.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 20 Oct 2020 06:35:36 PM CST
 ************************************************************************/

#include<stdio.h>
typedef long long ll;

ll Triangle (ll n) {
    return n * (n + 1) / 2;
}

ll Pentagonal(ll n) {
    return n * (3 * n - 1) / 2;
}
ll Hexagonal(ll n) {
    return n * (2 * n - 1);
}

ll binary_search(ll (*arr)(ll), ll n, ll x) {  
    // 数组arr[]变成函数arr()，因为数字序列的数组并不确定，但映射关系存在
    // 二分查找需要的并不仅仅是数组，而是映射关系
    ll head = 1, tail = n, mid;
    while (head <= tail) {  // 终止条件
        mid = (head + tail) >> 1;  // 使用位移做除以2操作
        if (arr(mid) == x) return mid;
        if (arr(mid) < x) head = mid + 1;
        else tail = mid -1;
    }
    return -1;  // 程序设计技巧，-1不是固定的，表示没有找到该值
}

int main() {
    ll n = 143;
    while (1) {
        n += 1;
        ll temp = Hexagonal(n);
        /*if (binary_search(Pentagonal, temp, temp) != -1) {
            if (binary_search(Triangle, temp, temp) != -1) {
                printf("%lld\n", temp);
                break;
            }
        }*/
        if (binary_search(Pentagonal, temp, temp) == -1) continue;
        //if (binary_search(Triangle, temp, temp) == -1) continue;
        printf("%lld\n", temp);
        break;
          
  
    }
}
