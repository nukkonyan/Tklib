//==========================================//
// Tklib / Multi-Colors. (Will be standalone later)
//==========================================//

#include	<tklib/multicolors/morecolors>
#include	<tklib/multicolors/colors>

/*
 *
 *	Credits:
 *		-	Popoklopsi
 *		-	Powerlord
 *		-	exvel
 *		-	Dr. McKay
 *		-	Tk /id/Teamkiller324
 *
 *	Based on stamm-colors
 *		-	https://github.com/popoklopsi/Stamm/blob/master/include/stamm/stamm-colors.inc
 *
 */

#define	PREFIX_MAX_LENGTH	64
#define	PREFIX_SEPARATOR	"{default} "

/* Global var to check whether colors are fixed or not */
static	bool	g_bCFixColors;
static	char	g_sCPrefix[PREFIX_MAX_LENGTH];

/**
 *	Add a chat prefix before all chat msg
 *
 *	@param	prefix		Prefix
 *	@param	...			Additional parameters.
 */
stock void CSetPrefix(const char[] prefix, any ...)	{
	if(!sPrefix[0])
		return;

	SetGlobalTransTarget(LANG_SERVER);
	VFormat(g_sCPrefix, sizeof(g_sCPrefix) - strlen(PREFIX_SEPARATOR), sPrefix, 2);

	// Add ending space
	Format(g_sCPrefix, sizeof(g_sCPrefix), "%s%s", g_sCPrefix, PREFIX_SEPARATOR);
}

/**
 *	Clears the prefix from the chat message.
 */
stock void CClearPrefix()	{
	g_sCPrefix[0] = '\0';
}

/**
 *	Writes a message to the user with the correct stock for the game.
 *
 *	@param	client		Users index.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool CPrintToChat(int client, const char[] message, any ...)	{
	if(!Tklib_IsValidClient(client, true))
		return	false;
	
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(client);
	VFormat(buffer, sizeof(buffer), message, 3);

	if(!g_bCFixColors)
		CFixColors();

	IsSource2009() ? MC_PrintToChat(client, "%s%s", g_sCPrefix, buffer):C_PrintToChat(client, "%s%s", g_sCPrefix, buffer);
	return	true;
}

/**
 *	Writes a message to the users with the correct stock for the game.
 *
 *	@param	client1		First Users index.
 *	@param	client2		Second Users index.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters
 *
 *	@error	If the users is invalid, this returns false.
 */
stock bool CPrintToChat2(int client1, int client2, const char[] message, any ...)	{
	char buffer[MAX_MESSAGE_LENGTH];
	VFormat(buffer, sizeof(buffer), message, 4);
	
	CPrintToChat(client1, buffer);
	CPrintToChat(client2, buffer);
}

/**
 *	Prints a message to all users in the chat area.
 *	Supports color tags.
 *
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 */
stock void CPrintToChatAll(const char[] message, any ...) {
	if(!g_bCFixColors)
		CFixColors();

	char buffer[MAX_BUFFER_LENGTH];
	switch(!IsSource2009())	{
		case	true:	{
			for(int i = 1; i <= MaxClients; ++i)	{
				if(Tklib_IsValidClient(i, true) && !C_SkipList[i])	{
					SetGlobalTransTarget(i);
					VFormat(buffer, sizeof(buffer), message, 2);
	
					C_PrintToChat(i, "%s", buffer);
				}
	
				C_SkipList[i] = false;
			}
		}
		case	false:	{
			MC_CheckTrie();
	
			char buffer2[MAX_BUFFER_LENGTH];
	
			for(int i = 1; i <= MaxClients; ++i)	{
				if(!IsClientInGame(i) || MC_SkipList[i])	{
					MC_SkipList[i] = false;
					continue;
				}
	
				SetGlobalTransTarget(i);
				Format(buffer, sizeof(buffer), "\x01%s", message);
				VFormat(buffer2, sizeof(buffer2), buffer, 2);
	
				MC_ReplaceColorCodes(buffer2);
				MC_SendMessage(i, buffer2);
			}
		}
	}
}

/**
 *	Writes a message to all of a users observers.
 *
 *	@param	target		Users index.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 */
stock void CPrintToChatObservers(int target, const char[] message, any ...) {
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(LANG_SERVER);
	VFormat(buffer, sizeof(buffer), message, 3);

	if(!g_bCFixColors)
		CFixColors();

 	for(int client = 1; client <= MaxClients; client++) {
 		if(Tklib_IsValidClient(client, true, true))	{
 			int observee = GetClientObserverTarget(client);
 			int ObserverMode = GetClientObserverMode(client);
 
 			if(observee == target && (ObserverMode == 4 || ObserverMode == 5))
 				CPrintToChat(client, buffer);
 		}
 	}
}

/**
 *	Writes a message to a client with the correct stock for the game.
 *
 *	@param	client		Users index.
 *	@param	author		Author index.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 *
 *	@error	If the client is not connected an error will be thrown.
 */
stock void CPrintToChatEx(int client, int author, const char[] message, any ...)	{
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(client);
	VFormat(buffer, sizeof(buffer), message, 4);

	if(!g_bCFixColors)
		CFixColors();

	IsSource2009() ? MC_PrintToChatEx(client, author, "%s%s", g_sCPrefix, buffer):C_PrintToChatEx(client, author, "%s%s", g_sCPrefix, buffer);
}

/**
 *	Writes a message to all clients with the correct stock for the game.
 *
 *	@param	author		Author index.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 */
stock void CPrintToChatAllEx(int author, const char[] message, any ...)	{
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(LANG_SERVER);
	VFormat(buffer, sizeof(buffer), message, 3);

	if(!g_bCFixColors)
		CFixColors();

	IsSource2009() ? MC_PrintToChatAllEx(author, "%s%s", g_sCPrefix, buffer):C_PrintToChatAllEx(author, "%s%s", g_sCPrefix, buffer);
}

/**
 *	Writes a message to all of a client's observers with the correct
 *	game stock.
 *
 *	@param	target		Users index.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 */
stock void CPrintToChatObserversEx(int target, const char[] message, any ...)	{
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(LANG_SERVER);
	VFormat(buffer, sizeof(buffer), message, 3);

	if(!g_bCFixColors)
		CFixColors();

 	for(int client = 1; client <= MaxClients; client++) {
 		if(Tklib_IsValidClient(client, true, true))	{
 			int observee = GetClientObserverTarget(client);
 			int ObserverMode = GetClientObserverMode(client);
 
 			if(observee == target && (ObserverMode == 4 || ObserverMode == 5))
 				CPrintToChatEx(client, target, buffer);
 		}
 	}
}

/**
 *	Replies to a command with colors
 * 
 *	@param	client		Users index to reply to.
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 */
stock void CReplyToCommand(int client, const char[] message, any ...) {
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(client);
	VFormat(buffer, sizeof(buffer), message, 3);

	if(!g_bCFixColors)
		CFixColors();

	IsSource2009() ? MC_ReplyToCommand(client, "%s%s", g_sCPrefix, buffer):C_ReplyToCommand(client, "%s%s", g_sCPrefix, buffer)
}

/**
 *	Replies to a command with colors
 *
 *	@param	client		Users index to reply to
 *	@param	author		Users index to use for {teamcolor}
 *	@param	message		Message (formatting rules)
 *	@param	...			Additional parameters.
 */
stock void CReplyToCommandEx(int client, int author, const char[] message, any ...)	{
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(client);
	VFormat(buffer, sizeof(buffer), message, 4);

	if(!g_bCFixColors)
		CFixColors();

	IsSource2009()) ? MC_ReplyToCommandEx(client, author, "%s%s", g_sCPrefix, buffer):C_ReplyToCommandEx(client, author, "%s%s", g_sCPrefix, buffer);
}

/**
 *	Remove all tags and print to server
 *
 *	@param	message		Message (formatting rules).
 *	@param	...			Additional parameters.
 */
stock void CPrintToServer(const char[] message, any ...)	{
	char buffer[MAX_MESSAGE_LENGTH];
	char prefixBuffer[PREFIX_MAX_LENGTH];
	SetGlobalTransTarget(LANG_SERVER);
	VFormat(buffer, sizeof(buffer), message, 2);
	strcopy(prefixBuffer, sizeof(prefixBuffer), g_sCPrefix);

	if(!g_bCFixColors)
		CFixColors();

	CRemoveTags(buffer, sizeof(buffer));
	CRemoveTags(prefixBuffer, sizeof(prefixBuffer));

	PrintToServer("%s%s", prefixBuffer, buffer);
}

/**
 *	Displays usage of an admin command to users depending on the 
 *	setting of the sm_show_activity cvar.  
 *
 *	This version does not display a message to the originating client 
 *	if used from chat triggers or menus.  If manual replies are used 
 *	for these cases, then this function will suffice.  Otherwise, 
 *	CShowActivity2() is slightly more useful.
 *	Supports color tags.
 *
 *	@param	client		Users index index doing the action, or 0 for server.
 *	@param	format		Formatting rules.
 *	@param	...			Additional parameters.
 */
stock void CShowActivity(int author, const char[] message, any ...)	{
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(LANG_SERVER);
	VFormat(buffer, sizeof(buffer), message, 3);

	if(!g_bCFixColors)
		CFixColors();

	IsSource2009() ? MC_ShowActivity(author, "%s", buffer):C_ShowActivity(author, "%s", buffer);
}

/**
 *	Same as C_ShowActivity(), except the tag parameter is used instead of "[SM] " (note that you must supply any spacing).
 *	Supports color tags.
 *
 *	@param	client		Users index doing the action, or 0 for server.
 *	@param	tags		Tag to display with.
 *	@param	format		Formatting rules.
 *	@param	...			Additional parameters.
 */
stock void CShowActivityEx(int author, const char[] tag, const char[] message, any ...) {
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(LANG_SERVER);
	VFormat(buffer, sizeof(buffer), message, 4);

	if(!g_bCFixColors)
		CFixColors();
	
	if(!IsSource2009())
		C_ShowActivityEx(author, tag, "%s", buffer);
	else
		MC_ShowActivityEx(author, tag, "%s", buffer);
}

/**
 *	Displays usage of an admin command to users depending on the setting of the sm_show_activity cvar.
 *	All users receive a message in their chat text, except for the originating client, 
 *	who receives the message based on the current ReplySource.
 *	Supports color tags.
 *
 *	@param	client		Users index doing the action, or 0 for server.
 *	@param	tags		Tag to prepend to the message.
 *	@param	format		Formatting rules.
 *	@param	...			Additional parameters.
 */
 stock void CShowActivity2(int author, const char[] tag, const char[] message, any ...) {
	char buffer[MAX_MESSAGE_LENGTH];
	SetGlobalTransTarget(LANG_SERVER);
	VFormat(buffer, sizeof(buffer), message, 4);

	if(!g_bCFixColors)
		CFixColors();

	IsSource2009() ? MC_ShowActivity2(author, tag, "%s", buffer):C_ShowActivity2(author, tag, "%s", buffer);
}

/**
 *	Replaces color tags in a string with color codes
 *
 *	@param	message		The message to print.
 *	@param	maxlength	Maximum length of the string buffer.
 */
stock void CFormatColor(const char[] message, int maxlength, int author = -1) {
	if(!g_bCFixColors)
		CFixColors();
	
	switch(!IsSource2009())	{
		case	true:	{
			if(author == 0)
				author = -1;
			
			C_Format(message, maxlength, author);
		}
		case	false:	{
			if(author == -1)
				author = 0;
	
			MC_ReplaceColorCodes(message, author, false, maxlength);
		}
	}
}

/**
 *	Removes color tags from a message
 *
 *	@param	message		Message to remove tags from
 *	@param	maxlen		Maximum buffer length
 */
stock void CRemoveTags(const char[] message, int maxlen) {
	IsSource2009() ? MC_RemoveTags(message, maxlen):C_RemoveTags(message, maxlen);		
}

/**
 *	Fixes missing Lightgreen color.
 */
stock void CFixColors() {
	g_bCFixColors = true;

	// Replace lightgreen if not exists
	if(!C_ColorAllowed(Color_Lightgreen))	{
		if(C_ColorAllowed(Color_Lime))
			C_ReplaceColor(Color_Lightgreen, Color_Lime);
		else if(C_ColorAllowed(Color_Olive))
			C_ReplaceColor(Color_Lightgreen, Color_Olive);
	}
}

stock bool IsSource2009()	{
	return	(IdentifyGame() == Game_CSS
	||	IdentifyGame() == Game_HL2DM
	||	IdentifyGame() == Game_DODS
	||	IdentifyGame() == Game_TF2
	||	IdentifyGame() == Game_TF2C
	||	IdentifyGame() == Game_SDK2013);
}