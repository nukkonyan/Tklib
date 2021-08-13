//Get the team name via strings for colored chat purpose (Usage example: TF2_GetTeamStringName[GetClientTeam(client)] will return the correct team name)
stock char TF2_GetTeamStringName[][]	=	{
	"{grey}Unassigned{default}",
	"{grey}Spectators{default}",
	"{red}Red{default}",
	"{blue}Blu{default}",
	"{lightgreen}Grn{default}",
	"{orange}Ylw{default}"
};

//TF2 Flag Event
enum	{
	TFFlag_None		=	0,
	TFFlag_PickedUp	=	1,
	TFFlag_Captured	=	2,
	TFFlag_Defended	=	3,
	TFFlag_Dropped	=	4,
	TFFlag_Carrier	=	5
}

//TF Slots
enum	TFSlot
{
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


/**
 *	Set the users mvm currency/cash.
 *
 *	@param client		The users index.
 *	@param value		Currency value.
 */
stock void TF2_SetClientMvMCash(int client, int value)	{
	if(Tklib_IsValidClient(client))
		SetEntProp(client, Prop_Send, "m_nCurrency", value);
}

/**
 *	Returns the users mvm currency/cash
 *
 *	@param client		The users index.
 */
stock int TF2_GetClientMvMCash(int client)	{
	return Tklib_IsValidClient(client) ? GetEntProp(client, Prop_Send, "m_nCurrency"):-1;
}

/**
 *	Set the users taunt cam on/off, useful for thirdperson plugin.
 *
 *	@param client		The users index.
 *	@param value		Bool value.
 */
stock void TF2_SetClientTauntCam(int client, bool value)	{
	if(Tklib_IsValidClient(client, true, true))
		SetEntProp(client, Prop_Send, "m_nForceTauntCam", value);
}

/**
 *	Returns the users taunt cam.
 *
 *	@param client		The users index.
 */
stock bool TF2_GetClientTauntCam(int client)	{
	return Tklib_IsValidClient(client, _, true) ? view_as<bool>(GetEntProp(client, Prop_Send, "m_nForceTauntCam")):false;
}

//Set or get the users killstreak count
/**
 *	Set the clients killstreak count
 *
 *	@param	client		The users index.
 *	@param	value		Killstreak count.
 */
stock void TF2_SetClientKillstreak(int client, int value=5)	{
	if(Tklib_IsValidClient(client))
		SetEntProp(client, Prop_Send, "m_nStreaks", value);
}

/**
 *	Returns the users killstreak count
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this will return -1.
 */
stock int TF2_GetClientKillstreak(int client)	{
	return Tklib_IsValidClient(client) ? GetEntProp(client, Prop_Send, "m_nStreaks"):-1;
}

/**
 *	Returns the users cloak meter.
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this will return -1.0.
 */
stock float TF2_GetClientCloakMeter(int client)	{
	return Tklib_IsValidClient(client, _, true)) ? GetEntPropFloat(client, Prop_Send, "m_flCloakMeter"):-1.0;
}

/**
 *	Set the clients cloak meter.
 *
 *	@param client		The users index.
 *	@param value		Cloak duration.
 *	@error If the user is invalid, nothing will happen.
 */
stock float TF2_SetClientCloakMeter(int client, float value=1.0)	{
	if(Tklib_IsValidClient(client) && TF2_GetPlayerClass(client) == TFClass_Spy)
		SetEntPropFloat(client, Prop_Send, "m_flCloakMeter", value);
}

/**
 *	Returns the users glow value.
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this will return false.
*/
stock bool TF2_GetClientGlow(int client)	{
	return Tklib_IsValidClient(client)) ? view_as<bool<(GetEntProp(client, Prop_Send, "m_bGlowEnabled")):false;
}

/**
 *	Set the clients glow value.
 *
 *	@param	client		The users index.
 *	@param	value		Glow value.
 *	@error	If the user is invalid, nothing will happen.
 */
stock bool TF2_SetClientGlow(int client, bool value)	{
	if(Tklib_IsValidClient(client))
		SetEntProp(client, Prop_Send, "m_bGlowEnabled", value);
}

/**
 *	Returns the users ubercharge value,
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, this will return -1.0.
*/
stock float TF2_GetClientUbercharge(int client)	{
	return Tklib_IsValidClient(client, _, true)) GetEntPropFloat(client, Prop_Send, "m_flChargeLevel"):-1.0;
}

/**
 *	Set the clients ubercharge value,
 *
 *	@param	client		The users index.
 *	@param	value		Ubercharge value, Defaulted to 1.0.
 *	@error	If the user is invalid, nothing will happen.
*/
stock void TF2_SetClientUbercharge(int client, float value=1.0)	{
	if(Tklib_IsValidClient(client, _, true))
		SetEntPropFloat(client, Prop_Send, "m_flChargeLevel", value);
}

/**
 *	Returns the users charge value,
 *
 *	@param client		The users index.
 *	@error				Invalid The users index.
*/
stock float TF2_GetClientChargeMeter(int client)	{
	if(Tklib_IsValidClient(client))
		ThrowError("The users index %d is invalid", client)
	
	return GetEntPropFloat(client, Prop_Send, "m_flChargeMeter");
}

/**
 *	Set the users charge value,
 *
 *	@param client		The users index.
 *	@param value		Float value.
 *	@error				Invalid The users index.
*/
stock void TF2_SetClientChargeMeter(int client, float value=1.0)	{
	if(Tklib_IsValidClient(client, _, true))
		SetEntPropFloat(client, Prop_Send, "m_flChargeMeter", value);
}

/**
 *	Returns the users metal value,
 *
 *	@param client		The users index.
 *	@error				Invalid The users index.
*/
stock int TF2_GetClientMetal(int client)	{
	if(Tklib_IsValidClient(client))
		ThrowError("The users index %d is invalid", client)
	
	return	GetEntProp(client, Prop_Data, "m_iAmmo", 4, 3);
}

/**
 *	Set the users metal value,
 *
 *	@param client		The users index.
 *	@param value		Amount value.
 *	@error				Invalid The users index.
*/
stock void TF2_SetClientMetal(int client, int value=200)	{
	if(Tklib_IsValidClient(client))
		ThrowError("The users index %d is invalid", client)
	
	SetEntProp(client, Prop_Data, "m_iAmmo", value, 4, 3);
}

/**
 *	Returns the users decapitations value,
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, this will return -1.
*/
stock int TF2_GetClientDecapitations(int client)	{
	if(Tklib_IsValidClient(client))
		ThrowError("The users index %d is invalid", client)
	
	return	GetEntProp(client, Prop_Send, "m_iDecapitations");
}

/**
 *	Set the users decapitations value,
 *
 *	@param client		The users index.
 *	@param value		Amount value.
 *	@error				Invalid The users index.
*/
stock void TF2_SetClientDecapitations(int client, int value=10)	{
	if(Tklib_IsValidClient(client))
		ThrowError("The users index %d is invalid", client)
	
	SetEntProp(client, Prop_Send, "m_iDecapitations");
}

/**
 *	Returns the TF2 Weapon Slot
 *
 *	@param client		The users index.
 *	@param slot			TFSlot slot.
 *	@error	If the client is invalid, nothing will happen.
 */
stock int TF2_GetPlayerWeaponSlot(int client, TFSlot slot)	{
	return GetPlayerWeaponSlot(client, view_as<int>(slot));
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
 *	Get the TFBuilding type.
 *
 *	@param		index		The building to get TFBuilding type from.
 *	@return	Returns TFBuilding type.
 */
stock TFBuilding TF2_GetBuildingType(int index)	{
	if(!IsValidEdict(index) || !IsValidEntity(index))	{
		PrintToServer("[Tklib: Additional] Failed to get TFBuilding type from entity %d", index);
		return TFBuilding_Invalid;
	}
	
	char classname[64];
	GetEntityClassname(index, classname, sizeof(classname));
	
	if(StrEqual(classname, "obj_dispenser", false))
		return	TFBuilding_Dispenser;
	if(StrEqual(classname, "obj_sentrygun", false))
		return	TFBuilding_Sentrygun;
	if(StrEqual(classname, "obj_teleporter", false))	{
		switch(TF2_GetObjectMode(index))	{
			case	TFObjectMode_Entrance:	return TFBuilding_Teleporter_Entrance;
			case	TFObjectMode_Exit:		return TFBuilding_Teleporter_Exit;
		}
	}
	if(StrEqual(classname, "obj_minisentry", false))
		return	TFBuilding_MiniSentry;
	
	return TFBuilding_Invalid;
}