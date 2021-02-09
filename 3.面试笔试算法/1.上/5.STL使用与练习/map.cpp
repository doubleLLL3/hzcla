/*************************************************************************
	> File Name: map.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 11 Nov 2020 08:37:30 PM CST
 ************************************************************************/
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

struct node {
    int x, y;
    // 需要重载<
    bool operator< (const node &b) const {
        return this->x > b.x;
    }
};

int main() {
    // map
    map<string, int> m;
    string a = "123";
    m[a] = 999;
    cout << "m[\"123\"] = " << m["123"] << endl;
    cout << "m[a] = " << m[a] << endl;
    cout << "m[\"456\"] = " << m["456"] << endl;  // 不存在会自动创建，赋值类型的默认值
    
    map<node, int> m_node;
    node n;
    m_node[n] = 5;
    cout << endl;

    // unordered_map 在c++11标准下
    /*unordered_map<node, int> um_node2;  // 需自己实现node的哈希函数
    um_node2[n] = 5;*/
    
    unordered_map<string, int> um;  // string类已经定义好了哈希函数
    um[a] = 99;
    cout << "um[\"123\"] = " << um["123"] << endl;
    cout << "um[a] = " << um[a] << endl;
    cout << "um[\"456\"] = " << um["456"] << endl;
    return 0;
}
