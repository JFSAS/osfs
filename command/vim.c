#include "stdio.h"
#include "string.h"

#define ELF_MAGIC "\x7f\x45\x4c\x46"

int is_elf(char *filename) {
    // 打开文件
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        return 0;  // 文件无法打开
    }

    // 检查文件的前4个字节
    char magic[4];
    long bytesRead = read(fd, magic, 4);
    close(fd);

    if (bytesRead == 4 && memcmp(magic, ELF_MAGIC, 4) == 0) {
        return 1;  // 是ELF文件
    }

    return 0;  // 不是ELF文件
}

void do_exe(char *argv[]){
	execv(argv[1], argv + 1);
}

int main(int argc, char *argv[]) {

    // 打开文件
    int fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }
	if(is_elf(argv[1])){
		printf("This is a executable file %s\n", argv[1]);
		do_exe(argv);
		return;
	}
	printf("This is a editable file %s\n", argv[1]);
	int buffer_size = 1024;

	char buf[buffer_size];
	int n = read(fd, buf, buffer_size);
	char rdbuf[buffer_size];
	int r = vim(0, buf, rdbuf, buffer_size);	
	close(fd);
	unlink(argv[1]);
	fd = open(argv[1], O_CREAT);
	close(fd);
	fd = open(argv[1], O_RDWR);
	write(fd, rdbuf, r);

    close(fd);
    return 0;
}
