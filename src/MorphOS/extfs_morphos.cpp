/*
 *  extfs_amiga.cpp - MacOS file system for access native file system access, AmigaOS specific stuff
 *
 *  Basilisk II (C) 1997-2001 Christian Bauer
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <proto/dos.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#include "sysdeps.h"
#include "extfs.h"
#include "extfs_defs.h"

#define DEBUG 0
#include "debug.h"


// Default Finder flags
const uint16 DEFAULT_FINDER_FLAGS = kHasBeenInited;


/*
 *  Initialization
 */

void extfs_init(void)
{
}


/*
 *  Deinitialization
 */

void extfs_exit(void)
{
}


/*
 *  Add component to path name
 */

void add_path_component(char *path, const char *component)
{
	AddPart(path, (char *)component, MAX_PATH_LENGTH);
}


/*
 *  Finder info and resource forks are kept in helper files
 *
 *  Finder info:
 *    /path/.finf/file
 *  Resource fork:
 *    /path/.rsrc/file
 *
 *  The .finf files store a FInfo/DInfo, followed by a FXInfo/DXInfo
 *  (16+16 bytes)
 */

static void make_helper_path(const char *src, char *dest, const char *add, bool only_dir = false)
{
	dest[0] = 0;

	// Get pointer to last component of path
	const char *last_part = FilePart((char *)src);

	// Copy everything before
	stccpy(dest, src, last_part-src);

	// Add additional component
	AddPart(dest, (char *)add, MAX_PATH_LENGTH);

	// Add last component
	if (!only_dir)
		AddPart(dest, (char *)last_part, MAX_PATH_LENGTH);
}

static int create_helper_dir(const char *path, const char *add)
{
	char helper_dir[MAX_PATH_LENGTH];
	make_helper_path(path, helper_dir, add, true);
	if (helper_dir[strlen(helper_dir) - 1] == '/')	// Remove trailing "/"
		helper_dir[strlen(helper_dir) - 1] = 0;
	return mkdir(helper_dir, 0777);
}

static int open_helper(const char *path, const char *add, int flag)
{
	char helper_path[MAX_PATH_LENGTH];
	make_helper_path(path, helper_path, add);

	if ((flag & O_ACCMODE) == O_RDWR || (flag & O_ACCMODE) == O_WRONLY)
		flag |= O_CREAT;
	int fd = open(helper_path, flag, 0666);
	if (fd < 0) {
		if (errno == ENOENT && (flag & O_CREAT)) {
			// One path component was missing, probably the helper
			// directory. Try to create it and re-open the file.
			int ret = create_helper_dir(path, add);
			if (ret < 0)
				return ret;
			fd = open(helper_path, flag, 0666);
		}
	}
	return fd;
}

static int open_finf(const char *path, int flag)
{
	return open_helper(path, ".finf/", flag);
}

static int open_rsrc(const char *path, int flag)
{
	return open_helper(path, ".rsrc/", flag);
}


/*
 *  Get/set finder type/creator for file specified by full path
 */

struct ext2type {
	const char *ext;
	uint32 type;
	uint32 creator;
};

static const ext2type e2t_translation[] = {
	{".z", FOURCC('Z','I','V','M'), FOURCC('L','Z','I','V')},
	{".gz", FOURCC('G','z','i','p'), FOURCC('G','z','i','p')},
	{".hqx", FOURCC('T','E','X','T'), FOURCC('S','I','T','x')},
	{".bin", FOURCC('T','E','X','T'), FOURCC('S','I','T','x')},
	{".pdf", FOURCC('P','D','F',' '), FOURCC('C','A','R','O')},
	{".ps", FOURCC('T','E','X','T'), FOURCC('t','t','x','t')},
	{".sit", FOURCC('S','I','T','!'), FOURCC('S','I','T','x')},
	{".tar", FOURCC('T','A','R','F'), FOURCC('T','A','R',' ')},
	{".uu", FOURCC('T','E','X','T'), FOURCC('S','I','T','x')},
	{".uue", FOURCC('T','E','X','T'), FOURCC('S','I','T','x')},
	{".zip", FOURCC('Z','I','P',' '), FOURCC('Z','I','P',' ')},
	{".8svx", FOURCC('8','S','V','X'), FOURCC('S','N','D','M')},
	{".aifc", FOURCC('A','I','F','C'), FOURCC('T','V','O','D')},
	{".aiff", FOURCC('A','I','F','F'), FOURCC('T','V','O','D')},
	{".au", FOURCC('U','L','A','W'), FOURCC('T','V','O','D')},
	{".mid", FOURCC('M','I','D','I'), FOURCC('T','V','O','D')},
	{".midi", FOURCC('M','I','D','I'), FOURCC('T','V','O','D')},
	{".mp2", FOURCC('M','P','G',' '), FOURCC('T','V','O','D')},
	{".mp3", FOURCC('M','P','G',' '), FOURCC('T','V','O','D')},
	{".wav", FOURCC('W','A','V','E'), FOURCC('T','V','O','D')},
	{".bmp", FOURCC('B','M','P','f'), FOURCC('o','g','l','e')},
	{".gif", FOURCC('G','I','F','f'), FOURCC('o','g','l','e')},
	{".lbm", FOURCC('I','L','B','M'), FOURCC('G','K','O','N')},
	{".ilbm", FOURCC('I','L','B','M'), FOURCC('G','K','O','N')},
	{".jpg", FOURCC('J','P','E','G'), FOURCC('o','g','l','e')},
	{".jpeg", FOURCC('J','P','E','G'), FOURCC('o','g','l','e')},
	{".pict", FOURCC('P','I','C','T'), FOURCC('o','g','l','e')},
	{".png", FOURCC('P','N','G','f'), FOURCC('o','g','l','e')},
	{".sgi", FOURCC('.','S','G','I'), FOURCC('o','g','l','e')},
	{".tga", FOURCC('T','P','I','C'), FOURCC('o','g','l','e')},
	{".tif", FOURCC('T','I','F','F'), FOURCC('o','g','l','e')},
	{".tiff", FOURCC('T','I','F','F'), FOURCC('o','g','l','e')},
	{".htm", FOURCC('T','E','X','T'), FOURCC('M','O','S','S')},
	{".html", FOURCC('T','E','X','T'), FOURCC('M','O','S','S')},
	{".txt", FOURCC('T','E','X','T'), FOURCC('t','t','x','t')},
	{".rtf", FOURCC('T','E','X','T'), FOURCC('M','S','W','D')},
	{".c", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".cc", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".cpp", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".cxx", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".h", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".hh", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".hpp", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".hxx", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".s", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".i", FOURCC('T','E','X','T'), FOURCC('R','*','c','h')},
	{".mpg", FOURCC('M','P','E','G'), FOURCC('T','V','O','D')},
	{".mpeg", FOURCC('M','P','E','G'), FOURCC('T','V','O','D')},
	{".mov", FOURCC('M','o','o','V'), FOURCC('T','V','O','D')},
	{".fli", FOURCC('F','L','I',' '), FOURCC('T','V','O','D')},
	{".avi", FOURCC('V','f','W',' '), FOURCC('T','V','O','D')},
	{".qxd", FOURCC('X','D','O','C'), FOURCC('X','P','R','3')},
	{".hfv", FOURCC('D','D','i','m'), FOURCC('d','d','s','k')},
	{".dsk", FOURCC('D','D','i','m'), FOURCC('d','d','s','k')},
	{".img", FOURCC('r','o','h','d'), FOURCC('d','d','s','k')},
	{NULL, 0, 0}	// End marker
};

void get_finfo(const char *path, uint32 finfo, uint32 fxinfo, bool is_dir)
{
	// Set default finder info
	Mac_memset(finfo, 0, SIZEOF_FInfo);
	if (fxinfo)
		Mac_memset(fxinfo, 0, SIZEOF_FXInfo);
	WriteMacInt16(finfo + fdFlags, DEFAULT_FINDER_FLAGS);
	WriteMacInt32(finfo + fdLocation, (uint32)-1);

	// Read Finder info file
	int fd = open_finf(path, O_RDONLY);
	if (fd >= 0) {
		ssize_t actual = read(fd, Mac2HostAddr(finfo), SIZEOF_FInfo);
		if (fxinfo)
			actual += read(fd, Mac2HostAddr(fxinfo), SIZEOF_FXInfo);
		close(fd);
		if (actual >= SIZEOF_FInfo)
			return;
	}

	// No Finder info file, translate file name extension to MacOS type/creator
	if (!is_dir) {
		int path_len = strlen(path);
		for (int i=0; e2t_translation[i].ext; i++) {
			int ext_len = strlen(e2t_translation[i].ext);
			if (path_len < ext_len)
				continue;
			if (!strcasecmp(path + path_len - ext_len, e2t_translation[i].ext)) {
				WriteMacInt32(finfo + fdType, e2t_translation[i].type);
				WriteMacInt32(finfo + fdCreator, e2t_translation[i].creator);
				break;
			}
		}
	}
}

void set_finfo(const char *path, uint32 finfo, uint32 fxinfo, bool is_dir)
{
	// Open Finder info file
	int fd = open_finf(path, O_RDWR);
	if (fd < 0)
		return;

	// Write file
	write(fd, Mac2HostAddr(finfo), SIZEOF_FInfo);
	if (fxinfo)
		write(fd, Mac2HostAddr(fxinfo), SIZEOF_FXInfo);
	close(fd);
}


/*
 *  Resource fork emulation functions
 */

uint32 get_rfork_size(const char *path)
{
	// Open resource file
	int fd = open_rsrc(path, O_RDONLY);
	if (fd < 0)
		return 0;

	// Get size
	off_t size = lseek(fd, 0, SEEK_END);
	
	// Close file and return size
	close(fd);
	return size < 0 ? 0 : size;
}

int open_rfork(const char *path, int flag)
{
	return open_rsrc(path, flag);
}

void close_rfork(const char *path, int fd)
{
	close(fd);
}


/*
 *  Read "length" bytes from file to "buffer",
 *  returns number of bytes read (or -1 on error)
 */

ssize_t extfs_read(int fd, void *buffer, size_t length)
{
	return read(fd, buffer, length);
}


/*
 *  Write "length" bytes from "buffer" to file,
 *  returns number of bytes written (or -1 on error)
 */

ssize_t extfs_write(int fd, void *buffer, size_t length)
{
	return write(fd, buffer, length);
}


/*
 *  Remove file/directory (and associated helper files),
 *  returns false on error (and sets errno)
 */

bool extfs_remove(const char *path)
{
	// Remove helpers first, don't complain if this fails
	char helper_path[MAX_PATH_LENGTH];
	make_helper_path(path, helper_path, ".finf/", false);
	remove(helper_path);
	make_helper_path(path, helper_path, ".rsrc/", false);
	remove(helper_path);

	// Now remove file or directory (and helper directories in the directory)
	if (remove(path) < 0) {
		if (errno == EISDIR || errno == ENOTEMPTY) {
			stccpy(helper_path, path, MAX_PATH_LENGTH);
			add_path_component(helper_path, ".finf");
			#if 1
			remove(helper_path);
			#else
			rmdir(helper_path);
			#endif
			stccpy(helper_path, path, MAX_PATH_LENGTH);
			add_path_component(helper_path, ".rsrc");
			#if 1
			remove(helper_path);
			#else
			rmdir(helper_path);
			#endif
//			return rmdir(path) == 0;
			return remove(path) == 0;
		} else
			return false;
	}
	return true;
}


/*
 *  Rename/move file/directory (and associated helper files),
 *  returns false on error (and sets errno)
 */

bool extfs_rename(const char *old_path, const char *new_path)
{
	// Rename helpers first, don't complain if this fails
	char old_helper_path[MAX_PATH_LENGTH], new_helper_path[MAX_PATH_LENGTH];
	make_helper_path(old_path, old_helper_path, ".finf/", false);
	make_helper_path(new_path, new_helper_path, ".finf/", false);
	create_helper_dir(new_path, ".finf/");
	rename(old_helper_path, new_helper_path);
	make_helper_path(old_path, old_helper_path, ".rsrc/", false);
	make_helper_path(new_path, new_helper_path, ".rsrc/", false);
	create_helper_dir(new_path, ".rsrc/");
	rename(old_helper_path, new_helper_path);

	// Now rename file
	return rename(old_path, new_path) == 0;
}


#if 0
/*
 *  ftruncate() is missing from old libnix
 */

extern unsigned long *__stdfiledes;

int ftruncate(int fd, off_t size)
{
	if (SetFileSize(__stdfiledes[fd], size, OFFSET_BEGINNING) < 0)
		return -1;
	else
		return 0;
}
#endif