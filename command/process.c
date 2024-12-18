#include "stdio.h"
#include "type.h"
#include "string.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int cursor = 0;
	MESSAGE result;
	result = proc_search();

	for(i = 0; i < strlen(result.procnames); i++){
		if(result.procnames[i] == '\n'){
			printf("\tPID: %d",result.pids[cursor]);	
			printf("\tParent PID: %d",result.parentpids[cursor]);
			cursor++;		
		}
		printf("%c",result.procnames[i]);

	}

    return 0;
}

