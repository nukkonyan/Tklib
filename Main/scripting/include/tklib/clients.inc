//==========================================//
// Tklib / Clients.
//==========================================//
#if !defined _tklib_disable_clients

//Player permissions
/**
 *	Returns if the user is a Console
 *
 *	@param client	The users index.
 */
stock bool IsClientConsole(int client)	{	
	return view_as<bool>(client == 0);
}

/**
 *	Returns if the user is the Owner
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientOwner(int client)	{
	return CheckCommandAccess(client, "", ADMFLAG_ROOT);
}

/**
 *	Returns if the user is an Admin
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientAdmin(int client)	{
	return CheckCommandAccess(client, "", ADMFLAG_GENERIC);
}

/**
 *	Returns if the user is a Moderator
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientModerator(int client)	{
	return CheckCommandAccess(client, "", ADMFLAG_CUSTOM1);
}

/**
 *	Returns if the user is a Vip
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientVip(int client)	{
	return CheckCommandAccess(client, "", ADMFLAG_RESERVATION);
}

/**
 *	Returns if the user has the specified flag access.
 *
 *	@param	client		The users index.
 *	@param	adminflags	Administrative flags (bitstring) to use for permissions.
 *	@param	command		The flag access command. Disabled if empty.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientFlag(int client, int adminflags, char[] command="")	{
	return CheckCommandAccess(client, command, adminflags);
}

/**
 *	Returns if the users is the same player.
 *
 *	@param	client	The users index.
 *	@param	target	The targets index.
 *
 *	@return	Returns true if it's the same player, false otherwise.
 */
stock bool IsSamePlayers(int client, any target)	{
	return view_as<bool>(client == target);
}

/**
 *	Returns if the user and target is on the same team.
 *
 *	@param	client	The users index.
 *	@param	target	The targets index.
 *
 *	@return	Returns true if it's they're on the same team, false otherwise.
 */
stock bool IsSameTeam(int client, any target)	{
	return view_as<bool>(GetClientTeam(client) == GetClientTeam(target));
}

//General stuff

/**
 *	Set the users scoreboard ping
 *
 *	@param	client	The users index.
 *	@param	value	Amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientPing(int client, int value)	{
	return SetEntPropEx(client, Prop_Send, "m_iPing", value);
}

/**
 *	Returns the users scoreboard ping
 *
 *	@param	client	The users index.
 *
 *	@error	If the client is not valid, this returns -1.
 */
stock int GetClientPing(int client)	{
	return GetEntPropEx(GetPlayerResourceEntity(), Prop_Send, "m_iPing", _, client);
}

/**
 *	Set the users death count
 *
 *	@param	client	The users index.
 *	@param	value	Amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientDeaths(int client, int value)	{
	return SetEntPropEx(client, Prop_Data, "m_iDeaths", value);
}

/**
 *	Set the users frag count
 *
 *	@param	client	The users index.
 *	@param	value	Amount index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientFrags(int client, int value)	{
	return SetEntPropEx(client, Prop_Data, "m_iFrags", value);
}


/**
 *	Set the users health
 *
 *	@param	client	The users index.
 *	@param	value	Amount index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientHealth(int client, int value)	{
	return SetEntPropEx(client, Prop_Send, "m_iHealth", value);
}

/**
 *	Set the users max health
 *
 *	@param	client	The users index.
 *	@param	value	Amount index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientMaxHealth(int client, int value)	{
	return SetEntPropEx(client, Prop_Send, "m_iMaxHealth", value);
}

/**
 *	Returns the users max health
 *
 *	@param	client	The users index.
 *
 *	@error	If the client is not valid, this returns -1.
 */
stock int GetClientMaxHealth(int client)	{
	return GetEntPropEx(GetPlayerResourceEntity(), Prop_Send, "m_iMaxHealth", client);
}

/**
 *	Sets the users health & maximum health.
 *
 *	@param	client		The users index.
 *	@param	health		Health
 *	@param	maxhealth	Maximum health.
 *
 *	@noreturn
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientHealthEx(int client, int health, int maxhealth)	{
	if(!Tklib_IsValidClient(client, _, true))
		return false;
	
	SetClientMaxHealth(client, newmaxhealth);
	SetClientHealth(client, health);
	return true;
}

/**
 *	Set the users team index number called from the game's netprop m_iTeamNum.
 *
 *	@param	client	The users index.
 *	@param	value	Team index value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientTeamNum(int client, any value)	{
	return SetEntPropEx(client, Prop_Send, "m_iTeamNum", value);
}

/**
 *	Returns the users team index number called from the game's netprop m_iTeamNum.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is not valid or mod not supported, this returns -1.
 */
stock int GetClientTeamNum(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_iTeamNum");
}

/**
 *	Set the users field-of-view.
 *
 *	@param	client	The users index.
 *	@param	value	Amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientFOV(int client, int value)	{
	return SetEntPropEx(client, Prop_Send, "m_iFOV", value);
}

/**
 *	Returns the clients field-of-view.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientFOV(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_iFOV");
}

/**
 *	Set the users default field-of-view.
 *
 *	@param	client	The users index.
 *	@param	value	Amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientDefaultFOV(int client, int value)	{
	return SetEntPropEx(client, Prop_Send, "m_iDefaultFOV", value);
}

/**
 *	Returns the users default fov.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientDefaultFOV(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_iDefaultFOV");
}

/**
 *	Set the users Observer target.
 *
 *	@param	client 		The users index.
 *	@param	target		Target to observe.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientObserverTarget(int client, int target)	{
	return SetEntPropEntEx(client, Prop_Send, "m_iObserverTarget", target);
}

/**
 *	Returns the users Observer target.
 *
 *	@param	client 		The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientObserverTarget(int client)	{
	return GetEntPropEntEx(client, Prop_Send, "m_iObserverTarget");
}

/**
 *	Set the users Observer mode.
 *
 *	@param	client		The users index.
 *	@param	value		Observer mode value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientObserverMode(int client, int value)	{
	return SetEntPropEx(client, Prop_Send, "m_iObserverMode", value);
}

/**
 *	Returns the users Observer mode.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientObserverMode(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_iObserverMode");
}

/**
 *	Set the users last observer mode.
 *
 *	@param	client	The users index.
 *	@param	value	The mode value to set.
 *
 *	@error	If the user is invalid or procedure failed, this returns false.
 */
stock bool SetClientLastObserverMode(int client, int value)	{
	return SetEntPropEx(client, Prop_Send, "m_iObserverLastMode", value);
}

/**
 *	Returns the users last observer mode.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientLastObserverMode(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_iObserverLastMode");
}

/**
 *	Set the clients viewmodel to be drawn.
 *
 *	@param client	The users index.
 *	@param value	Turn on/off.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientDrawViewModel(int client, bool value)	{
	return SetEntPropEx(client, Prop_Send, "m_bDrawViewmodel", value);
}

/**
 *	Returns the clients drawviewmodel value
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientDrawViewModel(int client)	{
	return GetEntPropBool(client, Prop_Send, "m_bDrawViewmodel");
}

/**
 *	Set the clients godmode
 *
 *	@param	client		The users index.
 *	@param	godmode		If true, it will enable godmode, else disabled.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientGodMode(int client, bool godmode)	{
	return SetEntPropEx(client, Prop_Send, "m_takedamage", godmode ? 0:2, 1);
}

/**
 *	Returns if client is in godmode
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientGodmode(int client)	{
	return GetEntPropBool(client, Prop_Send, "m_takedamage", 0, 1)
}

/**
 *	Set the user buddha mode
 *
 *	@param	client		The users index.
 *	@param	buddha		If true, it will enable buddha mode, else disabled.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientBuddhaMode(int client, bool buddha)	{
	return SetEntPropEx(client, Prop_Send, "m_takedamage", buddha ? 1:2, 1);
}

/**
 *	Returns if the user is in buddha mode.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientBuddhaMode(int client)	{
	return GetEntPropBool(client, Prop_Send, "m_takedamage", 1, 1);
}

/**
 *	Set the users collision
 *
 *	@param	client		The users index.
 *	@param	collision	If true, it will enable collision, else disabled.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientCollision(int client, bool collision)	{
	if(!Tklib_IsValidClient(client))
		return false;
	
	SetEntData(client, FindSendPropInfo("CBaseEntity", "m_CollisionGroup"), collision ? 2 : 5, 4):
	return true;
}

/**
 *	Returns if the user has collision.
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientCollision(int client)	{
	return view_as<bool>(GetEntData(client, FindSendPropInfo("CBaseEntity", "m_CollisionGroup"), 2) == 4);
}

/**
 *	Set the user noclip on/off
 *
 *	@param	client		The users index.
 *	@param	noclip		If true, it will enable noclip, else disabled.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientNoclip(int client, bool noclip)	{
	if(!Tklib_IsValidClient(client))
		return false;
	
	SetEntityMoveType(client, noclip ? MOVETYPE_NOCLIP:MOVETYPE_WALK);
	return true;
}

/**
 *	Returns if the user is noclipping.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientNoclipping(int client)	{
	return GetEntityMoveType(client) == MOVETYPE_NOCLIP;
}
 

/**
 *	Set the users max speed
 *
 *	@param	client		The users index.
 *	@param	value		Float amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientMaxSpeed(int client, float value)	{
	return SetEntPropFloatEx(client, Prop_Send, "m_flMaxspeed", value);
}

/**
 *	Returns the users max speed
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns 0.0.
 */
stock float GetClientMaxSpeed(int client)	{
	return GetEntPropFloatEx(client, Prop_Send, "m_flMaxspeed");
}

/**
 *	Returns if the user is muted.
 *	Considered safer over IsClientMuted.
 *
 *	@param 	client		The users index.
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientMutedEx(int client)	{
	return GetClientListeningFlags(client) == VOICE_MUTED);
}

/**
 *	Set if the user should be muted or not.
 *
 *	@param	client		The users index.
 *	@param	mute		If true, it will enable noclip, else disabled.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientMute(int client, bool mute)	{
	if(!Tklib_IsValidClient(client, true))
		return false;
	
	SetClientListeningFlags(client, mute ? VOICE_MUTED:VOICE_NORMAL);
	return true;
}

/**
 *	Slays the user.
 *
 *	@param	client		The users index.
 *	@param	RandomDeath	Should death be random. (Should be used in games where is supported)
 *
 *	@error	If the user is invalid, this returns false.
 */
stock void SlayClient(int client, bool RandomDeath=false)	{
	if(!Tklib_IsValidClient(client, _, true))
		return false;
		
	FakeClientCommandEx(client, RandomDeath ? "kill": GetRandomBool() ? "kill":"explode");
	return true;
}

/**
 *	Returns the users lifestate.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientLifestate(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_lifeState");
}

/**
 *	Set the users lifestate.
 *
 *	@param	client		The users index.
 *	@param	value		Lifestate value.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock bool SetClientLifestate(int client, int value)	{
	return SetEntPropEx(client, Prop_Send, "m_lifeState", value);
}

/**
 *	Returns the users map navigation location name
 *
 *	@param	client		The users index.
 *	@param	location	Buffer to store the location name.
 *	@param	len			Size of the buffer.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientNavLocation(int client, char[] location, int maxlen)	{
	return GetEntPropStringEx(client, Prop_Send, "m_szLastPlaceName", location, maxlen);
}

//Respawning

//Set the respawn time for the specified user

#if !defined _tklib_disable_gameidentifier
/**
 *	Set the user to respawn in specified time
 *
 *	@param	client		The users index.
 *	@param	value		Respawn time.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool RespawnTime(int client, float value)	{
	if(Tklib_IsValidClient(client))	{
		CreateTimer(value, SetRespawnTime, client);
		return true;
	}
	
	return false;
}
#else
#error RespawnTime() requires GameIdentifier Include (for correct respawn actions)
#endif

#if !defined _tklib_disable_gameidentifier
//forwards the action to the respawn event
stock Action SetRespawnTime(Handle timer, int client)	{
	Respawn(client);
}
#else
#error SetRespawnTime() requires GameIdentifier Include (for correct respawn actions)
#endif

#if !defined _tklib_disable_gameidentifier
/**
 *	Respawn a client
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool Respawn(int client)	{
	if(Tklib_IsValidClient(client))	{
		switch(IdentifyGame())	{
			#if defined _tf2_included
			case Game_TF2, Game_TF2V, Game_TF2C, Game_TF2OP: TF2_RespawnPlayer(client);
			#endif
			#if defined _cstrike_included
			case Game_CSS, Game_CSGO, Game_CSPromod: CS_RespawnPlayer(client);
			#endif
		}
		
		return	true;
	}
	
	return	false;
}
#else
#error Respawn() requires GameIdentifier Include (for correct respawn actions)
#endif

/**
 *	Returns the users steam steamid.
 *	Same as GetClientAuthId but simpler.
 *
 *	@param	client		The users index.
 *	@param	buffer		Buffer storage.
 *	@param	maxlen		Length of the buffer.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientAuth(int client, char[] buffer, int maxlen)	{
	return Tklib_IsValidClient(client, _, _, false) ? GetClientAuthId(client, AuthId_Steam2, buffer, maxlen):false;
}

/**
 *	Returns the users steam steamid.
 *	Same as GetClientAuthId but simpler.
 *	This returns SteamID3 instead of SteamID2.
 *
 *	@param	client		The users index.
 *	@param	buffer		Buffer storage.
 *	@param	maxlen		Length of the buffer.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientAuth3(int client, char[] buffer, int maxlen)	{
	return Tklib_IsValidClient(client, _, _, false) ? GetClientAuthId(client, AuthId_Steam3, buffer, maxlen):false;
}

/**
 *	Returns the user by steam authentication.
 *
 *	@param auth.		Steam Auth.
 *
 *	@return				The users index.
 *
 *	@error	If the user is invalid, this returns 0.
 */
stock any GetClientOfAuth(const char[] auth)	{
	int user = 0;
	char tempauth[64];
	
	for(int client = 1; client < MaxClients; client++)	{
		GetClientAuth(client, tempauth, sizeof(tempauth));
		
		if(StrEqual(tempauth, auth, false))
			user = client;
	}
	
	return	user;
}

/**
 *	Returns the user by steam authentication.
 *
 *	@param auth.		Steam3 Auth.
 *
 *	@return				The users index.
 *
 *	@error	If the user is invalid, this returns 0.
 */
stock any GetClientOfAuth3(const char[] auth)	{
	int user = 0;
	char tempauth[64];
	
	for(int client = 1; client < MaxClients; client++)	{
		GetClientAuth3(client, tempauth, sizeof(tempauth));
		
		if(StrEqual(tempauth, auth, false))
			user = client;
	}
	
	return user;
}

/**
 *	Returns the users name properly. (GetClientName is buggy.)
 *
 *	@param	client		The users index.
 *	@param	buffer		Buffer to store the string.
 *	@param	maxlen		Max length of the string buffer.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientNameEx(int client, char[] buffer, int maxlen)	{
	return Tklib_IsValidClient(client, _, _, false) ? GetClientInfo(client, "name", buffer, maxlen):false;
}

/**
 *	Sets the users name properly.
 *
 *	@param	client		The users index.
 *	@param	buffer		Buffer to store the string.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientNameEx(int client, const char[] name)	{
	if(!Tklib_IsValidClient(client, _, _, false))
		return false;
	
	SetClientInfo(client, "name", name);
	return true;
}

/**
 *	Returns the users index if found from string.
 *
 *	@param		client			The user performing action.
 *	@param		player_name		The players name to search.
 *	@param		filter_flags	Filter flags.
 *
 *	@error		If the index of the player was not found or is invalid, this returns -1.
 */
stock int GetClientOfPlayername(int client, const char[] playername, int filter_flags=COMMAND_FILTER_CONNECTED|COMMAND_FILTER_NO_BOTS)	{
	char target_name[64];
	int target_list[64];
	bool tn_is_ml;
	int target = -1;
	
	int target_count = ProcessTargetString(playername, client, target_list, MAXPLAYERS, filter_flags, target_name, sizeof(target_name), tn_is_ml);
	
	for(int i = 0; i < target_count; i++)
		target = target_list[i];
	
	return target;
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
		if(Tklib_IsValidClient(i, nobots, false, false))
			count++;
	}
	return count;
}

/**
 *	Set a model path for the specified user.
 *	If setting model path in tf2, look at TF2_SetClientModel.
 *	This is paired with GetClientModel.
 *
 *	@param	client		The users index.
 *	@param	model		The model path.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientModel(int client, const char[] model)	{
	if(!Tklib_IsValidClient(client, _, true))
		return false;
	
	SetEntityModel(client, model);
	return true;
}

/**
 *	Returns the users current viewing angle.
 *
 *	@param	client	The users index.
 *	@param	angle	The angle user is looking at.
 *
 *	@error	If the used is invalid, this returns false.
 */
stock bool GetClientViewAngles(int client, float view[3])	{
	if(!Tklib_IsValidClient(client))
		return false;
	
	float eyes[3], angles[3];
	GetClientEyePosition(client, eyes); 
	GetClientEyeAngles(client, angles);
	TR_TraceRayFilter(eyes, angles, MASK_SOLID, RayType_Infinite, GetClientViewAngles_TraceEntityFilterPlayer, client);
	if(TR_DidHit())
		TR_GetEndPosition(view);
	
	return	true;
}

stock bool GetClientViewAngles_TraceEntityFilterPlayer(int entity, int contentsMask)	{
	return view_as<bool>(entity > MaxClients);
}

/**
 *	Set the users pending new team.
 *
 *	@param	client		The users index.
 *	@param	team		The new team index.
 *
 *	@error	If the user or is not supported in the current mod, this returns false.
 */
stock bool SetClientPendingTeam(int client, int team)	{
	return SetEntPropEx(client, Prop_Send, "m_iPendingTeamNum", team);
}

/**
 *	Returns the users pending new team.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user or is not supported in the current mod, this returns 0.
 */
stock int GetClientPendingTeam(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_iPendingTeamNum");
}

/**
 *	Returns if the user is ducking.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientDucking(int client)	{
	return GetEntPropBool(client, Prop_Data, "m_bDucking");
}

/**
 *	Set users ducking status.
 *
 *	@param	client	The users index.
 *	@param	duck	If true, the user will be ducking, else not.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientDucking(int client, bool duck)	{
	return SetEntPropEx(client, Prop_Data, "m_bDucking", duck);
}

/**
 *	Set if the user should be seen as 'connected'.
 *
 *	@param	client	The users index.
 *	@param	connet	If true, the client will be seen as 'connected'.
 *
 *	@error	If the user is invalid or has no connection property, this returns false.
 */
stock bool SetClientConnected(int client, bool connect)	{
	return SetEntPropEx(client, Prop_Send, "m_bConnected", connect);
}

#if !defined _tklib_disable_gameidentifier
/**
 *	Returns the teamcoloured name of the client specified.
 *
 *	@param	client	The client index.
 *	@param	buffer	Buffer storage to store the name.
 *	@param	maxlen	Maximum length of the buffer storage.
 *
 *	@noreturn
 */
stock void GetClientNameTeamString(int client, char[] buffer, int maxlen)	{
	int team = Tklib_IsValidClient(client) ? GetClientTeam(client):0;
	
	char TeamColour_Default[][] = {
		"{grey}",
		"{grey}",
		"{red}",
		"{blue}"
	}, TeamColour_TF2C[][] = {
		"{grey}",
		"{grey}",
		"{red}",
		"{blue}",
		"{lightgreen}",
		"{orange}"
	}, TeamColour_CSGO[][] = {
		"{grey}",
		"{grey}",
		"{orange}",
		"{blue}"
	}, TeamColour_L4D[][] = {
		"{grey}",
		"{grey}",
		"{orange}",
		"{lightred}"
	};
	
	switch(IdentifyGame())	{
		case Game_TF2C: Format(buffer, maxlen, "%s%N{default}", TeamColour_TF2C[team], client);
		case Game_CSGO: Format(buffer, maxlen, "%s%N{default}", TeamColour_CSGO[team], client);
		case Game_L4D1: Format(buffer, maxlen, "%s%N{default}", TeamColour_L4D[team], client);
		case Game_L4D2: Format(buffer, maxlen, "%s%N{default}", TeamColour_L4D[team], client);
		default: Format(buffer, maxlen, "%s%N{default}", TeamColour_Default[team], client);
	}
}
#else
#error GetClientTeamString() requires GameIdentifier Include (For correct team colours and game identification)
#endif

/**
 *	Returns the users m_fFlags status.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid or has no m_fFlags property, this returns -1.
 */
stock int GetClientFlags(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_fFlags");
}

/**
 *	Returns if the user is jumping.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid or has no m_bJumping property, this returns false.
 */
stock bool IsClientJumping(int client)	{
	return GetEntPropBool(client, Prop_Send, "m_bJumping");
}

/**
 *	Returns if the user is mid-air.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientMidAir(int client)	{
	return	Tklib_IsValidClient(client, _, true) ? 
	(GetClientFlags(client) == 256
	|| GetClientFlags(client) == 258
	|| GetClientFlags(client) == 262):false;
}

/**
 *	Returns the users water level
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientWaterLevel(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_nWaterLevel");
}

/**
 *	Set the users water level
 *
 *	@param	client	The users index.
 *	@param	level	The water level to set.
 *
 *	@error	If the user is invalid or procedure failed , this returns false.
 */
stock int SetClientWaterLevel(int client, int level)	{
	return SetEntPropEx(client, Prop_Send, "m_nWaterLevel", level);
}

/**
 *	Returns the users decal spray cooldown.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns -1.0.
 */
stock float GetClientSprayCooldown(int client)	{
	return GetEntPropFloatEx(client, Prop_Send, "m_flNextDecalTime");
}

/**
 *	Set the users decal spray cooldown.
 *
 *	@param	client		The users index.
 *	@param	cooldown	The cooldown to set.
 *
 *	@error	If the user is invalid or procedure failed, this returns false.
 */
stock bool SetClientSprayCooldown(int client, float cooldown)	{
	return SetEntPropFloatEx(client, Prop_Send, "m_flNextDecalTime", cooldown);
}

/**
 *	Returns if the user is actively using a ladder.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientUsingLadder(int client)	{
	return Tklib_IsValidClient(client, _, true) ? (GetEntityMoveType(client) == MOVETYPE_LADDER) : false;
}

/**
 *	Set the users hud hide-flags.
 *
 *	@param	client	The users index.
 *	@param	flag	Flags to be used.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientHideHud(int client, int flags)	{
	return SetEntPropEx(client, Prop_Send, "m_iHideHUD", flags);
}

/**
 *	Returns the users found matching the playername search criteria in an array.
 *	The array needs to be manually destroyed.
 *
 *	@param	playername	The playername to search.
 *
 *	@error	If no valid users are found, this returns empty.
 */
stock ArrayList FindClientsByPlayername(const char[] playername, bool nobots=false)	{
	ArrayList list = new ArrayList(64);
	char name[64];
	
	int found = 0;
	for(int client = 1; client < MaxClients; client++)	{
		if(Tklib_IsValidClient(client, nobots, false, false))	{
			GetClientInfo(client, "name", name, sizeof(name));
			if(StrContains(name, playername, false) != -1)	{
				found++;
				list.Push(client);
			}
		}
	}
	
	return list;
}

/**
 *	Returns the users found matching the team search criteria in an array.
 *	The array needs to be manually destroyed.
 *
 *	@param	team	The team index to search.
 *
 *	@error	If no valid users are found, this returns empty.
 */
stock ArrayList FindClientsByTeam(any team, bool nobots=false)	{
	ArrayList list = new ArrayList(64);
	
	int found = 0;
	for(int client = 1; client < MaxClients; client++)	{
		if(Tklib_IsValidClient(client, nobots, false, false))	{
			if(GetClientTeam(client) == team)	{
				found++;
				list.Push(client);
			}
		}
	}
	
	return list;
}

/**
 *	Set the users suit sprint power.
 *
 *	@param	client	The uses index.
 *	@param	value	The suit print power to set.
 *
 *	@param	If the user is invalid, procedure failed or invalid value is set, this returns false.
 */
stock bool SetClientSuitSprintPower(int client, float value)	{
	if(value < 0 || value > 100)
		return false;
	
	return SetEntPropFloatEx(client, Prop_Send, "m_flSuitPower", value);
}

/**
 *	Returns the users suit sprint power.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns -1.0.
 */
stock float GetClientSuitSpritPower(int client)	{
	return GetEntPropFloatEx(client, Prop_Send, "m_flSuitPower");
}

#endif

//Important

/**
 *	Returns true or false depending if the user is valid.
 *
 *	@param	client				The users index.
 *	@param	IgnoreBot			If true, the bots are counted as 'invalid'.					Defaulted to false.
 *	@param	IgnoreDead			If true, the dead are counted as 'invalid'.					Defaulted to false.
 *	@param	IgnoreNonInGame		If true, the non-ingame users are counted as 'invalid'		Defaulted to true.
 *	@param	IgnoreNonConnected	If true, the non-connected users are counted as 'invalid'	Defaulted to true.
 *	@param	IgnoreInvalidTeam	If true, the invalid team users are counted as 'invalid'	Defaulted to false.
 */
stock bool Tklib_IsValidClient(int client, bool IgnoreBot=false, bool IgnoreDead=false, bool IgnoreNonInGame=true, bool IgnoreNonConnected=true, bool IgnoreInvalidTeam=false)	{
	if(client == -1 || client == 0 || client < 1 || client > MaxClients)
		return false;
	if(IgnoreNonConnected)	{
		if(!IsClientConnected(client))
			return false;
	}
	if(IgnoreNonInGame)	{
		if(!IsClientInGame(client))
			return false;
	}
	if(IsClientSourceTV(client))
		return false;
	if(IsClientReplay(client))
		return false;
	if(IgnoreBot)	{
		if(IsFakeClient(client))
			return false;
	}
	if(IgnoreDead)	{
		if(!IsPlayerAlive(client))
			return false;
	}
	if(IgnoreInvalidTeam)	{
		if(GetClientTeam(client) < 1)
			return false;
	}
	return true;
}