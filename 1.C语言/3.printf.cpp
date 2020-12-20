/*************************************************************************
	> File Name: 3.printf.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 15 Oct 2020 06:14:14 PM CST
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int main() {
    // printf
    int n;
    scanf("%d", &n);   //stdin
    printf("%d\n", n); //stdout stderr EOF = -1
    
    // sprintf
    char str[1000] = {0}, buffer[1000] = {0}, *p = str, *q = buffer;
    sprintf(str, "%d.%d.%d.%d", 192, 168, 1, 2);  // printf sprintf fprintf 
    printf("%s\n", str);
    // 逐位判断
    if (n & 1) {
        sprintf(q, "(%s)", p); //使用中间变量传值，否则会出错；使用指针是为了高效
        swap(p, q); //一直保持p为最新的输出
    }
    if (n & 2) {
        sprintf(q, "[%s]", p);
        swap(p, q);
    }
    if (n & 4) {
        sprintf(q, "{%s}", p);
        swap(p, q);
    }
    printf("%s\n", p);
    
    //fprintf
    FILE *fout = fopen("output", "w");
    fprintf(fout, "str = %s\n", p);
    fprintf(stdout, "stdout = %s\n", p);
    fprintf(stderr, "stderr = %s\n", p);
    return 0;
}
