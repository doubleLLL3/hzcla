/*************************************************************************
	> File Name: 4.angle2arc.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Mon 19 Oct 2020 03:57:32 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define PI acos(-1)

int main() {
    double angle;
    scanf("%lf", &angle);
    printf("angle %lf° = arc %lf = %lfπ\n", angle, angle / 180 * PI, angle / 180);
    return 0;
}

