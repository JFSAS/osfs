#include "stdio.h"
#include "type.h"
#include "string.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int cursor = 0;
	MESSAGE result;
	result = dir_search("/");
	for(i = 0; i < strlen(result.filenames); i++){
		if(result.filenames[i] == '\n'){
			printf("\t%d",result.filesizes[cursor]);	
			cursor++;		
		}
		printf("%c",result.filenames[i]);

	}

    return 0;
}

