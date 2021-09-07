/*************************************************************************
	> File Name: 2.cout.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 27 Feb 2021 09:04:23 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
// 使用宏定义命名空间，减少缩进
#define BEGINS(x) namespace x {
#define ENDS(x) } // namespace x

BEGINS(haizei)

// 定义自己的ostream类
class ostream {
public:
    // 重载<<运算符
    ostream &operator<<(int x);         // 输出int
    ostream &operator<<(const char *);  // 输出字符串
};

// 返回当前对象（的引用，之后留意理解），使cout可以连续输出
ostream &ostream::operator<<(int x) {
    printf("%d", x);
    return *this;
}

ostream &ostream::operator<<(const char *x) {
    // 传入字面量使用const类型字符串接收，否则会警告
    printf("%s", x);
    return *this;
}

ostream cout;  // 定义ostream对象

ENDS(haizei)

int main() {
    int n = 123, m = 456;
    // 1、cout << n 是什么 ➡️  变量[即对象] + 左移运算符 + 变量 [即对象]
    std::cout << n << " " << m; std::cout << std::endl;  
    haizei::cout << n << " " << m; std::cout << std::endl;
    // 2、相同的对象名可以存在于不同的命名空间中
    return 0;
}
