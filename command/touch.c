#include "stdio.h"

int main(int argc, char *argv[])
{
    if (~open(argv[1], O_CREAT)) {
        printf("create file %s successfully\n", argv[1]);
	return -1;
    } else {
        printf("failed to create file %s\n", argv[1]);
    }

    return 0;
}

