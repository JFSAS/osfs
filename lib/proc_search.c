
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
PUBLIC MESSAGE proc_search()
{
	MESSAGE msg;
	msg.type   = PROC_SEARCH;
	send_recv(BOTH, TASK_MM, &msg);

	return msg;
}
