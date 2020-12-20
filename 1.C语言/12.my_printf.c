/*************************************************************************
> File Name: 12.my_printf.c
> Author: Double
> Mail: doubleliu3@gmail.com
> Created Time: Thu 22 Oct 2020 07:08:25 PM CST
************************************************************************/

#include<stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int rev_num(int n, int *temp) {
    int digit = 0;
    *temp = 0;
    do {  // 用do...while能正确计算0的位数
        *temp = *temp * 10 + n % 10;
        n /= 10;
        ++digit;
    } while (n);
    return digit;
}

int output_num(int n, int digit) {
    int cnt = 0;
    while (digit--) {  // 还是用位数控制输出，避免1000输出为1
        putchar(n % 10 + 48), ++cnt;  // 此cnt与my_printf里的cnt不是一个
        // PUTC(n % 10 + 48);  // 此处宏PUTC还未定义
        n /= 10;
    }
    return cnt;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    #define PUTC(a) putchar(a), ++cnt
    for (int i = 0; frm[i]; ++i) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%': PUTC(frm[i]); break;
                    case 'd': {
                        int xx = va_arg(arg, int);
                        uint32_t x;  // 该类型最大可表示2^32，_t表示是一个type（类型）
                        if (xx < 0) PUTC('-'), x = -xx;
                        else x = xx;
                        int temp1, temp2;  // 存翻转后的值
                        int x1 = x /100000, x2 = x % 100000;  // x1 高5位，x2 低5位
                        // temp1传的是地址，才能修改值，作为传出参数
                        int digit1 = rev_num(x1, &temp1);  // rev_num翻转数字并返回位数 
                        int digit2 = rev_num(x2, &temp2);
                        // 修正一下位数
                        if (x1) digit2 = 5;  // 避免把前面的0省略
                        else digit1 = 0;  // 避免算为0的位数，为1
                        cnt += output_num(temp1, digit1);  // output_num输出数字并返回位数
                        cnt += output_num(temp2, digit2);  // 我认为cnt += digit1也可以
                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char *);  // 字面量
                        for (int i = 0; str[i]; ++i) {
                            PUTC(str[i]);
                        }
                    } break;
                }
            } break;
            default: PUTC(frm[i]); break;
        }
    }
    #undef PUTC
    va_end(arg);
    return cnt;
}


int main() {
    printf("hello world\n");
    my_printf("hello world\n");

    int a = 123;
    printf("int(a) = %%\n");
    my_printf("int(a) = %%\n");
    printf("int(a) = %d\n", a);
    my_printf("int(a) = %d\n", a);

    printf("int(a) = %d\n", 0);
    my_printf("int(a) = %d\n", 0);

    printf("int(a) = %d\n", 1000);
    my_printf("int(a) = %d\n",1000);

    printf("int(a) = %d\n", -123);
    my_printf("int(a) = %d\n",-123);

    printf("INT32_MAX = %d\n", INT32_MAX);
    my_printf("INT32_MAX = %d\n", INT32_MAX);

    printf("INT32_MIN = %d\n", INT32_MIN);
    my_printf("INT32_MIN = %d\n", INT32_MIN);

    char str[100] = "I love China";
    printf("%s\n", str);
    my_printf("%s\n", str);
    
    int n;
    while (~scanf("%d", &n)) {
        printf(" has %d digits!\n", printf("%d", n));
        my_printf(" has %d digits!\n", my_printf("%d", n));
    }

    return 0;
}
