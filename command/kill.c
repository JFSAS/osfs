#include "stdio.h"

int main(int args, char *argv[])
{
	int pid = string2int(argv[1]);

	kill(pid);
    return 0;
}

int string2int(char *str) {
    int result = 0;
    while (*str) {
        result = result * 10 + (*str - '0'); // 将当前数字字符转换为整数并累加到结果中
        str++;
    }
    return result;
}
