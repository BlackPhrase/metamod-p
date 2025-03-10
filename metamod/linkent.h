// vi: set ts=4 sw=4 :
// vim: set tw=75 :

// linkent.h - export entities from mod "games" back to the HL engine

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

#include <extdll.h>		// always

#include "osdep.h"		// DLLEXPORT, etc
#include "metamod.h"	// GameDLL, etc
#include "mlist.h"		// MPluginList::find_match, etc
#include "mplugin.h"	// MPlugin::info, etc
#include "log_meta.h"	// META_DEBUG, etc


//Initializes replacement code
int DLLINTERNAL init_linkent_replacement(DLHANDLE moduleMetamod, DLHANDLE moduleGame);


// Comments from SDK dlls/util.h:
//! This is the glue that hooks .MAP entity class names to our CPP classes.
//! The _declspec forces them to be exported by name so we can do a lookup with GetProcAddress().
//! The function is used to intialize / allocate the object for the entity.

// Adapted from LINK_ENTITY_TO_FUNC in adminmod linkfunc.cpp.

typedef void (*ENTITY_FN) (entvars_t *);


// For now, we have to explicitly export functions for plugin entities,
// just as for gamedll entities.  Ideally, this could be generalized in
// some manner, so that plugins can declare and use their own entities
// without having them explicitly supported by metamod, but I don't know
// yet if that is actually possible.
//
// LINK_ENTITY_TO_PLUGIN
//  - if plugin not loaded & running, return
//  - plugin has to be set loadable=startup only, else log error, return
//  - (plugin loaded) if func missing, return
//  - (plugin loaded) if func not found, dlsym
//  - (plugin loaded) if func still not found, set missing, return
//  - (plugin loaded, func found) call func
#define LINK_ENTITY_TO_PLUGIN(entityName, pluginName) \
	C_DLLEXPORT void entityName(entvars_t *pev); \
	void entityName(entvars_t *pev) { \
		static ENTITY_FN pfnEntity = NULL; \
		static int missing=0; \
		char *entStr; \
		MPlugin *findp; \
		entStr = STRINGIZE(entityName, 0); \
		if(missing) \
			return; \
		if(!pfnEntity) { \
			if(!(findp=Plugins->find_match(pluginName))) { \
				META_WARNING("Couldn't find loaded plugin '%s' for plugin entity '%s'", pluginName, entStr); \
				missing=1; \
				return; \
			} \
			if(findp->info && findp->info->loadable != PT_STARTUP) { \
				META_WARNING("Can't link entity '%s' for plugin '%s'; loadable != startup: %s", entStr, pluginName, findp->str_loadable()); \
				missing=1; \
				return; \
			} \
			META_DEBUG(9, ("Looking up plugin entity '%s'", entStr)); \
			pfnEntity = (ENTITY_FN) DLSYM(findp->handle, entStr); \
		} \
		if(!pfnEntity) { \
			META_WARNING("Couldn't find plugin entity '%s' in plugin DLL '%s'", entStr, findp->file); \
			missing=1; \
			return; \
		} \
		META_DEBUG(8, ("Linking plugin entity '%s'", entStr)); \
		(*pfnEntity)(pev); \
	}