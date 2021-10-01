stock char CSGO_GetTeamStringName[][]	=	{
	"{grey}Unassigned{default}",
	"{grey}Spectators{default}",
	"{orange}Terrorists{default}",
	"{bluegrey}Counter-Terrorists{default}"
};

stock char CSGO_GetTeamColour[][]	=	{
	"{grey}",
	"{grey}",
	"{orange}",
	"{bluegrey}"
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

enum	{
	CSGO_Weapon_Glock	=	4,
	CSGO_Weapon_Ak47	=	7,
	CSGO_Weapon_Aug		=	8,
	CSGO_Weapon_AWP		=	9,
	CSGO_Weapon_Famas	=	10,
	CSGO_Weapon_G3SG1	=	11,
	CSGO_Weapon_GalilAR	=	13,
	CSGO_Weapon_M249	=	14,
	CSGO_Weapon_M4A4	=	16,
	CSGO_Weapon_Mac10	=	17,
	CSGO_Weapon_P90		=	19,
	CSGO_Weapon_MP5		=	23,
	CSGO_Weapon_MP5SD	=	23,
	CSGO_Weapon_UMP45	=	24,
	CSGO_Weapon_XM1014	=	25,
	CSGO_Weapon_Bizon	=	26,
	CSGO_Weapon_MAG7	=	27,
	CSGO_Weapon_Negev	=	28,
	CSGO_Weapon_SawedOff=	29,
	CSGO_Weapon_Tec9	=	30,
	CSGO_Weapon_Zeus	=	31,
	CSGO_Weapon_Taser	=	31,
	CSGO_Weapon_P2000	=	32,
	CSGO_Weapon_MP7		=	33,
	CSGO_Weapon_MP9		=	34,
	CSGO_Weapon_Nova	=	35,
	CSGO_Weapon_Scar20	=	38,
	CSGO_Weapon_SG556	=	39,
	CSGO_Weapon_SSG08	=	40,
	CSGO_Weapon_Scout	=	40,
	CSGO_Knife_CT		=	41,
	CSGO_Knife_Gold		=	42,
	CSGO_Flashbang		=	43,
	CSGO_HEGrenade		=	44,
	CSGO_SmokeGrenade	=	45,
	CSGO_Molotov		=	46,
	CSGO_Decoy			=	47,
	CSGO_Incendiary		=	48,
	CSGO_Knife_T		=	59,
	CSGO_Weapon_M4A1_S			=	60,
	CSGO_Weapon_USP_S			=	61,
	CSGO_Weapon_CZ75_A			=	62,
	CSGO_Knife_Spectral			=	80,
	CSGO_Knife_Ghost			=	80,
	CSGO_Knife_Bayonet			=	500,
	CSGO_Knife_Classic			=	503,
	CSGO_Knife_Flip				=	505,
	CSGO_Knife_Gut				=	506,
	CSGO_Knife_Karambit			=	507,
	CSGO_Knife_M9_Bayonet		=	508,
	CSGO_Knife_Huntsman			=	509,
	CSGO_Knife_Falchion			=	512,
	CSGO_Knife_Bowie			=	514,
	CSGO_Knife_Butterfly		=	515,
	CSGO_Knife_ShadowDaggers	=	516,
	CSGO_Knife_ButtPlugs		=	516,
	CSGO_Knife_Paracord			=	517,
	CSGO_Knife_Survival			=	518,
	CSGO_Knife_Ursus			=	519,
	CSGO_Knife_Navaja			=	520,
	CSGO_Knife_Nomad			=	521,
	CSGO_Knife_Stiletto			=	522,
	CSGO_Knife_Talon			=	523,
	CSGO_Knife_Skeleton			=	525
}

//Soon will be finished on.
enum	CSGORankType	{
	CSGORankType_Competitive	=	7
}

#define	CSGORank(%1)		view_as<CSGORank>(%1)
#define	CSGORankType(%1)	view_as<CSGORankType>(%1)

/**
 *	Fixes the StatTrak and Skins function not working.
 *
 *	@param weapon		Weapon entity.
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_FixWeaponId(any weapon)	{
	if(!IsValidEntityEx(weapon))
		return	false;
	
	//Fixes skin not appearing.
	static int IDHigh = 16384;
	SetEntProp(int(weapon), Prop_Send, "m_iItemIDHigh", IDHigh++);
	SetEntProp(int(weapon), Prop_Send, "m_iItemIDLow", -1);
	return	true;
}

/**
 *	Set the Weapon skin.
 *
 *	@param	weapon		The weapon entity.
 *	@param	index		The skin index.
 *
 *	@return	If the weapon entity is invalid, this returns false.
 */
stock bool CSGO_SetWeaponSkin(any weapon, int index)	{
	return	SetEntPropEx(weapon, Prop_Send, "m_nFallbackPaintKit", index);
}

/**
 *	Returns the Weapon skin.
 *
 *	@param weapon		The weapon entity.
 *	@param index		The Skin index.
 *
 *	@error				If the weapon or painkit is invalid, this returns -1.
 */
stock int CSGO_GetWeaponSkin(any weapon)	{
	return	GetEntPropEx(weapon, Prop_Send, "m_nFallbackPaintKit");
}

/**
 *	Set the weapon's pattern/seed.
 *
 *	@param	weapon		The weapon entity.
 *	@param	pattern		The pattern to set.
 *
 *	@error	If the weapon is invalid or procedure failed, this returns false.
 */
stock bool CSGO_SetWeaponPattern(any weapon, int pattern)	{
	return	SetEntPropEx(weapon, Prop_Send, "m_nFallbackSeed", pattern);
}

/**
 *	Returns the weapon's pattern/seed.
 *
 *	@param	weapon		The weapon entity.
 *
 *	@error	If the weapon is invalid or procedure failed, this returns false.
 */
stock int CSGO_GetWeaponPattern(any weapon)	{
	return	GetEntPropEx(weapon, Prop_Send, "m_nFallbackSeed");
}

/**
 *	Set the Weapon StatTrak.
 *
 *	@param	weapon		Weapon entity.
 *	@param	value		The 'kill' track amount. If -1 (by default), will be disabled.
 *
 *	@return	Returns false on failure, true otherwise.
 *
 *	@error	If the weapon is invalid or procedure failed, this returns false.
 */
stock bool CSGO_SetWeaponStatTrak(any weapon, int value=-1)	{
	return	SetEntPropEx(weapon, Prop_Send, "m_nFallbackStatTrak", value); 
}

/**
 *	Returns the Weapon StatTrak.
 *
 *	@param weapon		The weapon entity.
 *
 *	@error				If weapon or stattrak module is invalid, it will return -1.
 */
stock int CSGO_GetWeaponStatTrak(any weapon)	{
	return	GetEntPropEx(weapon, Prop_Send, "m_nFallbackStatTrak");
}

/**
 *	Set the weapon owner.
 *
 *	@param weapon		The weapon entity.
 *	@param client		Users index.
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_SetWeaponOwner(any weapon, int client)	{
	SetEntPropEx(weapon, Prop_Send, "m_iAccountID", GetSteamAccountID(client));
	SetEntPropEntEx(weapon, Prop_Send, "m_hOwnerEntity", client);
	SetEntPropEnt(weapon, Prop_Send, "m_hPrevOwner", -1);
	
	return	true;
}

/**
 *	Set the weapon quality.
 *
 *	@param	weapon		The weapon entity.
 *	@param	index		Quality index value. By default set to 3, adding a star to the weapon name.
 *
 *	@error	If the weapon is invalid or procedure failed, this returns false.
 */
stock bool CSGO_SetWeaponQuality(any weapon, int index=3)	{
	return	SetEntPropEx(weapon, Prop_Send, "m_iEntityQuality", index);
}

/**
 *	Set the weapon nametag
 *
 *	@param	weapon		The weapon entity.
 *	@param	nametag		A Nametag or string of characters you specify.
 *	@param	maxlen		Max character length for the string buffer.
 *
 *	@return	Returns false on failure, true otherwise.
 */
stock bool CSGO_SetWeaponNametag(any weapon, const char[] nametag)	{
	return	SetEntPropStringEx(weapon, Prop_Send, "m_szCustomName", nametag);
}

/**
 *	Returns the weapon nametag
 *
 *	@param	weapon		The weapon entity.
 *	@param	buffer		A Nametag or string of characters you specify.
 *	@param	maxlen		Length of the buffer.
 *
 *	@return	Returns false on failure, true otherwise.
 */
stock bool CSGO_GetWeaponNametag(any weapon, char[] buffer, int maxlen)	{
	return	GetEntPropStringEx(weapon, Prop_Send, "m_szCustomName", nametag, maxlen);
}

/**
 *	Set the weapon wear.
 *
 *	@param	weapon		The weapon entity.
 *	@param	wear		The wear float value.
 *
 *	@error	If the weapon is invalid or procedure failed, this returns false.
 */
stock bool CSGO_SetWeaponWear(any weapon, float wear)	{
	return	SetEntPropFloatEx(weapon, Prop_Send, "m_flFallbackWear", wear);
}

/**
 *	Returns the weapon's wear float.
 *
 *	@param	weapon		The weapon entity.
 *
 *	@error	If the weapon is invalid or procedure failed, this returns false.
 */
stock float CSGO_GetWeaponWear(any weapon)	{
	return	GetEntPropFloatEx(entity, Prop_Send, "m_flFallbackWear");
}

/**
 *	Returns the competitive rank offset. [CS:GO]
 */
stock int CSGO_GetCompetitiveOffset()	{
	return	FindSendPropInfo("CCSPlayerResource", "m_iCompetitiveRanking");
}

/**
 *	Set the competitive rank offset. [CS:GO]
 *
 *	@param	entity	The target entity.
 *	@param	array	array, example arraytest[MAXPLAYERS+1] without the [MAXPLAYERS+1]
 */
stock void CSGO_SetCompetitiveOffset(any entity, const CSGORank[] array)	{
	SetEntDataArray(int(entity), CSGO_GetCompetitiveOffset(), int(array), MAXPLAYERS+1);
}

/**
 *	Returns the competitive rank type. [CS:GO]
 */
stock CSGORankType CSGO_GetCompetitiveType()	{
	return	CSGORankType(FindSendPropInfo("CCSPlayerResource",	"m_iCompetitiveRankType"));
}

/**
 *	Set the competitive rank type. [CS:GO]
 *
 *	@param	entity	The target entity.
 *	@param	array	array, example arraytest[MAXPLAYERS+1] without the [MAXPLAYERS+1]
 */
stock void CSGO_SetCompetitiveType(any entity, const CSGORankType[] array)	{
	SetEntDataArray(int(entity), CSGO_GetCompetitiveType(), int(array), MAXPLAYERS+1, 1);
}

/**
 *	Set the users arms model.
 *
 *	@param	client	The users index.
 *	@param	arms	The Arm model path.
 *
 *	@return	Returns false on failure, true otherwise.
 */
stock bool CSGO_SetArmModel(int client, const char[] arms)	{
	return	SetEntPropStringEx(client, Prop_Send, "m_szArmsModel", name);
}

/**
 *	Return the users arms model.
 *
 *	@param client		The users index.
 *	@param name			The Arm model path.
 *
 *	@return				Returns false on failure, true otherwise.
 */
stock bool CSGO_GetArmModel(int client, char[] buffer, int maxlen)	{
	return	GetEntPropStringEx(client, Prop_Send, "m_szArmsModel", buffer, maxlen);
}