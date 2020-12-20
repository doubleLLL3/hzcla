/*************************************************************************
	> File Name: 1.cin.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 16 Dec 2020 09:35:09 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n;
    double m;
    cin >> n >> m;
    cout << n << " " << m << endl;
    scanf("%d %lf", &n, &m);
    printf("%d %lf\n", n, m);
    printf("%d %g\n", n, m);
    return 0;
}
