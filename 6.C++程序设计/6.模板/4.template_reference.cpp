/*************************************************************************
	> File Name: 4.template_reference.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Mon 22 Mar 2021 07:22:29 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

namespace haizei {

template<typename T>
void swap(T &&a, T &&b) {
    typename remove_reference<T>::type c;
    c = a; a = b; b = c;
    return ;
}

} // end of haizei


int main() {
    int n = 123, m = 456;
    haizei::swap(n, m);
    cout << n << " " << m << endl;
    //haizei::swap(789, n);    

    return 0;
}
