/*************************************************************************
	> File Name: 9.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 04:07:14 PM CST
 ************************************************************************/

#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
int max_int(int cnt, ...) {
    int ans = INT32_MIN;
    va_list arg;
    va_start(arg, cnt);
    while (cnt--) {
        int now = va_arg(arg, int);
        if (now > ans) ans = now;
    }
    va_end(arg);
    return ans;

}



int main() {
    printf("max: %d\n", max_int(4, 1, 4, 10, 15, 20));


    return 0;
}
