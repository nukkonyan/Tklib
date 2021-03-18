//CSGO

enum	CSGORank
{
	CSGORank_UnRanked	=	0,
	CSGORank_UR	=	0,
	CSGORank_Silver1	=	1,
	CSGORank_S1	=	1,
	CSGORank_Silver2	=	2,
	CSGORank_S2	=	2,
	CSGORank_Silver3	=	3,
	CSGORank_S3	=	3,
	CSGORank_Silver4	=	4,
	CSGORank_S4	=	4,
	CSGORank_SilverElite	=	5,
	CSGORank_SE	=	5,
	CSGORank_SilverEliteMaster	=	6,
	CSGORank_SEM	=	6,
	CSGORank_GoldNova1	=	7,
	CSGORank_GN1	=	7,
	CSGORank_GoldNova2	=	8,
	CSGORank_GN2	=	8,
	CSGORank_GoldNova3	=	9,
	CSGORank_GN3	=	9,
	CSGORank_GoldNovaMaster	=	10,
	CSGORank_GNM	=	10,
	CSGORank_MasterGuardian1	=	11,
	CSGORank_MG1	=	11,
	CSGORank_MasterGuardian2	=	12,
	CSGORank_MG2	=	12,
	CSGORank_MasterGuardianElite	=	13,
	CSGORank_MGE	=	13,
	CSGORank_DistinguishedMasterGuardian	=	14,
	CSGORank_DMG	=	14,
	CSGORank_LegendaryEagle	=	15,
	CSGORank_LE	=	15,
	CSGORank_LegendaryEagleMaster	=	16,
	CSGORank_LEM	=	16,
	CSGORank_SupremeMasterFirstClass	=	17,
	CSGORank_SMFC	=	17,
	CSGORank_TheGlobalElite	=	18,
	CSGORank_GE	=	18
}

//Soon will be finished on.
//enum	CSGORankType
//{
//	CSGORankType_Competitive	=	7
//}

/**
 *	Fixes the StatTrak and Skins function not working.
 *
 *	@param weapon		Weapon entity.
 */
stock void CSGO_FixWeaponId(int weapon)	{
	//Fixes skin not appearing.
	static int IDHigh = 16384;
	SetEntProp(weapon, Prop_Send, "m_iItemIDHigh", IDHigh++);
	SetEntProp(weapon, Prop_Send, "m_iItemIDLow", -1);
}

/**
 *	Set the Weapon skin.
 *
 *	@param weapon		Weapon entity.
 *	@param index		The Skin index.
 */
stock void CSGO_SetWeaponSkin(int weapon, int index)	{
	CSGO_FixWeaponId(weapon);
	SetEntProp(weapon, Prop_Send, "m_nFallbackPaintKit", index);
}

/**
 *	Get the Weapon skin.
 *
 *	@param weapon		Weapon entity.
 *	@param index		The Skin index.
 */
stock int CSGO_GetWeaponSkin(int weapon)	{
	return	GetEntProp(weapon, Prop_Send, "m_nFallbackPaintKit");
}

/**
 *	Set the Weapon StatTrak.
 *
 *	@param weapon		Weapon entity.
 *	@param value		The 'kill' track amount. If -1 (by default), will be disabled.
 */
stock void CSGO_SetWeaponStatTrak(int weapon, int value=-1)	{
	CSGO_FixWeaponId(weapon);
	SetEntProp(weapon, Prop_Send, "m_nFallbackStatTrak", value);
}

/**
 *	Get the Weapon StatTrak.
 *
 *	@param weapon		Weapon entity.
 */
stock int CSGO_GetWeaponStatTrak(int weapon)	{
	return	GetEntProp(weapon, Prop_Send, "m_nFallbackStatTrak");
}

/**
 *	Set the weapon owner.
 *
 *	@param weapon		Weapon entity.
 *	@param client		Client index.
 */
stock void CSGO_SetWeaponOwner(int weapon, int client)	{
	SetEntProp(weapon, Prop_Send, "m_iAccountID", GetSteamAccountID(client));
	SetEntPropEnt(weapon, Prop_Send, "m_hOwnerEntity", client);
	SetEntPropEnt(weapon, Prop_Send, "m_hPrevOwner", -1);
}

/**
 *	Set the weapon quality.
 *
 *	@param weapon		Weapon entity.
 *	@param index		Quality index value. By default set to 3, adding a star to the weapon name.
 */
stock void CSGO_SetWeaponQuality(int weapon, int index=3)	{
	SetEntProp(weapon, Prop_Send, "m_iEntityQuality", index);
}

/**
 *	Set the weapon nametag
 *
 *	@param weapon		Weapon entity.
 *	@param nametag		A Nametag or string of characters you specify.
 *	@param maxlen		Max character length for the string buffer.
 */
stock void CSGO_SetWeaponNametag(int weapon, char[] nametag, int maxlen=128)	{
	SetEntDataString(weapon, FindSendPropInfo("CBaseAttributableItem", "m_szCustomName"), nametag, maxlen);
}

/**
 *	Get the weapon nametag
 *
 *	@param weapon		Weapon entity.
 *	@param buffer		A Nametag or string of characters you specify.
 *	@param maxlen		Length of the buffer.
 */
stock void CSGO_SetWeaponNametag(int weapon, char[] buffer, int maxlen)	{
	GetEntDataString(weapon, FindSendPropInfo("CBaseAttributableItem", "m_szCustomName"), nametag, maxlen);
}

/**
 *	Get the competitive rank offset. [CS:GO]
 */
stock int CSGO_GetCompetitiveOffset()	{
	return	FindSendPropInfo("CCSPlayerResource",	"m_iCompetitiveRanking");
}

/**
 *	Set the competitive rank offset. [CS:GO]
 *	@param entity		The target entity.
 *	@param array			array, example arraytest[MAXPLAYERS+1] without the [MAXPLAYERS+1]
 */
stock void CSGO_SetCompetitiveOffset(int entity, const CSGORank[] array)	{
	SetEntDataArray(entity,	CSGO_GetCompetitiveOffset(),	view_as<int>(array),	MAXPLAYERS+1);
}

/**
 *	Get the competitive rank type. [CS:GO]
 */
stock int CSGO_GetCompetitiveType()	{
	return	FindSendPropInfo("CCSPlayerResource",	"m_iCompetitiveRankType");
}

/**
 *	Set the competitive rank type. [CS:GO]
 *
 *	@param entity		The target entity.
 *	@param array			array, example arraytest[MAXPLAYERS+1] without the [MAXPLAYERS+1]
 */
stock void CSGO_SetCompetitiveType(int entity, const CSGORankType[] array)	{
	SetEntDataArray(entity,	CSGO_GetCompetitiveType(),	view_as<int>(array),	MAXPLAYERS+1,	1);
}

/** 
 *	Set the arms model. [CS:GO]
 *
 *	@param client		Client index.
 *	@param name			The Arm model path.
 */
stock void CSGO_SetArmModel(int client, char[] name)	{
	SetEntPropString(client, Prop_Send, "m_szArmsModel", name);
}

//TF2

//Empty here atm, soon will come stuff.

//Other

/**
 *	Equips a players weapon.
 *	This is an alternative to that, this method fixes 0 clip magazine and glitchy reload animations because
 *	it was being spawned onto the client too early when using CreateEntityByName.
 *
 *	@param client		Client index.
 *	@param weapon		Weapon entity.
 */
stock void EquipPlayerWeaponEx(int client, int weapon)	{
	//Credits to Bacardi for part of the code.
	
	float origin[3];
	GetClientAbsOrigin(client, origin);
	//origin[2] += 100.0;
	
	TeleportEntity(weapon, origin, NULL_VECTOR, NULL_VECTOR);
	SetEntPropVector(weapon, Prop_Send, "m_vecOrigin", origin);
	
	//Lets force the weapon to never respawn.
	int SF_NORESPAWN = (1 << 30);
	int flags = GetEntProp(weapon, Prop_Data, "m_spawnflags");
	flags |= SF_NORESPAWN;
	
	SetEntProp(weapon, Prop_Data, "m_spawnflags", flags);
	
	DispatchSpawn(weapon);
}

/**
 *	Get entity name
 *
 *	@param entity		Entity index.
 *	@param buffer		Buffer storage.
 *	@param maxlen		Buffer max length.
 */
stock int GetEntityName(int entity, char[] buffer, int maxlen)	{
	GetEntPropString(entity, Prop_Data, "m_iName", buffer, maxlen);
}

/**
 *	Set entity name
 *
 *	@param entity		Entity index.
 *	@param name			Entity name.
 */
stock void SetEntityName(int entity, char[] name)	{
	DispatchKeyValue(entity, "targetname", name);
}

/**
 *	Find entity if it exists.
 *
 *	@param classname	Entity classname.
 *	@return				Returns true on success, or false on failure.
 *	@error				Invalid entity.
 */
stock bool FindEntity(char[] classname)	{
	int entity = -1;
	if((entity = FindEntityByClassname(entity, classname)) != -1)
		return	true;
	
	return	false;
}

/**
 *	Creates an entity by string name but does not spawn it (see DispatchSpawn).
 *	If ForceEdictIndex is not -1, then it will use an edict by that index. If the index is
 *	invalid or there is already an edict using that index, it will error out.
 *	This provides additional ability to force name on the entity you created.
 *
 *	@param classname		Entity classname.
 *	@param name				Entity name it will be referred as.
 *	@param ForceEdictIndex	Edict index used by the created entity (Ignored on Orangebox and above).
 *	@return					Entity index on success, or -1 on failure.
 *	@error					Invalid edict index, or no mod support.
 */
stock int CreateEntityByNameEx(char[] classname, char[] name, int ForceEdictIndex=-1)	{
	int entity = CreateEntityByName(classname, ForceEdictIndex);
	SetClientName(entity, name);
	return entity;
}

/**
 *	Should entity start disabled?
 *
 *	@param entity		Entity index.
 *	@param disabled		If true, starts disabled, else enabled if false
 */
stock void SetEntityDisabled(int entity, bool disabled)	{
	switch(disabled)	{
		case	true:	DispatchKeyValue(entity, "StartDisabled", "true");
		case	false:	DispatchKeyValue(entity, "StartDisabled", "false");
	}
}

/**
 *	Get the entitys model name/path
 *
 *	@param entity		Entity index.
 *	@param buffer		Buffer storage.
 *	@param maxlen		Length of the buffer.
 */
stock void GetEntityModel(int entity, char[] buffer, int maxlen)	{
	GetEntPropString(entity, Prop_Data, "m_ModelName", buffer, maxlen);
}

/**
 *	Get the clients steam authentication string.
 *	Same as GetClientAuthId but simpler.
 *
 *	@param client		Client index.
 *	@param buffer		Buffer storage.
 *	@param maxlen		Length of the buffer.
 */
stock void GetClientAuth(int client, char[] buffer, int maxlen)	{
	GetClientAuthId(client, AuthId_Steam2, buffer, maxlen);
}