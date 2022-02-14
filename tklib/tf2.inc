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
	TFQuality_SelfMade	=	9,
	TFQuality_Strange	=	11
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

#if defined __tf_econ_data_included
/**
 *	Spawns a weapon entity.
 *	The weapons spawned are visible to everyone.
 *
 *	@param	client		The users index.
 *	@param	defindex	The item definition index.
 *	@param	level		The item level.
 *	@param	quality		The item quality.
 *
 *	@return	Returns the entity index.
 */
stock int TF2_GiveWeapon(int client, int defindex, int level, int quality)	{	
	int item = CreateEntityByName(classname[TF2_GetPlayerClass(client)]);
	
	/* Credits to PC Gamer for most of the code. */
	if(IsValidEntityEx(item))	{
		char classname[256], netclass[64];
		TF2Econ_GetItemClassName(defindex, classname, sizeof(classname));
		TF2Econ_TranslateWeaponEntForClass(classname, sizeof(classname), TF2_GetPlayerClass(client));
		
		GetEntityNetClass(item, netclass, sizeof(netclass));
		SetEntData(item, FindSendPropInfo(netclass, "m_iItemDefinitionIndex"), defindex);
		SetEntData(item, FindSendPropInfo(netclass, "m_bInitialized"), 1);
		SetEntData(item, FindSendPropInfo(netclass, "m_iEntityLevel"), level);
		SetEntData(item, FindSendPropInfo(netclass, "m_iEntityQuality"), quality);
		SetEntData(item, FindSendPropInfo(netclass, "m_bValidatedAttachedEntity"), 1);
		SetEntProp(item, Prop_Send, "m_hOwnerEntity", client);
		SetEntProp(item, Prop_Send, "m_iAccountID", GetSteamAccountID(client));
		
		switch(defindex)	{
			case 735,736,810,831,933,1080,1102:	{
				SetEntProp(item, Prop_Send, "m_iObjectType", 3);
				SetEntProp(item, Prop_Data, "m_iSubType", 3);
				SetEntProp(item, Prop_Send, "m_aBuildableObjectTypes", 0, _, 0);
				SetEntProp(item, Prop_Send, "m_aBuildableObjectTypes", 0, _, 1);
				SetEntProp(item, Prop_Send, "m_aBuildableObjectTypes", 0, _, 2);
				SetEntProp(item, Prop_Send, "m_aBuildableObjectTypes", 1, _, 3);
			}
			case 998: SetEntData(item, FindSendPropInfo(netclass, "m_nChargeResistType"), GetRandomInt(0,2));
			#if defined _tf2attributes_included
			case 1071:	{
				TF2Attrib_SetByName(item, "item style override", 0.0);
				TF2Attrib_SetByName(item, "loot rarity", 1.0);
				TF2Attrib_SetByName(item, "turn to gold", 1.0);
			}
			#endif
		}
		
		DispatchSpawn(item);
		EquipPlayerWeapon(client, item);
	}
	
	return item;
}
#else
TF2_GiveWeapon() requires TF2EconData to function.
#endif

/**
 *	Returns wheter the definition index has an australium variant available.
 *
 *	@param	defindex	The weapon definition index.
 */
stock bool TF2_IsValidAustralium(int defindex)	{
	switch(defindex)	{
		case 4, 7, 13, 14, 15, 16, 18, 19, 20, 21, 29, 36, 38, 45, 61, 132,
		141, 194, 197, 200, 201, 202, 203, 205, 206, 207, 208, 211, 228, 264, 424: return true;
	}
	
	return false;
}

#if defined _tf2attributes_included
/**
 *	Turns the weapon into australium variant.
 *
 *	@param	weapon	The weapon entity index.
 *
 *	@noreturn.
 */
stock void TF2_TurnAustralium(any weapon)	{
	if(!IsValidEntityEx(weapon))
		return;
	
	int defindex = GetEntityDefinitionIndex(weapon);
	
	if(!TF2_IsValidAustralium(defindex))
		return;
	
	/* Force the stock weapons to be 'upgradable' version. */
	switch(defindex)	{
		case 7: SetEntityDefinitionIndex(weapon, 197);
		case 13: SetEntityDefinitionIndex(weapon, 200);
		case 14: SetEntityDefinitionIndex(weapon, 201);
		case 15: SetEntityDefinitionIndex(weapon, 202);
		case 16: SetEntityDefinitionIndex(weapon, 203);
		case 18: SetEntityDefinitionIndex(weapon, 205);
		case 19: SetEntityDefinitionIndex(weapon, 206);
		case 20: SetEntityDefinitionIndex(weapon, 207);
		case 21: SetEntityDefinitionIndex(weapon, 208);
		case 29: SetEntityDefinitionIndex(weapon, 211);
	}
	
	/* Turn the weapon to strange quality and random level. */
	SetEntityQuality(weapon, 11); /* Strange. */
	SetEntityQuality(weapon, GetRandomInt(0, 100)); /* Random level between 0 and 100. */
	
	/* Frying Pan. */
	switch(defindex == 264)	{
		case true:	{
			SetEntityDefinitionIndex(weapon, 1071); /* Turn to golden frying pan. */
			TF2Attrib_SetByName(weapon, "turn to gold", 1.0);
			TF2Attrib_SetByName(weapon, "killstreak tier", 1.0);
			TF2Attrib_SetByName(weapon, "killstreak effect", view_as<float>(GetRandomInt(2002, 2008)));
			TF2Attrib_SetByName(weapon, "killstreak idleeffect", view_as<float>(GetRandomInt(1, 7)));
		}
		/* Turn the weapon to australium. */
		case false:	TF2Attrib_SetByName(weapon, "is australium item", 1.0);
	}

	TF2Attrib_SetByName(weapon, "item style override", 1.0);
	TF2Attrib_SetByName(weapon, "loot rarity", 1.0);
}
#else
#error TF2_TurnAustralium() requires TF2Attributes.
#endif

#endif