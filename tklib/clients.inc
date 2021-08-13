//Player permissions
/**
 *	Returns if the client is a Console
 *
 *	@param client	The users index.
 */
stock bool IsClientConsole(int client)	{	
	return (client == 0)
}

/**
 *	Returns if the client is an Owner
 *
 *	@param	client		The users index.
 *	@error	If client is not valid, it will return false.
 */
stock bool IsClientOwner(int client)	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, "", ADMFLAG_ROOT, false):false
}

/**
 *	Returns if the client is an Admin
 *
 *	@param	client		The users index.
 *	@error	If client is not valid, it will return false.
 */
stock bool IsClientAdmin(int client)	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, "", ADMFLAG_GENERIC, false):false
}

/**
 *	Returns if the client is a Moderator
 *
 *	@param	client		The users index.
 *	@error	If client is not valid, it will return false.
 */
stock bool IsClientModerator(int client)	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, "", ADMFLAG_CUSTOM1, false):false
}

/**
 *	Returns if the client is a Vip
 *
 *	@param	client		The users index.
 *	@error	If client is not valid, it will return false.
 */
stock bool IsClientVip(int client)	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, "", ADMFLAG_RESERVATION, false):false
}

/**
 *	Returns if the client is has the specified flag
 *
 *	@param	client		The users index.
 *	@param	adminflags	Administrative flags (bitstring) to use for permissions.
 *	@param	flagaccess	The flag access command. Disabled if empty.
 */
stock bool IsClientFlag(int client, int adminflags, char[] flagaccess="")	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, flagaccess, adminflags, false):false
}

//General stuff

//Cookies
/**
 *	Simplified version of SetClientCookie
 *	Turns the specified integer into a string
 *
 *	@param	client		The users index.
 *	@param	cookie		Cookie handle.
 *	@param	value			The integer value
 *	@error	If the client or cookie handle is invalid, nothing will happen.
 */
stock void SetClientCookieInt(int client, ConVar cookie, int value)	{
	if(Tklib_IsValidClient(client, true) || cookie != null)	{
		char item[1024];
		IntToString(value, item, sizeof(item));
		cookie.Set(client, item);
	}
}

/**
 *	Set the clients scoreboard ping
 *
 *	@param	client		The users index.
 *	@param	value		Amount value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientPing(int client, int value)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iPing", value)
}

/**
 *	Returns the clients scoreboard ping
 *
 *	@param	client		The users index.
 *	@error	If the client is not valid, it will return -1.
 */
stock int GetClientPing(int client)	{
	return Tklib_IsValidClient(client, true)) ? GetEntProp(GetPlayerResourceEntity(), Prop_Send, "m_iPing", _, client):-1;
}

/**
 *	Set the clients death count
 *
 *	@param	client		The users index.
 *	@param	value		Amount value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientDeaths(int client, int value)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iDeaths", value);
}

/**
 *	Tk Libraries: Clients.
 *	Set the clients frag count
 *
 *	@param	client		The users index.
 *	@param	value		Amount index.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientFrags(int client, int value)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iFrags", value);
}


/**
 *	Set the clients health
 *
 *	@param	client		The users index.
 *	@param	value		Amount index.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientHealth(int client, int value)	{
	if(!Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iHealth", value);
}

/**
 *	Set the users max health
 *
 *	@param	client		The users index.
 *	@param	value		Amount index.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientMaxHealth(int client, int value)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iMaxHealth", value);
}

/**
 *	Returns the users max health
 *
 *	@param	client		The users index..
 *	@error	If the client is not valid, it will return -1.
 */
stock int GetClientMaxHealth(int client)	{
	return Tklib_IsValidClient(client) ? GetEntProp(client, Prop_Data, "m_iMaxHealth"):-1;
}

/**
 *	Set the users team index number called from the game's netprop m_iTeamNum.
 *
 *	@param	client			The users index.
 *	@param	value			Team index value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientTeamNum(int client, int value)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iTeamNum", value);
}

/**
 *	Returns the users team index number called from the game's netprop m_iTeamNum.
 *
 *	@param	client		The users index.
 *	@error	If the client is not valid, it will return -1.
 */
stock int GetClientTeamNum(int client)	{
	return Tklib_IsValidClient(client) ? GetEntProp(client, Prop_Send, "m_iTeamNum"):-1;
}

/**
 *	Set the users field-of-view.
 *
 *	@param	client		The users index.
 *	@param	value		Amount value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientFOV(int client, int value)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iFOV", value);
}

/**
 *	Returns the clients field-of-view.
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return -1.
 */
stock int GetClientFOV(int client)	{
	return Tklib_IsValidClient(client, true) ? GetEntProp(client, Prop_Send, "m_iFOV"):-1;
}

/**
 *	Set the clients default field-of-view.
 *
 *	@param	client		The users index.
 *	@param	value		Amount value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientDefaultFOV(int client, int value)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iDefaultFOV", value);
}

/**
 *	Tk Libraries: Clients.
 *	Returns the clients default fov
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return -1.
 */
stock int GetClientDefaultFOV(int client)	{
	return Tklib_IsValidClient(client, true) ? GetEntProp(client, Prop_Send, "m_iDefaultFOV"):-1;
}

/**
 *	Set the users Observer target
 *
 *	@param	client 		The users index.
 *	@param	target		Target to observe.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientObserverTarget(int client, int target)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iObserverTarget", target);
}

/**
 *	Set the clients Observer mode
 *
 *	@param	client		The users index.
 *	@param	value		Bool value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientObserverMode(int client, bool value)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_iObserverMode", value);
}

/**
 *	Set the clients viewmodel to be drawn.
 *
 *	@param client		The users index.
 *	@param value		Bool value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientDrawViewModel(int client, bool value)	{
	if(Tklib_IsValidClient(client, true))
		SetEntProp(client, Prop_Send, "m_bDrawViewmodel", value);
}

/**
 *	Tk Libraries: Clients.
 *	Returns the clients drawviewmodel value
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return false.
 */
stock bool GetClientDrawViewModel(int client)	{
	return Tklib_IsValidClient(client, true) ? SetEntProp(client, Prop_Send, "m_bDrawViewmodel"):false;
}

/**
 *	Set the clients godmode
 *
 *	@param	client		The users index.
 *	@param	godmode		If true, it will enable godmode, else disabled.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientGodMode(int client, bool godmode)	{
	if(Tklib_IsValidClient(client))
		godmode ? SetEntProp(client, Prop_Send, "m_takedamage", 0, 1):SetEntProp(client, Prop_Send, "m_takedamage", 2, 1);
}

/**
 *	Returns if client is in godmode
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return false.
 */
stock bool GetClientGodmode(int client)	{
	return Tklib_IsValidClient(client, _, true) ? (GetEntProp(client, Prop_Send, "m_takedamage", 0, 1) == 1):false
}

/**
 *	Set the clients buddha mode
 *
 *	@param	client		The users index.
 *	@param	buddha		If true, it will enable buddha mode, else disabled.
 *	@error	If the client is invalid, it will return false.
 */
stock void SetClientBuddhaMode(int client, bool buddha)	{
	if(Tklib_IsValidClient(client, _, true))
		buddha ? SetEntProp(client, Prop_Send, "m_takedamage", 1, 1):SetEntProp(client, Prop_Send, "m_takedamage", 2, 1);
}

/**
 *	Returns if the client is in buddha mode.
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return false.
 */
stock bool GetClientBuddhaMode(int client)	{
	return Tklib_IsValidClient(client, _, true) ? (GetEntProp(client, Prop_Send, "m_takedamage", 1, 1) == 1):false
}

/**
 *	Set the clients collision
 *
 *	@param	client		The users index.
 *	@param	collision	If true, it will enable collision, else disabled.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void	SetClientCollision(int client, bool collision)	{
	if(Tklib_IsValidClient(client))
		collision ? SetEntData(client, FindSendPropInfo("CBaseEntity", "m_CollisionGroup"), 2, 4):SetEntData(client, FindSendPropInfo("CBaseEntity", "m_CollisionGroup"), 5, 4);
}

/**
 *	Returns if the client has collision.
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return false.
 */
stock bool GetClientCollision(int client)	{
	return Tklib_IsValidClient(client) ? (GetEntData(client, FindSendPropInfo("CBaseEntity", "m_CollisionGroup"), 2, 4) == 1):false
}

/**
 *	Set the client noclip on/off
 *
 *	@param	client		The users index.
 *	@param	noclip		If true, it will enable nocip, else disabled.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientNoclip(int client, bool noclip)	{
	if(Tklib_IsValidClient(client))
		SetEntityMoveType(client, noclip ? MOVETYPE_NOCLIP:MOVETYPE_WALK);
}

/**
 *	Set the clients max speed
 *
 *	@param	client		The users index.
 *	@param	value		Float amount value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock float SetClientMaxSpeed(int client, float value)	{
	if(Tklib_IsValidClient(client))
		SetEntPropFloat(client,	Prop_Send,	"m_flMaxspeed",	value);
}

/**
 *	Returns the clients max speed
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return 0.0.
 */
stock float GetClientMaxSpeed(int client)	{
	return Tklib_IsValidClient(client) ? GetEntPropFloat(client, Prop_Send, "m_flMaxspeed"):0.0;
}

/**
 *	Returns if the client is muted.
 *
 *	@param 	client		The users index.
 *	@error	If the client is invalid, it will return false.
 */
stock bool IsClientMutedEx(int client)	{
	return Tklib_IsValidClient(client, true) ? (GetClientListeningFlags(client) == VOICE_NORMAL):false;
}

/**
 *	Set if the client should be muted or not.
 *
 *	@param	client		The users index.
 *	@param	mute		If true, it will enable nocip, else disabled.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientMute(int client, bool mute)	{
	if(Tklib_IsValidClient(client, true))
		SetClientListeningFlags(client, mute ? VOICE_MUTED:VOICE_NORMAL);
}

/**
 *	Slay the client.
 *
 *	@param	client		The users index.
 *	@param	randomdeath	Should death be random. (Should be used in games where is supported)
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SlayPlayer(int client, bool RandomDeath=false)	{
	if(Tklib_IsValidClient(client, _, true))
		FakeClientCommandEx(client, RandomDeath ? "kill":GetRandomBool() ? "kill":"death");
}

/**
 *	Returns the clients lifestate.
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return -1.
 */
stock int GetClientLifestate(int client)	{
	return Tklib_IsValidClient(client) ? GetEntProp(client, Prop_Send, "m_lifeState"):-1;
}

/**
 *	Set the clients lifestate.
 *
 *	@param	client		The users index.
 *	@param	value		Lifestate value.
 *	@error	If the client is invalid, it will return -1.
 */
stock void SetClientLifestate(int client, int value)	{
	if(Tklib_IsValidClient(client))
		SetEntProp(client, Prop_Send, "m_lifeState", value);
}

//Respawning

//Set the respawn time for the specified client

/**
 *	Set the client to respawn in specified time
 *
 *	@param	client		The users index.
 *	@param	value		Respawn time.
 *	@error	If the client is invalid, nothing will happen.
 */
stock float RespawnTime(int client, float value)	{
	if(Tklib_IsValidClient(client))
		CreateTimer(value, SetRespawnTime, client);
}

//forwards the action to the respawn event
stock Action SetRespawnTime(Handle timer, any client)	{
	Respawn(client);
}

/**
 *	Respawn a client
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void Respawn(int client)	{
	if(Tklib_IsValidClient(client))	{
		switch(IdentifyGame())	{
			case	Game_TF2:
				TF2_RespawnPlayer(client);
			case	Game_TF2C:	{
				//Fixes respawn bug issue with Team Fortress 2 Classic
				if(!IsPlayerAlive(client))
					TF2_RespawnPlayer(client);
			}
			case	Game_CSS,Game_CSPromod,Game_CSGO:
				CS_RespawnPlayer(client);
		}
	}
}

/**
 *	Returns the users steam steamid.
 *	Same as GetClientAuthId but simpler.
 *
 *	@param	client		The users index.
 *	@param	buffer		Buffer storage.
 *	@param	maxlen		Length of the buffer.
 *	@error	If the client is invalid, it will return false.
 */
stock bool GetClientAuth(int client, char[] buffer, int maxlen)	{
	return Tklib_IsValidClient(client) ? GetClientAuthId(client, AuthId_Steam2, buffer, maxlen):false;
}

/**
 *	Returns the users steam steamid.
 *	Same as GetClientAuthId but simpler.
 *	This returns SteamID3 instead of SteamID2.
 *
 *	@param	client		The users index.
 *	@param	buffer		Buffer storage.
 *	@param	maxlen		Length of the buffer.
 *	@error	If the client is invalid, it will return false.
 */
stock bool GetClientAuth3(int client, char[] buffer, int maxlen)	{
	return Tklib_IsValidClient(client) ? GetClientAuthId(client, AuthId_Steam3, buffer, maxlen):false;
}

/**
 *	Returns the user by steam authentication.
 *
 *	@param auth.		Steam Auth.
 *	@return				The users index. If invalid client, returns 0.
 */
stock int GetClientOfAuth(char[] auth)	{
	int client = 0;
	for(int i = 1; i < MaxClients; i++)	{
		if(!Tklib_IsValidClient(i, true);
			continue;
		
		char tempauth[64];
		GetClientAuth(i, tempauth, sizeof(tempauth));
		if(StrContainsEx(tempauth, auth, false))
			client = i;
	}
	return	client;
}

/**
 *	Get the client by steam authentication.
 *
 *	@param auth.		Steam3 Auth.
 *	@return				The users index. If invalid client, returns 0.
 */
stock int GetClientOfAuth3(char[] auth)	{
	int client = 0;
	for(int i = 1; i < MaxClients; i++)	{
		if(!IsClientInGame(i) || IsFakeClient(i))
			continue;
		
		char tempauth[64];
		GetClientAuthId(i, AuthId_Steam3, tempauth, sizeof(tempauth));
		if(StrContainsEx(tempauth, auth, false))
			client = i;
	}
	return	client;
}

/**
 *	Returns the users name properly.
 *
 *	@param	client		The users index.
 *	@param	buffer		Buffer to store the string.
 *	@param	maxlen		Max length of the string buffer.
 *	@error	If the user is invalid, this will return false.
 */
stock bool GetClientNameEx(int client, char[] buffer, int maxlen)	{
	return Tklib_IsValidClient(client, _, _, false, false) ? GetClientInfo(client, "name", buffer, maxlen):false;
}

/**
 *	Set the users name properly.
 *
 *	@param	client		The users index.
 *	@param	buffer		Buffer to store the string.
 *	@error	If the user is invalid, nothing will happen.
 */
stock void SetClientNameEx(int client, char[] name)	{
	if(Tklib_IsValidClient(client, false, false, false, false))
		SetClientName(client, "name", name);
}

/**
 *	Returns the users index if found from string.
 *
 *	@param		player_name		The players name to search.
 *	@param		filter_flags	Filter flags.
 *	@error		If the index of the player was not found or is invalid, it will return -1.
 */
stock int GetClientOfPlayername(char[] playername, int filter_flags=COMMAND_FILTER_CONNECTED|COMMAND_FILTER_NO_BOTS)	{
	char target_name[64];
	int target_list[64];
	bool tn_is_ml;
	
	int target_count = ProcessTargetString(playername, 0, target_list, MAXPLAYERS, filter_flags, target_name, sizeof(target_name), tn_is_ml);
	
	for(int i = 0; i < target_count; i++)	{
		return target_list[i];
	}
	
	return -1;
}

/**
 *	Returns user count in the server.
 *
 *	@param	nobots	If true, bots are ignored.
 *	@return	Returns the user count.
 */
stock int GetClientCountEx(bool nobots=true)	{
	int count = 0;
	for(int i = 1; i < MaxClients; i++)	{
		switch(nobots)	{
			case	true:	{
				if(Tklib_IsValidClient(i, true, false, false))
					count++;
			}
			case	false:	{
				if(Tklib_IsValidClient(i, false, false, false))
					count++
			}
		}
	}
	return	count;
}

/**
 *	Returns true or false depending if the client is valid.
 *
 *	@param	client				The users index.
 *	@param	IgnoreBot			If true, the bots are counted as 'invalid'.					Defaulted to false.
 *	@param	IgnoreDead			If true, the dead are counted as 'invalid'.					Defaulted to false.
 *	@param	IgnoreNonInGame		If true, the non-ingame users are counted as 'invalid'		Defaulted to true.
 *	@param	IgnoreNonConnected	If true, the non-connected users are counted as 'invalid'	Defaulted to true.
 */
stock bool Tklib_IsValidClient(int client, bool IgnoreBot=false, bool IgnoreDead=false, bool IgnoreNonInGame=true, bool IgnoreNonConnected=true)	{
	if(client == 0 || client == -1)	//This is to make sure console (index 0) & non-existing client (index -1) is not giving outright errors.
		return	false;
	if(client < 1 || client > MaxClients)
		return	false;
	if(!IsClientInGame(client) && IgnoreNonInGame)
		return	false;
	if(!IsClientConnected(client) && IgnoreNonConnected)
		return	false;
	if(IsClientSourceTV(client))
		return	false;
	if(IsClientReplay(client))
		return	false;
	if(IsFakeClient(client) && IgnoreBot)
		return	false;
	if(IgnoreDead)	{	//Corrects a bug complaining invalid client index when it actually shouldn't be able to read this line when the boolean was set to off.
		if(!IsPlayerAlive(client))
			return	false;
	}
	return	true;
}