#include "stdio.h"

int main(int args, char *argv[])
{
    if (unlink(argv[1]) == -1) {
        printf("remove file %s failed.\n", argv[1]);
        return -1;
    }
    printf("Successfully remove file %s\n", argv[1]);
    return 0;
}

