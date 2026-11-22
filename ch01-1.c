#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


void main(int argc, char* argv[])
{
    DIR *dp;
    struct dirent *dirp;
    
    if (argc != 2)
    {
        printf("useage: %s directory_name\n", argv[0]);
        exit(0);
    }

    // opendir 返回DIR类型指针，失败则返回NULL
    if ( (dp = opendir(argv[1])) == NULL )
    {
        perror("open dir error");
        exit(1);
    }

    // 从 dp指针，读取每一个目录项
    while ( (dirp = readdir(dp)) != NULL )
        printf("%s\n", dirp->d_name);

    // 关闭目录，该指针指向估计是在堆内存，经验证，dp保存的地址确实是指向堆内存
    printf("dp value: 0x%p", dp);

    getchar();

    closedir(dp);

}
