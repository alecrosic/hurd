/* Dead name notification

   Copyright (C) 1995 Free Software Foundation, Inc.

   Written by Miles Bader <miles@gnu.ai.mit.edu>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include "ports.h"
#include "notify_S.h"

error_t
ports_do_mach_notify_dead_name (mach_port_t notify, mach_port_t dead_name)
{
  void *pi = ports_lookup_port (0, notify, 0);
  if (!pi)
    return EOPNOTSUPP;
  ports_dead_name (pi, dead_name);
  ports_port_deref (pi);
  return 0;
}
