/*************************************************************************
	> File Name: main.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Mon 02 Nov 2020 05:19:59 PM CST
 ************************************************************************/
#include <stdio.h>
#include <haizei/test.h>

double add(double a, double b) {
    return a + b;
}

TEST(testfunc, add1) {
    EXPECT_EQ(add(2, 3), 1.0);
    EXPECT_LT(add(1.2, 0.3), 1.6);
    EXPECT_LE(add(2, 3.5), 5.5);
    EXPECT_GT(add(2, 3), 10.0);
}
TEST(testfunc, add2) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(1, 3), 4);
    EXPECT_LT(add(2.55, 3), 5.1);
    EXPECT_GE(add(2, 3), 5);
}
TEST(testfunc, add3) {
    EXPECT_EQ(add(0, 1.00), 1);
    EXPECT_LT(add(-2, -3), -4);
    EXPECT_LE(add(2, 3.4), 5.4);
    EXPECT_GE(add(2, 3), 3);
}
int main() {
    return RUN_ALL_TESTS();
    //return 0;
}
