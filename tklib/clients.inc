//==========================================//
// Tklib / Clients.
//==========================================//

enum	{
	Player_Unsupported	= -2,
	Player_Invalid		= -1,
	Player_Console		= 0
}

//Player permissions
/**
 *	Returns if the user is a Console
 *
 *	@param client	The users index.
 */
stock bool IsClientConsole(any client)	{	
	return	bool(client == 0);
}

/**
 *	Returns if the user is the Owner
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientOwner(any client)	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, "", ADMFLAG_ROOT, false):false;
}

/**
 *	Returns if the user is an Admin
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientAdmin(any client)	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, "", ADMFLAG_GENERIC, false):false;
}

/**
 *	Returns if the user is a Moderator
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientModerator(any client)	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, "", ADMFLAG_CUSTOM1, false):false;
}

/**
 *	Returns if the user is a Vip
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientVip(any client)	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, "", ADMFLAG_RESERVATION, false):false;
}

/**
 *	Returns if the user has the specified flag access.
 *
 *	@param	client		The users index.
 *	@param	adminflags	Administrative flags (bitstring) to use for permissions.
 *	@param	flagaccess	The flag access command. Disabled if empty.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientFlag(any client, int adminflags, char[] flagaccess="")	{
	return Tklib_IsValidClient(client, true) ? CheckCommandAccess(client, flagaccess, adminflags, false):false;
}

/**
 *	Returns if the users is the same player.
 *
 *	@param	client		The users index.
 *	@param	target		The targets index.
 *
 *	@return				Returns true if it's the same player, false otherwise.
 */
stock bool IsSamePlayers(any client, any target)	{
	return	bool(client == target);
}

/**
 *	Returns if the user and target is on the same team.
 *
 *	@param	client		The users index.
 *	@param	target		The targets index.
 *
 *	@return				Returns true if it's they're on the same team, false otherwise.
 */
stock bool IsSameTeam(any client, any target)	{
	return	bool(GetClientTeam(client) == GetClientTeam(target));
}

//General stuff

/**
 *	Set the users scoreboard ping
 *
 *	@param	client		The users index.
 *	@param	value		Amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientPing(any client, int value)	{
	return	Tklib_IsValidClient(client, true) ? SetEntPropEx(client, Prop_Send, "m_iPing", value):false;
}

/**
 *	Returns the users scoreboard ping
 *
 *	@param	client		The users index.
 *
 *	@error	If the client is not valid, this returns -1.
 */
stock int GetClientPing(any client)	{
	return	Tklib_IsValidClient(client, true) ? GetEntProp(GetPlayerResourceEntity(), Prop_Send, "m_iPing", _, client):-1;
}

/**
 *	Set the users death count
 *
 *	@param	client		The users index.
 *	@param	value		Amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientDeaths(any client, int value)	{
	return	Tklib_IsValidClient(client, true) ? SetEntPropEx(client, Prop_Data, "m_iDeaths", value):false;
}

/**
 *	Set the users frag count
 *
 *	@param	client		The users index.
 *	@param	value		Amount index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientFrags(any client, int value)	{
	return	Tklib_IsValidClient(client, true) ? SetEntPropEx(client, Prop_Data, "m_iFrags", value):false;
}


/**
 *	Set the users health
 *
 *	@param	client		The users index.
 *	@param	value		Amount index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientHealth(any client, int value)	{
	return	Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_iHealth", value):false;
}

/**
 *	Set the users max health
 *
 *	@param	client		The users index.
 *	@param	value		Amount index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientMaxHealth(any client, int value)	{
	return	Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_iMaxHealth", value):false;
}

/**
 *	Returns the users max health
 *
 *	@param	client		The users index.
 *
 *	@error	If the client is not valid, this returns -1.
 */
stock int GetClientMaxHealth(any client)	{
	return	Tklib_IsValidClient(client) ? GetEntPropEx(GetPlayerResourceEntity(), Prop_Send, "m_iMaxHealth", client):-1;
}

/**
 *	Sets the users health & maximum health.
 *
 *	@param	client			The users index.
 *	@param	health			Health
 *	@param	maxhealth		Maximum health.
 *
 *	@noreturn
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientHealthEx(any client, int health, int maxhealth)	{
	if(Tklib_IsValidClient(client, _, true))	{
		SetClientMaxHealth(client, newmaxhealth);
		SetClientHealth(client, health);
		return	true;
	}
	
	return	false;
}

/**
 *	Set the users team index number called from the game's netprop m_iTeamNum.
 *
 *	@param	client			The users index.
 *	@param	value			Team index value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientTeamNum(any client, int value)	{
	return	Tklib_IsValidClient(client, true) ? SetEntPropEx(client, Prop_Send, "m_iTeamNum", value):false;
}

/**
 *	Returns the users team index number called from the game's netprop m_iTeamNum.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is not valid or mod not supported, this returns -1.
 */
stock int GetClientTeamNum(any client)	{
	return	Tklib_IsValidClient(client) ? GetEntPropEx(client, Prop_Send, "m_iTeamNum"):-1;
}

/**
 *	Set the users field-of-view.
 *
 *	@param	client		The users index.
 *	@param	value		Amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientFOV(any client, int value)	{
	return	Tklib_IsValidClient(client, true) ? SetEntPropEx(client, Prop_Send, "m_iFOV", value):false;
}

/**
 *	Returns the clients field-of-view.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientFOV(any client)	{
	return	Tklib_IsValidClient(client, true) ? GetEntPropEx(client, Prop_Send, "m_iFOV"):-1;
}

/**
 *	Set the users default field-of-view.
 *
 *	@param	client		The users index.
 *	@param	value		Amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientDefaultFOV(any client, int value)	{
	return	Tklib_IsValidClient(client, true) ? SetEntPropEx(client, Prop_Send, "m_iDefaultFOV", value):false;
}

/**
 *	Returns the users default fov
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientDefaultFOV(any client)	{
	return	Tklib_IsValidClient(client, true) ? GetEntPropEx(client, Prop_Send, "m_iDefaultFOV"):-1;
}

/**
 *	Set the users Observer target
 *
 *	@param	client 		The users index.
 *	@param	target		Target to observe.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientObserverTarget(any client, int target)	{
	return	Tklib_IsValidClient(client, true) ? SetEntPropEntEx(client, Prop_Send, "m_iObserverTarget", target):false;
}

/**
 *	Returns the users Observer target
 *
 *	@param	client 		The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientObserverTarget(any client)	{
	return	Tklib_IsValidClient(client, true) ? GetEntPropEntEx(client, Prop_Send, "m_iObserverTarget"):-1;
}

/**
 *	Set the users Observer mode
 *
 *	@param	client		The users index.
 *	@param	value		Observer mode value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientObserverMode(any client, int value)	{
	return	Tklib_IsValidClient(client, true) ? SetEntPropEx(client, Prop_Send, "m_iObserverMode", value):false;
}

/**
 *	Returns the users Observer mode
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientObserverMode(any client)	{
	return	Tklib_IsValidClient(client, true) ? GetEntPropEx(client, Prop_Send, "m_iObserverMode"):-1;
}

/**
 *	Set the clients viewmodel to be drawn.
 *
 *	@param client		The users index.
 *	@param value		Bool value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientDrawViewModel(any client, bool value)	{
	return	Tklib_IsValidClient(client, true) ? SetEntPropEx(client, Prop_Send, "m_bDrawViewmodel", value):false;
}

/**
 *	Returns the clients drawviewmodel value
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientDrawViewModel(any client)	{
	return	Tklib_IsValidClient(client, true) ? GetEntPropBool(client, Prop_Send, "m_bDrawViewmodel"):false;
}

/**
 *	Set the clients godmode
 *
 *	@param	client		The users index.
 *	@param	godmode		If true, it will enable godmode, else disabled.
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientGodMode(any client, bool godmode)	{
	return	Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_takedamage", godmode ? 0:2, 1):false;
}

/**
 *	Returns if client is in godmode
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientGodmode(any client)	{
	return	Tklib_IsValidClient(client, _, true) ? GetEntPropBool(client, Prop_Send, "m_takedamage", 0, 1):false
}

/**
 *	Set the user buddha mode
 *
 *	@param	client		The users index.
 *	@param	buddha		If true, it will enable buddha mode, else disabled.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientBuddhaMode(any client, bool buddha)	{
	return	Tklib_IsValidClient(client, _, true) ? SetEntPropEx(client, Prop_Send, "m_takedamage", buddha ? 1:2, 1):false;
}

/**
 *	Returns if the user is in buddha mode.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientBuddhaMode(any client)	{
	return	Tklib_IsValidClient(client, _, true) ? GetEntPropBool(client, Prop_Send, "m_takedamage", 1, 1):false
}

/**
 *	Set the users collision
 *
 *	@param	client		The users index.
 *	@param	collision	If true, it will enable collision, else disabled.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientCollision(any client, bool collision)	{
	if(Tklib_IsValidClient(client, _, true))	{
		collision ? SetEntData(client, FindSendPropInfo("CBaseEntity", "m_CollisionGroup"), 2, 4):SetEntData(client, FindSendPropInfo("CBaseEntity", "m_CollisionGroup"), 5, 4);
		return	true;
	}
	
	return	false;
}

/**
 *	Returns if the user has collision.
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this returns false.
 */
stock bool GetClientCollision(any client)	{
	return	Tklib_IsValidClient(client) ? bool(GetEntData(client, FindSendPropInfo("CBaseEntity", "m_CollisionGroup"), 2, 4) == 1):false
}

/**
 *	Set the user noclip on/off
 *
 *	@param	client		The users index.
 *	@param	noclip		If true, it will enable noclip, else disabled.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientNoclip(any client, bool noclip)	{
	if(Tklib_IsValidClient(client))	{
		SetEntityMoveType(client, noclip ? MOVETYPE_NOCLIP:MOVETYPE_WALK);
		return	true;
	}
	
	return	false;
}

/**
 *	Returns if the user is noclipping.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientNoclipping(any client)	{
	return	Tklib_IsValidClient(client, _, true) ? bool(GetEntityMoveType(client) == MOVETYPE_NOCLIP):false;
}
 

/**
 *	Set the users max speed
 *
 *	@param	client		The users index.
 *	@param	value		Float amount value.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientMaxSpeed(any client, float value)	{
	return	Tklib_IsValidClient(client) ? SetEntPropFloatEx(client, Prop_Send, "m_flMaxspeed", value):false;
}

/**
 *	Returns the users max speed
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns 0.0.
 */
stock float GetClientMaxSpeed(any client)	{
	return	Tklib_IsValidClient(client) ? GetEntPropFloatEx(client, Prop_Send, "m_flMaxspeed"):0.0;
}

/**
 *	Returns if the user is muted.
 *	Considered safer over IsClientMuted.
 *
 *	@param 	client		The users index.
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientMutedEx(any client)	{
	return	Tklib_IsValidClient(client, true) ? bool(GetClientListeningFlags(client) == VOICE_MUTED):false;
}

/**
 *	Set if the user should be muted or not.
 *
 *	@param	client		The users index.
 *	@param	mute		If true, it will enable noclip, else disabled.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientMute(any client, bool mute)	{
	if(Tklib_IsValidClient(client, true))	{
		SetClientListeningFlags(client, mute ? VOICE_MUTED:VOICE_NORMAL);
		return	true;
	}
	
	return	false;
}

/**
 *	Slays the user.
 *
 *	@param	client		The users index.
 *	@param	RandomDeath	Should death be random. (Should be used in games where is supported)
 *
 *	@error	If the user is invalid, this returns false.
 */
stock void SlayClient(any client, bool RandomDeath=false)	{
	if(Tklib_IsValidClient(client, _, true))	{
		FakeClientCommandEx(client, RandomDeath ? "kill":GetRandomBool() ? "kill":"death");
		return	true;
	}
	
	return	false;
}

/**
 *	Returns the users lifestate.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int GetClientLifestate(any client)	{
	return Tklib_IsValidClient(client) ? GetEntProp(client, Prop_Send, "m_lifeState"):-1;
}

/**
 *	Set the users lifestate.
 *
 *	@param	client		The users index.
 *	@param	value		Lifestate value.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock bool SetClientLifestate(any client, int value)	{
	return Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_lifeState", value):false;
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
stock bool GetClientNavLocation(any client, char[] location, int maxlen)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropStringEx(client, Prop_Send, "m_szLastPlaceName", location, maxlen):false;
}

//Respawning

//Set the respawn time for the specified user

/**
 *	Set the user to respawn in specified time
 *
 *	@param	client		The users index.
 *	@param	value		Respawn time.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool RespawnTime(any client, float value)	{
	if(Tklib_IsValidClient(client))	{
		CreateTimer(value, SetRespawnTime, client);
		return	true;
	}
	
	return	false;
}

//forwards the action to the respawn event
stock Action SetRespawnTime(Handle timer, any client)	{
	Respawn(client);
}

/**
 *	Respawn a client
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool Respawn(any client)	{
	if(Tklib_IsValidClient(client))	{
		switch(IdentifyGame())	{
			#if !defined _tklib_disable_tf2
			case	Game_TF2:
				TF2_RespawnPlayer(client);
			case	Game_TF2C:	{
				//Fixes respawn bug issue with Team Fortress 2 Classic
				if(!IsPlayerAlive(client))
					TF2_RespawnPlayer(client);
			}
			#endif
			#if !defined _tklib_disable_cstrike
			case	Game_CSS,Game_CSPromod,Game_CSGO:
				CS_RespawnPlayer(client);
			#endif
		}
		
		return	true;
	}
	
	return	false;
}

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
stock bool GetClientAuth(any client, char[] buffer, int maxlen)	{
	return	Tklib_IsValidClient(client, _, _, false, false) ? GetClientAuthId(client, AuthId_Steam2, buffer, maxlen):false;
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
stock bool GetClientAuth3(any client, char[] buffer, int maxlen)	{
	return	Tklib_IsValidClient(client, _, _, false, false) ? GetClientAuthId(client, AuthId_Steam3, buffer, maxlen):false;
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
		if(!Tklib_IsValidClient(client, _, _, false))
			continue;
		
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
		if(!Tklib_IsValidClient(client, _, _, false))
			continue;
		
		GetClientAuth3(client, tempauth, sizeof(tempauth));
		
		if(StrEqual(tempauth, auth, false))
			user = client;
	}
	
	return	user;
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
stock bool GetClientNameEx(any client, char[] buffer, int maxlen)	{
	return	Tklib_IsValidClient(client, _, _, false, false) ? GetClientInfo(client, "name", buffer, maxlen):false;
}

/**
 *	Sets the users name properly.
 *
 *	@param	client		The users index.
 *	@param	buffer		Buffer to store the string.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientNameEx(any client, char[] name)	{
	if(Tklib_IsValidClient(client, false, false, false, false))	{
		SetClientName(client, "name", name);
		return	true;
	}
	
	return	false;
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
stock int GetClientOfPlayername(any client, const char[] playername, int filter_flags=COMMAND_FILTER_CONNECTED|COMMAND_FILTER_NO_BOTS)	{
	char target_name[64];
	int target_list[64];
	bool tn_is_ml;
	
	int target_count = ProcessTargetString(playername, client, target_list, MAXPLAYERS, filter_flags, target_name, sizeof(target_name), tn_is_ml);
	
	for(int i = 0; i < target_count; i++)	{
		return target_list[i];
	}
	
	return	-1;
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
	return	count;
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
stock bool SetClientModel(any client, const char[] model)	{
	if(Tklib_IsValidClient(client, _, true))	{
		SetEntityModel(client, model);
		return	true;
	}
	
	return	false;
}

/**
 *	Returns the users current viewing angle.
 *
 *	@param	client	The users index.
 *	@param	angle	The angle user is looking at.
 *
 *	@error	If the used is invalid, this returns false.
 */
stock bool GetClientViewAngles(any client, float view[3])	{
	if(Tklib_IsValidClient(client))	{
		float eyes[3], angles[3];
		GetClientEyePosition(client, eyes); 
		GetClientEyeAngles(client, angles);
		TR_TraceRayFilter(eyes, angles, MASK_SOLID, RayType_Infinite, GetClientViewAngles_TraceEntityFilterPlayer, client);
		if(TR_DidHit())
			TR_GetEndPosition(view);
		
		return	true;
	}
	
	return	false;
}

stock bool GetClientViewAngles_TraceEntityFilterPlayer(int entity, int contentsMask)	{
	return	bool(entity > MaxClients);
}

/**
 *	Set the users pending new team.
 *
 *	@param	client		The users index.
 *	@param	team		The new team index.
 *
 *	@error	If the user or is not supported in the current mod, this returns false.
 */
stock bool SetClientPendingTeam(any client, int team)	{
	return	Tklib_IsValidClient(client) ?  SetEntPropEx(client, Prop_Send, "m_iPendingTeamNum", team):false;
}

/**
 *	Returns the users pending new team.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user or is not supported in the current mod, this returns 0.
 */
stock int GetClientPendingTeam(any client)	{
	return	Tklib_IsValidClient(client) ? GetEntPropEx(client, Prop_Send, "m_iPendingTeamNum"):0;
}

/**
 *	Returns if the user is ducking.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool IsClientDucking(any client)	{
	return	Tklib_IsValidClient(client, _, true) ? GetEntPropBool(client, Prop_Data, "m_bDucking"):false;
}

/**
 *	Set users ducking status.
 *
 *	@param	client	The users index.
 *	@param	duck	If true, the user will be ducking, else not.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientDucking(any client, bool duck)	{
	return	Tklib_IsValidClient(client, _, true) ? SetEntPropEx(client, Prop_Data, "m_bDucking", duck):false;
}

/**
 *	Set if the user should be seen as 'connected'.
 *
 *	@param	client	The users index.
 *	@param	connet	If true, the client will be seen as 'connected'.
 *
 *	@error	If the user is invalid or has no connection property, this returns false.
 */
stock bool SetClientConnected(any client, bool connect)	{
	return	Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_bConnected", connect):false;
}

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
stock bool Tklib_IsValidClient(any client, bool IgnoreBot=false, bool IgnoreDead=false, bool IgnoreNonInGame=true, bool IgnoreNonConnected=true, bool IgnoreInvalidTeam=false)	{
	if(client == 0 || client == -1)	//This is to make sure console (index 0) & non-existing client (index -1) is not giving outright errors.
		return	false;
	if(client < 1 || client > MaxClients)
		return	false;
	if(IgnoreNonInGame)	{
		if(!IsClientInGame(client))
			return	false;
	}
	if(IgnoreNonConnected)	{
		if(!IsClientConnected(client))
			return	false;
	}
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
	if(IgnoreInvalidTeam)	{
		if(GetClientTeam(client) < 1)
			return	false;
	}
	return	true;
}

//Work in progress
/*

//Methodmaps

methodmap	Player	__nullable__	{
	public Player(int client)	{
		return	player(client);
	}
	
	public bool IsConsole()	{
		return	IsClientConsole(This);
	}
	
	public bool IsOwner()	{
		return	IsClientOwner(This);
	}
	
	public bool IsAdmin()	{
		return	IsClientAdmin(This);
	}
	
	public bool IsModerator()	{
		return	IsClientModerator(This);
	}
	
	public bool IsVip()	{
		return	IsClientVip(This);
	}
	
	public bool IsFlag(int adminflags, char[] flagaccess="")	{
		return	IsClientFlag(This, adminflags, flagaccess);
	}
	
	public bool SamePlayers(any target)	{
		return IsSamePlayers(This, target);
	}
	
	public bool SameTeam(any target)	{
		return IsSameTeam(This, target);
	}
	
	property int Ping	{
		public set(int value)	{
			SetClientPing(This, value);	
		}
		public get()	{
			return GetClientPing(This);	
		}
	}
	
	property int Deaths	{
		public set(int value)	{
			SetClientDeaths(This, value);
		}
		public get()	{
			return GetClientDeaths(This);
		}
	}
	
	property int Frags	{
		public set(int value)	{
			SetClientFrags(This, value);
		}
		public get()	{
			return GetClientFrags(This);
		}
	}
	
	public bool RespawnTime(float value)	{
		return RespawnTime(This, value);
	}
	
	public bool Respawn()	{
		return Respawn(This);
	}
	
	public bool GetAuth(char[] auth, int maxlen)	{
		return GetClientAuth(This, auth, maxlen);
	}
	
	public bool GetAuth3(char[] auth, int maxlen)	{
		return GetClientAuth3(This, auth, maxlen);
	}
	
	public bool SetName(char[] name)	{
		return SetClientNameEx(This, name);
	}
	
	public bool GetName(char[] name, int maxlen)	{
		return GetClientNameEx(This, name, maxlen);
	}
	
	public bool SetModel(char[] model)	{
		return SetClientModel(This, model);
	}
	
	public void GetModel(char[] model, int maxlen)	{
		GetClientModel(This, model, maxlen);
	}
	
	public bool GetViewAngles(float view[3])	{
		return GetClientViewAngles(This, view);
	}
	
	property any PendingTeam	{
		public set(any team)	{
			SetClientPendingTeam(This, team);
		}
		public get()	{
			return GetClientPendingTeam(This);
		}
	}
	
	property bool Ducking	{
		public set(bool duck)	{
			SetClientDucking(This, duck);
		}
		public get()	{
			return IsClientDucking(This);
		}
	}
	
	property bool Connected	{
		public set(bool connect)	{
			SetClientConnected(This, connect);
		}
		public get()	{
			return GetEntPropBool(This, Prop_Send, "m_bConnected");
		}
	}
	
	public bool IsValid(bool IgnoreBot=false,
						bool IgnoreDead=false,
						bool IgnoreNonInGame=false,
						bool IgnoreNonConnected=false,
						bool IgnoreInvalidTeam=false)	{
		return Tklib_IsValidClient(This, IgnoreBot, IgnoreDead, IgnoreNonInGame, IgnoreNonConnected, IgnoreInvalidTeam);
	}
}

*/