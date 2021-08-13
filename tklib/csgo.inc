stock char CSGO_GetTeamStringName[][]	=	{
	"{grey}Unassigned{default}",
	"{grey}Spectators{default}",
	"{orange}Terrorists{default}",
	"{bluegrey}Counter-Terrorists{default}"
};

enum	CSGORank	{
	CSGORank_UnRanked						=	0,
	CSGORank_UR								=	0,
	CSGORank_Silver1						=	1,
	CSGORank_S1								=	1,
	CSGORank_Silver2						=	2,
	CSGORank_S2								=	2,
	CSGORank_Silver3						=	3,
	CSGORank_S3								=	3,
	CSGORank_Silver4						=	4,
	CSGORank_S4								=	4,
	CSGORank_SilverElite					=	5,
	CSGORank_SE								=	5,
	CSGORank_SilverEliteMaster				=	6,
	CSGORank_SEM							=	6,
	CSGORank_GoldNova1						=	7,
	CSGORank_GN1							=	7,
	CSGORank_GoldNova2						=	8,
	CSGORank_GN2							=	8,
	CSGORank_GoldNova3						=	9,
	CSGORank_GN3							=	9,
	CSGORank_GoldNovaMaster					=	10,
	CSGORank_GNM							=	10,
	CSGORank_MasterGuardian1				=	11,
	CSGORank_MG1							=	11,
	CSGORank_MasterGuardian2				=	12,
	CSGORank_MG2							=	12,
	CSGORank_MasterGuardianElite			=	13,
	CSGORank_MGE							=	13,
	CSGORank_DistinguishedMasterGuardian	=	14,
	CSGORank_DMG							=	14,
	CSGORank_LegendaryEagle					=	15,
	CSGORank_LE								=	15,
	CSGORank_LegendaryEagleMaster			=	16,
	CSGORank_LEM							=	16,
	CSGORank_SupremeMasterFirstClass		=	17,
	CSGORank_SMFC							=	17,
	CSGORank_TheGlobalElite					=	18,
	CSGORank_GE								=	18
}

//Soon will be finished on.
enum	CSGORankType	{
	CSGORankType_Competitive	=	7
}

/**
 *	Tk Libraries.
 *	Fixes the StatTrak and Skins function not working.
 *
 *	@param weapon		Weapon entity.
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_FixWeaponId(int weapon)	{
	if((!IsValidEdict(weapon)) || IsValidEntity(weapon))
		return	false;
	
	//Fixes skin not appearing.
	static int IDHigh = 16384;
	SetEntProp(weapon, Prop_Send, "m_iItemIDHigh", IDHigh++);
	SetEntProp(weapon, Prop_Send, "m_iItemIDLow", -1);
	return	true;
}

/**
 *	Tk Libraries.
 *	Set the Weapon skin.
 *
 *	@param weapon		Weapon entity.
 *	@param index		The Skin index.
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_SetWeaponSkin(int weapon, int index)	{
	if((!IsValidEdict(weapon)) || IsValidEntity(weapon))
		return	false;
	
	SetEntProp(weapon, Prop_Send, "m_nFallbackPaintKit", index);
	return	true;
}

/**
 *	Tk Libraries.
 *	Get the Weapon skin.
 *
 *	@param weapon		Weapon entity.
 *	@param index		The Skin index.
 *	@error				If the weapon or painkit is invalid, it will return -1.
 */
stock int CSGO_GetWeaponSkin(int weapon)	{
	return	(IsValidEdict(weapon) || IsValidEntity(weapon)) ? GetEntProp(weapon, Prop_Send, "m_nFallbackPaintKit"):-1;
}

/**
 *	Tk Libraries.
 *	Set the Weapon StatTrak.
 *
 *	@param weapon		Weapon entity.
 *	@param value		The 'kill' track amount. If -1 (by default), will be disabled.
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_SetWeaponStatTrak(int weapon, int value=-1)	{
	if((!IsValidEdict(weapon)) || IsValidEntity(weapon))
		return	false;
	
	SetEntProp(weapon, Prop_Send, "m_nFallbackStatTrak", value);
	return	true;
}

/**
 *	Tk Libraries.
 *	Get the Weapon StatTrak.
 *
 *	@param weapon		Weapon entity.
 *	@error				If weapon or stattrak module is invalid, it will return -1.
 */
stock int CSGO_GetWeaponStatTrak(int weapon)	{
	return	(IsValidEdict(weapon) || IsValidEntity(weapon)) ? GetEntProp(weapon, Prop_Send, "m_nFallbackStatTrak"):-1;
}

/**
 *	Tk Libraries.
 *	Set the weapon owner.
 *
 *	@param weapon		Weapon entity.
 *	@param client		Client index.
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_SetWeaponOwner(int weapon, int client)	{
	if((!IsValidEdict(weapon)) || IsValidEntity(weapon))
		return	false;
	
	SetEntProp(weapon, Prop_Send, "m_iAccountID", GetSteamAccountID(client));
	SetEntPropEnt(weapon, Prop_Send, "m_hOwnerEntity", client);
	SetEntPropEnt(weapon, Prop_Send, "m_hPrevOwner", -1);
	return	true;
}

/**
 *	Tk Libraries.
 *	Set the weapon quality.
 *
 *	@param weapon		Weapon entity.
 *	@param index		Quality index value. By default set to 3, adding a star to the weapon name.
 */
stock bool CSGO_SetWeaponQuality(int weapon, int index=3)	{
	if(weapon == -1)
		return	false;
	
	SetEntProp(weapon, Prop_Send, "m_iEntityQuality", index);
	return	true;
}

/**
 *	Tk Libraries.
 *	Set the weapon nametag
 *
 *	@param weapon		Weapon entity.
 *	@param nametag		A Nametag or string of characters you specify.
 *	@param maxlen		Max character length for the string buffer.
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_SetWeaponNametag(int weapon, char[] nametag, int maxlen=128)	{
	if(weapon == -1)
		return	false;
	
	SetEntDataString(weapon, FindSendPropInfo("CBaseAttributableItem", "m_szCustomName"), nametag, maxlen);
	return	true;
}

/**
 *	Tk Libraries.
 *	Get the weapon nametag
 *
 *	@param weapon		Weapon entity.
 *	@param buffer		A Nametag or string of characters you specify.
 *	@param maxlen		Length of the buffer.
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_GetWeaponNametag(int weapon, char[] buffer, int maxlen)	{
	if(weapon == -1)
		return	false;
	
	GetEntDataString(weapon, FindSendPropInfo("CBaseAttributableItem", "m_szCustomName"), nametag, maxlen);
	return	true;
}

/**
 *	Tk Libraries.
 *	Get the competitive rank offset. [CS:GO]
 */
stock int CSGO_GetCompetitiveOffset()	{
	return	FindSendPropInfo("CCSPlayerResource",	"m_iCompetitiveRanking");
}

/**
 *	Tk Libraries.
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
stock CSGORankType CSGO_GetCompetitiveType()	{
	return	view_as<CSGORankType>(FindSendPropInfo("CCSPlayerResource",	"m_iCompetitiveRankType"));
}

/**
 *	Tk Libraries.
 *	Set the competitive rank type. [CS:GO]
 *
 *	@param entity		The target entity.
 *	@param array			array, example arraytest[MAXPLAYERS+1] without the [MAXPLAYERS+1]
 */
stock void CSGO_SetCompetitiveType(int entity, const CSGORankType[] array)	{
	SetEntDataArray(entity,	CSGO_GetCompetitiveType(),	view_as<int>(array),	MAXPLAYERS+1,	1);
}

/**
 *	Tk Libraries.
 *	Set the arms model.
 *
 *	@param client		Client index.
 *	@param name			The Arm model path.
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_SetArmModel(int client, char[] name)	{
	if(!Tklib_IsValidClient(client))
		return	false;
	
	SetEntPropString(client, Prop_Send, "m_szArmsModel", name);
	return	true;
}