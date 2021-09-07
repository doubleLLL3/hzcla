/*************************************************************************
	> File Name: 1.complex_num.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 02 Mar 2021 08:21:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define green_i "\033[32mi\033[0m"

// 复数类
class Complex {
public :
    Complex();
    Complex(double, double);
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    Complex operator*(const Complex &);
    Complex operator/(const Complex &);
private :
// [要求1] 实部、虚部设为私有
    double real, imag; 
    friend ostream &operator<<(ostream &, const Complex &);  // 友元函数
};

// [要求2]：构造函数初始化实部、虚部
Complex::Complex() : Complex(0, 0) {}                        // 委托构造函数 
Complex::Complex(double real, double imag) : real(real), imag(imag) {}

// [要求3]：实现四则运算
// 加
Complex Complex::operator+(const Complex &a) {
    Complex ret(real + a.real, imag + a.imag);
    return ret;
}

// 减
Complex Complex::operator-(const Complex &a) {
    Complex ret(real - a.real, imag - a.imag);
    return ret;
}

// 乘
Complex Complex::operator*(const Complex &a) {
    Complex ret(
        real * a.real - imag * a.imag, 
        real * a.imag + imag * a.real
    );
    return ret;
}

// 除
Complex Complex::operator/(const Complex &a) {
    Complex temp(a.real, -a.imag);                           // 用于分母有理化
    Complex numerator = *this * temp;                        // 分子
    double denominator = a.real * a.real + a.imag * a.imag;  // 分母
    Complex ret(numerator.real / denominator, numerator.imag / denominator);
    return ret;
}

// 友好输出复数 [根据正负等情况调整输出形式]
ostream &operator<<(ostream &out, const Complex &a) {
    if (a.real == 0) {
        if (a.imag == 0) cout << "0";
        else cout << "(" << a.imag << green_i << ")";
    } else {
        cout << "(";
        if (a.imag > 0) {
            out << a.real << " + " << a.imag << green_i;
        } else if (a.imag == 0) {
            out << a.real;
        } else {
            out << a.real << " - " << -a.imag << green_i;
        }
        cout << ")";
    }
    return out;
}

// 测试复数a、b的加减乘除运算
void testAll(Complex &a, Complex &b) {
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " × " << b << " = " << a * b << endl;
    cout << a << " ÷ " << b << " = " << a / b << endl;
    cout << "===============================" << endl;
    return ;
}

int main() {
    Complex a(0, 4);
    Complex b(4, 0);
    Complex c(3, 4);
    Complex d(3, -4);
    Complex e(-3.2, -4.5);
    testAll(a, b);
    testAll(a, c);
    testAll(b, d);
    testAll(c, e);
    return 0;
}
