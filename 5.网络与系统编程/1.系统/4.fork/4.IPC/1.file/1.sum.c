/*************************************************************************
	> File Name: 1.sum.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 14 Jan 2021 06:13:12 PM CST
 ************************************************************************/

#include "head.h"
#define INS 100

char data_file[] = "./.data";
char lock_file[] = "./.lock";  // [可选] 设置专门的一把锁

// 要传递的数据
struct Msg {
    int now;                   // 加数
    int sum;                   // 和
};

struct Msg data;               // 结构体数据

// 写入结构体数据
size_t set_data(struct Msg *msg) {
    FILE *f = fopen(data_file, "w");                         // 写
    if (f == NULL) {
        perror("fopen");
        return -1;                                          // 在一个小函数里面exit过于粗鲁
    }
    size_t nwrite = fwrite(msg, 1, sizeof(struct Msg), f);  // 每次写1个字节
    fclose(f);
    return nwrite;             // 返回的是成功写的字节数，如果出错也返回给上层
}

// 读取结构体数据
size_t get_data(struct Msg *msg) {
    FILE *f = fopen(data_file, "r");
    if (f == NULL) {
        perror("fopen");
        return -1;
    }
    size_t nread = fread(msg, 1, sizeof(struct Msg), f);    // 读入结构体数据到msg中
    return nread;
}

// 做加法 [原子操作：读 + 写]；end：加法停止条件；id：孩子的编号 [可用上帝视角监控]
void do_add(int end, int id) {
    // 孩子一直在里面做加法
    while (1) {
        /*
         * 思路二：两个文件，使用单独的文件作为锁 [更易理解]
         */
        // 打开或创建一个锁文件；如果文件已加锁，将等待使用者解锁
        FILE *lock = fopen(lock_file, "w");  // "w"：如果不存在文件，会创建一个
        if (lock == NULL) {
            perror("fopen");
            exit(1);
        }
        // 加锁
        flock(lock->_fileno, LOCK_EX); 
        // 从文件读取数据
        if (get_data(&data) < 0) {
            fclose(lock);                    // 关闭锁文件，释放锁
            continue;
        }
        // 加数+1，并判断是否满足停止加的条件
        if (++data.now > end) {
            fclose(lock);
            break;
        }
        // 做加法
        data.sum += data.now;
        printf("The <%d>th Child : now = %d, sum = %d\n", id, data.now, data.sum);
        // 将数据写入文件
        if (set_data(&data) < 0) continue;
        // 解锁 
        flock(lock->_fileno, LOCK_UN);      
        fclose(lock);
        
        /*
         * 思路一：一个文件，直接在数据文件加锁
         */
        /*
        // 打开data_file用来加锁
        FILE *f = fopen(data_file, "r");
        // 加互斥锁
        flock(f->_fileno, LOCK_EX);  
        // 从文件读取数据 [get_data函数里会再次打开data_file文件，对应新的fd，锁不共用]
        if (get_data(&data) < 0) continue;
        // 加数+1，并判断加数是否超过范围
        if (++data.now > end) {
            fclose(f);               
            break;
        }
        // 做加法
        data.sum += data.now;
        printf("The <%d>th Child : now = %d, sum = %d\n", id, data.now, data.sum);
        // 将数据写入文件
        if (set_data(&data) < 0) continue;
        // 解锁 [后面关闭其实也会自动释放锁]
        flock(fileno(f), LOCK_UN);
        fclose(f);
        */
    }
}

int main(int argc, char **argv) {
    int opt, start = 0, end = 0;
    while ((opt = getopt(argc, argv, "s:e:")) != -1) {
        switch (opt) {
            case 's':
                start = atoi(optarg);       // atoi: 字符串->整数
                break;
            case 'e':
                end = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -s start_num -e end_num\n", argv[0]);
                exit(1);
        }

    }
    printf("start = %d\nend = %d\n", start, end);

    // 先将初始数据写入文件
    if (set_data(&data) < 0) return -1;     // data为全局变量，成员默认均为0

    pid_t pid;
    int x = 0;                              // x: 第几号进程
    for (int i = 1; i <= INS; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);                        // 只是图方便，工作中不如此操作
        }
        if (pid == 0) {
            x = i;                          // 给子进程编号
            break;                          // 关键，否则会不断套娃
        }
    }
    if (pid != 0) {
        // 防止产生僵尸进程 [等待完所有的子进程]
        for (int i = 1; i <= INS; i++) {
            wait(NULL);
        }
        if (get_data(&data) < 0) return -1; // 获得最终结果
        printf("sum = %d\n", data.sum);
    } else {
        do_add(end, x);                     // 子进程唯一的事
    }
    return 0;
}
