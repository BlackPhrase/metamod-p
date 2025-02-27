# Metamod-P

A Half-Life Utility Mod

## About

    meta /me't*/ or /may't*/ or (Commonwealth) /mee't*/ adj.,pref.
        [from analytic philosophy] One level of description up.

The purpose of MetaMod is to function "one level up" from the normal
Half-Life game mod DLL. Sitting between the mod game DLL and the Half-Life
engine/binary, it intercepts the function calls between the two, with the
option of passing them along untouched, as well as passing them on to as
any number of _additional mod-like DLLs_.

Thus, you can actually have multiple "mod-like" DLLs in operation at one
time. I say "mod-like" because these additional DLLs (we'll call them
"plugins") are not intended to provide a full "game"; that functionality
is still provided by the "game dll". However, these plugins can _add to_
or _modify the functionality provided by the game dll, or by the engine
itself - for instance, adding new server commands, or new client commands,
or even disabling commands built into the game dll. Although the plugin
isn't intended to provide full HL-game functionality, since it's receiving
the same information given to the game DLL, it has the opportunity to do 
_anything_ the game DLL can do (given enough coding effort of course).

This is very similar to the way Alfred Reynolds' AdminMod
(www.adminmod.org) works, as it also sits between the engine and game dll,
catching routines, and passing them on. thus modifying functionality.
However, rather than providing just the additional server features builtin
to AdminMod DLL, MetaMod allows you to add features from multiple,
separate DLLs. Under that framework, AdminMod can be a plugin itself, and
be run alongside numerous other plugins. And, as of version 2.50 of
AdminMod, AM has now transitioned to running as a Metamod plugin.

See the files under "doc/txt" or "doc/html" for more information.

Will Day
willday@metamod.org
http://www.metamod.org/