/*************************************************************************
	> File Name: testG.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 07 Nov 2020 10:12:59 PM CST
 ************************************************************************/
#include <stdio.h>
#include <testG.h>
int main() {
    int a = 3;
    double b = 0.333;
    
    printf("TYPE():\n");
    TYPE(a);

    printf("P2():\n");
    P2(a);
    P2(b);

    PP("abc");


    /*printf("表达式值、返回值比较:\n");
    printf("%d\n",TYPE2(a) == ("%d"));
    printf("%d\n",TYPE2(a) == "%d");
    printf(("%d\n"), a);*/
    
    /*char frm2[50];
    sprintf(frm2, "%s\n", (__typeof(a)));
    printf(frm2, a);*/

    return 0;
}
