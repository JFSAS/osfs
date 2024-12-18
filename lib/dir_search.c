
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

/*****************************************************************************
 *                                dir_search
 *****************************************************************************/
/**
 *****************************************************************************/
PUBLIC MESSAGE dir_search(char * Path)
{
	MESSAGE msg;
	msg.type   = SEARCH;
	memcpy(msg.filenames, Path, strlen(Path));
	send_recv(BOTH, TASK_FS, &msg);

	return msg;
}
