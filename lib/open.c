/*************************************************************************//**
 *****************************************************************************
 * @file   open.c
 * @brief  open()
 * @author Forrest Y. Yu
 * @date   2008
 *****************************************************************************
 *****************************************************************************/

#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"

PRIVATE char* prot_file_table[] = {"ls", "kill", "process"};

/*****************************************************************************
 *                                open
 *****************************************************************************/
/**
 * open/create a file.
 * 
 * @param pathname  The full path of the file to be opened/created.
 * @param flags     O_CREAT, O_RDWR, etc.
 * 
 * @return File descriptor if successful, otherwise -1.
 *****************************************************************************/
PUBLIC int open(const char *pathname, int flags)
{
	MESSAGE msg;

	int inwhite = getprot();
	int flag = 0;
	for (int i = 0; i < prot_file_nr; i++){
		if (strcmp(prot_file_table[i], pathname) == 0){
			flag = 1;
			break;
		}
	}
	if (flag == 1 && inwhite == 0){
		printf("You are not allowed to open this file\n");
		return -1;
	}

	msg.type	= OPEN;


	msg.PATHNAME	= (void*)pathname;
	msg.FLAGS	= flags;
	msg.NAME_LEN	= strlen(pathname);

	send_recv(BOTH, TASK_FS, &msg);
	assert(msg.type == SYSCALL_RET);

	return msg.FD;
}
