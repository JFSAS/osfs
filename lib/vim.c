/*************************************************************************//**
 *****************************************************************************
 * @file   write.c
 * @brief  write()
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

/*****************************************************************************
 *                                write
 *****************************************************************************/
/**
 * Write to a file descriptor.
 * 
 * @param fd     usually stdin
 * @param buf    Buffer including the bytes to write.
 * @param count  How many bytes to write.
 * 
 * @return  On success, the number of bytes written are returned.
 *          On error, -1 is returned.
 *****************************************************************************/
PUBLIC int vim(int fd, char *buf1, char *buf2, int need)
{
	MESSAGE msg;
	msg.type = VIM;
	msg.FD   = fd;
	
	memcpy(msg.filenames, buf1, strlen(buf1));
	msg.filenames[strlen(buf1)] = '\0';
	msg.CNT  = need;
	msg.BUF  = buf2;
	send_recv(BOTH, TASK_FS, &msg);

	return msg.CNT;
}
