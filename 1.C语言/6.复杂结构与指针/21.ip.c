/*************************************************************************
	> File Name: 21.ip.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 29 Oct 2020 07:23:52 PM CST
 ************************************************************************/
 #include <stdio.h>

union IP {
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    } ip;  // 这里必须声明变量，否则无法访问
    unsigned int num;
};

//检验本机是否是小端机
int is_little() {
    static int num = 1;  // 00000...1，不用static也可以
    return ((char *)(&num))[0];  // 强转为char类型数组地址，则可以判断0号字节上的值
}

int main() {
    printf("本机是小端机吗？：%d\n", is_little());

    union IP p;
    char str[100] = {0};  // 用来读取IP地址如192.168.0.1，初始化为0
    int arr[4];  // 用来取出4段整数值：192 168 0 1
    while (~scanf("%s", str)) {
        // 从字符串读入值传给arr[4]
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
        // 写入共用体，反向存储，因为是小端机
        p.ip.a1 = arr[3];  //  必须通过p1来访问a1
        p.ip.a2 = arr[2];
        p.ip.a3 = arr[1];
        p.ip.a4 = arr[0];
        // 直接输出其对应的4字节整数值
        printf("%u\n", p.num);
    }
    return 0;
}
