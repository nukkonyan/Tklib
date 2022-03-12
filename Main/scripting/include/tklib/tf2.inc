//==========================================//
// Tklib / Team Fortress 2.
//==========================================//
#if !defined _tklib_no_tf2

//Get the team name via strings for colored chat purpose (Usage example: TF2_GetTeamStringName[GetClientTeam(client)] will return the correct team name)
stock char TF2_GetTeamStringName[][] = {
	"{grey}Unassigned{default}",
	"{grey}Spectators{default}",
	"{red}RED{default}",
	"{blue}BLU{default}",
	"{lightgreen}GRN{default}",
	"{orange}YLW{default}"
}, TF2_GetTeamColour[][] = {
	"{grey}",
	"{grey}",
	"{red}",
	"{blue}",
	"{lightgreen}",
	"{orange}"
}, TF2_GetFlagTypeName[][] = {
	"None",
	"Picked up",
	"Captured",
	"Defended",
	"Dropped",
	"Carrier"
}, TF2_GetGameTypeName[][] = {
	"Unknown",
	"Capture-The-Flag",
	"Capture Points",
	"Payload / Payload Race",
	"Arena",
	"Unknown",
	"Unknown",
	"Passball"
}, TF2_GetCritTypeName[][] = {
	"None",
	"Mini-Crit",
	"Crit"
}, TF2_GetClassTypeName[][] = {
	"Unknown",
	"Scout",
	"Sniper",
	"Soldier",
	"Demoman",
	"Medic",
	"Heavy",
	"Pyro",
	"Spy",
	"Engineer",
	"Civilian"
};

//TF2 Flag Event
enum TFFlag	{
	TFFlag_None		=	0,
	TFFlag_PickedUp	=	1,
	TFFlag_Captured	=	2,
	TFFlag_Defended	=	3,
	TFFlag_Dropped	=	4,
	TFFlag_Carrier	=	5
}

//TF Slots
enum TFSlot	{
	TFSlot_Invalid	=	-1,
	TFSlot_Primary	=	0,
	TFSlot_Secondary=	1,
	TFSlot_Melee	=	2,
	TFSlot_PDA		=	3,
	TFSlot_PDA2		=	4,
	TFSlot_Slot6	=	5,
	TFSlot_Slot7	=	6,
	TFSlot_Slot8	=	7,
	TFSlot_Slot9	=	8,
	TFSlot_Slot10	=	9,
	TFSlot_Slot11	=	10
}

enum TFCritType	{
	TFCritType_None		=	0,
	TFCritType_Minicrit	=	1,
	TFCritType_Crit		=	2
}

enum TFBuilding	{
	TFBuilding_Invalid				=	-1,
	TFBuilding_Sentrygun			=	0,
	TFBuilding_Dispenser			=	1,
	TFBuilding_Teleporter_Entrance	=	2,
	TFBuilding_Teleporter_Exit		=	3,
	TFBuilding_MiniSentry			=	4,
	TFBuilding_Sapper				=	5
}

enum TFQuality	{
	TFQuality_Normal	= 0,
	TFQuality_Genuine	= 1,
	TFQuality_Rarity2	= 2,
	TFQuality_Vintage	= 3,
	TFQuality_Rarity4	= 4,
	TFQuality_Unusual	= 5,
	TFQuality_Unique	= 6,
	TFQuality_Community	= 7,
	TFQuality_Valve		= 8,
	TFQuality_SelfMade	= 9,
	TFQuality_Rarity10	= 10,
	TFQuality_Strange	= 11,
	TFQuality_Completed	= 12,
	TFQuality_Haunted	= 13,
	TFQuality_Collectors= 14,
	TFQuality_Skins		= 15
}

/* Look up "item_found" event */
enum TFMethod	{
	TFFound_Achieved	=	-1,
	TFFound_Found		=	0,
	TFFound_Crafted		=	1,
	TFFound_Traded		=	2,
	TFFound_Unboxed		=	4,
	TFFound_Gifted		=	5,
	TFFound_Earned		=	8,
	TFFound_Refunded	=	9,
	TFFound_WrappedGift	=	10
}

enum TFGameType	{
	TFGameType_Unknown	=	0,
	TFGameType_CTF		=	1,
	TFGameType_CP		=	2,
	TFGameType_PL		=	3,
	TFGameType_Arena	=	4,
	TFGameType_PassBall	=	7
}

/* See event "halloween_boss_killed" for more info */
enum	{
	TFBoss_Killed_HHH = 1,
	TFBoss_Killed_Monoculus = 2,
	TFBoss_Killed_Merasmus = 3
}

/* Achievement id's
enum	{
	TF2AchID_SentryGunner = 127,
	TF2AchID_Nemesis = 128,
	TF2AchID_HardToKill = 129,
	TF2AchID_MasterOfDisguise = 130,
	TF2AchID_WithFriendsLikeThese = 131,
	TF2AchID_Dynasty = 132,
	TF2AchID_Hardcore = 133,
	TF2AchID_PowerhouseOffense = 134,
	TF2AchID_LightningOffense = 135,
	TF2AchID_RelentlessOffense = 136,
	TF2AchID_ImpenetrableDefense = 137,
	TF2AchID_ImpossibleDefense = 138,
	TF2AchID_HeadOfTheClass = 139,
	TF2AchID_WorldTraveler = 140,
	TF2AchID_TeamDoctor = 141,
	TF2AchID_Flamethrower = 142,
	TF2AchID_GreyMatter = 145,
	TF2AchID_Riftwalker = 150,
	TF2AchID_ReadyForDuty = 151,
	TF2AchID_EscapeTheHeat = 152,
	TF2AchID_TheGreatDeflate = 153,
	TF2AchID_BFF2 = 154,
	TF2AchID_MassHysteria = 155,
	TF2AchID_AFreshPairOfEyes = 156,
	TF2AchID_NoseDive = 157,
	TF2AchID_PunchingBag = 158,
	TF2AchID_EmergencyBrake = 159,
	TF2AchID_PartyCrasher = 160,
	TF2AchID_CongaLine = 161,
	TF2AchID_OnTheRocks = 162,
	TF2AchID_RunningWithScissors = 163,
	TF2AchID_MayICutInToo = 164,
	TF2AchID_Showboat = 165,
	TF2AchID_TuneMerasmusMultDimensionalTelevision = 166,
	TF2AchID_Jackpot = 167,
	TF2AchID_FirstBlood = 1001,
	TF2AchID_FirstBloodPart2 = 1002,
	TF2AchID_QuickHook = 1003,
	TF2AchID_AYearToRemember = 1004,
	TF2AchID_TheCycle = 1005,
	TF2AchID_Closer = 1006,
	TF2AchID_IfYouBuildIt = 1007,
	TF2AchID_GunDown = 1008,
	TF2AchID_BatterUp = 1009,
	TF2AchID_DoctoringTheBall = 1010,
	TF2AchID_Dodgers1Giants0 = 1011,
	TF2AchID_BattingTheDoctor = 1012,
	TF2AchID_ImBatMan = 1013,
	TF2AchID_TripleSteal = 1014,
	TF2AchID_PopFly = 1015,
	TF2AchID_RoundTripper = 1016,
	TF2AchID_ArtfulDodger = 1017,
	TF2AchID_FallClassic = 1018,
	TF2AchID_StrikeZone = 1019,
	TF2AchID_FoulTerritory = 1020,
	TF2AchID_TheBigHurt = 1021,
	TF2AchID_Brushback = 1022,
	TF2AchID_MoonShot = 1023,
	TF2AchID_Beanball = 1024,
	TF2AchID_RetireTheRunner = 1025,
	TF2AchID_CaughtNapping = 1026,
	TF2AchID_SideRetired = 1027,
	TF2AchID_TriplePlay = 1028,
	TF2AchID_StealingHome = 1029,
	TF2AchID_SetTheTable = 1030,
	TF2AchID_BlockThePlate = 1031,
	TF2AchID_BelittledBeleaguer = 1032,
	TF2AchID_NoHitter = 1033,
	TF2AchID_RaceForThePennant = 1034,
	TF2AchID_OutOfThePark = 1035,
	TF2AchID_ScoutMilestone1 = 1036,
	TF2AchID_ScoutMilestone2 = 1037,
	TF2AchID_ScoutMilestone3 = 1038,
	TF2AchID_BackInBusiness = 1039,
	TF2AchID_Back2Back = 1040,
	TF2AchID_SeveredTies = 1041,
	TF2AchID_RodeHardPutAwayWet = 1101,
	TF2AchID_BePolite = 1102,
	TF2AchID_BeEfficient = 1103,
	TF2AchID_HaveAPlan = 1104,
	TF2AchID_KillEveryoneYouMeet = 1105,
	TF2AchID_TriplePrey = 1106,
	TF2AchID_SelfDestructSequence = 1107,
	TF2AchID_DeSentrylized = 1108,
	TF2AchID_ShootTheBreeze = 1109,
	TF2AchID_DroppedDead = 1110,
	TF2AchID_TheLastWave = 1111,
	TF2AchID_AustralianRules = 1112,
	TF2AchID_KookTheSpook = 1112,
	TF2AchID_SocketToHim = 1113,
}
*/

#define	TFTeam(%1)		view_as<TFTeam>(%1)
#define	TFFlag(%1)		view_as<TFFlag>(%1)
#define	TFSlot(%1)		view_as<TFSlot>(%1)
#define	TFCritType(%1)	view_as<TFCritType>(%1)
#define	TFBuilding(%1)	view_as<TFBuilding>(%1)
#define	TFQuality(%1)	view_as<TFQuality>(%1)
#define	TFMethod(%1)	view_as<TFMethod>(%1)
#define	TFGameType(%1)	view_as<TFGameType>(%1)


/**
 *	Set the users mvm currency/cash.
 *
 *	@param	client		The users index.
 *	@param	value		Currency value.
 *
 *	@error	If the user is invalid or has no currency property, this returns false.
 */
stock bool TF2_SetClientMvMCash(int client, int value)	{
	return Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_nCurrency", value):false;
}

/**
 *	Returns the users mvm currency/cash
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid or has no currency property, this returns -1.
 */
stock int TF2_GetClientMvMCash(int client)	{
	return Tklib_IsValidClient(client) ? GetEntPropEx(client, Prop_Send, "m_nCurrency"):-1; 
}

/**
 *	Set the users taunt cam on/off, useful for thirdperson plugin.
 *
 *	@param	client		The users index.
 *	@param	value		Bool value.
 *
 *	@error	If the user is invalid or has no taunt cam property, this returns false.
 */
stock bool TF2_SetClientTauntCam(int client, bool value)	{
	return Tklib_IsValidClient(client, true, true) ? SetEntPropEx(client, Prop_Send, "m_nForceTauntCam", value):false;
}

/**
 *	Returns the users taunt cam.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid or has no taunt cam property, this returns false.
 */
stock bool TF2_GetClientTauntCam(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropBool(client, Prop_Send, "m_nForceTauntCam"):false;
}

//Set or get the users killstreak count
/**
 *	Set the clients killstreak count
 *
 *	@param	client		The users index.
 *	@param	value		Killstreak count.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool TF2_SetClientKillstreak(int client, int value=5)	{
	return Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_nStreaks", value):false;
}

/**
 *	Returns the users killstreak count
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int TF2_GetClientKillstreak(int client)	{
	return Tklib_IsValidClient(client) ? GetEntPropEx(client, Prop_Send, "m_nStreaks"):-1;
}

/**
 *	Returns the users cloak meter.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid or has no cloak, this returns -1.0.
 */
stock float TF2_GetClientCloakMeter(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloatEx(client, Prop_Send, "m_flCloakMeter"):false;
}

/**
 *	Set the users cloak meter.
 *
 *	@param	client		The users index.
 *	@param	value		Cloak duration.
 *
 *	@error	If the user is invalid or has no cloak, this returns false.
 */
stock bool TF2_SetClientCloakMeter(int client, float value=1.0)	{
	return Tklib_IsValidClient(client) ? SetEntPropFloatEx(client, Prop_Send, "m_flCloakMeter", value):false;
}

/**
 *	Returns the users glow value.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
*/
stock bool TF2_IsClientGlowing(int client)	{
	return Tklib_IsValidClient(client) ? GetEntPropBool(client, Prop_Send, "m_bGlowEnabled"):false;
}

/**
 *	Toggle the users glow value.
 *
 *	@param	client		The users index.
 *	@param	value		Glow value.
 *
 *	@error	If the user is invalid, this returns.
 */
stock bool TF2_SetClientGlow(int client, bool value)	{
	return	Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_bGlowEnabled", value):false;
}

/**
 *	Returns the users ubercharge value,
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid or has no medigun, this will return -1.0.
*/
stock float TF2_GetClientUbercharge(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloatEx(client, Prop_Send, "m_flChargeLevel"):false;
}

/**
 *	Set the users ubercharge value,
 *
 *	@param	client		The users index.
 *	@param	value		Ubercharge value, Defaulted to 1.0.
 *
 *	@error	If the user is invalid or has no medigun, this returns false.
*/
stock bool TF2_SetClientUbercharge(int client, float value=1.0)	{
	return Tklib_IsValidClient(client, _, true) ? SetEntPropFloatEx(client, Prop_Send, "m_flChargeLevel", value):false;
}

/**
 *	Returns the users charge value,
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns -1.0.
*/
stock float TF2_GetClientChargeMeter(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloatEx(client, Prop_Send, "m_flChargeMeter"):-1.0;
}

/**
 *	Set the users charge value,
 *
 *	@param client		The users index.
 *	@param value		Charge value.
 *
 *	@error	If the user is invalid or has no charge-weapon, this returns -1.0.
*/
stock bool TF2_SetClientChargeMeter(int client, float value=1.0)	{
	return Tklib_IsValidClient(client, _, true) ? SetEntPropFloatEx(Exclient, Prop_Send, "m_flChargeMeter", value):false;
}

/**
 *	Returns the users metal value,
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid or has no metal-property, this returns -1.
*/
stock int TF2_GetClientMetal(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropEx(client, Prop_Data, "m_iAmmo", 4, 3):-1;
}

/**
 *	Set the users metal value,
 *
 *	@param	client		The users index.
 *	@param	metal		Metal amount.
 *
 *	@error	If the user is invalid or has no metal-property, this returns false.
*/
stock bool TF2_SetClientMetal(int client, int metal=200)	{
	return Tklib_IsValidClient(client, _, true) ? SetEntPropEx(client, Prop_Data, "m_iAmmo", metal, 4, 3):false;
}

/**
 *	Returns the users decapitations value,
 *
 *	@param	client		The users index.
 *
 *	@error	If the client is invalid or has no decapitation-property, this returns -1.
*/
stock int TF2_GetClientDecapitations(int client)	{
	return Tklib_IsValidClient(client) ? GetEntPropEx(client, Prop_Send, "m_iDecapitations"):-1;
}

/**
 *	Set the users decapitations value,
 *
 *	@param	client		The users index.
 *	@param	value		Decapitations amount.
 *
 *	@error	If the user is invalid or has no decapitation-property, this returns false.
*/
stock bool TF2_SetClientDecapitations(int client, int value=10)	{
	return Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_iDecapitations"):false;
}

/**
 *	Returns the TF2 Weapon Slot
 *
 *	@param	client		The users index.
 *	@param	slot		TFSlot slot.
 *
 *	@error	If the user or slot is invalid, this returns -1.
 */
stock int TF2_GetPlayerWeaponSlot(int client, TFSlot slot)	{
	return Tklib_IsValidClient(client, _, true) ? GetPlayerWeaponSlot(client, int(slot)):-1;
}

/**
 *	Returns the name of the building.
 *
 *	@param	building		The TFBuilding.
 *	@param	buildingname	String to store the building name to.
 *
 *	@param	maxlen			Maximum length of the string.
 */
stock void TF2_GetBuildingName(TFBuilding building, char[] buildingname, int maxlen)	{
	switch(building)	{
		case TFBuilding_Dispenser: strcopy(buildingname, maxlen, "Dispenser");
		case TFBuilding_Sentrygun: strcopy(buildingname, maxlen, "Sentrygun");
		case TFBuilding_Teleporter_Entrance: strcopy(buildingname, maxlen, "Teleporter Entrance");
		case TFBuilding_Teleporter_Exit: strcopy(buildingname, maxlen, "Teleporter Exit");
		case TFBuilding_MiniSentry: strcopy(buildingname, maxlen, "Mini-Sentry");
		case TFBuilding_Sapper: strcopy(buildingname, maxlen, "Sapper");
	}
}

/**
 *	Returns the TFBuilding type.
 *
 *	@param	entity	The building to get TFBuilding type from.
 *
 *	@error	If the building is invalid, this returns TFBuilding_Invalid.
 */
stock TFBuilding TF2_GetBuildingType(any entity)	{
	char classname[64];
	GetEntityClassname(entity, classname, sizeof(classname));
	
	if(StrEqual(classname, "obj_dispenser"))
		return TFBuilding_Dispenser;
	if(StrEqual(classname, "obj_sentrygun"))
		return TFBuilding_Sentrygun;
	if(StrEqual(classname, "obj_teleporter"))	{
		switch(TF2_GetObjectMode(entity))	{
			case TFObjectMode_Entrance:	return TFBuilding_Teleporter_Entrance;
			case TFObjectMode_Exit:		return TFBuilding_Teleporter_Exit;
		}
	}
	if(StrEqual(classname, "obj_minisentry"))
		return TFBuilding_MiniSentry;
	if(StrContainsEx(classname, "sapper", false))
		return TFBuilding_Sapper;
	
	return TFBuilding_Invalid;
}

/**
 *	Sets if the users current class-model should be forced using its class animations.
 *
 *	@param	client	The users index.
 *	@param	value	The bool on/off value.
 *
 *	@error	If the user is invalid or has no class animations, this returns false.
 */
stock bool TF2_SetClassAnimations(int client, bool value)	{
	return Tklib_IsValidClient(client, _, true) ? SetEntPropEx(client, Prop_Send, "m_bUseClassAnimations", value):false;
}

/**
 *	Sets the clients model.
 *	This is the alternative to SetClientModel, as this actually puts the model.
 *	This is paired with GetClientModel.
 *
 *	@param	client				The users index.
 *	@param	model				The model path.
 *	@param	UseClassAnimations	If true, this will force the model to use the class animations.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool TF2_SetClientModel(int client, const char[] model, bool UseClassAnimations)	{
	if(Tklib_IsValidClient(client, _, true))	{
		SetVariantString(model);
		AcceptEntityInput(client, "SetCustomModel");
		TF2_SetClassAnimations(client, UseClassAnimations);
		return true;
	}
	
	return	false;
}

/**
 *	Removes a weapon from the users specified weapon slot.
 *	Use this over TF2_RemoveWeaponSlot.
 *
 *	@param	client		The users index.
 *	@param	slot		The weapon slot to target.
 *
 *	@error	If the procedure failed, this returns false.
 */
stock bool TF2_RemovePlayerWeaponSlot(int client, TFSlot slot)	{
	int weapon = -1;
	if((weapon = GetPlayerWeaponSlot(client, int(slot))) != -1)	{
		RemovePlayerItem(client, weapon);
		RemoveEdict(weapon);
		return true;
	}
	
	return false;
}

/**
 *	Returns if the entity is a building.
 *
 *	@param	entity	The building entity index.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool TF2_IsEntityBuilding(int entity)	{
	return GetEntPropBool(entity, Prop_Send, "m_bBuilding");
}

/**
 *	Returns if the entity is a mini-building.
 *
 *	@param	entity	The building entity index.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool TF2_IsEntityMiniBuilding(int entity)	{
	return GetEntPropBool(entity, Prop_Send, "m_bMiniBuilding");
}

/**
 *	Returns the buildings builder.
 *	Otherwise use GetEntityOwner.
 *
 *	@param	entity	The building entity index.
 *
 *	@error	If the entity is invalid, this returns -1.
 */
stock bool TF2_SetBuildingOwner(any entity, int client)	{
	return Tklib_IsValidClient(client) ? SetEntPropEntEx(entity, Prop_Send, "m_hBuilder", client):false;
}

/**
 *	Returns the buildings builder.
 *	Otherwise use GetEntityOwner.
 *
 *	@param	entity	The building entity index.
 *
 *	@error	If the entity is invalid, this returns -1.
 */
stock int TF2_GetBuildingOwner(any entity)	{
	return	GetEntPropEntEx(entity, Prop_Send, "m_hBuilder"):-1;
}

/**
 *	Set the buildings upgrade level.
 *
 *	@param	entity	The building entity index.
 *	@param	level	The level to set.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool TF2_SetBuildingLevel(any entity, int level=1)	{
	return	SetEntPropEx(entity, Prop_Send, "m_iUpgradeLevel", level);
}

/**
 *	Returns the buildings upgrade level.
 *
 *	@param	entity	The building entity index.
 *	@error	If the entity is invalid, this returns -1.
 */
stock int TF2_GetBuildingLevel(any entity)	{
	return	HasEntPropEx(entity, Prop_Send, "m_iUpgradeLevel") ? GetEntProp(entity, Prop_Send, "m_iUpgradeLevel"):-1;
}

/**
 *	Set the buildings max upgrade level.
 *
 *	@param	entity	The building entity index.
 *	@param	level	The maximum upgrade level to set.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool TF2_SetBuildingMaxLevel(any entity, int level=3)	{
	return	SetEntPropEx(entity, Prop_Send, "m_iHighestUpgradeLevel", level);
}

/**
 *	Returns the buildings max upgrade level.
 *
 *	@param	entity	The building entity index.
 *
 *	@error	If the entity is invalid, this returns -1.
 */
stock int TF2_GetBuildingMaxLevel(any entity)	{
	return	GetEntPropEx(entity, Prop_Send, "m_iHighestUpgradeLevel");
}

/**
 *	Set the buildings required metal to upgrade to next upgrade level.
 *
 *	@param	entity	The building entity index.
 *	@param	metal	The metal required.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool TF2_SetBuildingMetalRequired(any entity, int metal)	{
	return	SetEntPropEx(entity, Prop_Send, "m_iUpgradeMetalRequired", metal);
}

/**
 *	Returns the buildings required metal to upgrade to next upgrade level.
 *
 *	@param	entity	The building entity index.
 *
 *	@error	If the entity is invalid, this returns -1.
 */
stock int TF2_GetBuildingMetalRequired(any entity)	{
	return	GetEntPropEx(entity, Prop_Send, "m_iUpgradeMetalRequired");
}

/**
 *	Destroys the building.
 *
 *	@param	entity	The building index.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool TF2_DestroyBuilding(any entity)	{
	if(HasEntPropEx(entity, Prop_Send, "m_hBuilder"))	{
		SetVariantInt(999999);
		AcceptEntityInput(entity, "RemoveHealth");
		return	true;
	}
	
	return	false;
}

#if !defined _tklib_no_sdktools
/**
 *	Returns if MvM (Mann-Vs-Machine) mode is active.
 */
stock bool TF2_IsMvMGameMode()	{
	return view_as<bool>(GameRules_GetProp("m_bPlayingMannVsMachine"));
}
#else
#error TF2_IsMvMGameMode() requires SDKTools include
#endif

/**
 *	Returns a random TFTeam team (Red or Blue) (Including Green or Yellow if TF2 Classic)
 *
 *	@return	Returns a TFTeam team.
 */
#if !defined _tklib_disable_gameidentifier
stock TFTeam TF2_GetRandomTeam()	{
	return view_as<TFTeam>(IsCurrentGame(Game_TF2C) ? GetRandomInt(2, 5) : GetRandomInt(2, 3));
}
#else
#error TF2_GetRandomTeam() requires GameIdentifer include. [IsCurrentGame()]
#endif

/**
 *	Returns the gametype of the server.
 */
stock TFGameType TF2_GetGameType()	{
	return TFGameType(GameRules_GetProp("m_nGameType"));
}

/**
 *	Set the gametype of the server.
 *
 *	@param	gametype	TFGameType gametype to set.
 */
stock void TF2_SetGameType(TFGameType gametype)	{
	GameRules_SetProp("m_nGameType", gametype);
}

/**
 *	Returns if Waiting For Players phase is active.
 */
stock bool TF2_IsWaitingForPlayers()	{
	return	bool(GameRules_GetProp("m_bInWaitingForPlayers"));
}

/**
 *	Set the Waiting For Players phase.
 *
 *	@param	value	If true, this forces waiting for players phase to be active.
 */
stock void TF2_SetWarmupForPlayers(bool value)	{
	GameRules_SetProp("m_bInWaitingForPlayers", value);
}

/**
 *	Returns if Powerup Mode is active.
 */
stock bool TF2_IsPowerupMode()	{
	return	bool(GameRules_GetProp("m_bPowerupMode"));
}

/**
 *	Set the Powerup Mode.
 *
 *	@param	value	If true, this forces Powerup Mode to be active.
 */
stock void TF2_SetPowerupMode(bool value)	{
	GameRules_SetProp("m_bPowerupMode", value);
}

/**
 *	Returns if Truce is active.
 */
stock bool TF2_IsTruceActive()	{
	return	bool(GameRules_GetProp("m_bTruceActive"));
}

/**
 *	Set the Truce.
 *
 *	@param	value	If true, this forces Truce to be active.
 */
stock void TF2_SetTruce(bool value)	{
	GameRules_SetProp("m_bTruceActive", value);
}

/**
 *	Get users airdash count.
 *
 *	@param	client	The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int TF2_GetClientAirDash(any client)	{
	return GetEntPropEx(client, Prop_Send, "m_iAirDash");
}

/**
 *	Set users airdash count.
 *
 *	@param	client	The users index.
 *	@param	value	The value to set.
 *
 *	@error	If the user is invalid or has no m_iAirDash property, this returns false.
 */
stock bool TF2_SetClientAirDash(int client, int value)	{
	return SetEntPropEx(client, Prop_Send, "m_iAirDash", value);
}

/**
 *	Returns if TF2Attributes is available.
 */
stock bool IsTF2AttributesLoaded()	{
	return view_as<bool>(GetFeatureStatus(FeatureType_Native, "TF2Attrib_SetByName") == FeatureStatus_Available);
}

/**
 *	Returns the Footprint name type.
 *
 *	@param	defindex	The definition index of the footprint.
 *	@param	type		The buffer to store the name.
 *	@param	maxlen		The maximum length of the buffer.
 *
 *	@noreturn.
 */
stock void TF2_GetFootprintName(int defindex, char[] type, int maxlen)	{
	switch(defindex)	{
		case 1: strcopy(type, maxlen, "Team Based");
		case 2: strcopy(type, maxlen, "Purple");
		case 3: strcopy(type, maxlen, "4 8 15 16 23 42");
		case 7777: strcopy(type, maxlen, "Blue");
		case 83552: strcopy(type, maxlen, "Ghost in the Machine");
		case 300000: strcopy(type, maxlen, "Satan's Blue");
		case 933333: strcopy(type, maxlen, "Light Blue");
		case 3100495: strcopy(type, maxlen, "Dark Green");
		case 4552221: strcopy(type, maxlen, "Corrupted Green");
		case 5322826: strcopy(type, maxlen, "Brown");
		case 8208497: strcopy(type, maxlen, "Cream");
		case 8355220: strcopy(type, maxlen, "Oak Tree Brown");
		case 8421376: strcopy(type, maxlen, "Yellow");
		case 13595446: strcopy(type, maxlen, "Flames");
		case 41234123: strcopy(type, maxlen, "Pink");
		case 51234123: strcopy(type, maxlen, "Lime");
		default: strcopy(type, maxlen, "Unknown");
	}
}

/**
 *	Attach an effect particle onto an entity.
 *
 *	@param	entity			The entity index to target.
 *	@param	particle_name	Particle name to set.
 *	@param	offset			Offset by Z-Angle.
 *
 *	@return	Returns the particle entity.
 */
stock int TF2_AttachParticle(any entity, const char[] particle_name, float offset=0.0)	{
	int particle = CreateEntityByName("info_particle_system");
	if(IsValidEntityEx(particle))	{
		float pos[3];
		GetEntityAbsOrigin(entity, pos);
		pos[2] += offset;
		
		TeleportEntity(particle, pos, NULL_VECTOR, NULL_VECTOR);
		DispatchKeyValue(particle, "effect_name", particle_name);
		DispatchSpawn(particle);
		SetVariantString("!activator");
		AcceptEntityInput(particle, "SetParent", entity);
		ActivateEntity(particle);
		AcceptEntityInput(particle, "start");
	}
	
	return particle;
}

/**
 *	Spawns a weapon entity.
 *	The weapons spawned are visible to everyone.
 *	Requires TF2Econ Data plugin.
 *	TF2Attributes for golden frying pan to be corrected.
 *
 *	@param	client		The users index.
 *	@param	defindex	The item definition index.
 *	@param	level		The item level.
 *	@param	quality		The item quality.
 *
 *	@return	Returns the weapon entity index. If invalid user or entity is invalid returns -1.
 */
stock int TF2_GiveWeapon(int client, int defindex, int level, TFQuality quality)	{
	static int weapon;
	
	char classname[256];
	TF2Econ_GetItemClassName(defindex, classname, sizeof(classname));
	//TF2Econ_TranslateWeaponEntForClass(classname, sizeof(classname), TF2_GetPlayerClass(client));
	
	/* Credits to PC Gamer for most of the code. */
	if(IsValidEntityEx((weapon = CreateEntityByName(classname))) && Tklib_IsValidClient(client, _, true))	{
		char netclass[64];
		GetEntityNetClass(weapon, netclass, sizeof(netclass));
		
		SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), defindex);
		SetEntData(weapon, FindSendPropInfo(netclass, "m_iEntityLevel"), level);
		SetEntData(weapon, FindSendPropInfo(netclass, "m_iEntityQuality"), quality);
		SetEntData(weapon, FindSendPropInfo(netclass, "m_bInitialized"), true);
		SetEntPropEnt(weapon, Prop_Send, "m_hOwnerEntity", client);
		SetEntProp(weapon, Prop_Send, "m_iAccountID", GetSteamAccountID(client));
		SetEntProp(weapon, Prop_Send, "m_bValidatedAttachedEntity", 1);
		
		switch(defindex)	{
			case 735,736,810,831,933,1080,1102:	{
				SetEntProp(weapon, Prop_Send, "m_iObjectType", 3);
				SetEntProp(weapon, Prop_Data, "m_iSubType", 3);
				SetEntProp(weapon, Prop_Send, "m_aBuildableObjectTypes", 0, _, 0);
				SetEntProp(weapon, Prop_Send, "m_aBuildableObjectTypes", 0, _, 1);
				SetEntProp(weapon, Prop_Send, "m_aBuildableObjectTypes", 0, _, 2);
				SetEntProp(weapon, Prop_Send, "m_aBuildableObjectTypes", 1, _, 3);
			}
			case 998: SetEntData(weapon, FindSendPropInfo(netclass, "m_nChargeResistType"), GetRandomInt(0,2));
			#if defined _tf2attributes_included
			case 1071:	{
				TF2Attrib_SetByName(weapon, "item style override", 0.0);
				TF2Attrib_SetByName(weapon, "loot rarity", 1.0);
				TF2Attrib_SetByName(weapon, "turn to gold", 1.0);
			}
			#endif
		}
		
		DispatchSpawn(weapon);
		EquipPlayerWeapon(client, weapon);
	}
	
	return weapon;
}

/**
 *	Give the wearable to the client.
 *
 *	@param	client		The users index.
 *	@param	defindex	The wearable definition index.
 *	@param	quality		The wearable TFQuality index.
 *	@param	level		The wearable level.
 *
 *	@return	Returns the wearable entity index. If invalid user or entity is invalid returns -1.
 */
stock int TF2_GiveWearable(int client, int defindex, int level, TFQuality quality)	{
	static int wearable;
	static Handle EquipWearable;
	static GameData data;
	StartPrepSDKCall(SDKCall_Player);
	PrepSDKCall_SetVirtual((data = new GameData("sm-tf2.games")).GetOffset("RemoveWearable")-1);
	PrepSDKCall_AddParameter(SDKType_CBaseEntity, SDKPass_Pointer);
	EquipWearable = EndPrepSDKCall();
	
	/* Credits to PC Gamer for most of the code. */
	if(EquipWearable != null && IsValidEntityEx((wearable = CreateEntityByName("tf_wearable"))) && Tklib_IsValidClient(client, _, true))	{
		SetEntData(wearable, FindSendPropInfo("CTFWearable", "m_iItemDefinitionIndex"), defindex);
		SetEntData(wearable, FindSendPropInfo("CTFWearable", "m_iEntityLevel"), level);
		SetEntData(wearable, FindSendPropInfo("CTFWearable", "m_iEntityQuality"), quality);
		SetEntData(wearable, FindSendPropInfo("CTFWearable", "m_bInitialized"), true);
		SetEntPropEnt(wearable, Prop_Send, "m_hOwnerEntity", client);
		SetEntProp(wearable, Prop_Send, "m_iAccountID", GetSteamAccountID(client));
		SetEntProp(wearable, Prop_Send, "m_bValidatedAttachedEntity", 1);
		DispatchSpawn(wearable);
		SDKCall(EquipWearable, client, wearable);
	}
	
	delete EquipWearable;
	delete data;
	return wearable;
}

/**
 *	Returns wheter the definition index has an australium variant available.
 *
 *	@param	defindex	The weapon definition index.
 */
stock bool TF2_IsValidAustralium(int defindex)	{
	switch(defindex)	{
		case 4,7,13,14,15,16,18,19,20,
		21,29,36,38,45,61,132,141,194,
		197,200,201,202,203,205,206,207,
		208,211,228,264,424: return true;
	}
	
	return false;
}

/**
 *	Turns the weapon into australium variant.
 *	Requires TF2Attributes.
 *
 *	@param	weapon	The weapon entity index.
 *
 *	@noreturn.
 */
stock void TF2_TurnAustralium(any weapon)	{
	if(!IsValidEntityEx(weapon))
		return;

	char netclass[64];
	GetEntityNetClass(weapon, netclass, sizeof(netclass));

	int defindex = GetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"));
	
	if(!TF2_IsValidAustralium(defindex))
		return;
	
	/* Force the stock weapons to be 'upgradable' version. */
	switch(defindex)	{
		case 7: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 197);
		case 13: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 200);
		case 14: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 201);
		case 15: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 202);
		case 16: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 203);
		case 18: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 205);
		case 19: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 206);
		case 20: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 207);
		case 21: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 208);
		case 29: SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 211);
	}
	
	/* Turn the weapon to strange quality and random level. */
	SetEntData(weapon, FindSendPropInfo(netclass, "m_iEntityQuality"), TFQuality_Strange); /* Strange. */
	SetEntData(weapon, FindSendPropInfo(netclass, "m_iEntityLevel"), GetRandomInt(0, 100)); /* Random level between 0 and 100. */
	
	/* Frying Pan. */
	switch(defindex == 264)	{
		case true:	{
			SetEntData(weapon, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), 1071); /* Turn to golden frying pan. */
			TF2Attrib_SetByName(weapon, "turn to gold", 1.0);
			TF2Attrib_SetByName(weapon, "killstreak tier", 1.0);
			TF2Attrib_SetByName(weapon, "killstreak effect", view_as<float>(GetRandomInt(2002, 2008)));
			TF2Attrib_SetByName(weapon, "killstreak idleeffect", view_as<float>(GetRandomInt(1, 7)));
			TF2Attrib_SetByName(weapon, "item style override", 0.0);
		}
		/* Turn the weapon to australium. */
		case false:	{
			TF2Attrib_SetByName(weapon, "is australium item", 1.0);
			TF2Attrib_SetByName(weapon, "item style override", 1.0);
		}
	}
	
	TF2Attrib_SetByName(weapon, "loot rarity", 1.0);
}

/**
 *	Returns the killstreaker name.
 *
 *	@param	defindex	The definition index.
 *	@param	buffer		Buffer to store the killstreaker name.
 *	@param	maxlen		Maximum length of the buffer.
 *
 *	@return	Returns true if the definition index is valie, false otherwise. 
 */
stock bool TF2_GetKillstreakerEffectName(int defindex, char[] buffer, int maxlen)	{
	switch(defindex)	{
		/* Fire Horns. */
		case 2002:	{
			strcopy(buffer, maxlen, "Fire Horns");
			return true;
		}
		
		/* Cerebral Discharge. */
		case 2003:	{
			strcopy(buffer, maxlen, "Cerebral Discharge");
			return true;
		}
		
		/* Tornado. */
		case 2004:	{
			strcopy(buffer, maxlen, "Tornade");
			return true;
		}
		
		/* Flames. */
		case 2005:	{
			strcopy(buffer, maxlen, "Flames");
			return true;
		}
		
		/* Singularity. */
		case 2006:	{
			strcopy(buffer, maxlen, "Singularity");
			return true;
		}
		
		/* Incinerator. */
		case 2007:	{
			strcopy(buffer, maxlen, "Incinerator");
			return true;
		}
		
		/* Hypno-Beam. */
		case 2008:	{
			strcopy(buffer, maxlen, "Hypno-Beam");
			return true;
		}
	}
	
	return false;
}

/**
 *	Returns the killstreak sheen name.
 *
 *	@param	defindex	The sheen definition index.
 *	@param	buffer		The sheen name buffer string.
 *	@param	maxlen		The maximum length of the sheen name.
 *
 *	@return	Returns true if the definition index is valid, false otherwise.
 */
stock bool TF2_GetKillstreakSheenName(int defindex, char[] buffer, int maxlen)	{
	switch(defindex)	{
		/* Team Shine. */
		case 1:	{
			strcopy(buffer, maxlen, "Team Shine");
			return true;
		}
		
		/* Deadly Daffodil. */
		case 2:	{
			strcopy(buffer, maxlen, "Deadly Daffodil");
			return true;
		}
		
		/* Manndarin. */
		case 3:	{
			strcopy(buffer, maxlen, "Manndarin");
			return true;
		}
		
		/* Mean Green. */
		case 4:	{
			strcopy(buffer, maxlen, "Mean Green");
			return true;
		}
		
		/* Agonizing Emerald. */
		case 5:	{
			strcopy(buffer, maxlen, "Agonizing Emerald");
			return true;
		}
		
		/* Villainous Violet. */
		case 6:	{
			strcopy(buffer, maxlen, "Villainous Violet");
			return true;
		}
		
		/* Hot Rod. */
		case 7:	{
			strcopy(buffer, maxlen, "Hot Rod");
			return true;
		}
	}
	
	return false;
}

/**
 *	Returns an attribute's value of an entity.
 *	Requires TF2Attributes.
 *
 *	@param	entity		Entity index to get the attribute from. Must have m_AttributeList.
 *	@param	defindex	Definition index of the attribute, as from the number on the attribute entry in items_game.
 *
 *	@return				True if the attribute was added successfully, false if entity does not have m_AttributeList.
 *
 *	@error				Invalid entity index or attribute name will return -1.0.
 */
stock float TF2Attrib_GetByDefIndexEx(int entity, int defindex) 	{
	if(!IsValidEntityEx(entity))
		return -1.0;
	
	int indice[16];
	float value[16];
	
	for(int i = 0; i < TF2Attrib_GetSOCAttribs(entity, indice, value); i++) 	{
		if(indice[i] == defindex) 
			return value[i];
	}
	
	return 0.0;
}

/**
 *	Returns wheter the warpaint definition index is valid.
 *
 *	@param	defindex	The warpaint definition index.
 *
 *	@return	If the warpaint is valid, this returns true. False otherwise.
 */
stock bool TF2_IsValidWarPaint(int defindex)	{
	switch(defindex)	{
		case 200,201,202,203,204,205,206,207,208,
		209,210,211,212,213,214,215,217,218,220,
		221,223,224,225,226,228,230,232,234,235,
		236,237,238,239,240,241,242,243,244,245,
		246,247,248,249,250,251,252,253,254,255,
		256,257,258,259,260,261,262,263,264,265,
		266,267,268,269,270,271,272,273,275,276,
		277,278,279,280,281,282,283,284,285,286,
		287,289,290,291,292,293,294,295,296,297,
		300,301,302,303,304,305,306,307,308,309,
		310,390,391: return true;
	}
	
	return false;
}

/**
 *	Returns the warpaint name.
 *
 *	@param	defindex	The warpaint definition index.
 *	@param	buffer		The warpaint name.
 *	@param	maxlen		The warpaint name maximum length.
 *
 *	@noreturn.
 */
stock void TF2_GetWarPaintName(int defindex, char[] buffer, int maxlen)	{
	switch(defindex)	{
		case 200: strcopy(buffer, maxlen, "Bloom Buffed");
		case 201: strcopy(buffer, maxlen, "Quack Canvassed");
		case 202: strcopy(buffer, maxlen, "Bank Rolled");
		case 203: strcopy(buffer, maxlen, "Merc Stained");
		case 204: strcopy(buffer, maxlen, "Kill Covered");
		case 205: strcopy(buffer, maxlen, "Fire Glazed");
		case 206: strcopy(buffer, maxlen, "Pizza Polished");
		case 207: strcopy(buffer, maxlen, "Bonk Varnished");
		case 208: strcopy(buffer, maxlen, "Star Crossed");
		case 209: strcopy(buffer, maxlen, "Clover Camo'd");
		case 210: strcopy(buffer, maxlen, "Freedom Wrapped");
		case 211: strcopy(buffer, maxlen, "Cardboard Boxed");
		case 212: strcopy(buffer, maxlen, "Dream Piped");
		case 213: strcopy(buffer, maxlen, "Miami Element");
		case 214: strcopy(buffer, maxlen, "Neo Tokyo");
		case 215: strcopy(buffer, maxlen, "Geometrical Teams");
		case 217: strcopy(buffer, maxlen, "Bomber Soul");
		case 218: strcopy(buffer, maxlen, "Uranium");
		case 220: strcopy(buffer, maxlen, "Cabin Fevered");
		case 221: strcopy(buffer, maxlen, "Polar Surprise");
		case 223: strcopy(buffer, maxlen, "Hana");
		case 224: strcopy(buffer, maxlen, "Dovetailed");
		case 225: strcopy(buffer, maxlen, "Cosmic Calamity");
		case 226: strcopy(buffer, maxlen, "Hazard Warning");
		case 228: strcopy(buffer, maxlen, "Mosaic");
		case 230: strcopy(buffer, maxlen, "Jazzy");
		case 232: strcopy(buffer, maxlen, "Alien Tech");
		case 234: strcopy(buffer, maxlen, "Damascus and Mahogany");
		case 235: strcopy(buffer, maxlen, "Skull Study");
		case 236: strcopy(buffer, maxlen, "Haunted Ghosts");
		case 237: strcopy(buffer, maxlen, "Spectral Shimmered");
		case 238: strcopy(buffer, maxlen, "Spirit Of Halloween");
		case 239: strcopy(buffer, maxlen, "Horror Holiday");
		case 240: strcopy(buffer, maxlen, "Totally Boned");
		case 241: strcopy(buffer, maxlen, "Electroshocked");
		case 242: strcopy(buffer, maxlen, "Ghost Town");
		case 243: strcopy(buffer, maxlen, "Tumor Toasted");
		case 244: strcopy(buffer, maxlen, "Calavera Canvas");
		case 245: strcopy(buffer, maxlen, "Snow Covered");
		case 246: strcopy(buffer, maxlen, "Frost Ornamented");
		case 247: strcopy(buffer, maxlen, "Smissmass Village");
		case 248: strcopy(buffer, maxlen, "Igloo");
		case 249: strcopy(buffer, maxlen, "Seriously Snowed");
		case 250: strcopy(buffer, maxlen, "Smissmas Camo");
		case 251: strcopy(buffer, maxlen, "Sleighin' Style");
		case 252: strcopy(buffer, maxlen, "Alpine");
		case 253: strcopy(buffer, maxlen, "Gift Wrapped");
		case 254: strcopy(buffer, maxlen, "Winterland Wrapped");
		case 255: strcopy(buffer, maxlen, "Helldriver");
		case 256: strcopy(buffer, maxlen, "Organ-ically Hellraised");
		case 257: strcopy(buffer, maxlen, "Spectrum Splattered");
		case 258: strcopy(buffer, maxlen, "Candy Coated");
		case 259: strcopy(buffer, maxlen, "Pumpkin Pied");
		case 260: strcopy(buffer, maxlen, "Sweet Toothed");
		case 261: strcopy(buffer, maxlen, "Crawlspace Critters");
		case 262: strcopy(buffer, maxlen, "Portal Plastered");
		case 263: strcopy(buffer, maxlen, "Death Deluxe");
		case 264: strcopy(buffer, maxlen, "Raving Dead");
		case 265: strcopy(buffer, maxlen, "Eyestalker");
		case 266: strcopy(buffer, maxlen, "Spider's Cluster");
		case 267: strcopy(buffer, maxlen, "Gourdy Green");
		case 268: strcopy(buffer, maxlen, "Mummified Mimic");
		case 269: strcopy(buffer, maxlen, "Spider Season");
		case 270: strcopy(buffer, maxlen, "Gingerbread Winner");
		case 271: strcopy(buffer, maxlen, "Saccharine Striped");
		case 272: strcopy(buffer, maxlen, "Elfin Enamel");
		case 273: strcopy(buffer, maxlen, "Peppermint Swirl");
		case 275: strcopy(buffer, maxlen, "Snow Globalization");
		case 276: strcopy(buffer, maxlen, "Gifting Mann's Wrapping Paper");
		case 277: strcopy(buffer, maxlen, "Snowflake Swirled");
		case 278: strcopy(buffer, maxlen, "Smissmass Spycrabs");
		case 279: strcopy(buffer, maxlen, "Frozen Aurora");
		case 280: strcopy(buffer, maxlen, "Starlight Serenity");
		case 281: strcopy(buffer, maxlen, "Frosty Delivery");
		case 282: strcopy(buffer, maxlen, "Glacial Glazed");
		case 283: strcopy(buffer, maxlen, "Cookie Fortress");
		case 284: strcopy(buffer, maxlen, "Sarsaparilla Sprayed");
		case 285: strcopy(buffer, maxlen, "Swashbuckled");
		case 286: strcopy(buffer, maxlen, "Skull Cracked");
		case 287: strcopy(buffer, maxlen, "Missfortunate");
		case 289: strcopy(buffer, maxlen, "Neon-Ween");
		case 290: strcopy(buffer, maxlen, "Simple Spirits");
		case 291: strcopy(buffer, maxlen, "Broken Bones");
		case 292: strcopy(buffer, maxlen, "Potent Poison");
		case 293: strcopy(buffer, maxlen, "Searing Souls");
		case 294: strcopy(buffer, maxlen, "Party Phantoms");
		case 295: strcopy(buffer, maxlen, "Polster-Guised");
		case 296: strcopy(buffer, maxlen, "Kiln and conquer");
		case 297: strcopy(buffer, maxlen, "Necromanced");
		case 300: strcopy(buffer, maxlen, "Yeti Coated");
		case 301: strcopy(buffer, maxlen, "Dark Pigmented");
		case 302: strcopy(buffer, maxlen, "Mannana");
		case 303: strcopy(buffer, maxlen, "Macaw Masked");
		case 304: strcopy(buffer, maxlen, "Sax Waxed");
		case 305: strcopy(buffer, maxlen, "Anodized Aloha");
		case 306: strcopy(buffer, maxlen, "Bamboo Brushed");
		case 307: strcopy(buffer, maxlen, "Tiger Buffed");
		case 308: strcopy(buffer, maxlen, "Croc Dusted");
		case 309: strcopy(buffer, maxlen, "Piña Polished");
		case 310: strcopy(buffer, maxlen, "Leopard Printed");
		case 390: strcopy(buffer, maxlen, "Dragon Slayer");
		case 391: strcopy(buffer, maxlen, "Smissmass Sweater");
		default: Format(buffer, maxlen, "Unknown warpaint (%i)", defindex);
	}
}

/**
 *	Returns the users active taunt definition index.
 *
 *	@param	client	The users index.
 *
 *	@return	Returns the taunt definition index. -1 if invalid user or 0 if no taunt.
 */
stock int TF2_GetClientActiveTauntDefinitionIndex(int client)	{
	return GetEntPropEx(client, Prop_Send, "m_iTauntItemDefIndex");
}

/**
 *	Returns the paintcan name.
 *
 *	@param	defindex	The paint definition index.
 *	@param	buffer		The buffer to store the paint name.
 *	@param	maxlen		The maximum length of the buffer name.
 *
 *	@noreturn.
 */
stock void TF2_GetPaintName(int defindex, char[] buffer, int maxlen)	{
	switch(defindex)	{
		case 2960676: strcopy(buffer, maxlen, "After Eight");
		case 3100495: strcopy(buffer, maxlen, "A Colour Similiar To Slate");
		case 3329330: strcopy(buffer, maxlen, "A Bitter Taste Of Defeat And Lime");
		case 3874595: strcopy(buffer, maxlen, "Balaclavas Are Forever");
		case 4345659: strcopy(buffer, maxlen, "Zepheniahs Greed");
		case 4732984: strcopy(buffer, maxlen, "Operators Overalls");
		case 5322826: strcopy(buffer, maxlen, "Noble Hatters Violet");
		case 6637376: strcopy(buffer, maxlen, "An Air Of Debonair");
		case 6901050: strcopy(buffer, maxlen, "Radigan Conagher Brown");
		case 7511618: strcopy(buffer, maxlen, "Indubitably Green");
		case 8154199: strcopy(buffer, maxlen, "Ye Olde Rustic Colour");
		case 8208497: strcopy(buffer, maxlen, "A Deep Commitment To Purple");
		case 8289918: strcopy(buffer, maxlen, "Aged Moustache Grey");
		case 8400928: strcopy(buffer, maxlen, "The Value Of Teamwork");
		case 8421376: strcopy(buffer, maxlen, "Drably Olive");		
		case 10843461: strcopy(buffer, maxlen, "Muskelmannbraun");
		case 11049612: strcopy(buffer, maxlen, "Waterlogged Lab Coat");
		case 12073019: strcopy(buffer, maxlen, "Team Spirit");
		case 12807213: strcopy(buffer, maxlen, "Cream Spirit");
		case 1315860: strcopy(buffer, maxlen, "A Distinctive Lack Of Blue");
		case 13595446: strcopy(buffer, maxlen, "Mann Co. Orange");
		case 14204632: strcopy(buffer, maxlen, "Colour No 216-190-216");
		case 15132390: strcopy(buffer, maxlen, "An Extraordinary Abudance Of Tinge");
		case 15185211: strcopy(buffer, maxlen, "Australium Gold");
		case 15308410: strcopy(buffer, maxlen, "Dark Salmon Injustice");
		case 12377523: strcopy(buffer, maxlen, "A Mann's Mint");
		case 12955537: strcopy(buffer, maxlen, "Peculiarly Drab Tincture");
		case 15787660: strcopy(buffer, maxlen, "The Colour Of A Gentlemanns Business Pants");
		case 16738740: strcopy(buffer, maxlen, "Pink As Hell");
	}
}

#endif