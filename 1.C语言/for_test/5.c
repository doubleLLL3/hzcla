/*************************************************************************
	> File Name: 5.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 03:12:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define PI acos(-1)
int main() {
    int n;  // double 
    while (~scanf("%d", &n)) {
        printf("%lf\n", n / PI * 180);
    }

    return 0;
}
