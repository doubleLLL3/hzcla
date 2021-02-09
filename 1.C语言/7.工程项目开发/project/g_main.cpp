/*************************************************************************
	> File Name: main.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Mon 02 Nov 2020 05:19:59 PM CST
 ************************************************************************/
#include <stdio.h>
#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(testefunc, add1) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(1, 3), 4);
    EXPECT_EQ(add(2, 2), 3);
    EXPECT_EQ(add(3, 3), 6);
}

TEST(testefunc, add2) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(1, 3), 4);
    EXPECT_EQ(add(2, 2), 4);
    EXPECT_EQ(add(3, 3), 6);
}
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
