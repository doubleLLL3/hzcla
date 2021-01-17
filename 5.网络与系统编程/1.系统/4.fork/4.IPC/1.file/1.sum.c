/*************************************************************************
	> File Name: 1.sum.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 14 Jan 2021 06:13:12 PM CST
 ************************************************************************/

#include "head.h"
#define INS 5

char num_file[] = "./.num";
char lock_file[] = "./.lock";

struct Msg {
    int now;
    int sum;
};

struct Msg num;

size_t set_num(struct Msg *msg) {
    FILE *f = fopen(num_file, "w");
    if (f == NULL) {
        fclose(f); // 细节
        perror("fopen");
        return -1;   // 在一个函数里面exit不太好
    }
    size_t nwrite = fwrite(msg, 1, sizeof(struct Msg), f);
    fclose(f);
    return nwrite;
}
size_t get_num(struct Msg *msg) {
    FILE *f = NULL;
    if ((f = fopen(num_file, "r")) == NULL) {
        fclose(f);
        perror("fopen");
        return -1;
    }
    size_t nread = fread(msg, 1, sizeof(struct Msg), f);  // 不需要-1吗?
    fclose(f);
    return nread;
}

void do_add(int end, int pid_num) {
    while (1) {
        FILE *lock = fopen(lock_file, "w");
        if (lock == NULL) {
            perror("fopen");
            exit(1);
        }
        flock(lock->_fileno, LOCK_EX);
        if (get_num(&num) < 0) {
            fclose(lock);
            continue;
        }
        if (num.now > end) {
            fclose(lock);
            break;
        }
        num.sum += num.now;
        num.now++;
        printf("The <%d>th Child : now = %d, sum = %d\n", pid_num, num.now, num.sum);
        set_num(&num);
        flock(lock->_fileno, LOCK_UN);
        fclose(lock);
        
        /*
        FILE *f = fopen(num_file, "r");
        flock(f->_fileno, LOCK_EX);  // 
        fread(&num, sizeof(struct Msg), 1, f);
        if (num.now > end) {
            fclose(f);
            break;
        }
        printf("The <%d>th Child : now = %d, sum = %d\n", pid_num, num.now, num.sum);
        num.sum += num.now;
        num.now++;
        set_num(&num);
        flock(f->_fileno, LOCK_UN);
        fclose(f);
        */
    }
}

int main(int argc, char **argv) {
    int opt, start = 0, end = 0, ins;
    while ((opt = getopt(argc, argv, "s:e:i:")) != -1) {
        switch (opt) {
            case 's':
                start = atoi(optarg);
                break;
            case 'e':
                end = atoi(optarg);
                break;
            case 'i':
                ins = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -s start_num -e end_num\n", argv[0]);
                exit(1);
        }

    }
    printf("start = %d\nend = %d\n", start, end);

    num.now = 0;
    num.sum = 0;
    set_num(&num);
    pid_t pid;
    int x = 0;
    for (int i = 1; i < INS; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);  // 图方便，工作中不是如此操作
        }
        if (pid == 0) {
            x = i;
            break;  // 关键，否则会不断套娃
        }
    }
    if (pid != 0) {
        //printf("I'm parent!\n");
        //sleep(100);
        for (int i = 0; i < INS; i++) {
            wait(NULL);
        }
    } else {
        do_add(end, x);
        //printf("I'm %dth Child!\n", x);
    }
    get_num(&num);
    printf("sum = %d\n", num.sum);
    return 0;
}
