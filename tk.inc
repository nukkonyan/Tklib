#include	<sdktools>
#include	<sdkhooks>
#include	<cstrike>
#include	<tf2_stocks>

public	Extension	__ext_tf2	= 	{
	name		=	"TF2 Tools",		//This allows the plugin to load even though the TF2 Tools extension is not running
	file		=	"game.tf2.ext",	//To allow other TF2 versions to work with this plugin
	required	=	0,
};

public	Extension	__ext_cstrike	= 	{
	name		=	"cstrike",
	file		=	"games/game.cstrike.ext",
	autoload	=	0,
	required	=	0,
};

//I made this because TFTeam enum exists and cs doesn't have it :)
enum	CSTeam
{
	CSTeam_Unassigned	=	0,
	CSTeam_Spectators	=	1,
	CSTeam_Terrorists	=	2,
	CSTeam_CTerrorists	=	3
}

//Player permissions
/**
 * Returns if the client is a Console
 *
 * @param client		Client index.
 */
stock	bool	Console(int	client)	{
	if(client == 0)
		return true;
	return	false;
}

/**
 * Returns if the client is a bot
 *
 * @param client		Client index.
 */
stock	bool	Bot(int client)	{
	if(IsFakeClient(client))
		return	true;
	return	false;
}

/**
 * Returns if the client is an Owner
 *
 * @param client		Client index.
 */
stock	bool	IsClientOwner(int client)	{
	if(!CheckCommandAccess(client,	"owner_flag",	ADMFLAG_ROOT,	false))
		return false;
	return	true;
}

/**
 * Returns if the client is an Admin
 *
 * @param client		Client index.
 */
stock	bool	IsClientAdmin(int client)	{
	if(!CheckCommandAccess(client,	"admin_flag",	ADMFLAG_GENERIC,	false))
		return false;
	return	true;
}

/**
 * Returns if the client is a Moderator
 *
 * @param client		Client index.
 */
stock	bool	IsClientModerator(int client)	{
	if(!CheckCommandAccess(client,	"moderator_flag",	ADMFLAG_CUSTOM1,	false))
		return false;
	return	true;
}

/**
 * Returns if the client is a Vip
 *
 * @param client		Client index.
 */
stock	bool	IsClientVip(int	client)	{
	if(!CheckCommandAccess(client,	"vip_flag",	ADMFLAG_RESERVATION,	false))	return false;
	return	true;
}

//General stuff

//Cookies
/**
 * Simplified version of SetClientCookie
 * Turns the specified integer into a string
 *
 * @param client		Client index.
 * @param cookie		Cookie handle.
 * @param value			The integer value
 */
stock	void	SetClientCookieInt(int client, Handle cookie, int value)	{
	char	item[1024];
	IntToString(value,	item,	sizeof(item));
	cookie.Set(client,	item);
}

//Ping
/**
 * Set the clients scoreboard ping
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void		SetClientPing(int	client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_iPing",	value);
}

/**
 * Get the clients scoreboard ping
 *
 * @param client		Client index.
 */
stock	int		GetClientPing(int	client)	{
	return	GetEntProp(GetPlayerResourceEntity(), Prop_Send, "m_iPing", _, client);
}

//Set & Get Death count
/**
 * Set the clients death count
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	SetClientDeaths(int	client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_iDeaths",	value);
}

//Set & Get Frag count
/**
 * Set the clients frag count
 *
 * @param client		Client index.
 * @param value			Amount index.
 */
stock	void	SetClientFrags(int	client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_iFrags",		value);
}

//Set & Get Health point
/**
 * Set the clients max health
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	SetClientHealth(int	client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_iHealth",	value);
}

/**
 * Get the clients max health
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	GetClientMaxHealth(int	client)	{
	return	SetEntProp(client,	Prop_Send,	"m_iMaxHealth");
}

//Set & Get Team index number
/**
 * Set the clients team index number called from the game itself
 *
 * @param client		Client index.
 * @param value			Team index value.
 */
stock	void	SetClientTeamNum(int client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_iTeamNum",	value);
}

/**
 * Get the clients team index number called from the game itself
 *
 * @param client		Client index.
 */
stock	int		GetClientTeamNum(int client)	{
	return	GetEntProp(client,	Prop_Send,	"m_iTeamNum");
}

//Set & Get FOV || Field-Of-View
/**
 * Set the clients fov
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	SetClientFOV(int	client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_iFOV",	value);
}

/**
 * Get the clients fov
 *
 * @param client		Client index.
 */
stock	int		GetClientFOV(int client)	{
	return	GetEntProp(client,	Prop_Send,	"m_iFOV");
}

/**
 * Set the clients default fov
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	SetClientDefaultFOV(int	client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_iDefaultFOV",	value);
}

/**
 * Get the clients default fov
 *
 * @param client		Client index.
 */
stock	int		GetClientDefaultFOV(int	client)	{
	return	GetEntProp(client,	Prop_Send,	"m_iDefaultFOV");
}

//Set Observer Mode on client
/**
 * Set the clients Observer target
 *
 * @param client 		Client index.
 * @param value			Amount value.
 */
stock	void	SetClientObserverTarget(int	client,	int value)	{
	SetEntProp(client,	Prop_Send,	"m_iObserverTarget",	value);
}

/**
 * Set the clients Observer mode
 *
 * @param client		Client index.
 * @param value			Bool value.
 */
stock	void	SetClientObserverMode(int	client,	bool value)	{
	SetEntProp(client,	Prop_Send,	"m_iObserverMode",		value);
}

//Clients viewmodel
/**
 * Set the clients drawviewmodel value
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	SetClientDrawViewModel(int	client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_bDrawViewmodel",	value);
}

/**
 * Get the clients drawviewmodel value
 *
 * @param client		Client index.
 */
stock	int		GetClientDrawViewModel(int	client)	{
	return	SetEntProp(client,	Prop_Send,	"m_bDrawViewmodel");
}

//Godmode stuff

/**
 * Set the clients godmode
 *
 * @param client		Client index.
 * @param godmode		Bool value.
 */
stock	void	SetClientGodMode(int	client,	bool	godmode)	{
	if(godmode)
		SetEntProp(client,	Prop_Send,	"m_takedamage",	0,	1);
	else
		SetEntProp(client,	Prop_Send,	"m_takedamage",	2,	1);
}

/**
 * Set the clients buddha mode
 *
 * @param client		Client index.
 * @param buddha		Bool value.
 */
stock	void	SetClientBuddhaMode(int	client,	bool	buddha)	{
	if(godmode)
		SetEntProp(client,	Prop_Send,	"m_takedamage",	1,	1);
	else
		SetEntProp(client,	Prop_Send,	"m_takedamage",	2,	1);
}

//Enable or disable clients collision
/**
 * Set the clients collision
 *
 * @param client		Client index.
 * @param collision		Bool value.
 */
stock	void	SetClientCollision(int	client,	bool collision)	{
	int	block	=	FindSendPropInfo("CBaseEntity", "m_CollisionGroup");
	if(collision)
		SetEntData(client,	block,	2,	4,	true);
	else
		SetEntData(client,	block,	5,	4,	true);
}

//Noclip toggle
/**
 * Set the client noclip on/off
 *
 * @param client		Client index.
 * @param noclip		Bool value.
 */
stock	void	SetClientNoclip(int	client,	bool	noclip)	{
	if(noclip)
		SetEntityMoveType(client,	MOVETYPE_NOCLIP);
	else
		SetEntityMoveType(client,	MOVETYPE_WALK);
}

//Clients max speed

/**
 * Set the clients max speed
 *
 * @param client		Client index.
 * @param value			Float amount value.
 */
stock	float	SetClientMaxSpeed(int	client,	float	value)	{
	SetEntPropFloat(client,	Prop_Send,	"m_MaxSpeed",	value);
}

/**
 * Get the clients max speed
 *
 * @param client		Client index.
 */
stock	float	GetClientMaxSpeed(int	client)	{
	return	GetEntPropFloat(client,	Prop_Send,	"m_MaxSpeed");
}


//Respawning

//Set the respawn time for the specified client

/**
 * Set the client to respawn in specified time
 *
 * @param client		Client index.
 * @param value			Float amount value.
 */
stock	float	RespawnTime(int	client,	float	value)	{
	CreateTimer(value,	SetRespawnTime,	client);
}

//forwards the action to the respawn event
stock	Action	SetRespawnTime(Handle	timer,	any	client)	{
	Respawn(client);
}

/**
 * Respawn a client
 *
 * @param client		Client index.
 */
stock	Action	Respawn(int	client)	{
	//Checks if client is a console user or ingame/valid
	if(client == 0 || client > MaxClients)	{
		return Plugin_Handled;
	}
	else	{
		switch(GetEngineVersion())	{
			case	Engine_TF2:	{
				//Fix respawn issue with Team Fortress 2 Classic
				char	game[64];
				GetGameFolderName(game,	sizeof(game));
				if(StrEqual(game,	"tf2classic"))	{
					if(!IsPlayerAlive(client))
						TF2_RespawnPlayer(client);
				}
				else	TF2_RespawnPlayer(client);
			}
			case	Engine_CSS,Engine_CSGO:	CS_RespawnPlayer(client);
		}
	}
	return	Plugin_Handled;
}

//Weapons

/**
 * Get the clients current active weapon
 *
 * @param client		Client index.
 */
stock	int		GetClientActiveWeapon(int client)	{
	return	GetEntPropEnt(client,	Prop_Send,	"m_hActiveWeapon");
}

/**
 * Get the actual name of the clients weapon entity
 *
 * @param client		Client index.
 * @param weapon		weapon entity name.
 * @param output		Buffer to store in.
 * @param maxlen		Maximum length of the buffer.
 */
stock	int		CS_GetClientWeaponName(int	client,	char[] weapon,	char[] output,	int maxlen)	{
	char	final[256];
	
	//Rifles
	if(StrEqual(weapon,	"weapon_ak47"))			{	final	=	"AK-47";					} //They talk about my 1taps, aiming is so easy
	if(StrEqual(weapon,	"weapon_m4a1_silencer")){	final	=	"M4A1 Silenced";			}
	if(StrEqual(weapon,	"weapon_galilar"))		{	final	=	"Galil Automatic Rifle";	}
	if(StrEqual(weapon,	"weapon_famas"))		{	final	=	"Famas";					}
	if(StrEqual(weapon,	"weapon_sg556"))		{	final	=	"Krieg SG556";				}
	if(StrEqual(weapon,	"weapon_sg552"))		{	final	=	"Krieg SG552";				}
	if(StrEqual(weapon,	"weapon_aug"))			{	final	=	"AUG";						}
	
	//Sub-Machine-Guns
	if(StrEqual(weapon,	"weapon_mp5sd"))		{	final	=	"MP5 Silenced";	}
	if(StrEqual(weapon,	"weapon_mp5navy"))		{	final	=	"MP5 Navy";		}
	if(StrEqual(weapon,	"weapon_mac10"))		{	final	=	"MAC-10";		}
	if(StrEqual(weapon,	"weapon_p90"))			{	final	=	"P90";			}	//Suka rush b fast no stop
	
	//Shotguns
	if(StrEqual(weapon,	"weapon_m3"))			{	final	=	"M3";			}
	if(StrEqual(weapon,	"weapon_xm1014"))		{	final	=	"XM1014";		}
	if(StrEqual(weapon,	"weapon_sawedoff"))		{	final	=	"Sawed-Off";	}
	if(StrEqual(weapon,	"weapon_mag7"))			{	final	=	"Mag-7";		}
	
	//Pistols
	if(StrEqual(weapon,	"weapon_deagle"))		{	final	=	"Desert Eagle";	}	//Aka Pocket AWP
	if(StrEqual(weapon,	"weapon_p250"))			{	final	=	"P250";			}
	if(StrEqual(weapon,	"weapon_p228"))			{	final	=	"P228";			}
	if(StrEqual(weapon,	"weapon_cz75a"))		{	final	=	"CZ75-Auto";	}
	if(StrEqual(weapon,	"weapon_glock"))		{	final	=	"Glock";		}	//Glawks
	if(StrEqual(weapon,	"weapon_hkp2000"))		{	final	=	"P2000";		}
	if(StrEqual(weapon,	"weapon_usp_silencer"))	{	final	=	"USP Silenced";	}
	if(StrEqual(weapon,	"weapon_usp"))			{	final	=	"USP";			}
	if(StrEqual(weapon,	"weapon_tec9"))			{	final	=	"Tec-9";		}	//Rush b fast no stop
	
	//Snipers
	if(StrEqual(weapon,	"weapon_awp"))			{	final	=	"AWP";			}
	if(StrEqual(weapon,	"weapon_ssg08"))		{	final	=	"SSG08 Scout";	}
	if(StrEqual(weapon,	"weapon_scout"))		{	final	=	"Scout";		}
	if(StrEqual(weapon,	"weapon_g3sg1"))		{	final	=	"G3SG1";		}
	if(StrEqual(weapon,	"weapon_scar20"))		{	final	=	"SCAR-20";		}
	
	//Machine Guns
	if(StrEqual(weapon,	"weapon_m249"))			{	final	=	"M249";			}
	if(StrEqual(weapon,	"weapon_negev"))		{	final	=	"Negev";		}	//Laser beam
	
	//Grenades
	if(StrEqual(weapon,	"weapon_hegrenade"))	{	final	=	"High-Explosive Grenade";	}
	if(StrEqual(weapon,	"weapon_flashgrenade"))	{	final	=	"Flashbang Grenade";		}
	if(StrEqual(weapon,	"weapon_smokegrenade"))	{	final	=	"Smoke Grenade";			}
	if(StrEqual(weapon,	"weapon_tacgrenade"))	{	final	=	"Tactical Grenade";			}
	if(StrEqual(weapon,	"weapon_incgrenade"))	{	final	=	"Incendiary Grenade";		}
	if(StrEqual(weapon,	"weapon_molotov"))		{	final	=	"Molotov Grenade";			}
	
	//Other
	if(StrEqual(weapon,	"weapon_zeus"))			{	final	=	"Zeus-X21";		}	//Ingame called X27 but model calls itself X21, volvo pls fix
	
	switch(GetEngineVersion())	{
		case	Engine_CSS:	{
			if(StrEqual(weapon,	"weapon_m4a1"))	{	final	=	"M4A4";		}
		}
		case	Engine_CSGO:	{
			if(StrEqual(weapon,	"weapon_m4a1"))	{	final	=	"M4A1";		}
		}
	}
	FormatEx(output,	sizeof(maxlen),	"%s",	final);
}


/**
 * Set the clients primary ammo
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	SetClientWeaponAmmo(int	client,	int	value)	{
	SetEntProp(GetClientActiveWeapon(client),	Prop_Send,	"m_iClip1",	value);
}

/**
 * Get the clients primary ammo
 *
 * @param client		Client index.
 */
stock	int		GetClientWeaponAmmo(int	client)	{
	return	GetEntProp(GetClientActiveWeapon(client),	Prop_Send,	"m_iClip1");
}

/**
 * Set the weapon reserve ammo
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	SetClientWeaponReserveAmmo(int	client,	int	value)	{
	SetEntProp(GetClientActiveWeapon(client),	Prop_Send,	"m_iPrimaryReserveAmmoCount",	value);
}

/**
 * Return the weapon reserve ammo
 *
 * @param client		Client index.
 */
stock	int		GetClientWeaponReserveAmmo(int	client)	{
	return	GetEntProp(GetClientActiveWeapon(client),	Prop_Send,	"m_iPrimaryReserveAmmoCount");
}

/**
 * Get the clients weapon entity name via slot
 *
 * @param client		Client index.
 * @param slot			Target slot.
 * @param output		Buffer to store the weapon entity name.
 * @param maxlen		The maximum length for the buffer.
 */
stock	int		GetClientWeaponEx(int	client,	int	slot,	char[]	output,	int maxlen)	{
	int	clientweapon	=	GetPlayerWeaponSlot(client,	slot);
	if(IsValidEdict(clientweapon))	{
		GetEdictClassname(clientweapon,	output,	sizeof(maxlen));
	}
}

/**
 * Give client a weapon and delete their slot & set primary and secondary ammo
 *
 * @param client		Client index.
 * @param weapon		Weapon entity name.
 * @param slot			Players slot to be removed.
 * @param primary		Amount of primary ammo for the weapon selected.
 * @param secondary		Amount of secondary ammo for the weapon selected.
 */
stock	void	GiveClientWeaponEx2(int	client,	char[] weapon,	int slot,	int primary,	int secondary)	{
	CS_ClientRemoveWeaponSlot(client,	slot);
	GivePlayerItem(client,	weapon);
	SetClientWeaponAmmo(client,	primary);
	SetClientWeaponReserveAmmo(client,	secondary);
}

/**
 * Give client a weapon and delete their current slot
 *
 * @param client		Client index.
 * @param weapon		Weapon entity name.
 * @param slot			Players slot to be removed.
 */
stock	void	GiveClientWeapon(int client, char[] weapon,	int	slot)	{
	CS_ClientRemoveWeaponSlot(client,	slot);
	GivePlayerItem(client,	weapon);
}


//Counter-Strike

/**
 * Gets a client's current team.
 *
 * @param client        Client index.
 * @return              Current TFTeam of client.
 * @error               Invalid client index.
 */
stock	CSTeam	CS_GetClientTeam(int client)	{
	return view_as<CSTeam>(GetClientTeam(client));
}

/**
 * Changes a client's current team.
 *
 * @param client        Client index.
 * @param team          CSTeam team symbol.
 * @error               Invalid client index.
 */
stock	void	CS_ChangeClientTeam(int client,	CSTeam team)	{
	ChangeClientTeam(client,	view_as<int>(team));
}

/**
 * Remove a clients weapon in a specified slot
 *
 *
 * @pragma client			Client index.
 * @pragma slot				Weapon slot.
 *
 * Slot 1 = Primary.
 * Slot 2 = Secondary.
 * Slot 3 = Knife/Melee.
 * Slot 4 = Grenade.
 * Slot 5 = Bomb.
 */
stock	void	CS_ClientDropWeaponSlot(int	client,	int	slot)	{
	int ent;
	switch(slot)	{
		case	1:	{
			if((ent =	GetPlayerWeaponSlot(client,	CS_SLOT_PRIMARY))	!= -1)
				CS_DropWeapon(client,	ent,	true,	true);
		}
		case	2:	{
			if((ent =	GetPlayerWeaponSlot(client,	CS_SLOT_SECONDARY))	!= -1)
				CS_DropWeapon(client,	ent,	true,	true);
		}
		case	3:	{
			if((ent =	GetPlayerWeaponSlot(client,	CS_SLOT_KNIFE))		!= -1)
				CS_DropWeapon(client,	ent,	true,	true);
		}
		case	4:	{
			if((ent	=	GetPlayerWeaponSlot(client,	CS_SLOT_GRENADE))	!=	-1)
				CS_DropWeapon(client,	ent,	true,	true);
		}
		case	5:	{
			if((ent =	GetPlayerWeaponSlot(client,	CS_SLOT_C4))		!= -1)
				CS_DropWeapon(client,	ent,	true,	true);
		}
	}
}

/**
 * Remove a clients weapon in a specified slot
 *
 *
 * @pragma client			Client index.
 * @pragma slot				Weapon slot.
 *
 */
stock	void	CS_ClientRemoveWeaponSlot(int	client,	int	slot)	{
	int ent;
	switch(slot)	{
		case	1:	{
			if((ent =	GetPlayerWeaponSlot(client,	CS_SLOT_PRIMARY))	!= -1)	{
				RemovePlayerItem(client, ent);
				RemoveEdict(ent);
			}
		}
		case	2:	{
			if((ent =	GetPlayerWeaponSlot(client,	CS_SLOT_SECONDARY))	!= -1)	{
				RemovePlayerItem(client, ent);
				RemoveEdict(ent);
			}
		}
		case	3:	{
			if((ent =	GetPlayerWeaponSlot(client,	CS_SLOT_KNIFE))	!= -1)		{
				RemovePlayerItem(client, ent);
				RemoveEdict(ent);
			}
		}
		case	4:	{
			if((ent =	GetPlayerWeaponSlot(client,	CS_SLOT_GRENADE))	!= -1)		{
				RemovePlayerItem(client, ent);
				RemoveEdict(ent);
			}
		}
		case	5:	{
			if((ent =	GetPlayerWeaponSlot(client,	CS_SLOT_C4))	!= -1)		{
				RemovePlayerItem(client, ent);
				RemoveEdict(ent);
			}
		}
	}
}

/**
 * Gets the clients map navigation location name
 *
 * @param client		Client index.
 * @param location		Buffer to store the location name.
 * @param len			Size of the buffer.
 *
 */
stock	int	CS_GetClientNavLocation(int client,	char[] location,	int	maxlen)	{
	char	storage[256];
	GetEntPropString(client,	Prop_Send,	"m_szLastPlaceName",	storage,	sizeof(storage));
	
	if(StrEqual(storage,	"BombsiteA"))
		FormatEx(location,	sizeof(maxlen),	"Bombsite A");
	else if(StrEqual(storage,	"BombsiteB"))
		FormatEx(location,	sizeof(maxlen),	"Bombsite B");
	else if(StrEqual(storage,	"BombsiteC"))
		FormatEx(location,	sizeof(maxlen),	"Bombsite C");
	else
		FormatEx(location,	sizeof(maxlen),	"%s",	storage);
}

//Gets the clients last place via the maps navigation area (such as Bombsite A or Bombsite B)
stock	int		CS_GetClientLastPlace(int client,	char[] output,	int maxlen)	{
	GetEntPropString(client,	Prop_Send,	"m_szLastPlaceName",	output,	sizeof(maxlen));
}

/**
 * Sets the clients current account/cash/money balance
 *
 * @param client        Client index.
 * @param value			Amount value.
 */
stock	void	CS_SetClientMoney(int client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_iAccount",	value);	
}

/**
 * Returns the clients current account/cash/money balance
 *
 * @param client        Client index.
 */
stock	int		CS_GetClientMoney(int client)	{
	return	GetEntProp(client,	Prop_Send,	"m_iAccount");
}

/**
 * Returns if the warmup is currently ongoing
 *
 */
stock	int		CS_IsWarmupRound()	{
	if(GameRules_GetProp("m_bWarmupPeriod")	==	1)
		return true;
	return false;
}

/**
 * Returns if the match is currently paused/is in freezetime
 *
 */
stock	int		CS_IsMatchPaused()	{
	if(GameRules_GetProp("m_bMatchWaitingForResume") ==	1)
		return true;
	return false;
}

//Set the clients flash duration, 0.0 or 0 is basically disabled
/**
 * Set the clients flash duration, 0.0 or 0 is basically disabled
 *
 * @param client		Client index.
 * @param value			Float value.
 */
stock	void	CS_SetClientFlashDuration(int	client,	float value)	{
	SetEntPropFloat(client,	Prop_Send,	"m_flFlashDuration",	value);
}

/**
 * Get the clients flash duration
 *
 * @param client		Client index.
 */
stock	int		CS_GetClientFlashDuration(int	client)	{
	return	GetEntPropFloat(client,	Prop_Send,	"m_flFlashDuration");
}

//Team Fortress

//Set the clients mvm currency/cash
/**
 * Set the clients mvm currency
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	TF2_SetClientMvMCash(int	client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_nCurrency",	value);
}

/**
 * Get the clients mvm currency/cash
 *
 * @param client		Client index.
 */
stock	int		TF2_GetClientMvMCash(int	client)	{
	return	GetEntProp(client,	Prop_Send,	"m_nCurrency");
}


//Set the clients taunt cam on/off, useful for thirdperson plugin
/**
 * Set the clients taunt cam
 *
 * @param client		Client index.
 * @param value			Bool value.
 */
stock	void	TF2_SetClientTauntCam(int	client,	bool value)	{
	SetEntProp(client,	Prop_Send,	"m_nForceTauntCam",	value);
}

/**
 * Get the clients taunt cam
 *
 * @param client		Client index.
 */
stock	int		TF2_GetClientTauntCam(int	client)	{
	return	GetEntProp(client,	Prop_Send,	"m_nForceTauntCam");
}

//Set the clients killstreak count
/**
 * Set the clients killstreak count
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock	void	TF2_SetClientKillstreak(int	client,	int	value)	{
	SetEntProp(client,	Prop_Send,	"m_nStreaks",	value);
}

/**
 * Get the clients killstreak count
 *
 * @param client		Client index.
 */
stock	int	TF2_GetClientKillstreak(int	client)	{
	return	SetEntProp(client,	Prop_Send,	"m_nStreaks");
}