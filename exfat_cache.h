/*
 *  Copyright (C) 2012-2013 Samsung Electronics Co., Ltd.
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _EXFAT_CACHE_H
#define _EXFAT_CACHE_H

#include "exfat_config.h"
#include "exfat_global.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LOCKBIT                 0x01
#define DIRTYBIT                0x02

	typedef struct __BUF_CACHE_T {
		struct __BUF_CACHE_T *next;
		struct __BUF_CACHE_T *prev;
		struct __BUF_CACHE_T *hash_next;
		struct __BUF_CACHE_T *hash_prev;
		s32                drv;
		u32               sec;
		u32               flag;
		struct buffer_head   *buf_bh;
	} BUF_CACHE_T;

	s32  buf_init(struct super_block *sb);
	s32  buf_shutdown(struct super_block *sb);
	s32  FAT_read(struct super_block *sb, u32 loc, u32 *content);
	s32  FAT_write(struct super_block *sb, u32 loc, u32 content);
	u8 *FAT_getblk(struct super_block *sb, u32 sec);
	void   FAT_modify(struct super_block *sb, u32 sec);
	void   FAT_release_all(struct super_block *sb);
	void   FAT_sync(struct super_block *sb);
	u8 *buf_getblk(struct super_block *sb, u32 sec);
	void   buf_modify(struct super_block *sb, u32 sec);
	void   buf_lock(struct super_block *sb, u32 sec);
	void   buf_unlock(struct super_block *sb, u32 sec);
	void   buf_release(struct super_block *sb, u32 sec);
	void   buf_release_all(struct super_block *sb);
	void   buf_sync(struct super_block *sb);

#ifdef __cplusplus
}
#endif

#endif
