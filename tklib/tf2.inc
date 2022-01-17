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
	return	Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_nCurrency", value):false;
}

/**
 *	Returns the users mvm currency/cash
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid or has no currency property, this returns -1.
 */
stock int TF2_GetClientMvMCash(int client)	{
	return	Tklib_IsValidClient(client) ? GetEntPropEx(client, Prop_Send, "m_nCurrency"):-1; 
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
	return	Tklib_IsValidClient(client, true, true) ? SetEntPropEx(client, Prop_Send, "m_nForceTauntCam", value):false;
}

/**
 *	Returns the users taunt cam.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid or has no taunt cam property, this returns false.
 */
stock bool TF2_GetClientTauntCam(int client)	{
	return	Tklib_IsValidClient(client, _, true) ? GetEntPropBool(client, Prop_Send, "m_nForceTauntCam"):false;
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
	return	Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_nStreaks", value):false;
}

/**
 *	Returns the users killstreak count
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns -1.
 */
stock int TF2_GetClientKillstreak(int client)	{
	return	Tklib_IsValidClient(client) ? GetEntPropEx(client, Prop_Send, "m_nStreaks"):-1;
}

/**
 *	Returns the users cloak meter.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid or has no cloak, this returns -1.0.
 */
stock float TF2_GetClientCloakMeter(int client)	{
	return	Tklib_IsValidClient(client, _, true) ? GetEntPropFloatEx(client, Prop_Send, "m_flCloakMeter"):false;
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
	return	Tklib_IsValidClient(client) ? SetEntPropFloatEx(client, Prop_Send, "m_flCloakMeter", value):false;
}

/**
 *	Returns the users glow value.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
*/
stock bool TF2_IsClientGlowing(int client)	{
	return	Tklib_IsValidClient(client) ? GetEntPropBool(client, Prop_Send, "m_bGlowEnabled"):false;
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
	return	Tklib_IsValidClient(client, _, true) ? GetEntPropFloatEx(client, Prop_Send, "m_flChargeLevel"):false;
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
	return	Tklib_IsValidClient(client, _, true) ? SetEntPropFloatEx(client, Prop_Send, "m_flChargeLevel", value):false;
}

/**
 *	Returns the users charge value,
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns -1.0.
*/
stock float TF2_GetClientChargeMeter(int client)	{
	return	Tklib_IsValidClient(client, _, true) ? GetEntPropFloatEx(client, Prop_Send, "m_flChargeMeter"):-1.0;
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
	return	Tklib_IsValidClient(client, _, true) ? SetEntPropFloatEx(Exclient, Prop_Send, "m_flChargeMeter", value):false;
}

/**
 *	Returns the users metal value,
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid or has no metal-property, this returns -1.
*/
stock int TF2_GetClientMetal(int client)	{
	return	Tklib_IsValidClient(client, _, true) ? GetEntPropEx(client, Prop_Data, "m_iAmmo", 4, 3):-1;
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
	return	Tklib_IsValidClient(client, _, true) ? SetEntPropEx(client, Prop_Data, "m_iAmmo", metal, 4, 3):false;
}

/**
 *	Returns the users decapitations value,
 *
 *	@param	client		The users index.
 *
 *	@error	If the client is invalid or has no decapitation-property, this returns -1.
*/
stock int TF2_GetClientDecapitations(int client)	{
	return	Tklib_IsValidClient(client) ? GetEntPropEx(client, Prop_Send, "m_iDecapitations"):-1;
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
	return	Tklib_IsValidClient(client) ? SetEntPropEx(client, Prop_Send, "m_iDecapitations"):false;
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
	return	Tklib_IsValidClient(client, _, true) ? GetPlayerWeaponSlot(client, int(slot)):-1;
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
		case	TFBuilding_Dispenser:			strcopy(buildingname, maxlen, "Dispenser");
		case	TFBuilding_Sentrygun:			strcopy(buildingname, maxlen, "Sentrygun");
		case	TFBuilding_Teleporter_Entrance:	strcopy(buildingname, maxlen, "Teleporter Entrance");
		case	TFBuilding_Teleporter_Exit:		strcopy(buildingname, maxlen, "Teleporter Exit");
		case	TFBuilding_MiniSentry:			strcopy(buildingname, maxlen, "Mini-Sentry");
		case	TFBuilding_Sapper:				strcopy(buildingname, maxlen, "Sapper");
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
		return	TFBuilding_Dispenser;
	if(StrEqual(classname, "obj_sentrygun"))
		return	TFBuilding_Sentrygun;
	if(StrEqual(classname, "obj_teleporter"))	{
		switch(TF2_GetObjectMode(entity))	{
			case	TFObjectMode_Entrance:	return TFBuilding_Teleporter_Entrance;
			case	TFObjectMode_Exit:		return TFBuilding_Teleporter_Exit;
		}
	}
	if(StrEqual(classname, "obj_minisentry"))
		return	TFBuilding_MiniSentry;
	if(StrEqual(classname, "obj_sapper"))
		return	TFBuilding_Sapper;
	
	return	TFBuilding_Invalid;
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
	return	Tklib_IsValidClient(client, _, true) ? SetEntPropEx(client, Prop_Send, "m_bUseClassAnimations", value):false;
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
		return	true;
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
		RemoveEdict(weapon);
		RemovePlayerItem(client, weapon);
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
	return	GetEntPropBool(entity, Prop_Send, "m_bBuilding");
}

/**
 *	Returns if the entity is a mini-building.
 *
 *	@param	entity	The building entity index.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool TF2_IsEntityMiniBuilding(int entity)	{
	return	GetEntPropBool(entity, Prop_Send, "m_bMiniBuilding");
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
	return	Tklib_IsValidClient(client) ? SetEntPropEntEx(entity, Prop_Send, "m_hBuilder", client):false;
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
stock TFTeam TF2_GetRandomTeam()	{
	return	TFTeam((IdentifyGame() == Game_TF2C) ? GetRandomInt(2, 3, 4, 5) : GetRandomInt(2, 3));
}

/**
 *	Returns the gametype of the server.
 */
stock TFGameType TF2_GetGameType()	{
	return	TFGameType(GameRules_GetProp("m_nGameType"));
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

#endif