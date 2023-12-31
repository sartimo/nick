#! /bin/sh
###########################################################################
#
# Name
#    coopt.sh -- an inefficient optimizer that can produce very efficient
#                code
#
# DESCRIPTION
#    This optimizer is only run on noninteractive code that takes no
#    output. (It's designed to run on executables produced by INTERCAL
#    code, but will run on other executables that support the +mystery
#    option). It optimizes the file by replacing it by one that simply
#    produces the required output! Therefore, it creates fast but
#    inefficient code. If the file to be optimized hits an error or
#    is terminated by +mystery, then no changes are made.
#
# LICENSE TERMS
#    Copyright (C) 2006 Alex Smith
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
###########################################################################

rm -f icktemp.out >/dev/null 2>/dev/null
if `readlink -f $1` +mystery >icktemp.out 2>/dev/null ; then : ; else
echo Execution of $1 failed.
rm -f icktemp.out ; exit 0 ; fi
rm $1
echo '#! /bin/sh
tail -n+3 $0; exit 0' | cat - icktemp.out > $1
chmod +x $1
rm -f icktemp.out
exit 0
