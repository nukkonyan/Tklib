stock char CSS_GetTeamStringName[][]	=	{
	"{grey}Unassigned{default}",
	"{grey}Spectators{default}",
	"{red}Terrorists{default}",
	"{blue}Counter-Terrorists{default}"
};

//CS Slots
enum	CSSlot	{
	CSSlot_Primary	=	0,
	CSSlot_Secondary=	1,
	CSSlot_Knife	=	2,
	CSSlot_Grenade	=	3,
	CSSlot_C4		=	4
}

enum	CSWeaponType	{
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
enum	CSTeam	{
	CSTeam_Unassigned	=	0,
	CSTeam_Spectator	=	1,
	CSTeam_Terrorist	=	2,
	CSTeam_T			=	2,
	CSTeam_CTerrorist	=	3,
	CSTeam_CT			=	3
}

/**
 *	Returns the users current team.
 *
 *	@param	client        The users The users index.
 *	@error	If the client is invalid, this will return CSTeam_Unassigned.
 */
stock CSTeam CS_GetClientTeam(int client)	{
	return Tklib_IsValidClient(client) ? view_as<CSTeam>(GetClientTeam(client)):CSTeam_Unassigned;
}

/**
 *	Changes a users current team.
 *
 *	@param	client        The users The users index.
 *	@param	team          CSTeam team symbol.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void CS_ChangeClientTeam(int client, CSTeam team)	{
	if(Tklib_IsValidClient(client))
		ChangeClientTeam(client, view_as<int>(team));
}

/**
 *	Returns the teams client count.
 *
 *	@param team			CSTeam team.
 */
stock int CS_GetTeamClientCount(CSTeam team)	{
	return GetTeamClientCount(view_as<int>(team));
}

/**
 *	Returns if the warmup is currently ongoing
 */
stock bool CS_IsWarmupRound()	{
	return (GameRules_GetProp("m_bWarmupPeriod") == 1);
}

/**
 *	If true, warmup will start, else will be ended.
 */
stock bool CS_SetWarmupRound(bool warmup)	{
	GameRules_SetProp("m_bWarmupPeriod", view_as<int>(warmup));
}

/**
 *	Returns if the match is currently paused/is in freezetime
 */
stock bool CS_IsMatchPaused()	{
	return (GameRules_GetProp("m_bMatchWaitingForResume") == 1);
}

/**
 *	Set if the match should be paused.
 *	@param pause		If true, match will be paused. Else unpaused.
 */
stock bool CS_SetMatchPaused(bool pause)	{
	GameRules_SetProp("m_bMatchWaitingForResume", view_as<int>(pause));
}

/**
 *	Returns the clients map navigation location name
 *
 *	@param	client		The users index.
 *	@param	location	Buffer to store the location name.
 *	@param	len			Size of the buffer.
 *	@error	If the client is invalid, this will return false.
 */
stock bool CS_GetClientNavLocation(int client, char[] location, int maxlen)	{
	char storage[64];
	
	if(!Tklib_IsValidClient(client, _, true))
		return	false;
	
	GetEntPropString(client, Prop_Send, "m_szLastPlaceName", storage, sizeof(storage));
	
	if(StrEqual(storage, "BombsiteA"))
		FormatEx(location, sizeof(maxlen), "Bombsite A");
	else if(StrEqual(storage, "BombsiteB"))
		FormatEx(location, sizeof(maxlen), "Bombsite B");
	else if(StrEqual(storage, "BombsiteC"))
		FormatEx(location, sizeof(maxlen), "Bombsite C");
	else
		FormatEx(location, sizeof(maxlen), "%s", storage);
	
	return	true;
}

/**
 *	Sets the clients current account/cash/money balance
 *
 *	@param	client		The users index.
 *	@param	value		Money amount.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void CS_SetClientMoney(int client, int value)	{
	if(Tklib_IsValidClient(client))
		SetEntProp(client, Prop_Send, "m_iAccount", value);	
}

/**
 *	Returns the clients current account/cash/money balance
 *
 *	@param	client        The users index.
 *	@error	If the client is invalid, it will return -1.
 */
stock int CS_GetClientMoney(int client)	{
	return Tklib_IsValidClient(client) ? GetEntProp(client, Prop_Send, "m_iAccount"):-1;
}

/**
 *	Set the users flash duration, 0.0 or 0 is basically disabled
 *
 *	@param	client		The users index.
 *	@param	value		Flash duration.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void CS_SetClientFlashDuration(int client, float value)	{
	if(Tklib_IsValidClient(client))
		SetEntPropFloat(client, Prop_Send, "m_flFlashDuration", value);
}

/**
 *	Returns the users flash duration
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this will return -1.0.
 */
stock float CS_GetClientFlashDuration(int client)	{
	return Tklib_IsValidClient(client) ? GetEntPropFloat(client, Prop_Send, "m_flFlashDuration"):-1.0;
}

/**
 *	Tk Libraries.
 *	Set the clients armor.
 *
 *	@param	client		The users index.
 *	@param	value		The armor points.
 *	@error	If the user is invalid, nothing will happen.
 */
stock void CS_SetClientArmor(int client, int value, bool helmet=false, bool heavyarmor=false)	{
	if(Tklib_IsValidClient(client, _, true))	{
		SetEntProp(client, Prop_Send, "m_ArmorValue", value);
		
		if(helmet)
			SetEntProp(client, Prop_Send, "m_bHasHelmet", 1);
			
		if(heavyarmor)
			SetEntProp(client, Prop_Send, "m_bHasHeavyArmor", 1);
	}
}

/**
 *	Returns the clients armor value.
 *
 *	@param client		The users index.
 *	@param value		The value you specify.
 *	@error				If client is invalid, it will return -1.
 */
stock int CS_GetClientArmor(int client)	{
	return	Tklib_IsValidClient(client) ? GetEntProp(client, Prop_Send, "m_ArmorValue"):-1;
}

/**
 *	Returns if the client has helmet.
 *
 *	@param client		The users index.
 *	@param value		The value you specify.
 *	@error				If client is invalid, it will return -1.
 */
stock bool CS_ClientHasHelmet(int client)	{
	return	Tklib_IsValidClient(client) ? view_as<bool<(GetEntProp(client, Prop_Send, "m_bHasHelmet")):false;
}

/**
 *	Returns if the client has heavy armor.
 *
 *	@param client		The users index.
 *	@param value		The value you specify.
 *	@error				If client is invalid, it will return false.
 */
stock bool CS_ClientHasHeavyArmor(int client)	{
	return	Tklib_IsValidClient(client) ? view_as<bool>(GetEntProp(client, Prop_Send, "m_bHasHeavyArmor")):false;
}

/**
 *	Returns the users weapon entity name via slot
 *
 *	@param	client		The users index.
 *	@param	slot		Target CSSlot slot.
 *	@param	output		Buffer to store the weapon entity name.
 *	@param	maxlen		The maximum length for the buffer.
 *	@error	If the client or clients active weapon is invalid, nothing will happen.
 */
stock void CS_GetClientWeaponEx(int client, CSSlot slot, char[] output, int maxlen)	{
	if(Tklib_IsValidClient(client, _, true) || (IsValidEdict(CS_GetPlayerWeaponSlot(client, slot)) || IsValidEntity(CS_GetPlayerWeaponSlot(client, slot))))
		GetEdictClassname(CS_GetPlayerWeaponSlot(client, slot),	output,	sizeof(maxlen));
}

/**
 *	Give the user a weapon and delete their slot & set primary and secondary ammo
 *
 *	@param	client		The users index.
 *	@param	weapon		Weapon entity name.
 *	@param	slot		Players slot to be removed.
 *	@param	primary		Amount of primary ammo for the weapon selected.
 *	@param	secondary	Amount of secondary ammo for the weapon selected.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void CS_GiveClientWeaponEx2(int client, char[] weapon, CSSlot slot, int primary, int secondary)	{
	if(Tklib_IsValidClient(client, _, true))	{
		CS_ClientRemoveWeaponSlot(client, slot);
		GivePlayerItem(client, weapon);
		if(primary > 0)
			SetClientWeaponAmmo(client,	primary);
		if(secondary > 0)
			SetClientWeaponReserveAmmo(client,	secondary);
	}
}

/**
 *	Remove a users weapon in a specified slot
 *
 *	@param	client		The users index.
 *	@param	slot		CSSlot slot.
 *	@error	If the client or weapon in the specified slot is invalid, nothing will happen.
 */
stock void CS_ClientDropWeaponSlot(int client, CSSlot slot)	{
	if(Tklib_IsValidClient(client, _, true))	{
		int weapon = -1;
		if((weapon = CS_GetPlayerWeaponSlot(client,	slot)) != -1)
			CS_DropWeapon(client, weapon, true, true);
	}
}

/**
 *	Remove a users weapon in a specified slot
 *
 *	@param	client		The users index.
 *	@param	slot		CSSlot weapon slot.
 *	@error	If the client or weapon in the specified slot is invalid, nothing will happen.
 */
stock void CS_ClientRemoveWeaponSlot(int client, CSSlot slot)	{
	if(Tklib_IsValidClient(client, _, true))	{
		int weapon = -1;
		if((weapon = CS_GetPlayerWeaponSlot(client,	slot)) != -1)	{
			RemovePlayerItem(client, weapon);
			RemoveEdict(weapon)
		}
	}
}

/**
 *	Give the user a weapon and delete their current slot
 *
 *	@param	client		The users index.
 *	@param	weapon		Weapon entity name.
 *	@param	slot		Players slot to be removed.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void CS_GiveClientWeapon(int client, char[] weapon, CSSlot slot)	{
	if(Tklib_IsValidClient(client), _, true)	{
		CS_ClientRemoveWeaponSlot(client, slot);
		GivePlayerItem(client, weapon);
	}
}

/**
 *	Return the users weapon entity.
 *
 *	@param	client		The users index.
 *	@param	slot		CSSlot value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock int CS_GetPlayerWeaponSlot(int client, CSSlot slot)	{
	return Tklib_IsValidClient(client, _, true) ? GetPlayerWeaponSlot(client, view_as<int>(slot)):-1;
} 

/**
 *	Return if the weapon is in silenced mode.
 *
 *	@param	weapon		Weapon entity.
 *	@error	If the client is invalid, nothing will happen.
*/
stock int CS_IsWeaponSilenced(int weapon)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntProp(weapon, Prop_Data, "m_bSilencerOn"):false;
}

/**
 *	Set the sniper's scope level.
 *
 *	@param	weapon		Weapon entity.
 *	@param	value		Value amount.
 *	@error	If the weapon entity is invalid, nothing will happen.
 */
stock void CS_SetSniperZoomLevel(int weapon, int value)	{
	if((IsValidEdict(weapon) || IsValidEntity(weapon)))
		SetEntProp(weapon, Prop_Send, "m_zoomLevel", value);
}

/**
 *	Returns the sniper's scope level.
 *
 *	@param	weapon		Weapon entity.
 *	@error	If the weapon entity is invalid, it will return -1.
 */
stock int CS_GetSniperZoomLevel(int weapon)	{
	return (IsValidEdict(weapon) || IsValidEntity(weapon)) GetEntProp(weapon, Prop_Send, "m_zoomLevel"):-1;
}

/**
 *	Get the actual name of the clients weapon entity
 *
 *	@param weapon		Weapon entity name.
 *	@param name			Buffer to store in.
 *	@param maxlen		Maximum length of the buffer.
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
	
	if(StrEqual(weapon,	"weapon_m4a1"))
		strcopy(output, len, IdentifyGame() == Game_CSS|Game_CSPromod ? "M4A1":"M4A4");
}