/*************************************************************************
	> File Name: 1.myls-random.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Mon 11 Jan 2021 09:17:49 PM CST
 ************************************************************************/

#include "head.h"

// 路径拼接，获得绝对路径
void absolute_path(char *ab_path, char* path, char *filename) {
    strcpy(ab_path, path);                            // 保留原path值
    strcat(ab_path, "/");                             // 注意添加路径分隔符
    strcat(ab_path, filename);                        // 拼接
    return ;
}

// 获取友好的文件权限
void mode2str(mode_t smode, char *mode) {
    int i = 0;
    // rwx数组，分别对应000、001、...、110、111
    char *rwx[] = {
        "---", "--x", "-w-", 
        "-wx", "r--", "r-x",
        "rw-", "rwx"
    };  
    // 获取文件类型
    if (S_ISREG(smode)) mode[0] = '-';
    else if (S_ISDIR(smode)) mode[0] = 'd';
    else if (S_ISBLK(smode)) mode[0] = 'b';
    else if (S_ISCHR(smode)) mode[0] = 'c';
#ifdef S_ISFIFO
    else if (S_ISFIFO(smode)) mode[0] = 'p';
#endif
#ifdef S_ISLNK
    else if (S_ISLNK(smode)) mode[0] = 'l';
#endif
#ifdef S_ISSOCK
    else if (S_ISSOCK(smode)) mode[0] = 's';
#endif
    else mode[i++] = '?';
    // 获取文件权限
    strcpy(&mode[1], rwx[(smode >> 6) & 7]);
    strcpy(&mode[4], rwx[(smode >> 3) & 7]);
    strcpy(&mode[7], rwx[smode & 7]);
    // 获取文件特殊权限
    if (smode & S_ISUID) mode[3] = (smode & S_IXUSR) ? 's' : 'S';
    if (smode & S_ISGID) mode[6] = (smode & S_IXGRP) ? 's' : 'S';
    if (smode & S_ISVTX) mode[9] = (smode & S_IXOTH) ? 't' : 'T';
    return ;
}

// 获取友好的mtime
void mtim2str(struct timespec *mtim, char *str, size_t max) {
    struct tm *tmp_time = localtime(&mtim->tv_sec);           // 转换为当地日历时间
    strftime(str, max, "%b %e %H:%M", tmp_time);              // 转换为指定格式
    return ;
}

void myls(char **argv, char *path, int a_flag) {
    DIR *dirp;
    // 0. 打开并读取目录
    if ((dirp = opendir(path)) != NULL) {
        struct dirent *dir;
        while (dir = readdir(dirp)) {
            if (dir->d_name[0] == '.' && !a_flag) continue;
            struct stat st;                                   // 需要为该结构体开辟内存
            char ab_path[128];                                // 记录绝对路径
            absolute_path(ab_path, path, dir->d_name);        // +. 路径拼接
            // 1. 读取文件信息
            if (!lstat(ab_path, &st)) {
                char mode[16], mtime[32], uname[16], gname[16];
                mode2str(st.st_mode, mode);                   // 2. 处理文件权限
                mtim2str(&st.st_mtim, mtime, sizeof(mtime));  // 3. 处理修改时间
                strcpy(uname, getpwuid(st.st_uid)->pw_name);  // 4. 获取文件所属者名称
                strcpy(gname, getgrgid(st.st_gid)->gr_name);  // 5. 获取文件所属组名称
                printf("%s %lu %s %s %*lu %s %s\n", 
                        mode, st.st_nlink, uname, gname, 
                        6, st.st_size, mtime, dir->d_name
                      );
            } else {
                perror("lstat");
                exit(1);
            }
        }
    } else {
        perror("opendir");
        exit(1);
    }
    return ;
}

void show_tips(char **argv) {
    fprintf(stderr, "Usage: %s -[a]l [path]\n", argv[0]);
    return ;
}

int main(int argc, char **argv) {
    // 不带路径参数 [默认为当前目录]
    if (argc == 2){
        if (!strcmp(argv[1], "-al")) myls(argv, ".", 1);
        else if (!strcmp(argv[1], "-l")) myls(argv, ".", 0);
        else show_tips(argv), exit(1);
        return 0;
    }
    int opt;
    int a_flag = 0;  // 判断-a选项
    // 带路径参数
    while ((opt = getopt(argc, argv, "al:")) != -1) {
        switch (opt) {
            case 'a': {
                a_flag = 1;
            } break;
            case 'l': {
                myls(argv, optarg, a_flag);
            } break;
            default: {
                show_tips(argv);
                exit(1);
            }
        }
    }
    return 0;
}
