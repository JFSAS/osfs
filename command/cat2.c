#include "stdio.h"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // 打开文件
    int fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }

    char buf[BUFFER_SIZE];
    int n;

    //读取并输出
    while ((n = read(fd, buf, BUFFER_SIZE)) > 0) {
        write(1, buf, n); // 1 是标准输出文件描述符
    }
	printf("\n");
    close(fd);
    return 0;
}
