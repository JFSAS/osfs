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

/*****************************************************************************
 *                                do_search
 *****************************************************************************/
/**

 *****************************************************************************/
PUBLIC int do_dir_search()
{
	char tmp[2];
    char* dir = fs_msg.filenames;

    int cursor = 0, cursor2 = 0, i, j;
	struct inode * pin = 0;

    char filename[MAX_PATH];
    memset(filename, 0, MAX_FILENAME_LEN);
    struct inode* dir_inode;
	struct inode* file_inode;
    if (strip_path(filename, dir, &dir_inode) != 0) // dir初始存放了要查找的文件夹路径
        return 0;

    /**
     * Search the dir for the file.
     */
    int dir_blk0_nr = dir_inode->i_start_sect;
    int nr_dir_blks = (dir_inode->i_size + SECTOR_SIZE - 1) / SECTOR_SIZE;
    int nr_dir_entries = dir_inode->i_size / DIR_ENTRY_SIZE;
	int fd;
    /**
     * including unused slots
     * (the file has been deleted
     * but the slot is still there)
     */

    struct dir_entry* pde;
	char f[MAX_PATH];
    for (i = 0; i < nr_dir_blks; i++) {
        RD_SECT(dir_inode->i_dev, dir_blk0_nr + i);
        pde = (struct dir_entry*)fsbuf;
        for (j = 0; j < SECTOR_SIZE / DIR_ENTRY_SIZE; j++, pde++) {
			if(strlen(pde->name) == 0) continue;
            memcpy(dir + cursor, pde->name, strlen(pde->name));
            cursor += strlen(pde->name);
            dir[cursor] = '\n';
            cursor++;
			// 读取inode信息，参考了open
			
			memcpy(f, pde->name, strlen(pde->name)); // 这里复制是因为之前直接使用pde->name不知道为什么好像栈溢出了
			strip_path(filename, f, &file_inode);
			int inode_nr = search_file(f);
			pin = get_inode(file_inode->i_dev, inode_nr);
			int filesize = pin->i_start_sect;
			fs_msg.filesizes[cursor2] = filesize;
			cursor2++;
			//intToStr(filesize, tmp);
			//memcpy(dir + cursor, tmp, strlen(tmp));
			//cursor += strlen(tmp);
           	//dir[cursor] = '\n';
            //cursor++;
        }
    }

    return 0;
}


