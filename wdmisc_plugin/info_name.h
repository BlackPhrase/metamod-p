// vi: set ts=4 sw=4 :
// vim: set tw=75 :

// info_name.h - name, desc, author, etc

/*
 * Copyright (c) 2001-2006 Will Day <willday@hpgx.net>
 *
 *    This file is part of Metamod.
 *
 *    Metamod is free software; you can redistribute it and/or modify it
 *    under the terms of the GNU General Public License as published by the
 *    Free Software Foundation; either version 2 of the License, or (at
 *    your option) any later version.
 *
 *    Metamod is distributed in the hope that it will be useful, but
 *    WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Metamod; if not, write to the Free Software Foundation,
 *    Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *    In addition, as a special exception, the author gives permission to
 *    link the code of this program with the Half-Life Game Engine ("HL
 *    Engine") and Modified Game Libraries ("MODs") developed by Valve,
 *    L.L.C ("Valve").  You must obey the GNU General Public License in all
 *    respects for all of the code used other than the HL Engine and MODs
 *    from Valve.  If you modify this file, you may extend this exception
 *    to your version of the file, but you are not obligated to do so.  If
 *    you do not wish to do so, delete this exception statement from your
 *    version.
 *
 */

#pragma once

#include "vers_meta.h"		// VDATE, VVERSION, etc

#define VNAME		"WD Misc Functions"
#define VAUTHOR		"Will Day <willday@metamod.org>"
#define VURL		"http://www.metamod.org/"
#define VLOGTAG		"WDMISC"

// Various strings for the Windows DLL Resources in res_plugin.rc
#define RC_COMMENTS		"Adds various server functions.  Requires Metamod; see " VURL
#define RC_DESC			"WDMisc Metamod Plugin DLL"
#define RC_FILENAME		"WDMISC_MM.DLL"
#define RC_INTERNAL		"WDMISC_MM"
#define RC_COPYRIGHT	"Copyrightę 2001-2006 Will Day; licensed under the GPL"