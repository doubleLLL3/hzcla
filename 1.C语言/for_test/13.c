/*************************************************************************
	> File Name: 13.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 05:56:07 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
// NewTon
double F(double x, double n) {
    return x * x - n;
}

double f(double x) {
    return 2 * x;
}

double NewTon(double (*F)(double, double), double (*f)(double), double n) {
    double x = n / 2;
    #define EPSL 1e-7
    while (fabs(F(x, n)) >= EPSL) {
        x -= F(x, n) / f(x);
    }
    return x;
}

double my_sqrt(double n) {
    return NewTon(F, f, n);
}

int main() {
    double n;
    while (~scanf("%lf", &n)) {
        printf("%g\n", my_sqrt(n));
    }
    return 0;
}
