/*************************************************************************
	> File Name: 2.strlen.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 11 Dec 2020 06:55:55 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string s = "0";
    for (int i = 0; i < 100000000; i++) {
        s += "0";
    }
    // 两种方式求字符串s长度
    cout << clock() << endl;
    for (int i = 0; i < 500000; strlen(s.c_str()), i++) ;  // .c_str()：从string类转成C类型的字符串组
    cout << clock() << endl;
    for (int i = 0; i < 500000; s.length(), i++) ;
    cout << clock() << endl;

    s = "hello kaikeba";   
    for (int i = 0; i < strlen(s.c_str()); i++) {
        // 判断条件：每次都要重新求长度【不推荐】
        // cout << s[i] << endl;
    }
    // 推荐的写法👇
    // for (int i = 0, I = strlen(s.c_str()); i < I; i++)
    // for (int i = 0; s[i]; i++)
    
    return 0;
}
