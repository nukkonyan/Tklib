//Get true of false message statements easier.
stock char Bool[][]	=	{
	"True",
	"False"
};

//Coloured
stock char BoolEx[][]	=	{
	"{green}True{default}",
	"{red}False{default}"
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
 *	Retrieves a command as integer at its index, from the current console or server command.
 *
 *	@note Argument indexes start at 1; 0 retrieves the command name.
 *	@param argnum		Argument number to retrieve.
 *	@return				Integer of the returned argument.
 */
stock int GetCmdInt(int argnum)	{
	char buffer[64];
	GetCmdArg(argnum, buffer, sizeof(buffer));
	
	if(StrEqual(buffer, ""))
		return	-1;
	
	return	StringToInt(buffer);
}

/**
 *	Returns if the client and target is the same player.
 *
 *	@param client		Client index.
 *	@param target		Target index.
 *	@return				Returns true if it's the same player, false otherwise.
 */
stock bool IsSamePlayers(int client, int target)	{
	return (client == target);
}

/**
 *	Returns if the client and target is on the same team.
 *
 *	@param client		Client index.
 *	@param target		Target index.
 *	@return				Returns true if it's they're on the same team, false otherwise.
 */
stock bool IsSameTeam(int client, int target)	{
	return (GetClientTeam(client) == GetClientTeam(target));
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
	return (Identifygame() == gameversion);
}

/**
 *	Tests whether a string is found in another string.
 *	This is same as StrContains but no need to use the -1 at the end, now just returns true or false.
 *
 *	@param	str				String to search in.
 *	@param	substr			Substring to find inside the original string.
 *	@param	caseSensitive	if true (by default), search is case sensitive. If false, search is case insensitive.
 *	*/
stock bool StrContainsEx(char[] str, char[] substr, bool caseSensitive=true)	{
	return (StrContains(str, substr, caseSensitive) != -1);
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
		
	char	TeamColour_Default[][]	=	{
		"{grey}",
		"{grey}",
		"{red}",
		"{blue}"
	},
		TeamColour_TF2[][]	=	{
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
		"{bluegrey}"
	},
		TeamColour_L4D[][]	=	{
		"{grey}",
		"{grey}",
		"{orange}",
		"{lightred}"
	};
	switch(GetEngineVersion())	{
		case	Engine_TF2:			Format(buffer, maxlen, "%s%N{default}", TeamColour_TF2[team],		client);
		case	Engine_CSGO:		Format(buffer, maxlen, "%s%N{default}", TeamColour_CSGO[team],		client);
		case	Engine_Left4Dead:	Format(buffer, maxlen, "%s%N{default}", TeamColour_L4D[team],		client);
		case	Engine_Left4Dead2:	Format(buffer, maxlen, "%s%N{default}", TeamColour_L4D[team],		client);
		default:					Format(buffer, maxlen, "%s%N{default}", TeamColour_Default[team],	client);
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
stock Database SQL_Connect2(char[] confname, bool persistent=true, bool dbg=false)	{
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
	return view_as<bool>(GetRandomInt(0, 1));
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