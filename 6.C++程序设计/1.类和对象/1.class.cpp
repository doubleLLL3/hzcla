/*************************************************************************
	> File Name: 1.class.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 27 Feb 2021 08:27:37 PM CST
 ************************************************************************/

#include <iostream> 
#include <string>
// using namespace std; // 工程开发中，不推荐直接使用
using std::string;      // 使用到精确的标识符，避免未意识到的重名

// 命名空间haizei，可理解为一个限定域
namespace haizei {
    class Cat {};       // 别忘了末尾的';'
    class Dog {};
    class People {    
    // class内的属性和方法，默认为private权限
    public :            // 往下都是public权限
        string name;
        int age;
        double height;
        double weight;
        /* 方式一：声明和实现在一起，只适用于小程序，不推荐
        void say() {
            std::cout << "my name is " << name << std::endl;
        };
        */
        // 方式二：声明和实现分开，更清晰，适用于工程开发
        void say(string name); 
        void run();
};
    
    // 注意：记得声明方法所属的class [可理解为一种特殊的命名空间]
    void People::say(string name) {
        // 🌟this：只在成员方法中使用，可以明确调用的是是成员属性
        std::cout << "this = " << this << std::endl;                            // 输出this指针（当前对象）的地址
        std::cout << "my name is " << this->name << ", " << name << std::endl;  // 调用成员属性（this）和方法参数
    };
}  // end of haizei

// using namespace haizei;  // 不推荐，可以省略下面对haizei命名空间的声明

// 主函数是类外方法
int main() {
    haizei::People bob;
    haizei::People hug;
    bob.name = "DobleLLL";
    hug.name = "Captain Hu";
    std::cout << "&bob = " << &bob << std::endl;
    std::cout << "&hug = " << &hug << std::endl;
    bob.say("hahaha");
    hug.say("hahaha");
    return 0;
}
