//Get the team name via strings for colored chat purpose (Usage example: TF2_GetTeamStringName[GetClientTeam(client)] will return the correct team name)
stock char TF2_GetTeamStringName[][]	=	{
	"{grey}Unassigned{default}",
	"{grey}Spectators{default}",
	"{red}Red{default}",
	"{blue}Blu{default}",
	"{lightgreen}Grn{default}",
	"{orange}Ylw{default}"
};

stock char TF2_GetTeamColour[][]	=	{
	"{grey}",
	"{grey}",
	"{red}",
	"{blue}",
	"{lightgreen}",
	"{orange}"
};

//TF2 Flag Event
enum	TFFlag	{
	TFFlag_None		=	0,
	TFFlag_PickedUp	=	1,
	TFFlag_Captured	=	2,
	TFFlag_Defended	=	3,
	TFFlag_Dropped	=	4,
	TFFlag_Carrier	=	5
}

//TF Slots
enum	TFSlot	{
	TFSlot_Invalid	=	-1,
	TFSlot_Primary	=	0,
	TFSlot_Secondary=	1,
	TFSlot_Melee	=	2,
	TFSlot_PDA		=	3,
	TFSlot_PDA2		=	4
}

enum	TFCritType	{
	TFCritType_None		=	0,
	TFCritType_Minicrit	=	1,
	TFCritType_Crit		=	2
}

enum	TFBuilding	{
	TFBuilding_Invalid				=	-1,
	TFBuilding_Sentrygun			=	0,
	TFBuilding_Dispenser			=	1,
	TFBuilding_Teleporter_Entrance	=	2,
	TFBuilding_Teleporter_Exit		=	3,
	TFBuilding_MiniSentry			=	4
}

#define	TFTeam(%1)		view_as<TFTeam>(%1)
#define	TFFlag(%1)		view_as<TFFlag>(%1)
#define	TFSlot(%1)		view_as<TFSlot>(%1)
#define	TFCritType(%1)	view_as<TFCritType>(%1)
#define	TFBuilding(%1)	view_as<TFBuilding>(%1)


/**
 *	Set the users mvm currency/cash.
 *
 *	@param client		The users index.
 *	@param value		Currency value.
 */
stock bool TF2_SetClientMvMCash(int client, int value)	{
	if(!Tklib_IsValidClient(client))
		return	false;
	
	SetEntProp(client, Prop_Send, "m_nCurrency", value);
	return	true;
}

/**
 *	Returns the users mvm currency/cash
 *
 *	@param client		The users index.
 */
stock int TF2_GetClientMvMCash(int client)	{
	if(!Tklib_IsValidClient(client) || !HasEntProp(client, Prop_Send, "m_nCurrency"))
		return	-1;
	
	return GetEntProp(client, Prop_Send, "m_nCurrency");
}

/**
 *	Set the users taunt cam on/off, useful for thirdperson plugin.
 *
 *	@param client		The users index.
 *	@param value		Bool value.
 */
stock bool TF2_SetClientTauntCam(int client, bool value)	{
	if(!Tklib_IsValidClient(client, true, true) || !HasEntProp(client, Prop_Send, "m_nForceTauntCam"))
		return	false;
	
	SetEntProp(client, Prop_Send, "m_nForceTauntCam", value);
	return	true;
}

/**
 *	Returns the users taunt cam.
 *
 *	@param client		The users index.
 */
stock bool TF2_GetClientTauntCam(int client)	{
	if(!Tklib_IsValidClient(client, _, true) || !HasEntProp(client, "m_nForceTauntCam"))
		return	false;
	
	return GetEntPropBool(client, Prop_Send, "m_nForceTauntCam");
}

//Set or get the users killstreak count
/**
 *	Set the clients killstreak count
 *
 *	@param	client		The users index.
 *	@param	value		Killstreak count.
 */
stock void TF2_SetClientKillstreak(int client, int value=5)	{
	if(Tklib_IsValidClient(client) && HasEntProp(client, Prop_Send, "m_nStreaks"))
		SetEntProp(client, Prop_Send, "m_nStreaks", value);
}

/**
 *	Returns the users killstreak count
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this will return -1.
 */
stock int TF2_GetClientKillstreak(int client)	{
	if(!Tklib_IsValidClient(client) || !HasEntProp(client, Prop_Send, "m_nStreaks"))
		return	-1;
	
	return	GetEntProp(client, Prop_Send, "m_nStreaks");
}

/**
 *	Returns the users cloak meter.
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this will return -1.0. (Altough if the target doesn't have a cloak, this will put out an error)
 */
stock float TF2_GetClientCloakMeter(int client)	{
	if(!Tklib_IsValidClient(client, _, true) || !HasEntProp(client, Prop_Send, "m_flCloakMeter"))
		return	-1.0;
	
	return	GetEntPropFloat(client, Prop_Send, "m_flCloakMeter");
}

/**
 *	Set the clients cloak meter.
 *
 *	@param client		The users index.
 *	@param value		Cloak duration.
 *	@error If the user is invalid, nothing will happen. (Altough if the target doesn't have a cloak, this will put out an error)
 */
stock float TF2_SetClientCloakMeter(int client, float value=1.0)	{
	if(Tklib_IsValidClient(client) && HasEntProp(client, Prop_Send, "m_flCloakMeter"))
		SetEntPropFloat(client, Prop_Send, "m_flCloakMeter", value);
}

/**
 *	Returns the users glow value.
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this will return false.
*/
stock bool TF2_GetClientGlow(int client)	{
	if(!Tklib_IsValidClient(client) || !HasEntProp(client, "m_bGlowEnabled"))
		return	false;
	
	return	GetEntPropBool(client, Prop_Send, "m_bGlowEnabled");
}

/**
 *	Toggle the clients glow value.
 *
 *	@param	client		The users index.
 *	@param	value		Glow value.
 *	@error	If the user is invalid, nothing will happen.
 */
stock void TF2_SetClientGlow(int client, bool value)	{
	if(Tklib_IsValidClient(client) && HasEntProp(client, Prop_Send, "m_bGlowEnabled"))
		SetEntProp(client, Prop_Send, "m_bGlowEnabled", value);
}

/**
 *	Returns the users ubercharge value,
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this will return -1.0.
*/
stock float TF2_GetClientUbercharge(int client)	{
	if(!Tklib_IsValidClient(client, _, true) || !HasEntProp(client, "m_flChargeLevel"))
		return	-1.0;
	
	return	GetEntPropFloat(client, Prop_Send, "m_flChargeLevel");
}

/**
 *	Set the clients ubercharge value,
 *
 *	@param	client		The users index.
 *	@param	value		Ubercharge value, Defaulted to 1.0.
 *	@error	If the user is invalid, nothing will happen.
*/
stock void TF2_SetClientUbercharge(int client, float value=1.0)	{
	if(Tklib_IsValidClient(client, _, true) && HasEntProp(client, Prop_Send, "m_flChargeLevel"))
		SetEntPropFloat(client, Prop_Send, "m_flChargeLevel", value);
}

/**
 *	Returns the users charge value,
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, it will return -1.
*/
stock float TF2_GetClientChargeMeter(int client)	{
	if(!Tklib_IsValidClient(client, _, true) || !HasEntProp(client, Prop_Send, "m_flChargeMeter"))
		return	-1.0;
	
	return	GetEntPropFloat(client, Prop_Send, "m_flChargeMeter");
}

/**
 *	Set the users charge value,
 *
 *	@param client		The users index.
 *	@param value		Charge value.
 *	@error				Invalid The users index.
*/
stock void TF2_SetClientChargeMeter(int client, float value=1.0)	{
	if(Tklib_IsValidClient(client, _, true) && HasEntProp(client, Prop_Send, "m_flChargeMeter"))
		SetEntPropFloat(client, Prop_Send, "m_flChargeMeter", value);
}

/**
 *	Returns the users metal value,
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, it will return -1.
*/
stock int TF2_GetClientMetal(int client)	{
	if(!Tklib_IsValidClient(client, _, true) || !HasEntProp(client, Prop_Send, "m_iAmmo"))
		return	-1;
	
	return	GetEntProp(client, Prop_Data, "m_iAmmo", 4, 3);
}

/**
 *	Set the users metal value,
 *
 *	@param	client		The users index.
 *	@param	value		Metal amount.
 *	@error	If the user is invalid, nothing will happen.
*/
stock void TF2_SetClientMetal(int client, int value=200)	{
	if(Tklib_IsValidClient(client, _, true) && HasEntProp(client, Prop_Send, "m_iAmmo"))
		SetEntProp(client, Prop_Data, "m_iAmmo", value, 4, 3);
}

/**
 *	Returns the users decapitations value,
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, this will return -1.
*/
stock int TF2_GetClientDecapitations(int client)	{
	if(!Tklib_IsValidClient(client) || !HasEntProp(client, "m_iDecapitation"))	
		return	-1;
	
	return	GetEntProp(client, Prop_Send, "m_iDecapitations");
}

/**
 *	Set the users decapitations value,
 *
 *	@param	client		The users index.
 *	@param	value		Decapitations amount.
 *	@error	If the user is invalid, nothing will happen.
*/
stock void TF2_SetClientDecapitations(int client, int value=10)	{
	if(Tklib_IsValidClient(client) && HasEntProp(client, Prop_Send, "m_iDecapitations"))
		SetEntProp(client, Prop_Send, "m_iDecapitations");
}

/**
 *	Returns the TF2 Weapon Slot
 *
 *	@param	client		The users index.
 *	@param	slot			TFSlot slot.
 *	@error	If the user is invalid, it will return -1.
 */
stock int TF2_GetPlayerWeaponSlot(int client, TFSlot slot)	{
	return Tklib_IsValidClient(client, _, true) ? GetPlayerWeaponSlot(client, view_as<int>(slot)):-1;
}

/**
 *	Returns the name of the building.
 *
 *	@param	building		The TFBuilding.
 *	@param	buildingname	String to store the building name to.
 *	@param	maxlen			Maximum length of the string.
 */
stock void TF2_GetBuildingName(TFBuilding building, char[] buildingname, int maxlen)	{
	switch(building)	{
		case	TFBuilding_Dispenser:			strcopy(buildingname, maxlen, "Dispenser");
		case	TFBuilding_Sentrygun:			strcopy(buildingname, maxlen, "Sentrygun");
		case	TFBuilding_Teleporter_Entrance:	strcopy(buildingname, maxlen, "Teleporter Entrance");
		case	TFBuilding_Teleporter_Exit:		strcopy(buildingname, maxlen, "Teleporter Exit");
		case	TFBuilding_MiniSentry:			strcopy(buildingname, maxlen, "Mini-Sentry");
	}
}

/**
 *	Returns the TFBuilding type.
 *
 *	@param	entity	The building to get TFBuilding type from.
 *	@error	If the building is invalid, it will return TFBuilding_Invalid.
 */
stock TFBuilding TF2_GetBuildingType(int entity)	{
	if(IsValidEntityEx(entity))	{
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
	}
	
	return TFBuilding_Invalid;
}

/**
 *	Sets if the users current class-model should be forced using its class animations.
 *
 *	@param	client	The users client index.
 *	@param	value	The bool on/off value.
 *	@error	If the user is invalid, nothing will happen.
 */
stock void TF2_SetClassAnimations(int client, bool value)	{
	if(Tklib_IsValidClient(client, _, true) && HasEntProp(client, Prop_Send, "m_bUseClassAnimations"))
		SetEntProp(client, Prop_Send, "m_bUseClassAnimations", value);
}

/**
 *	Sets the clients model.
 *	This is the alternative to SetClientModel, as this actually puts the model.
 *	This is paired with GetClientModel.
 *
 *	@param	client				The users index.
 *	@param	model				The model path.
 *	@param	UseClassAnimations	If true, this will force the model to use the class animations.
 *	@error	If the user is invalid, nothing will happen.
 */
stock void TF2_SetClientModel(int client, char[] model, bool UseClassAnimations)	{
	if(Tklib_IsValidClient(client, _, true))	{
		SetVariantString(model);
		AcceptEntityInput(client, "SetCustomModel");
		TF2_SetClassAnimations(client, UseClassAnimations);
	}
}

/**
 *	Removes a weapon from the users specified weapon slot.
 *	Use this over TF2_RemoveWeaponSlot.
 *
 *	@param	client		The users index.
 *	@param	slot		The weapon slot to target.
 *	@error	If the procedure failed, it returns false.
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
 *	@param	entity	Entity index.
 *	@error	If the entity is invalid, this returns false.
 */
stock bool TF2_IsEntityBuilding(int entity)	{
	if(!IsValidEntityEx(entity) || !HasEntProp(entity, Prop_Send, "m_bBuilding"))
		return	false;
	
	return	GetEntPropBool(entity, Prop_Send, "m_bBuilding");
}

/**
 *	Returns if the entity is a mini-building.
 *
 *	@param	entity	Entity index.
 *	@error	If the entity is invalid, this returns false.
 */
stock bool TF2_IsEntityMiniBuilding(int entity)	{
	if(!IsValidEntityEx(entity))
		return	false;
	
	if(!HasEntProp(client, Prop_Send, "m_bMiniBuilding"))
		return	false;
	
	return	GetEntPropBool(entity, Prop_Send, "m_bMiniBuilding");
}

/**
 *	Returns the buildings builder.
 *	Otherwise use GetEntityOwner.
 *
 *	@param	entity	Entity index.
 *	@param	If the entity is invalid, this returns -1.
 */
stock int TF2_GetBuildingOwner(int entity)	{
	if(!IsValidEntityEx(entity) || !HasEntProp(entity, Prop_Send, "m_hBuilder"))
		return	-1;
	
	return	GetEntProp(entity, Prop_Send, "m_hBuilder");
}