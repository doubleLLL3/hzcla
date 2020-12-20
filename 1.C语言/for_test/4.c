/*************************************************************************
	> File Name: 4.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 03:07:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    double n;
    while (~scanf("%lf", &n)) {
        printf("%lf\n", pow(n, 1 / 3.0));
    }

    return 0;
}
