/*************************************************************************
	> File Name: 4.cube_root.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Mon 19 Oct 2020 03:41:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    double x;
    scanf("%lf", &x);
    printf("cube root value of %lf is %lf\n", x, pow(x, 1 / 3.0));
    return 0;
}

