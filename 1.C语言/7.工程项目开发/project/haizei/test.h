/*************************************************************************
	> File Name: test.h
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 06:28:36 PM CST
 ************************************************************************/
#ifndef _TEST_H
#define _TEST_H
#include <haizei/linklist.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"
#define COLOR_UL(a, b) "\033[4;" #b "m" a "\033[0m"

#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
#define YELLOW(a) COLOR(a, 33)
#define BLUE(a) COLOR(a, 34)
#define PURPLE(a) COLOR(a, 35)

#define RED_HL(a) COLOR_HL(a, 31)
#define GREEN_HL(a) COLOR_HL(a, 32)
#define YELLOW_HL(a) COLOR_HL(a, 33)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define PURPLE_HL(a) COLOR_HL(a, 35)

#define RED_UL(a) COLOR_UL(a, 31)
#define GREEN_UL(a) COLOR_UL(a, 32)
#define YELLOW_UL(a) COLOR_UL(a, 33)
#define BLUE_UL(a) COLOR_UL(a, 34)
#define PURPLE_UL(a) COLOR_UL(a, 35)

#define NAME(a, b, link) a##link##b
#define STR(x) _STR(x)
#define _STR(x) #x
#define STR2(a, b, link) #a #link #b

// 1 测试用例
#define TEST(a, b)\
void a##_##b();  /*需要在add_fucntion()前声明*/\
__attribute__((constructor))\
void add##_##a##_##b(){\
    add_function(NAME(a, b, _), STR2(a, b, .));  /*可使用宏NAME(a, b)、STR(NAME(a, b))封装*/\
}\
void a##_##b()

// 2 断言
#define EXPECT(a, b, comp) {\
    haizei_test_info.total += 1;\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    if(!((_a) comp (_b))) LOG(a, b, _a, _b, comp);\
    printf(GREEN("[-----------] "));\
    printf("%s %s %s\t%s\n", #a, #comp, #b, (_a) comp (_b) ?\
           (haizei_test_info.success += 1, GREEN("TRUE")) : \
           RED_HL("FALSE"));\
}
// 打印出错信息
#define TYPE(a) _Generic((a),\
    int: "%d",\
    double: "%.2lf",\
    float: "%.2f",\
    long long: "%.2llf",\
    const char * : "%s",\
    char * : "%s"\
)
#define P(a, color) {\
    char frm[20];\
    sprintf(frm, color("%s"), TYPE(a));\
    printf(frm, a);\
}
#define LOG(a, b, _a, _b, comp) ({\
    printf(YELLOW_HL("\n\t%s:%d: failure\n"), __FILE__, __LINE__);\
    printf(YELLOW_HL("\t\texcept : %s %s %s\n"), #a, #comp, #b);\
    printf(YELLOW_HL("\t\tactual : "));\
    P(_a, YELLOW_HL);\
    printf(YELLOW_HL(" vs "));\
    P(_b, YELLOW_HL);\
    printf("\n\n");\
})
#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)

// (重要)函数指针变量提升为函数指针类型
typedef void(*TestFuncT)();  

// 把函数和函数名封装在结构体Function里 
typedef struct Function{
    TestFuncT func;
    const char *str;
    struct LinkNode node;  // 安上链表的外骨骼~
} Function;  // 类型别名Fucntion

// 定义统计测试点数量、成功数的结构体
struct FunctionInfo {
    int total, success;
};

// 声明区
int RUN_ALL_TESTS();  // 3 控制开关
void add_function(TestFuncT, const char *);  // 记录函数和函数的名字
extern struct FunctionInfo haizei_test_info;  // 使用extern声明外部变量，避免重复定义
#endif
