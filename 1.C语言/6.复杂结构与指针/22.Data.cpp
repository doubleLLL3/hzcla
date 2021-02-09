/*************************************************************************
	> File Name: test.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 31 Oct 2020 10:59:27 AM CST
 ************************************************************************/

#include <iostream>
//#include <stdio.h>
using namespace std;
#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

struct Data {
    int x, y;
};

int main() {
    struct Data a[2], *p = a;  // 表示a[1].x
    a[0].x = a[0].y = 0;
    a[1].x = 1, a[1].y = 2;
    
    cout << "尽可能多的形式表示a[1].x" << endl;
    cout << " 正确答案: " << a[1].x << endl;
   
    // p[1] = *(p + 1) = a[1] = *(a + 1)
    P((*(a + 1)).x);
    P((a + 1)->x);
    P((p + 1)->x);
    P((*(p + 1)).x);
    P(p[1].x);
    // 套娃：&就用->，*就用.
    P((&p[1])->x);
    P((&p[0] + 1)->x);
    P((*(&p[0] + 1)).x);
    // 奇门绝技：a[n] = *(a + n) = *(n + a) = n[a]
    P(1[a].x);
}
