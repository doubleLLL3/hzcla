/*************************************************************************
	> File Name: 6.struct_program.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 17 Oct 2020 06:29:05 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /*int a, b;
    scanf("%d%d", &a, &b);
    if (a - b) {
        printf("not equal!\n");
    } else {
        printf("equal\n");
    }
    printf("%s\n", (a - b) ? "not eqaul!" : "equal");
    
    a = 0, b = 0;
    if ((a++) && (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
    
    if ((a++) || (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
*/
    int n, cnt = 0;
    srand(time(0));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val = rand() % 100;
        //if (val & 1) {  // 用位运算代替val % 2，等价
        //    cnt += 1;
        //}
        cnt += (val & 1);  // 上面的if还可以再被简化掉
        i && printf(" ");  // 利用逻辑与的短路规则优化掉if语句
        printf("%d", val);
    }
    printf("\n");
    printf("odd num: %d\n", cnt);
    return 0;
}
