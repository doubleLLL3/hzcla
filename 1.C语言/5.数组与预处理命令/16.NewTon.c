/*************************************************************************
	> File Name: 16.NewTon.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 24 Oct 2020 07:24:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

// 原函数
double F(double x, double n) {
    return x * x - n;
}

// 原函数的导函数
double f(double x) {
    return 2 * x;
}

double NewTon(double (*F)(double, double), double (*f)(double), double n) {
    double x = n / 2.0;  // 这个值可以设想离要求的x近点，其在实际解x的左侧右侧都没问题
    #define EPSL 1e-7
    // fabs取绝对值
    while (fabs(F(x, n)) > EPSL) {
        x -= F(x, n) / f(x);
    }
    #undef EPSL
    return x;
}

// 将NewTon函数再包装在my_sqrt函数里，减少传参的数量
double my_sqrt(double n) {
    return NewTon(F, f, n);
}

int main() {
    double n;
    while (~scanf("%lf", &n)) {
        printf("sqrt(%g) = %g\n", n, sqrt(n));
        printf("my_sqrt(%g) = %g\n", n, my_sqrt(n));
    }
    return 0;
}
