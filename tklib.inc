/*****************************************\
 *			Tk Libraries (Tklib)		 *
 *										 *
 * 		Made by Tk /id/Teamkiller324	 *
 *										 *
 *				Version 1.1.2			 *
\*****************************************/

//Changelogs

// - Version 1.1.0
// + Fixed Set weapon ammo being only at 0.
// + Updated the code lines to be not filled with tab spaces.
// + Added numerous new set/change functions.
// + Added checks to return error if the client is invalid.

// - Version 1.1.1
// + Added Day of Defeat: Source
// + Added TFFlag event type support (Events related to example picking up, defending, capturing and dropping intelligence in tf2.)
// + Updated some enum structures to better match the existing ones.

// - Version 1.1.2
// + Added Get & Set client lifestate function.
// + Added TFFlag_Carrier to TFFlag enum structure.
// + Few other changes on some functions.

// - Version 1.2.0
// + Updated name to Tk Libraries from Tk Include.
// + More stuff added in /additionals subinclude.
// + Added CSGORank enum, making it easier to handle ranks.
// + Added CSGO_SetWeaponSkin and CSGO_GetWeaponSkin to get or set the clients current skin of their weapon.
// + Added CSGO_SetWeaponStatTrak and CSGO_SetWeaponStatTrak to get or set clients current stattrak of their weapon.
// + Added CSGO_SetWeaponOwner to set the owner of the weapon as the client specified.
// + Added CSGO_SetWeaponQuality to set the quality of the weapon. By default (3) adds a star to the weapon name.
// + Added CSGO_SetWeaponNametag and CSGO_GetWeaponNametag to set or get the clients current name of their weapon.
// + Added CSGO_SetCompetitiveOffset and CSGO_GetCompetitiveOffset to set or get the clients competitive offsets. Useful for the plugins that sets custom ranks.
// + Added CSGO_SetCompetitiveType and CSGO_GetCompetitiveType to set or get the clients competitive types. Also useful for the plugins that sets custom ranks.
// + Added CSGO_SetArmModel to be easier to set the model of the players arm.
// + Added EquipPlayerWeaponEx as alternative option to EquipPlayerWeapon. Fixes issues regarding EquipPlayerWeapon when it comes to spawning weapons. (Credit to bacardi for part of the code.)
// + Added GetEntityName to get the entitys name.
// + Added SetEntityName to set the entitys name.
// + Added FindEntity to return true or false wheter the entity by classname exists in the current map.
// + Added CreateEntityByNameEx which does same functionality as CreateEntityByNameEx but it has additional string to put in the entitys custom name you specify.
// + Added SetEntityDisabled if the entity you target should start disabled or not as a boolean. true/false statement.
// + Added GetEntityModel as easier method to return the model of the entity.
// + Added GetClientAuth which is same as GetClientAuthId but it functions similiarly to GetClientAuthString.

//TF2 Flag Event
enum
{
	TFFlag_PickedUp	=	1,
	TFFlag_Defended	=	2,
	TFFlag_Captured	=	3,
	TFFlag_Dropped	=	4,
	TFFlag_Carrier	=	5
}

//TF Slots
enum	TFSlot
{
	TFSlot_Primary	=	0,
	TFSlot_Secondary=	1,
	TFSlot_Melee	=	2,
	TFSlot_PDA		=	3,
	TFSlot_PDA2		=	4
}

//CS Slots
enum	CSSlot
{
	CSSlot_Primary	=	0,
	CSSlot_Secondary=	1,
	CSSlot_Knife	=	2,
	CSSlot_Grenade	=	3,
	CSSlot_C4		=	4
}

enum	CSWeaponType
{
	CSWeaponType_Unknown	=	-1,
	CSWeaponType_Knife		=	0,
	CSWeaponType_Pistol		=	1,
	CSWeaponType_SMG		=	2,
	CSWeaponType_Rifle		=	3,
	CSWeaponType_Shotgun	=	4,
	CSWeaponType_Sniper		=	5,
	CSWeaponType_MachineGun	=	6,
	CSWeaponType_C4			=	7,
	CSWeaponType_Taser		=	8,
	CSWeaponType_Grenade	=	9,
	CSWeaponType_Healthshot	=	11
}

//I made this because TFTeam enum exists and cs doesn't have it :)
enum	CSTeam
{
	CSTeam_Unassigned	=	0,
	CSTeam_Spectator	=	1,
	CSTeam_Terrorist	=	2,
	CSTeam_CTerrorist	=	3
}

//Left 4 Dead 2 enum
enum	L4DTeam
{
	L4DTeam_Unassigned	=	0,
	L4DTeam_Spectator	=	1,
	L4DTeam_Survivor	=	2,
	L4DTeam_Zombie		=	3
}

//Day of Defeat: Source enum
enum	DODTeam
{
	DODTeam_Unassigned	=	0,
	DODTeam_Spectator	=	1,
	DODTeam_Red			=	2,
	DODTeam_Blue		=	3
}

//SM Includes
#include	<sdktools>
#include	<sdkhooks>
#undef		REQUIRE_EXTENSIONS
#include	<cstrike>
#include	<tf2_stocks>

//Core includes
#include	"tklib/additional"

#define		CONSOLE		0
#define		TK_Include_Version	"1.1.2"

//Get the team name via strings for colored chat purpose (Usage example: TF2_GetTeamStringName[GetClientTeam(client)] will return the correct team name)
stock	char	TF2_GetTeamStringName[][128]	=	{
	"{grey}Unassigned",
	"{grey}Spectators",
	"{red}Red",
	"{blue}Blue",
	"{lightgreen}Green",
	"{orange}Yellow"
},
		CSS_GetTeamStringName[][128]	=	{
	"{grey}Unassigned",
	"{grey}Spectators",
	"{red}Terrorists",
	"{blue}Counter-Terrorists"
},
		CSGO_GetTeamStringName[][128]	=	{
	"{grey}Unassigned",
	"{grey}Spectators",
	"{orange}Terrorists",
	"{bluegrey}Counter-Terrorists"
},
		L4D_GetTeamStringName[][128]	=	{
	"{grey}Unassigned",
	"{grey}Spectators",
	"{orange}Survivors",
	"{lightred}Zombies"
};

/**
 * Returns if the client actually exists.
 *
 * @param client		Client index.
 */
stock bool ClientExists(int client)	{
	if(client < 1 || client > MaxClients)
		return	false;
	return	true;
}

//Player permissions
/**
 * Returns if the client is a Console
 *
 * @param client		Client index.
 */
stock	bool	IsClientConsole(int client)	{	
	if(client == 0)
		return true;
	return	false;
}

/**
 * Returns if the client is a bot
 *
 * @param client		Client index.
 */
stock bool IsClientBot(int client)	{	
	if(IsFakeClient(client))
		return	true;
	return	false;
}

/**
 * Returns if the client is an Owner
 *
 * @param client		Client index.
 */
stock bool IsClientOwner(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	if(!CheckCommandAccess(client,	"owner_flag",	ADMFLAG_ROOT,	false))
		return false;
	return	true;
}

/**
 * Returns if the client is an Admin
 *
 * @param client		Client index.
 */
stock bool IsClientAdmin(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	if(!CheckCommandAccess(client,	"admin_flag",	ADMFLAG_GENERIC,	false))
		return false;
	return	true;
}

/**
 * Returns if the client is a Moderator
 *
 * @param client		Client index.
 */
stock bool IsClientModerator(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	if(!CheckCommandAccess(client,	"moderator_flag",	ADMFLAG_CUSTOM1,	false))
		return false;
	return	true;
}

/**
 * Returns if the client is a Vip
 *
 * @param client		Client index.
 */
stock bool IsClientVip(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	if(!CheckCommandAccess(client,	"vip_flag",	ADMFLAG_RESERVATION,	false))
		return false;
	return	true;
}

/**
 * Returns if the client is has the specified flag
 *
 * @param client		Client index.
 * @param adminflags	Administrative flags (bitstring) to use for permissions.
 */
stock bool IsClientFlag(int client, int adminflags)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	if(!CheckCommandAccess(client,	"",	adminflags,	false))
		return	false;
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
stock void SetClientCookieInt(int client, Handle cookie, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	char	item[1024];
	IntToString(value,	item,	sizeof(item));
	SetClientCookie(client,	cookie, item);
}

//Ping
/**
 * Set the clients scoreboard ping
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock void SetClientPing(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_iPing",	value);
}

/**
 * Get the clients scoreboard ping
 *
 * @param client		Client index.
 */
stock int GetClientPing(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(GetPlayerResourceEntity(), Prop_Send, "m_iPing", _, client);
}

//Set & Get Death count
/**
 * Set the clients death count
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock void SetClientDeaths(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_iDeaths",	value);
}

//Set & Get Frag count
/**
 * Set the clients frag count
 *
 * @param client		Client index.
 * @param value			Amount index.
 */
stock void SetClientFrags(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_iFrags",		value);
}

//Set & Get Health point
/**
 * Set the clients max health
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock void SetClientHealth(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_iHealth",	value);
}

/**
 * Set the clients max health
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock int SetClientMaxHealth(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Data,	"m_iMaxHealth",	value);
}

/**
 * Get the clients max health
 *
 * @param client		Client index.
 */
stock int GetClientMaxHealth(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(client,	Prop_Data,	"m_iMaxHealth");
}

//Set & Get Team index number
/**
 * Set the clients team index number called from the game itself
 *
 * @param client		Client index.
 * @param value			Team index value.
 */
stock void SetClientTeamNum(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_iTeamNum",	value);
}

/**
 * Get the clients team index number called from the game itself
 *
 * @param client		Client index.
 */
stock int GetClientTeamNum(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(client,	Prop_Send,	"m_iTeamNum");
}

//Set & Get FOV || Field-Of-View
/**
 * Set the clients fov
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock void SetClientFOV(int client, int value)	{
	SetEntProp(client,	Prop_Send,	"m_iFOV",	value);
}

/**
 * Get the clients fov
 *
 * @param client		Client index.
 */
stock int GetClientFOV(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(client,	Prop_Send,	"m_iFOV");
}

/**
 * Set the clients default fov
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock void SetClientDefaultFOV(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_iDefaultFOV",	value);
}

/**
 * Get the clients default fov
 *
 * @param client		Client index.
 */
stock int GetClientDefaultFOV(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(client,	Prop_Send,	"m_iDefaultFOV");
}

//Set Observer Mode on client
/**
 * Set the clients Observer target
 *
 * @param client 		Client index.
 * @param value			Amount value.
 */
stock void SetClientObserverTarget(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_iObserverTarget",	value);
}

/**
 * Set the clients Observer mode
 *
 * @param client		Client index.
 * @param value			Bool value.
 */
stock void SetClientObserverMode(int client, bool value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_iObserverMode",		value);
}

//Clients viewmodel
/**
 * Set the clients drawviewmodel value
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock void SetClientDrawViewModel(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_bDrawViewmodel",	value);
}

/**
 * Get the clients drawviewmodel value
 *
 * @param client		Client index.
 */
stock int GetClientDrawViewModel(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	SetEntProp(client,	Prop_Send,	"m_bDrawViewmodel");
}

//Godmode stuff

/**
 * Set the clients godmode
 *
 * @param client		Client index.
 * @param godmode		Bool value.
 */
stock void SetClientGodMode(int client, bool godmode)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	switch(godmode)	{
		case	true:	SetEntProp(client,	Prop_Send,	"m_takedamage",	0,	1);
		case	false:	SetEntProp(client,	Prop_Send,	"m_takedamage",	2,	1);
	}
}


/**
 * Get the clients godmode value.
 *
 * @param client		Client index.
 */
stock bool GetClientGodmode(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	if(GetEntProp(client,	Prop_Send,	"m_takedamage",	0,	1) == 1)
		return	true;
	return	false;
}

/**
 * Set the clients buddha mode
 *
 * @param client		Client index.
 * @param buddha		Bool value.
 */
stock void SetClientBuddhaMode(int client, bool buddha)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	switch(buddha)	{
		case	true:	SetEntProp(client,	Prop_Send,	"m_takedamage",	1,	1);
		case	false:	SetEntProp(client,	Prop_Send,	"m_takedamage",	2,	1);
	}
}

/**
 * Get the clients buddha mode
 *
 * @param client		Client index.
 */
stock bool GetClientBuddhaMode(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	if(GetEntProp(client,	Prop_Send,	"m_takedamage",	1,	1) == 1)
		return	true;
	return	false;
}

//Clients collision
/**
 * Set the clients collision
 *
 * @param client		Client index.
 * @param collision		Bool value.
 */
stock void	SetClientCollision(int client, bool collision)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	int	block	=	FindSendPropInfo("CBaseEntity", "m_CollisionGroup");
	switch(collision)	{
		case	true:	SetEntData(client,	block,	2,	4);
		case	false:	SetEntData(client,	block,	5,	4);
	}
}

/**
 * Get the clients collision
 *
 * @param client		Client index.
 * @param collision		Bool value.
 */
stock bool GetClientCollision(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	int	block	=	FindSendPropInfo("CBaseEntity", "m_CollisionGroup");
	if(GetEntData(client,	block,	2,	4) == 1)
		return	true;
	return	false;
}

//Noclip toggle
/**
 * Set the client noclip on/off
 *
 * @param client		Client index.
 * @param noclip		Bool value.
 */
stock void SetClientNoclip(int client, bool noclip)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	switch(noclip)	{
		case	true:	SetEntityMoveType(client,	MOVETYPE_NOCLIP);
		case	false:	SetEntityMoveType(client,	MOVETYPE_WALK);
	}
}

//Clients max speed

/**
 * Set the clients max speed
 *
 * @param client		Client index.
 * @param value			Float amount value.
 */
stock float SetClientMaxSpeed(int client, float value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntPropFloat(client,	Prop_Send,	"m_flMaxspeed",	value);
}

/**
 * Get the clients max speed
 *
 * @param client		Client index.
 */
stock float GetClientMaxSpeed(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntPropFloat(client,	Prop_Send,	"m_flMaxspeed");
}

//Comms

/**
 * Returns if the client is muted.
 *
 * @param client		Client index
 * @param error			Invalid client index.
 */
stock void IsClientMutedEx(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	if(GetClientListeningFlags(client) == VOICE_NORMAL)
		return	false;
	return	true;
}

/**
 * Set if the client should be muted or not.
 *
 * @param client		Client index.
 * @param mute			True/False statement.
 * @param error			Invalid error.
 */
stock void SetClientMute(int client, int mute)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	switch(mute)	{
		case	true:	SetClientListeningFlags(client, VOICE_MUTED);
		case	false:	SetClientListeningFlags(client,	VOICE_NORMAL);
	}
}

/**
 * Slay the client.
 *
 * @param client		Client index.
 * @param randomdeath	Should death be random. (Should be used in games where is supported)
 * @error				Invalid client index.
 */
stock void SlayPlayer(int client, bool RandomDeath=false)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	char	death[][] = {
		"kill",
		"explode"
	};
	
	switch(RandomDeath)	{
		case	true:	FakeClientCommandEx(client, death[GetRandomInt(0, 1)]);
		case	false:	FakeClientCommandEx(client, death[0]);
	}
}

/**
 *	Get the weapon definition index value
 *
 *	@param weapon		Weapon entity.
 */
stock int GetWeaponDefinitionIndex(int weapon)	{
	return	GetEntProp(weapon, Prop_Send, "m_iItemDefinitionIndex");
}

/**
 *	Get the clients lifestate.
 *
 *	@param client		Client index.
 *	@error				Invalid client index.
 */
stock int GetClientLifestate(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return GetEntProp(client, Prop_Send, "m_lifeState");
}

/**
 *	Set the clients lifestate.
 *
 *	@param client		Client index.
 *	@param value		Lifestate value.
 *	@error				Invalid client index.
 */
stock void SetClientLifestate(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client, Prop_Send, "m_lifeState", value);
}

//Respawning

//Set the respawn time for the specified client

/**
 * Set the client to respawn in specified time
 *
 * @param client		Client index.
 * @param value			Float amount value.
 */
stock float RespawnTime(int client, float value)	{
	CreateTimer(value,	SetRespawnTime,	client);
}

//forwards the action to the respawn event
stock	Action	SetRespawnTime(Handle timer, any client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	Respawn(client);
}

/**
 * Respawn a client
 *
 * @param client		Client index.
 */
stock	Action	Respawn(int client)	{
	//Checks if client exists or is invalid
	if(!ClientExists(client))	{
		return	Plugin_Handled;
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
 *	Get the clients current active weapon.
 *
 *	@param client		Client index.
 */
stock int GetClientActiveWeapon(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntPropEnt(client,	Prop_Send,	"m_hActiveWeapon");
}

/**
 *	Set the clients current active weapon.
 *
 *	@param client		Client index.
 *	@param slot			Client slot.
 *	@error				Invalid client index.
 *	@error				Invalid weapon entity.
 */
stock void SetClientActiveWeapon(int client, int slot)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntPropEnt(client,	Prop_Send,	"m_hActiveWeapon", slot);
}

/**
 * Get the actual name of the clients weapon entity
 *
 * @param weapon		weapon entity name.
 * @param name			Buffer to store in.
 * @param maxlen		Maximum length of the buffer.
 */
stock int CS_GetWeaponName(char[] weapon, char[] output, int maxlen)	{
	//Rifles
	if(StrEqual(weapon,	"weapon_ak47"))	//They talk about my 1taps, aiming is so easy
		strcopy(output, maxlen, "AK-47");
	if(StrEqual(weapon,	"weapon_m4a1_silencer"))
		strcopy(output, maxlen, "M4A1 Silenced");
	if(StrEqual(weapon,	"weapon_galilar"))
		strcopy(output, maxlen, "Galil Automatic Rifle");
	if(StrEqual(weapon,	"weapon_famas"))
		strcopy(output, maxlen, "Famas");
	if(StrEqual(weapon,	"weapon_sg556"))
		strcopy(output, maxlen, "Krieg SG556");
	if(StrEqual(weapon,	"weapon_sg552"))
		strcopy(output, maxlen, "Krieg SG552");
	if(StrEqual(weapon,	"weapon_aug"))
		strcopy(output, maxlen, "AUG");
	
	//Sub-Machine-Guns
	if(StrEqual(weapon,	"weapon_mp5sd"))
		strcopy(output, maxlen, "MP5 Silenced");
	if(StrEqual(weapon,	"weapon_mp5navy"))
		strcopy(output, maxlen, "MP5 Navy");
	if(StrEqual(weapon,	"weapon_mac10"))
		strcopy(output, maxlen, "MAC-10");
	if(StrEqual(weapon,	"weapon_p90"))	//Suka rush b fast no stop
		strcopy(output, maxlen, "P90");
	
	//Shotguns
	if(StrEqual(weapon,	"weapon_m3"))
		strcopy(output, maxlen, "M3");
	if(StrEqual(weapon,	"weapon_xm1014"))
		strcopy(output, maxlen, "XM1014");
	if(StrEqual(weapon,	"weapon_sawedoff"))
		strcopy(output, maxlen, "Sawed-Off");
	if(StrEqual(weapon,	"weapon_mag7"))
		strcopy(output, maxlen, "Mag-7");
	
	//Pistols
	if(StrEqual(weapon,	"weapon_deagle"))	//Aka Pocket AWP
		strcopy(output, maxlen, "Desert Eagle");
	if(StrEqual(weapon,	"weapon_p250"))
		strcopy(output, maxlen, "P250");
	if(StrEqual(weapon,	"weapon_p228"))
		strcopy(output, maxlen, "P228");
	if(StrEqual(weapon,	"weapon_cz75a"))	//Used to be known as pocket-ak47 in 2016-2018
		strcopy(output, maxlen, "CZ75-Auto");
	if(StrEqual(weapon,	"weapon_glock"))	//Glawks (Reference to GoDaZeD if you remember him)
		strcopy(output, maxlen "Glock");
	if(StrEqual(weapon,	"weapon_hkp2000"))
		strcopy(output, maxlen, "P2000");
	if(StrEqual(weapon,	"weapon_usp_silencer"))
		strcopy(output, maxlen, "USP Silenced");
	if(StrEqual(weapon,	"weapon_usp"))
		strcopy(output, maxlen, "USP");
	if(StrEqual(weapon,	"weapon_tec9"))	//Rush b fast no stop
		strcopy(output, maxlen, "Tec-9");
	
	//Snipers
	if(StrEqual(weapon,	"weapon_awp"))
		strcopy(output, maxlen, "AWP");
	if(StrEqual(weapon,	"weapon_ssg08"))	//Oldschool jumping scout ftw
		strcopy(output, maxlen, "SSG08 Scout");
	if(StrEqual(weapon,	"weapon_scout"))
		strcopy(output, maxlen, "Scout");
	if(StrEqual(weapon,	"weapon_g3sg1"))
		strcopy(output, maxlen, "G3SG1");
	if(StrEqual(weapon,	"weapon_scar20"))
		strcopy(output, maxlen, "SCAR-20");
	
	//Machine Guns
	if(StrEqual(weapon,	"weapon_m249"))
		strcopy(output, maxlen, "M249");
	if(StrEqual(weapon,	"weapon_negev"))	//Laser beam
		strcopy(output, maxlen, "Negev");
	
	//Grenades
	if(StrEqual(weapon,	"weapon_hegrenade"))
		strcopy(output, maxlen, "High-Explosive Grenade");
	if(StrEqual(weapon,	"weapon_flashgrenade"))
		strcopy(output, maxlen, "Flashbang Grenade");
	if(StrEqual(weapon,	"weapon_smokegrenade"))
		strcopy(output, maxlen,	"Smoke Grenade");
	if(StrEqual(weapon,	"weapon_tacgrenade"))
		strcopy(output, maxlen, "Tactical Grenade");
	if(StrEqual(weapon,	"weapon_incgrenade"))
		strcopy(output, maxlen, "Incendiary Grenade");
	if(StrEqual(weapon,	"weapon_molotov"))
		strcopy(output, maxlen, "Molotov Grenade");
	
	//Other
	if(StrEqual(weapon,	"weapon_zeus"))	//Ingame called X27 but model calls itself X21, volvo pls fix
		strcopy(output, maxlen, "Zeus-X21");
	
	switch(GetEngineVersion())	{
		case	Engine_CSS:		if(StrEqual(weapon,	"weapon_m4a1"))	strcopy(output, len, "M4A4");
		case	Engine_CSGO:	if(StrEqual(weapon,	"weapon_m4a1"))	strcopy(output, len, "M4A1");
	}
}


/**
 * Set the clients primary ammo
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock void SetClientWeaponAmmo(int client, int value)	{
	SetEntProp(GetClientActiveWeapon(client),	Prop_Send,	"m_iClip1",	value);
}

/**
 *	Set the clients primary and secondary ammo.
 *
 *	@param client		Client index.
 *	@param primary		Primary ammo amount.
 *	@param secondary	Secondary ammo amount.
 */
stock void SetClientWeaponAmmoEx(int client, int primary, int secondary)	{
	if(primary != 0)
		SetEntProp(GetClientActiveWeapon(client), Prop_Send, "m_iClip1", primary);
	if(secondary != 0)
		SetEntProp(GetClientActiveWeapon(client), Prop_Send, "m_iPrimaryReserveAmmoCount", secondary);
}

/**
 * Set the weapon primary ammo
 *
 * @param weapon		Weapon entity.
 * @param value			Amount value.
 */
stock void SetWeaponAmmo(int weapon, int value)	{
	SetEntProp(weapon, Prop_Send, "m_iClip1", value);
}

/**
 *	Set the weapon primary and secondary ammo.
 *
 *	@param weapon		Weapon entity.
 *	@param primary		Primary ammo amount. Zero amount input will do nothing.
 *	@param secondary	Secondary ammo amount. Zero amount input will do nothing.
 */
stock void SetWeaponAmmoEx(int weapon, int primary, int secondary)	{
	if(primary > 0)
		SetEntProp(weapon, Prop_Send, "m_iClip1", primary);
	if(secondary > 0)
		SetEntProp(weapon, Prop_Send, "m_iPrimaryReserveAmmoCount", secondary);
}

/**
 * Get the weapon primary ammo
 *
 * @param weapon		Weapon entity.
 */
stock int GetWeaponAmmo(int weapon)	{
	return GetEntProp(weapon, Prop_Send, "m_iClip1");
}

/**
 * Get the clients primary ammo
 *
 * @param client		Client index.
 */
stock int GetClientWeaponAmmo(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(GetClientActiveWeapon(client), Prop_Send, "m_iClip1");
}

/**
 * Set the weapon reserve ammo
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock void SetClientWeaponReserveAmmo(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(GetClientActiveWeapon(client), Prop_Send, "m_iPrimaryReserveAmmoCount", value);
}

/**
 * Set the weapon reserve ammo
 *
 * @param weapon		Weapon entity.
 * @param value			Amount value.
 */
stock void SetWeaponReserveAmmo(int weapon, int value)	{
	if(!IsValidEdict(weapon))
		ThrowError("Weapon entity %d is invalid",	weapon);
	
	SetEntProp(weapon, Prop_Send, "m_iPrimaryReserveAmmoCount", value);
}

/**
 * Return the weapon reserve ammo
 *
 * @param weapon		Weapon entity.
 */
stock int GetWeaponReserveAmmo(int weapon)	{
	if(!IsValidEdit(weapon))
		ThrowError("Weapon entity %d is invalid",	weapon);
	
	return	GetEntProp(weapon,	Prop_Send,	"m_iPrimaryReserveAmmoCount");
}

/**
 * Return the weapon reserve ammo
 *
 * @param client		Client index.
 */
stock int GetClientWeaponReserveAmmo(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(GetClientActiveWeapon(client),	Prop_Send,	"m_iPrimaryReserveAmmoCount");
}

/**
 * Get the clients weapon entity name via slot
 *
 * @param client		Client index.
 * @param slot			Target CSSlot slot.
 * @param output		Buffer to store the weapon entity name.
 * @param maxlen		The maximum length for the buffer.
 */
stock int CS_GetClientWeaponEx(int client, CSSlot slot, char[] output, int maxlen)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	int	clientweapon	=	CS_GetPlayerWeaponSlot(client,	slot);
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
stock void CS_GiveClientWeaponEx2(int client, char[] weapon, CSSlot slot, int primary, int secondary)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	CS_ClientRemoveWeaponSlot(client, slot);
	GivePlayerItem(client,	weapon);
	if(primary > 0)
		SetClientWeaponAmmo(client,	primary);
	if(secondary > 0)
		SetClientWeaponReserveAmmo(client,	secondary);
}

/**
 * Give client a weapon and delete their current slot
 *
 * @param client		Client index.
 * @param weapon		Weapon entity name.
 * @param slot			Players slot to be removed.
 */
stock void CS_GiveClientWeapon(int client, char[] weapon, CSSlot slot)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	CS_ClientRemoveWeaponSlot(client,	slot);
	GivePlayerItem(client,	weapon);
}


//Counter-Strike

/**
 * Return the clients weapon entity.
 *
 * @param client		Client index.
 * @param slot			CSSlot value.
 */
stock int CS_GetPlayerWeaponSlot(int client, CSSlot slot)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
		
	return	GetPlayerWeaponSlot(client, view_as<int>(slot));
} 

/**
 * Return if the weapon is in silenced mode.
 *
 * @param weapon		Weapon entity.
*/
stock bool CS_IsWeaponSilenced(int weapon)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	if(!IsValidEdict(weapon) || weapon == -1)
		ThrowError("Weapon entity %d is invalid",	weapon);
		
	return	GetEntProp(weapon,	Prop_Data,	"m_bSilencerOn");
}

/**
 * Set the sniper scope level.
 *
 * @param weapon		Weapon entity.
 * @param value			Value amount.
 */
stock int CS_SetSniperZoomLevel(int weapon, int value)	{
	if(!IsValidEdict(weapon))
		ThrowError("Weapon entity %d is invalid",	weapon);
	
	if(value < 0)
		ThrowError("Zoom level cannot be lower than 0");
	if(value > 2)
		ThrowError("Zoom level cannot be greater than 2");
	
	SetEntProp(weapon,	Prop_Send,	"m_zoomLevel",	value);
}

/**
 * Return the sniper scope level.
 *
 * @param weapon		Weapon entity.
 */
stock int CS_GetSniperZoomLevel(int weapon)	{
	if(!IsValidEdict(weapon))
		ThrowError("Weapon entity %d is invalid",	weapon);
	
	return	GetEntProp(weapon,	Prop_Send,	"m_zoomLevel");
}

/**
 * Gets a client's current team.
 *
 * @param client        Client index.
 * @return              Current TFTeam of client.
 * @error               Invalid client index.
 */
stock CSTeam CS_GetClientTeam(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	view_as<CSTeam>(GetClientTeam(client));
}

/**
 * Changes a client's current team.
 *
 * @param client        Client index.
 * @param team          CSTeam team symbol.
 * @error               Invalid client index.
 */
stock void CS_ChangeClientTeam(int client, CSTeam team)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	ChangeClientTeam(client,	view_as<int>(team));
}

/**
 * Get the teams client count.
 *
 * @param team			CSTeam team.
 * @error error			Invalid team.
 */
stock int CS_GetTeamClientCount(CSTeam team)	{
	return	GetTeamClientCount(view_as<int>(team));
}

/**
 * Remove a clients weapon in a specified slot
 *
 *
 * @pragma client			Client index.
 * @pragma slot				CSSlot slot.
 *
 * Slot 1 = Primary.
 * Slot 2 = Secondary.
 * Slot 3 = Knife/Melee.
 * Slot 4 = Grenade.
 * Slot 5 = Bomb.
 */
stock void CS_ClientDropWeaponSlot(int client, CSSlot slot)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	int weapon;
	if((weapon = CS_GetPlayerWeaponSlot(client,	slot)) != -1)
		CS_DropWeapon(client, weapon, true, true);
	else return;
}

/**
 * Remove a clients weapon in a specified slot
 *
 *
 * @pragma client			Client index.
 * @pragma slot				CSSlot weapon slot.
 *
 * Slots:
 * 1 = Primary
 * 2 = Secondary
 * 3 = Melee
 * 4 = Grenade
 * 5 = Bomb
 */
stock void CS_ClientRemoveWeaponSlot(int client, CSSlot slot)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	int weapon;
	if((weapon = CS_GetPlayerWeaponSlot(client,	slot)) != -1)	{
		RemovePlayerItem(client, weapon);
		RemoveEdict(weapon)
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
stock int CS_GetClientNavLocation(int client, char[] location, int maxlen)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
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
stock int CS_GetClientLastPlace(int client, char[] output, int maxlen)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	GetEntPropString(client,	Prop_Send,	"m_szLastPlaceName",	output,	sizeof(maxlen));
}

/**
 * Sets the clients current account/cash/money balance
 *
 * @param client        Client index.
 * @param value			Amount value.
 */
stock void CS_SetClientMoney(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_iAccount",	value);	
}

/**
 * Returns the clients current account/cash/money balance
 *
 * @param client        Client index.
 */
stock int CS_GetClientMoney(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(client,	Prop_Send,	"m_iAccount");
}

/**
 * Returns if the warmup is currently ongoing
 *
 */
stock int CS_IsWarmupRound()	{
	if(GameRules_GetProp("m_bWarmupPeriod")	==	1)
		return true;
	return false;
}

/**
 * Returns if the match is currently paused/is in freezetime
 *
 */
stock int CS_IsMatchPaused()	{
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
stock void CS_SetClientFlashDuration(int client, float value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntPropFloat(client,	Prop_Send,	"m_flFlashDuration",	value);
}

/**
 * Get the clients flash duration
 *
 * @param client		Client index.
 */
stock int CS_GetClientFlashDuration(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
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
stock void TF2_SetClientMvMCash(int client, int value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client, Prop_Send, "m_nCurrency", value);
}

/**
 * Get the clients mvm currency/cash
 *
 * @param client		Client index.
 */
stock int TF2_GetClientMvMCash(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(client, Prop_Send, "m_nCurrency");
}


//Set the clients taunt cam on/off, useful for thirdperson plugin
/**
 * Set the clients taunt cam
 *
 * @param client		Client index.
 * @param value			Bool value.
 */
stock void TF2_SetClientTauntCam(int client, bool value)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_nForceTauntCam",	value);
}

/**
 * Get the clients taunt cam
 *
 * @param client		Client index.
 */
stock int TF2_GetClientTauntCam(int	client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetEntProp(client,	Prop_Send,	"m_nForceTauntCam");
}

//Set or get the clients killstreak count
/**
 * Set the clients killstreak count
 *
 * @param client		Client index.
 * @param value			Amount value.
 */
stock void TF2_SetClientKillstreak(int client, int value=5)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntProp(client,	Prop_Send,	"m_nStreaks",	value);
}

/**
 * Get the clients killstreak count
 *
 * @param client		Client index.
 */
stock int TF2_GetClientKillstreak(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	SetEntProp(client,	Prop_Send,	"m_nStreaks");
}

/**
 *	Get the clients cloak meter.
 *
 *	@param client		Client index.
 *	@error				Invalid client index.
 */
stock float TF2_GetClientCloakMeter(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	GetEntPropFloat(client, Prop_Send, "m_flCloakMeter");
}

/**
 *	Set the clients cloak meter.
 *
 *	@param client		Client index.
 *	@param value		Float value.
 *	@error				Invalid client index.
 */
stock float TF2_SetClientCloakMeter(int client, float value=1.0)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	SetEntPropFloat(client, Prop_Send, "m_flCloakMeter", value);
}

/**
 *	Get the clients glow value.
 *
 *	@param client		Client index.
 *	@error				Invalid client index.
*/
stock int TF2_GetClientGlow(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	GetEntProp(client, Prop_Send, "m_bGlowEnabled");
}

/**
 *	Set the clients glow value.
 *
 *	@param client		Client index.
 *	@param value		Glow value.
 *	@error				Invalid client index.
 */
stock void TF2_SetClientGlow(int client, int value=1)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client)
	
	SetEntProp(client, Prop_Send, "m_bGlowEnabled", value);
}

/**
 *	Get the clients ubercharge value,
 *
 *	@param client		Client index.
 *	@error				Invalid client index.
*/
stock float TF2_GetClientUbercharge(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client)
	
	return GetEntPropFloat(client, Prop_Send, "m_flChargeLevel");
}

/**
 *	Set the clients ubercharge value,
 *
 *	@param client		Client index.
 *	@param value		Float value.
 *	@error				Invalid client index.
*/
stock void TF2_SetClientUbercharge(int client, float value=1.0)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client)
	
	SetEntPropFloat(client, Prop_Send, "m_flChargeLevel", value);
}

/**
 *	Get the clients charge value,
 *
 *	@param client		Client index.
 *	@error				Invalid client index.
*/
stock float TF2_GetClientChargeMeter(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client)
	
	return GetEntPropFloat(client, Prop_Send, "m_flChargeMeter");
}

/**
 *	Set the clients charge value,
 *
 *	@param client		Client index.
 *	@param value		Float value.
 *	@error				Invalid client index.
*/
stock void TF2_SetClientChargeMeter(int client, float value=1.0)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client)
	
	SetEntPropFloat(client, Prop_Send, "m_flChargeMeter", value);
}

/**
 *	Get the clients metal value,
 *
 *	@param client		Client index.
 *	@error				Invalid client index.
*/
stock int TF2_GetClientMetal(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client)
	
	return	GetEntProp(client, Prop_Data, "m_iAmmo", 4, 3);
}

/**
 *	Set the clients metal value,
 *
 *	@param client		Client index.
 *	@param value		Amount value.
 *	@error				Invalid client index.
*/
stock void TF2_SetClientMetal(int client, int value=200)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client)
	
	SetEntProp(client, Prop_Data, "m_iAmmo", value, 4, 3);
}

/**
 *	Get the clients decapitations value,
 *
 *	@param client		Client index.
 *	@error				Invalid client index.
*/
stock int TF2_GetClientDecapitations(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client)
	
	return	GetEntProp(client, Prop_Send, "m_iDecapitations");
}

/**
 *	Set the clients decapitations value,
 *
 *	@param client		Client index.
 *	@param value		Amount value.
 *	@error				Invalid client index.
*/
stock void TF2_SetClientDecapitations(int client, int value=10)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client)
	
	SetEntProp(client, Prop_Send, "m_iDecapitations");
}

/**
 *	Returns the TF2 Weapon Slot
 *
 *	@param client		Client index.
 *	@param slot			TFSlot slot.
 */
stock int TF_GetPlayerWeaponSlot(int client, TFSlot slot)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	GetPlayerWeaponSlot(client, view_as<int>(slot));
}

//Left 4 Dead

/**
 * Gets a client's current team.
 *
 * @param client		Client index.
 * @return				Current L4DTeam of client.
 * @error				Invalid client index.
 */
stock L4DTeam L4D_GetClientTeam(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	view_as<L4DTeam>(GetClientTeam(client));
}

/**
 * Changes a client's current team.
 *
 * @param client		Client index.
 * @param team			L4DTeam team symbol.
 * @error				Invalid client index.
 */
stock void L4D_ChangeClientTeam(int client, L4DTeam team)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	ChangeClientTeam(client,	view_as<int>(team));
}

//Day of Defeat: Source

/**
 * Gets a client's current team.
 *
 * @param client		Client index.
 * @return				Current DODTeam of client.
 * @error				Invalid client index.
 */
stock DODTeam DOD_GetClientTeam(int client)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	return	view_as<DODTeam>(GetClientTeam(client));
}

/**
 * Changes a client's current team.
 *
 * @param client		Client index.
 * @param team			DODTeam team symbol.
 * @error				Invalid client index.
 */
stock void DOD_ChangeClientTeam(int client, DODTeam team)	{
	if(!ClientExists(client))
		ThrowError("Client index %d is invalid", client);
	
	ChangeClientTeam(client,	view_as<int>(team));
}