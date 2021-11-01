//Get true of false message statements easier.
stock char Bool[][]	=	{
	"False",
	"True"
};

//Coloured
stock char BoolEx[][]	=	{
	"{red}False{default}",
	"{green}True{default}"
};

//Useful for simple open/closing door entites. Value 0 = Close, 1 = Open.
stock char DoorSwitch[][]	=	{
	"close",
	"open"
};

//On - Off switch.
stock char OnOff[][]	=	{
	"Off",
	"On"
};

//On - Off switch coloured.
stock char OnOffEx[][]	=	{
	"{red}Off{default}",
	"{green}On{default}"
};

/**
 *	Returns the AdminFlag from the ADMFLAG you specify.
 *
 *	@param adminflags	The adminflag integer.
 */
stock AdminFlag AdmflagToAdminFlag(int adminflags)	{
	AdminFlag adminflag;
	
	switch(adminflags)	{
		case	ADMFLAG_RESERVATION:	adminflag = Admin_Reservation;
		case	ADMFLAG_GENERIC:		adminflag = Admin_Generic;
		case	ADMFLAG_KICK:			adminflag = Admin_Kick;
		case	ADMFLAG_BAN:			adminflag = Admin_Ban;
		case	ADMFLAG_UNBAN:			adminflag = Admin_Unban;
		case	ADMFLAG_SLAY:			adminflag = Admin_Slay;
		case	ADMFLAG_CHANGEMAP:		adminflag = Admin_Changemap;
		case	ADMFLAG_CONVARS:		adminflag = Admin_Convars;
		case	ADMFLAG_CONFIG:			adminflag = Admin_Config;
		case	ADMFLAG_CHAT:			adminflag = Admin_Chat;
		case	ADMFLAG_VOTE:			adminflag = Admin_Vote;
		case	ADMFLAG_PASSWORD:		adminflag = Admin_Password;
		case	ADMFLAG_RCON:			adminflag = Admin_RCON;
		case	ADMFLAG_CHEATS:			adminflag = Admin_Cheats;
		case	ADMFLAG_ROOT:			adminflag = Admin_Root;
		case	ADMFLAG_CUSTOM1:		adminflag = Admin_Custom1;
		case	ADMFLAG_CUSTOM2:		adminflag = Admin_Custom2;
		case	ADMFLAG_CUSTOM3:		adminflag = Admin_Custom3;
		case	ADMFLAG_CUSTOM4:		adminflag = Admin_Custom4;
		case	ADMFLAG_CUSTOM5:		adminflag = Admin_Custom5;
		case	ADMFLAG_CUSTOM6:		adminflag = Admin_Custom6;
	}
	
	return	adminflag;
}

/**
 *	Returns the ADMFLAG from the AdminFlag you specify.
 *
 *	@param adminflags	The AdminFlag flag.
 */
stock int AdminFlaglagToAdmflag(AdminFlag adminflags)	{
	int adminflag;
	
	switch(adminflags)	{
		case	Admin_Reservation:	adminflag = ADMFLAG_RESERVATION;
		case	Admin_Generic:		adminflag = ADMFLAG_GENERIC;
		case	Admin_Kick:			adminflag = ADMFLAG_KICK;
		case	Admin_Ban:			adminflag = ADMFLAG_BAN;
		case	Admin_Unban:		adminflag = ADMFLAG_UNBAN;
		case	Admin_Slay:			adminflag = ADMFLAG_SLAY;
		case	Admin_Changemap:	adminflag = ADMFLAG_CHANGEMAP;
		case	Admin_Convars:		adminflag = ADMFLAG_CONVARS;
		case	Admin_Config:		adminflag = ADMFLAG_CONFIG;
		case	Admin_Chat:			adminflag = ADMFLAG_CHAT;
		case	Admin_Vote:			adminflag = ADMFLAG_VOTE;
		case	Admin_Password:		adminflag = ADMFLAG_PASSWORD;
		case	Admin_RCON:			adminflag = ADMFLAG_RCON;
		case	Admin_Cheats:		adminflag = ADMFLAG_CHEATS;
		case	Admin_Root:			adminflag = ADMFLAG_ROOT;
		case	Admin_Custom1:		adminflag = ADMFLAG_CUSTOM1;
		case	Admin_Custom2:		adminflag = ADMFLAG_CUSTOM2;
		case	Admin_Custom3:		adminflag = ADMFLAG_CUSTOM3;
		case	Admin_Custom4:		adminflag = ADMFLAG_CUSTOM4;
		case	Admin_Custom5:		adminflag = ADMFLAG_CUSTOM5;
		case	Admin_Custom6:		adminflag = ADMFLAG_CUSTOM6;
	}
	
	return	adminflag;
}

/**
 *	Retrieves a command as integer given its index, from the current console or server command.
 *
 *	@note Argument indexes start at 1; 0 retrieves the command name.
 *	@param	argnum		Argument number to retrieve.
 *	@return				Integer of the returned argument.
 */
stock int GetCmdInt(int argnum)	{
	char buffer[256];
	GetCmdArg(argnum, buffer, sizeof(buffer));
	return	StringToInt(buffer);
}

/**
 *	Retrieves a command as boolean given its index, from the current console or server command.
 *
 *	@note Argument indexes start at 1; 0 retrieves the command name.
 *	@param	argnum		Argument number to retrieve.
 *
 *	@return				Integer of the returned argument.
 */
stock bool GetCmdBool(int argnum)	{
	char buffer[256];
	GetCmdArg(argnum, buffer, sizeof(buffer));
	return	bool(StringToInt(buffer);
}

/**
 *	Turns an integer into a floating point.
 *
 *	@param value	Float to convert.
 *	@return			Integer result, or 0 on error. 
 */
stock int FloatToInt(float value)	{
	char buffer[96];
	FloatToString(value, buffer, sizeof(buffer));
	return	StringToInt(buffer);
}

/**
 *	Returns if the game is the game you you specified.
 *	This can be quite useful for checking things and not take too much space.
 *
 *	@param game			The EngineVersion game you specify.
 *	@return				If true, game you specified is active, else false.
 */
stock bool IsCurrentGame(GameIdentifier gameversion)	{
	return	bool(IdentifyGame() == gameversion);
}

/**
 *	Tests whether a string is found in another string.
 *	This is same as StrContains but no need to use the -1 at the end, now just returns true or false.
 *
 *	@param	str				String to search in.
 *	@param	substr			Substring to find inside the original string.
 *	@param	caseSensitive	if true (by default), search is case sensitive. If false, search is case insensitive.
 *	*/
stock bool StrContainsEx(const char[] str, const char[] substr, bool caseSensitive=true)	{
	return	bool(StrContains(str, substr, caseSensitive) != -1);
}

/**
 *	Returns the teamcoloured name of the client specified.
 *
 *	@param		client		The client index.
 *	@param		buffer		Buffer storage to store the name.
 *	@param		maxlen		Maximum length of the buffer storage.
 *	@return		Returns true if succeeded, else false.
 */
stock bool GetClientTeamString(int client, char[] buffer, int maxlen)	{
	int team = Tklib_IsValidClient(client) ? GetClientTeam(client):0;
		
	char
		TeamColour_Default[][]	=	{
		"{grey}",
		"{grey}",
		"{red}",
		"{blue}"
	},
		TeamColour_TF2C[][]	=	{
		"{grey}",
		"{grey}",
		"{red}",
		"{blue}",
		"{lightgreen}",
		"{orange}"
	},
		TeamColour_CSGO[][]	=	{
		"{grey}",
		"{grey}",
		"{orange}",
		"{blue}"
	},
		TeamColour_L4D[][]	=	{
		"{grey}",
		"{grey}",
		"{orange}",
		"{lightred}"
	};
	
	switch(IdentifyGame())	{
		case	Game_TF2C:	Format(buffer, maxlen, "%s%N{default}", TeamColour_TF2C[team],		client);
		case	Game_CSGO:	Format(buffer, maxlen, "%s%N{default}", TeamColour_CSGO[team],		client);
		case	Game_L4D1:	Format(buffer, maxlen, "%s%N{default}", TeamColour_L4D[team],		client);
		case	Game_L4D2:	Format(buffer, maxlen, "%s%N{default}", TeamColour_L4D[team],		client);
		default:			Format(buffer, maxlen, "%s%N{default}", TeamColour_Default[team],	client);
	}
	
	return	true;
}

/**
 *	Same as SQL_Connect but this is if you just want a temporary connection.
 *
 *	@param		confname		The name of the database config connection.
 *	@param		persistent		If true, it will try to use a previous persistent connection.
 *	@param		debug			If true, it will show message if the connection returned 'null' (Error) or if it succeeded.
 */
stock Database SQL_Connect2(const char[] confname, bool persistent=true, bool dbg=false)	{
	char error[256];
	Database database = SQL_Connect(confname, persistent, error, sizeof(error));
	if(dbg)	{
		switch(database == null)	{
			case	true:	PrintToServer("[Tklib: Additional] SQL_Connect2: Connection to database \"%s\" had an error (%s)", confname, error);
			case	false:	PrintToServer("[Tklib: Additional] SQL_Connect2: Connection to database \"%s\" succeeded!", confname);
		}
	}
	
	return database;
}

/**
 *	Returns GetRandomInt(0, 1) in boolean.
 */
stock bool GetRandomBool()	{
	return	bool(GetRandomInt(0, 1));
}

/**
 *	Same as CreateNative but you use 2 natives before forwarding it to a callback.
 *	Useful for having 2 natives that uses the same forward.
 *	Paired with MarkNativeAsOptionalEx.
 *
 *	@param	native1		Native 1.
 *	@param	native2		Native 2.
 *	@param	func		Native callback.
 */
stock void CreateNativeEx(const char[] native1, const char[] native2, NativeCall func)	{
	CreateNative(native1, func);
	CreateNative(native2, func);
}

/**
 *	Same as MarkNativeAsOptional but you use 2 natives before marking it optional.
 *	Useful for cleaning up code and also for 2 natives that use same forward.
 *	Paired with CreateNativeEx.
 */
stock void MarkNativeAsOptionalEx(const char[] native1, const char[] native2)	{
	MarkNativeAsOptional(native1);
	MarkNativeAsOptional(native2);
}

/**
 *	Functions the same as CreateNative and MarkNativeAsOptional.
 *	Useful for having a fairly 'clean' code.
 *
 *	@param	name	The dynamic native name.
 *	@param	func	The dynamic native callback.
 */
stock void CreateNativeEx2(const char[] name, NativeCall func)	{
	CreateNative(name, func);
	MarkNativeAsOptional(name);
}

/**
 *	Alternative to strcopy, adds ability to use extra parameters.
 *	Pretty much does the same as Format.
 *
 *	@param	dest		Destination buffer to copy to.
 *	@param	destLen		Destination buffer length (includes null terminator).
 *	@param	source		Source string to copy from.
 *
 *	@return				Number of cells written.
 */
stock int strcopyEx(char[] dest, int destLen, const char[] source, any...)	{
	char format[256];
	strcopy(format, sizeof(format), source);
	
	VFormat(format, sizeof(format), 4);
	
	strcopy(dest, destLen, format);
}

/**
 *	Auto-switches the bool value on/off.
 *	Example: if the value is on, it will return off.
 *	If it's off, it will return on.
 *	Useful for toggling functions in plugins.
 *
 *	@param	value		The value to toggle.
 *	@return	Returns the new value.
 */
stock bool AutoSwitch(bool value)	{
	switch(value)	{
		case	true:	value = false;
		case	false:	value = true;
	}
	
	return value;
}

/**
 *	Same as AddFileToDownloadsTable but adds support for additional parameters.
 *
 *	@param	filename	File path.
 *	@param	...			Additional parameters.
 */
stock void AddFileToDownloadsTableEx(const char[] filename, any ...)	{
	char download[256];
	VFormat(download, sizeof(download), filename, 2);
	AddFileToDownloadsTable(download);
}

/**
 *	Adds the specified files within the folder directory onto the downloads table.
 *
 *	@param	path		The path directory.
 *	@param	precache	Should the files be precached?.
 *	@param	type		The type of file to precache. (materials, models, sound, etc.)
 *	@param	filter		If non-empty, this will filter to require the meeting to be added to the dl table.
 *	@param	dbg			If the path is valid, this is useful for debugging seeing what got added to the dl table.
 *	@error	If the path is invalid or this failed in general, this returns false.
 */
stock bool AddFolderToDownloadsTable(const char[] path, bool precache=false, const char[] type="", const char[] filter="", bool dbg=false)	{
	DirectoryListing DLPath = OpenDirectory(path);
	bool success = false, invalid_filter = false;
	
	switch(DLPath == null)	{
		case	false:	{
			char FileDir[64], FileDL[256];
			
			while(ReadDirEntry(DLPath, FileDir, sizeof(FileDir)))	{
				if(!StrEqual(FileDir, ".") && !StrEqual(FileDir, ".."))	{
					invalid_filter = (!StrEqual(filter, "") && !StrContainsEx(FileDir, filter));
					
					if(!invalid_filter)	{
						AddFileToDownloadsTableEx(FileDL, "%s/%s", path, FileDir);
						if(precache && !StrEqual(type, ""))
							PrecacheModel(FileDL);
						
						if(dbg)
							PrintToServer("[Tklib: Additional] AddFolderToDownloadsTable: %s/%s", path, FileDir);
					}
				}
			}
			
			success = true;
		}
		case	true:	{
			if(dbg)
				PrintToServer("[Tklib: Additional] AddFolderToDownloadsTable failed due to invalid path (%s)", path);
		}
	}
	
	delete DLPath;
	
	return	success;
}

/**
 *	Turns a string into a boolean.
 *
 *	@param	str		String to convert.
 *	@param	nBase	Numerical base to use. 10 is default.
 *
 *	@return	Boolean conversion of string or false on failure.
 */
stock bool StringToBool(const char[] str, int nBase=10)	{
	return bool(StringToInt(str, nBase));
}

/**
 *	Adds ConVar flag(s).
 *
 *	@param	cvar	The ConVar to change.
 *	@param	flags	The flags to add.
 *
 *	@error	If the ConVar is invalid, this returns false.
 */
stock bool AddConVarFlags(ConVar cvar, int flags)	{
	if(cvar == null)
		return	false;
	
	int flag = cvar.Flags;
	
	flag |= flags;
	
	cvar.Flags = flags;
	
	return	true;
}

/**
 *	Adds ConVar flag(s).
 *
 *	@param	cvar	The ConVar name to change.
 *	@param	flags	The flags to add.
 *
 *	@error	If the ConVar is invalid, this returns false.
 */
stock bool AddConVarFlagsEx(const char[] convar, int flags)	{
	ConVar cvar = FindConVar(convar);
	if(cvar == null)	{
		delete cvar;
		return	false;
	}
	
	int flag = cvar.Flags;
	
	flag |= flags;
	
	cvar.Flags = flags;
	
	delete cvar;
	
	return	true;
}

/**
 *	Removes ConVar flag(s).
 *
 *	@param	cvar	The ConVar to change.
 *	@param	flags	The flags to remove.
 *
 *	@error	If the ConVar is invalid, this returns false.
 */
stock bool RemoveConVarFlags(ConVar cvar, int flags)	{
	if(cvar == null)
		return	false;
	
	int flag = cvar.Flags;
	
	flag &= ~flags;
	
	cvar.Flags = flag;
	
	return	true;
}

/**
 *	Removes ConVar flag(s).
 *
 *	@param	cvar	The ConVar name to change.
 *	@param	flags	The flags to remove.
 *
 *	@error	If the ConVar is invalid, this returns false.
 */
stock bool RemoveConVarFlagsEx(const char[] convar, int flags)	{
	ConVar cvar = FindConVar(convar);
	if(cvar == null)	{
		delete cvar;
		return	false;
	}
	
	int flag = cvar.Flags;
	
	flag &= ~flags;
	
	cvar.Flags = flag;
	
	delete cvar;
	
	return	true;
}

/**
 *	Sends a SayText2 usermessage to a client.
 *
 *	@param	client		Users index.
 *	@param	index		Sender index.
 *	@param	message		Message.
 *	@noreturn
 *
 *	@error	If the user is invalid or the procedure failed/not supported for the current gamemod, this returns false.
 */
stock bool SayText2(int client, int index=-1, const char[] message, any ...) {
	if(!Tklib_IsValidClient(client))
		return	false;
	
	if(!Tklib_IsValidClient(author))
		return	false;
	
	if(GetFeatureStatus(FeatureType_Native, "GetUserMessageType") == FeatureStatus_Unavailable)
		return	false;
	
	if(GetUserMessageId("SayText2") == INVALID_MESSAGE_ID)
		return	false;
	
	Handle msg = null;
	
	if((msg = StartMessageOne("SayText2", client, USERMSG_RELIABLE|USERMSG_BLOCKHOOKS)) != null)	{
		char format[96];
		VFormat(format, sizeof(format), message, 4);
		
		switch(GetUserMessageType())	{
			case	UM_Protobuf:	{
				Protobuf pb = UserMessageToProtobuf(msg);
				pb.SetInt("ent_idx", author);
				pb.SetBool("chat", true);
				pb.SetString("msg_name", format);
				pb.AddString("params", "");
				pb.AddString("params", "");
				pb.AddString("params", "");
				pb.AddString("params", "");
			}
			case	UM_BitBuf:	{
				BfWrite bf = UserMessageToBfWrite(msg);
				bf.WriteByte(author);
				bf.WriteByte(true);
				bf.WriteString(format);
			}
		}
	
		EndMessage();
		
		return	true;
	}
	
	return	false;
}

/**
 *	Gets a cell in boolean from native parameter.
 *
 *	@param	param	Parameter number, starting from 1.
 *
 *	@return			Boolean value from cell at the parameter number.
 *
 *	@error			Invalid paramteter number or calling from non-native function.
 */
stock bool GetNativeBool(int param)
{
	return	bool(GetNativeCell(param));
}