/* Parse run-time options

   Copyright (C) 1995 Free Software Foundation, Inc.

   This file is part of the GNU Hurd.

   The GNU Hurd is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   The GNU Hurd is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include <errno.h>
#include <argz.h>

#include "priv.h"
#include "fsys_S.h"

/* Implement fsys_set_options as described in <hurd/fsys.defs>. */
kern_return_t
diskfs_S_fsys_set_options (fsys_t fsys,
			   char *data, mach_msg_type_number_t len,
			   int do_children)
{
  int argc = argz_count (data, len);
  char **argv = alloca (sizeof (char *) * (argc + 1));

  argz_extract (data, len, argv);

  return diskfs_set_options (argc, argv);
}
