/*************************************************************************
	> File Name: 19.MAX.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 27 Oct 2020 07:14:33 PM CST
 ************************************************************************/

#include <stdio.h>
//#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX(a, b) ({\
    __typeof(a) _a = (a);\
    /*printf("a = %d, _a = %d\n", a, _a);*/ \
    __typeof(b) _b = (b);\
    _a > _b ? _a : _b;\
})
#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

//int MAX(a);

int main() {
    int a = 7;
   P(MAX(2, 3));
   P(5 + MAX(2, 3));
   P(MAX(2, MAX(3, 4)));
   P(MAX(2, 3 > 4 ? 3 : 4));
   P(MAX(a++, 6));
   P(a);
    return 0;
}
