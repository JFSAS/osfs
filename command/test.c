#include "stdio.h"
#include "type.h"
#include "string.h"

int main(int argc, char *argv[])
{
	int fd = open("ls", O_RDWR);
	if(fd == -1){
		printf("open ls failed");
	}else{

	}
	printf("for test, Hello rxy\n");
}

