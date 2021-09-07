/*************************************************************************
	> File Name: 7.static_const.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 28 Feb 2021 07:36:26 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class People {
public :
    People() : say_cnt(0) {
        People::total_num += 1;  // 增加"People::"域限定符以防重名，类似命名空间
    }
    // 🌟 类方法：输出人类总数量
    static void say_count() {
        cout << "Total num: " << People::total_num << endl;
    }
    // 🌟 const方法
    void say() const {
        cout << "hahaha!" << endl;
        say_cnt += 1;            // 逻辑上的const，不影响关键数据
        output();                // 只能调用const方法
        return ;
    }
    // 函数重载：2个output方法
    void output() {
        cout << "non-const output function" << endl;
    }
    void output() const {
        cout << "const output function" << endl;
    }
    ~People() {
        People::total_num -= 1;
    }
private :
    static int total_num;
    // 🌟 类属性：人类总数量
    //  使用static声明，告诉编译器其是类属性，还需要在类外初始化
    //  ❗️不可以在此处初始化，因为是全局的
    mutable int say_cnt;
    // 🌟 某个对象say的次数
    //  可在const方法里变化，满足逻辑上的const，而不是数据意义上的const
    //  ❗️逻辑上的const：可以改变不太重要的属性
};

int People::total_num = 0;     // 在类外初始化类属性，❗️不能加static

int main() {
    People hug, xiao_hug;
    // 🌟 调用类方法的2种方式
    hug.say_count();           // 1、通过对象调用
    People::say_count();       // 2、通过域限定符（类名）调用
    // 在额外的花括号作用域里增加人类
    {
        People hug, xiao_hug;  // 重名不冲突
        People::say_count();
    }
    People::say_count();

    // 🌟 const类型对象，只能调用const类型方法 
    const People xiaobo;
    xiaobo.say();
    return 0;
}
