/*************************************************************************//**
 *****************************************************************************
 * @file   mm/exec.c
 * @brief  
 * @author Forrest Y. Yu
 * @date   Tue May  6 14:14:02 2008
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
#include "keyboard.h"
#include "proto.h"


PUBLIC int do_proc_search()
{
	int cursor1 = 0, cursor2 = 0, i;
	char* procs = mm_msg.procnames;
	struct proc* p = proc_table;

	for (i = 0; i < NR_TASKS + NR_PROCS; i++, p++)
		if (p->p_flags != FREE_SLOT){
			mm_msg.pids[cursor1] = i;
			mm_msg.parentpids[cursor1] = proc_table[i].p_parent;
			cursor1++;
			memcpy(procs + cursor2, proc_table[i].name, strlen(proc_table[i].name));
			cursor2 += strlen(proc_table[i].name);
			procs[cursor2] = '\n';
			cursor2++;
		}
	return 0;
			
}
