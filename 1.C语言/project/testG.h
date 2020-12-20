/*************************************************************************
	> File Name: testG.h
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 07 Nov 2020 11:14:44 PM CST
 ************************************************************************/
#ifndef _TESTG_H
#define _TESTG_H
#define P(a, con) printf(con "\n", a)
#define _TYPE(a) _Generic((a),\
    int : P(a, "%d"),\
    double : P(a, "%lf"),\
    char : P(a, "%c"),\
    float : P(a, "%f"),\
    char *: P(a, "%s")\
)
#define TYPE(a) _TYPE(a)
#define P2(a) {\
    char frm[50];\
    sprintf(frm, "%s\n", TYPE2(a));\
    printf(frm, a);\
}
#define TYPE2(a) _Generic((a),\
    int : "%d",\
    double : "%lf"\
)
#define PP(a) {\
    char s[10] = "xxx";\
    int x = 1;\
    printf(s);\
    printf(x);\
}
#endif
