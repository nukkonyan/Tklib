/**************************************************************************
 *                                                                        *
 *                       Colored Chat Functions                           *
 *                   Author: exvel, Editor: Popoklopsi, Powerlord, Bara   *
 *                                                                        *
 *					Updated by Tk /id/Teamkiller324			 			  *
 *				  			 for Tk Libraries							  *
 **************************************************************************/
 

#if defined _colors_included
 #endinput
#endif
#define _colors_included
 
#define		MAX_MESSAGE_LENGTH	250
#define		MAX_COLORS			18

#define		SERVER_INDEX	0
#define		NO_INDEX		-1
#define		NO_PLAYER		-2

enum C_Colors {
 	Color_Default = 0,
	Color_Darkred,
	Color_Green,
	Color_Lightgreen,
	Color_Red,
	Color_Blue,
	Color_Olive,
	Color_Lime,
	Color_Lightred,
	Color_Purple,
	Color_Grey,
	Color_Yellow,
	Color_Orange,
	Color_Bluegrey,
	Color_Lightblue,
	Color_Darkblue,
	Color_Grey2,
	Color_Orchid,
	Color_Lightred2
}

/* C_Colors' properties */
char	C_Tag[][]	=	{
	"{default}",
	"{darkred}",
	"{green}",
	"{lightgreen}",
	"{red}",
	"{blue}",
	"{olive}",
	"{lime}",
	"{lightred}",
	"{purple}",
	"{grey}",
	"{yellow}",
	"{orange}",
	"{bluegrey}",
	"{lightblue}",
	"{darkblue}",
	"{grey2}",
	"{orchid}",
	"{lightred2}"
};

char	C_TagCode[][]	=	{
	"\x01",
	"\x02",
	"\x04",
	"\x03",
	"\x03",
	"\x03",
	"\x05",
	"\x06",
	"\x07",
	"\x03",
	"\x08",
	"\x09",
	"\x10",
	"\x0A",
	"\x0B",
	"\x0C",
	"\x0D",
	"\x0E",
	"\x0F"
};

bool	C_TagReqSayText2[]	=	{
	false,
	false,
	false,
	true,
	true,
	true,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false
};

bool	C_EventIsHooked;
bool	C_SkipList[MAXPLAYERS+1];

/* Game default profile */
bool	C_Profile_Colors[]	=	{
	true,
	false,
	true,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false
};

int		C_Profile_TeamIndex[]	=	{
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX,
	NO_INDEX
};

bool	C_Profile_SayText2;

static ConVar sm_show_activity;

/**
 *	Prints a message to a specific client in the chat area.
 *	Supports color tags.
 *
 *	@param	client		Users index.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 *	@noreturn
 *
 *	@error	If the user is invalid, nothing will happen.
 */
stock void C_PrintToChat(int client, const char[] message, any ...) {
	if(!Tklib_IsValidClient(client))
		return;

	char buffer[MAX_MESSAGE_LENGTH];
	char format[MAX_MESSAGE_LENGTH];

	SetGlobalTransTarget(client);

	Format(buffer, sizeof(buffer), "\x01%s", message);
	VFormat(format, sizeof(format), buffer, 3);

	int index = C_Format(format, sizeof(format));

	if(index == NO_INDEX)
		//If the reciever is the console user
		(client == 0) ? C_ReplyToCommand(client, "%s", format):PrintToChat(client, "%s", format);
	else
		C_SayText2(client, index, format);
}

/**
 *	Reples to a message in a command. A client index of 0 will use PrintToServer().
 *	If the command was from the console, PrintToConsole() is used. If the command was from chat, C_PrintToChat() is used.
 *	Supports color tags.
 *
 *	@param	client		Users index, or 0 for server.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 *	@noreturn
 *
 *	@error	If the user is invalid, nothing will happen.
 */
stock void C_ReplyToCommand(int client, const char[] message, any ...)	{
	if(client != 0 && !Tklib_IsValidClient(client))
		return;
	
	char format[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(client);
	VFormat(format, sizeof(format), message, 3);

	if(client == 0)	{
		C_RemoveTags(format, sizeof(format));
		PrintToServer("%s", szCMessage);
	}
	else if(GetCmdReplySource() == SM_REPLY_TO_CONSOLE)	{
		C_RemoveTags(format, sizeof(format));
		PrintToConsole(client, "%s", szCMessage);
	}
	else
		C_PrintToChat(client, "%s", format);
}

/**
 *	Reples to a message in a command. A client index of 0 will use PrintToServer().
 *	If the command was from the console, PrintToConsole() is used. If the command was from chat, C_PrintToChat() is used.
 *	Supports color tags.
 *
 *	@param	client		Users index, or 0 for server.
 *	@param	author		Author index whose color will be used for teamcolor tag.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 *	@noreturn
 *
 *	@error	If the users is invalid, nothing will happen.
 */
stock void C_ReplyToCommandEx(int client, int author, const char[] message, any ...) {
	char format[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(client);
	VFormat(format, sizeof(format), message, 4);

	if(client == 0)	{
		C_RemoveTags(format, sizeof(format));
		PrintToServer("%s", format);
	}
	else if(GetCmdReplySource() == SM_REPLY_TO_CONSOLE)	{
		C_RemoveTags(format, sizeof(format));
		PrintToConsole(client, "%s", format);
	}
	else
		C_PrintToChatEx(client, author, "%s", format);
}

/**
 *	Prints a message to all clients in the chat area.
 *	Supports color tags.
 *
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 *	@noreturn
 */
stock void C_PrintToChatAll(const char[] message,	any ...) {
	char format[MAX_MESSAGE_LENGTH];

	for(int i = 1; i <= MaxClients; i++)	{
		if(Tklib_IsValidClient(i, true) && !C_SkipList[i])	{
			SetGlobalTransTarget(i);
			VFormat(format, sizeof(format), message, 2);
			
			C_PrintToChat(i, "%s", format);
		}

		C_SkipList[i] = false;
	}
}

/**
 *	Prints a message to a specific client in the chat area.
 *	Supports color tags and teamcolor tag.
 *
 *	@param	client		Users index.
 *	@param	author		Author index whose color will be used for teamcolor tag.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 *	@noreturn
 * 
 *	@error	If invalid users, nothing will happen.
 */
stock void C_PrintToChatEx(int client, int author, const char[] message, any ...)	{
	if(!Tklib_IsValidClient(client))
		return;
	
	if(!Tklib_IsValidClient(author))
		return;

	char format[MAX_MESSAGE_LENGTH], formatmsg[MAX_MESSAGE_LENGTH];

	SetGlobalTransTarget(client);

	Format(format, sizeof(format), "\x01%s", message);
	VFormat(formatmsg, sizeof(formatmsg), szBuffer, 4);

	int	index = C_Format(szCMessage, sizeof(szCMessage), author);

	if(index == NO_INDEX)
		(client == 0) ? C_ReplyToCommand(client, "%s", formatmsg):PrintToChat(client, "%s", formatmsg);
	else
		C_SayText2(client, author, formatmsg);
}

/**
 *	Prints a message to all clients in the chat area.
 *	Supports color tags and teamcolor tag.
 *
 *	@param	author		Author index whos color will be used for teamcolor tag.
 *	@param	message		Message (formatting rules).
 *	@noreturn
 *
 *	@error	If the user is invalid, nothing will happen.
 */
stock void C_PrintToChatAllEx(int author, const char[] message, any ...) {
	if(!Tklib_IsValidClient(author))
		return;

	char format[MAX_MESSAGE_LENGTH];

	for(int i = 1; i <= MaxClients; ++i) {
		if(Tklib_IsValidClient(i, true) && !C_SkipList[i])	{
			SetGlobalTransTarget(i);
			VFormat(szBuffer, sizeof(szBuffer), szMessage, 3);

			C_PrintToChatEx(i, author, "%s", szBuffer);
		}
		
		C_SkipList[i] = false;
	}
}

/**
 *	Removes colour tags from the string.
 *
 *	@param	message		The message to print.
 *	@param	maxlen		The maximum length of the message.
 *	@noreturn
 */
stock void C_RemoveTags(const char[] message, int maxlen) {
	for(int i = 0; i < MAX_COLORS; i++)	{
		ReplaceString(szMessage, maxlength, C_Tag[i], "", false);
	}
	
	ReplaceString(szMessage, maxlength, "{teamcolor}", "", false);
}

/**
 *	Checks whether a color is allowed or not
 *
 *	@param	tag		Color Tag.
 *	@return		True when color is supported, otherwise false
 */
stock bool C_ColorAllowed(C_Colors color)	{
	if(!C_EventIsHooked)	{
		C_SetupProfile();

		C_EventIsHooked = true;
	}

	return	C_Profile_Colors[color];
}

/**
 *	Replace the color with another color
 *	Handle with care!
 *
 *	@param	color		color to replace.
 *	@param	newColor	color to replace with.
 *	@noreturn
 */
stock void C_ReplaceColor(C_Colors color, C_Colors newColor)	{
	if(!C_EventIsHooked)	{
		C_SetupProfile();

		C_EventIsHooked = true;
	}

	C_Profile_Colors[color] = C_Profile_Colors[newColor];
	C_Profile_TeamIndex[color] = C_Profile_TeamIndex[newColor];

	C_TagReqSayText2[color] = C_TagReqSayText2[newColor];
	Format(C_TagCode[color], sizeof(C_TagCode[]), C_TagCode[newColor]);
}

/**
 *	This function should only be used right in front of
 *	C_PrintToChatAll or C_PrintToChatAllEx and it tells
 *	to those funcions to skip specified client when printing
 *	message to all clients. After message is printed client will
 *	no more be skipped.
 *
 *	@param	client	Users index
 *	@noreturn
 */
stock void C_SkipNextClient(int client)	{
	if(client > MaxClients)
		ThrowError("Invalid client index %d", client);

	C_SkipList[client] = true;
}

/**
 *	Replaces color tags in a string with color codes
 *
 *	@param		message		Message to print.
 *	@param		maxlen		Maximum length of the message.
 *	@return		Client		User index that can be used for SayText2 author index
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int C_Format(char[] message, int maxlen, int author = NO_INDEX)	{
	/* Hook event for auto profile setup on map start */
	if(!C_EventIsHooked)	{
		C_SetupProfile();
		HookEvent("server_spawn", C_Event_MapStart, EventHookMode_PostNoCopy);

		C_EventIsHooked = true;
	}

	int iRandomPlayer = NO_INDEX;

	// On CS:GO set invisible precolor
	if(IdentifyGame() == Game_CSGO)
		Format(message, maxlen, " %s", message);

	/* If author was specified replace {teamcolor} tag */
	if(author != NO_INDEX)	{
		if(C_Profile_SayText2)	{
			ReplaceString(message, maxlen, "{teamcolor}", "\x03", false);

			iRandomPlayer = author;
		}
		/* If saytext2 is not supported by game replace {teamcolor} with green tag  */
		else
			ReplaceString(message, maxlen, "{teamcolor}", C_TagCode[Color_Green], false);
	}
	else
		ReplaceString(message, maxlen, "{teamcolor}", "", false);

	/* For other color tags we need a loop */
	for(int i = 0; i < MAX_COLORS; i++)	{
		/* If tag not found - skip */
		if(!StrContainsEx(message, C_Tag[i], false))
			continue;

		/* If tag is not supported by game replace it with green tag */
		else if(!C_Profile_Colors[i])
			ReplaceString(message, maxlen, C_Tag[i], C_TagCode[Color_Green], false);

		/* If tag doesn't need saytext2 simply replace */
		else if(!C_TagReqSayText2[i])
			ReplaceString(message, maxlen, C_Tag[i], C_TagCode[i], false);

		/* Tag needs saytext2 */
		else	{
			/* If saytext2 is not supported by game replace tag with green tag */
			if(!C_Profile_SayText2)
				ReplaceString(message, maxlen, C_Tag[i], C_TagCode[Color_Green], false);

			/* Game supports saytext2 */
			else	{
				/* If random player for tag wasn't specified replace tag and find player */
				if(iRandomPlayer == NO_INDEX)	{
					/* Searching for valid client for tag */
					iRandomPlayer = C_FindRandomPlayerByTeam(C_Profile_TeamIndex[i]);

					/* If player not found replace tag with green color tag */
					if(iRandomPlayer == NO_PLAYER)
						ReplaceString(message, maxlen, C_Tag[i], C_TagCode[Color_Green], false);

					/* If player was found simply replace */
					else
						ReplaceString(message, maxlen, C_Tag[i], C_TagCode[i], false);

				}
				/* If found another team color tag throw error */
				else	{
					//ReplaceString(message, maxlen, C_Tag[i], "");
					ThrowError("Using two team colors in one message is not allowed");
				}
			}
		}
	}

	return Tklib_IsValidClient(iRandomPlayer) ? iRandomPlayer:-1;
}

/**
 *	Finds a random player with specified team
 *
 *	@param	color_team  Client team.
 *	@return		Client index or NO_PLAYER if no player found
 */
stock int C_FindRandomPlayerByTeam(int color_team)	{
	if(color_team == SERVER_INDEX)
		return 0;

	int[] players = new int[MaxClients];
	int count;
	
	for(int i = 1; i <= MaxClients; i++)	{
		if(Tklib_IsValidClient(i) && GetClientTeam(i) == color_team)	{
			players[count++] = i;
		}
	}

	if(count)
		return players[GetRandomInt(0, count-1)];

	return NO_PLAYER;
}

/**
 *	Sends a SayText2 usermessage to a client
 *
 *	@param	client		Users index.
 *	@param	author		Author index.
 *	@param	message		Message.
 *	@noreturn
 *
 *	@error	If the user is invalid, nothing will happen.
 */
stock void C_SayText2(int client, int author, const char[] message) {
	if(!Tklib_IsValidClient(client))
		return;
	
	if(!Tklib_IsValidClient(author))
		return;
	
	Handle hBuffer = StartMessageOne("SayText2", client, USERMSG_RELIABLE|USERMSG_BLOCKHOOKS);

	if(GetFeatureStatus(FeatureType_Native, "GetUserMessageType") == FeatureStatus_Available && GetUserMessageType() == UM_Protobuf)	{
		Protobuf pb = UserMessageToProtobuf(hBuffer);
		pb.SetInt("ent_idx", author);
		pb.SetBool("chat", true);
		pb.SetString("msg_name", szMessage);
		pb.AddString("params", "");
		pb.AddString("params", "");
		pb.AddString("params", "");
		pb.AddString("params", "");
	}
	else	{
		BfWrite bf = UserMessageToBfWrite(hBuffer);
		bf.WriteByte(author);
		bf.WriteByte(true);
		bf.WriteString(szMessage);
	}

	EndMessage();
}

/**
 *	Creates game color profile.
 *	This function must be edited if you want to add more games support.
 *	@noreturn
 */
stock void C_SetupProfile() {
	EngineVersion engine = GetEngineVersion();

	if(engine == Engine_CSS)	{
		C_Profile_Colors[Color_Lightgreen] = true;
		C_Profile_Colors[Color_Red] = true;
		C_Profile_Colors[Color_Blue] = true;
		C_Profile_Colors[Color_Olive] = true;
		C_Profile_TeamIndex[Color_Lightgreen] = SERVER_INDEX;
		C_Profile_TeamIndex[Color_Red] = 2;
		C_Profile_TeamIndex[Color_Blue] = 3;
		C_Profile_SayText2 = true;
	}
	else if(engine == Engine_CSGO)	{
		C_Profile_Colors[Color_Red] = true;
		C_Profile_Colors[Color_Blue] = true;
		C_Profile_Colors[Color_Olive] = true;
		C_Profile_Colors[Color_Darkred] = true;
		C_Profile_Colors[Color_Lime] = true;
		C_Profile_Colors[Color_Lightred] = true;
		C_Profile_Colors[Color_Purple] = true;
		C_Profile_Colors[Color_Grey] = true;
		C_Profile_Colors[Color_Yellow] = true;
		C_Profile_Colors[Color_Orange] = true;
		C_Profile_Colors[Color_Bluegrey] = true;
		C_Profile_Colors[Color_Lightblue] = true;
		C_Profile_Colors[Color_Darkblue] = true;
		C_Profile_Colors[Color_Grey2] = true;
		C_Profile_Colors[Color_Orchid] = true;
		C_Profile_Colors[Color_Lightred2] = true;
		C_Profile_TeamIndex[Color_Red] = 2;
		C_Profile_TeamIndex[Color_Blue] = 3;
		C_Profile_SayText2 = true;
	}
	else if(engine == Engine_TF2)	{
		C_Profile_Colors[Color_Lightgreen] = true;
		C_Profile_Colors[Color_Red] = true;
		C_Profile_Colors[Color_Blue] = true;
		C_Profile_Colors[Color_Olive] = true;
		C_Profile_TeamIndex[Color_Lightgreen] = SERVER_INDEX;
		C_Profile_TeamIndex[Color_Red] = 2;
		C_Profile_TeamIndex[Color_Blue] = 3;
		C_Profile_SayText2 = true;
	}
	else if(engine == Engine_Left4Dead || engine == Engine_Left4Dead2)	{
		C_Profile_Colors[Color_Lightgreen] = true;
		C_Profile_Colors[Color_Red] = true;
		C_Profile_Colors[Color_Blue] = true;
		C_Profile_Colors[Color_Olive] = true;
		C_Profile_TeamIndex[Color_Lightgreen] = SERVER_INDEX;
		C_Profile_TeamIndex[Color_Red] = 3;
		C_Profile_TeamIndex[Color_Blue] = 2;
		C_Profile_SayText2 = true;
	}
	else if(engine == Engine_HL2DM)	{
		/* hl2mp profile is based on mp_teamplay convar */
		if(FindConVar("mp_teamplay").BoolValue)	{
			C_Profile_Colors[Color_Red] = true;
			C_Profile_Colors[Color_Blue] = true;
			C_Profile_Colors[Color_Olive] = true;
			C_Profile_TeamIndex[Color_Red] = 3;
			C_Profile_TeamIndex[Color_Blue] = 2;
			C_Profile_SayText2 = true;
		}
		else	{
			C_Profile_SayText2 = false;
			C_Profile_Colors[Color_Olive] = true;
		}
	}
	else if(engine == Engine_DODS)	{
		C_Profile_Colors[Color_Olive] = true;
		C_Profile_SayText2 = false;
	}
	/* Profile for other games */
	else	{
		if(GetUserMessageId("SayText2") == INVALID_MESSAGE_ID)
			C_Profile_SayText2 = false;
		else	{
			C_Profile_Colors[Color_Red] = true;
			C_Profile_Colors[Color_Blue] = true;
			C_Profile_TeamIndex[Color_Red] = 2;
			C_Profile_TeamIndex[Color_Blue] = 3;
			C_Profile_SayText2 = true;
		}
	}
}

public void C_Event_MapStart(Event event, const char[] name, bool dontBroadcast)	{
	C_SetupProfile();

	for(int i = 1; i <= MaxClients; i++)	{
		C_SkipList[i] = false;
	}
}

/**
 *	Displays usage of an admin command to users depending on the 
 *	setting of the sm_show_activity cvar.  
 *
 *	This version does not display a message to the originating client 
 *	if used from chat triggers or menus.  If manual replies are used 
 *	for these cases, then this function will suffice.  Otherwise, 
 *	C_ShowActivity2() is slightly more useful.
 *	Supports color tags.
 *
 *	@param	client		Users index doing the action, or 0 for server.
 *	@param	message		Message to send (formatting rules).
 *	@param	...			Additional parameters.
 *	@noreturn
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int C_ShowActivity(int client, const char[] message, any ...)	{
	if(sm_show_activity == null)
		sm_show_activity = FindConVar("sm_show_activity");

	char tag[] = "[SM] ", format[MAX_MESSAGE_LENGTH];
	//char szCMessage[MAX_MESSAGE_LENGTH];
	int value = sm_show_activity.IntValue;
	ReplySource replyto = GetCmdReplySource();

	char name[MAX_NAME_LENGTH] = "Console", sign[MAX_NAME_LENGTH] = "ADMIN";
	bool display_in_chat = false;
	if(client != 0)	{
		if(!Tklib_IsValidClient(client))
			return -1;

		GetClientName(client, name, sizeof(name));
		AdminId id = GetUserAdmin(client);
		if(id == INVALID_ADMIN_ID || !GetAdminFlag(id, Admin_Generic, Access_Effective))
			sign = "PLAYER";

		/* Display the message to the client? */
		if(replyto == SM_REPLY_TO_CONSOLE)	{
			SetGlobalTransTarget(client);
			VFormat(format, sizeof(format), message, 3);

			C_RemoveTags(format, sizeof(format));
			PrintToConsole(client, "%s%s\n", tag, format);
			display_in_chat = true;
		}
	}
	else	{
		SetGlobalTransTarget(LANG_SERVER);
		VFormat(format, sizeof(format), message, 3);

		C_RemoveTags(format, sizeof(format));
		PrintToServer("%s%s\n", tag, format);
	}

	if(!value)
		return 1;

	for(int i = 1; i < MaxClients; i++)	{
		if(!Tklib_IsValidClient(i, true) || (display_in_chat && i == client))
			continue;

		AdminId id = GetUserAdmin(i);
		SetGlobalTransTarget(i);
		if(id == INVALID_ADMIN_ID || !GetAdminFlag(id, Admin_Generic, Access_Effective)) {
			/* Treat this as a normal user. */
			if((value & 1) | (value & 2))	{
				char newsign[MAX_NAME_LENGTH];
				
				newsign = ((value & 2) || (i == client)) ? name:sign;
				VFormat(format, sizeof(format), message, 3);
				C_PrintToChatEx(i, client, "%s%s: %s", tag, newsign, format);
			}
		}
		else	{
			/* Treat this as an admin user */
			bool is_root = GetAdminFlag(id, Admin_Root, Access_Effective);
			if((value & 4) || (value & 8) || ((value & 16) && is_root))	{
				char newsign[MAX_NAME_LENGTH];
				
				newsign = ((value & 8) || ((value & 16) && is_root) || (i == client)) ? name:sign;
				VFormat(format, sizeof(format), message, 3);
				C_PrintToChatEx(i, client, "%s%s: %s", tag, newsign, format);
			}
		}
	}

	return	1;
}

/**
 *	Same as C_ShowActivity(), except the tag parameter is used instead of "[SM] " (note that you must supply any spacing).
 *	Supports color tags.
 *
 *	@param	client		Users index doing the action, or 0 for server.
 *	@param	tags		Tag to display with.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int C_ShowActivityEx(int client, const char[] tag, const char[] message, any ...)	{
	if(sm_show_activity == null)
		sm_show_activity = FindConVar("sm_show_activity");

	char format[MAX_MESSAGE_LENGTH];
	//char szCMessage[MAX_MESSAGE_LENGTH];
	int value = sm_show_activity.IntValue;
	ReplySource replyto = GetCmdReplySource();

	char name[MAX_NAME_LENGTH] = "Console", sign[MAX_NAME_LENGTH] = "ADMIN";
	bool display_in_chat = false;
	if(client != 0)	{
		if(!Tklib_IsValidClient(client))
			return -1;

		GetClientName(client, name, sizeof(name));
		AdminId id = GetUserAdmin(client);
		if(id == INVALID_ADMIN_ID || !GetAdminFlag(id, Admin_Generic, Access_Effective))
			sign = "PLAYER";

		/* Display the message to the client? */
		if(replyto == SM_REPLY_TO_CONSOLE)	{
			SetGlobalTransTarget(client);
			VFormat(format, sizeof(format), message, 4);

			C_RemoveTags(format, sizeof(format));
			PrintToConsole(client, "%s%s\n", tag, format);
			display_in_chat = true;
		}
	}
	else	{
		SetGlobalTransTarget(LANG_SERVER);
		VFormat(format, sizeof(format), message, 4);

		C_RemoveTags(format, sizeof(format));
		PrintToServer("%s%s\n", tag, format);
	}

	if(!value)
		return 1;

	for(int i = 1; i <= MaxClients; i++)	{
		if(!Tklib_IsValidClient(i, true) || (display_in_chat && i == client))
			continue;

		AdminId id = GetUserAdmin(i);
		SetGlobalTransTarget(i);
		if(id == INVALID_ADMIN_ID || !GetAdminFlag(id, Admin_Generic, Access_Effective))	{
			/* Treat this as a normal user. */
			if((value & 1) | (value & 2)) {
				char newsign[MAX_NAME_LENGTH];

				newsign = ((value & 2) || (i == client)) ? name:sign;
				VFormat(format, sizeof(format), message, 4);
				C_PrintToChatEx(i, client, "%s%s: %s", tag, newsign, format);
			}
		}
		else	{
			/* Treat this as an admin user */
			bool is_root = GetAdminFlag(id, Admin_Root, Access_Effective);
			if((value & 4) || (value & 8) || ((value & 16) && is_root))	{
				char newsign[MAX_NAME_LENGTH];

				newsign = ((value & 8) || ((value & 16) && is_root) || (i == client)) ? name_sign;;
				VFormat(format, sizeof(format), message, 4);
				C_PrintToChatEx(i, client, "%s%s: %s", tag, newsign, format);
			}
		}
	}

	return	1;
}

/**
 *	Displays usage of an admin command to users depending on the setting of the sm_show_activity cvar.
 *	All users receive a message in their chat text, except for the originating client, 
 *	who receives the message based on the current ReplySource.
 *	Supports color tags.
 *
 *	@param	client		Users index doing the action, or 0 for server.
 *	@param	tags		Tag to prepend to the message.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int C_ShowActivity2(int client, const char[] tag, const char[] message, any ...)	{
	if(sm_show_activity == null)
		sm_show_activity = FindConVar("sm_show_activity");

	char format[MAX_MESSAGE_LENGTH];
	//char	szCMessage[MAX_MESSAGE_LENGTH];
	int	 value = sm_show_activity.IntValue;
	// ReplySource replyto = GetCmdReplySource();

	char name[MAX_NAME_LENGTH] = "Console",	sign[MAX_NAME_LENGTH] = "ADMIN";
	
	if(client != 0)	{
		if(!Tklib_IsValidClient(client))
			return -1;

		GetClientNameEx(client, name, sizeof(name));
		AdminId id = GetUserAdmin(client);
		if(id == INVALID_ADMIN_ID || !GetAdminFlag(id, Admin_Generic, Access_Effective))
			sign = "PLAYER";

		SetGlobalTransTarget(client);
		VFormat(format, sizeof(format), message, 4);

		/* We don't display directly to the console because the chat text 
		 * simply gets added to the console, so we don't want it to print 
		 * twice.
		 */
		C_PrintToChatEx(client, client, "%s%s", tag, format);
	}
	else	{
		SetGlobalTransTarget(LANG_SERVER);
		VFormat(format, sizeof(format), message, 4);

		C_RemoveTags(format, sizeof(format));
		PrintToServer("%s%s\n", tag, format);
	}

	if(!value)
		return 1;

	for(int i = 1; i <= MaxClients; i++)	{
		if(!Tklib_IsValidClient(i, true) || i == client)
			continue;

		AdminId id = GetUserAdmin(i);
		SetGlobalTransTarget(i);
		if(id == INVALID_ADMIN_ID || !GetAdminFlag(id, Admin_Generic, Access_Effective))	{
			/* Treat this as a normal user. */
			if((value & 1) | (value & 2))	{
				char newsign[MAX_NAME_LENGTH];

				if ((value & 2))
					newsign = name;
				else
					newsign = sign;

				VFormat(format, sizeof(format), format, 4);

				C_PrintToChatEx(i, client, "%s%s: %s", tag, newsign, format);
			}
		}
		else	{
			/* Treat this as an admin user */
			bool is_root = GetAdminFlag(id, Admin_Root, Access_Effective);
			if((value & 4) || (value & 8) || ((value & 16) && is_root)) {
				char newsign[MAX_NAME_LENGTH];

				newsign = ((value & 8) || ((value & 16) && is_root)) ? name:sign;
				VFormat(szBuffer, sizeof(szBuffer), message, 4);
				C_PrintToChatEx(i, client, "%s%s: %s", tag, newsign, szBuffer);
			}
		}
	}

	return 1;
}
