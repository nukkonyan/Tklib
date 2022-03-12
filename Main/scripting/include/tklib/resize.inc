//==========================================//
// Tklib / Resize.
//==========================================//
#if !defined _tklib_disable_resize

enum	TF2ResizeType	{
	TF2ResizeType_Head = 0,
	TF2ResizeType_Torso = 1,
	TF2ResizeType_Hand = 2,
	TF2ResizeType_Model = 3,
	TF2ResizeType_Steps = 4
}

/**
 *	Resize a users body part.
 *
 *	@param	client		The players client index.
 *	@param	type		ResizeType type.
 *	@param	value		The specified resize value.
 *
 *	@error	If the client is invalid, this returns false.
 */
stock bool TF2_SetClientSize(int client, TF2ResizeType type, float value)	{
	if(Tklib_IsValidClient(client, _, true))	{
		switch(type)	{
			case	TF2ResizeType_Head:		TF2_SetClientHeadScale(client, value);
			case	TF2ResizeType_Torso:	TF2_SetClientTorsoScale(client, value);
			case	TF2ResizeType_Hand:		TF2_SetClientHandScale(client, value);
			case	TF2ResizeType_Model:	SetEntityModelScale(client, value);
			case	TF2ResizeType_Steps:	SetClientStepSize(client, value);
		}
		
		return	true;
	}
	
	return	false;
}

/**
 *	Returns the size of a users body part.
 *
 *	@param	client		The users index.
 *	@param	type		ResizeType type.
 *
 *	@error	If the user is invalid, this returns -1.0
 */
stock float TF2_GetClientSize(int client, TF2ResizeType type)	{
	if(Tklib_IsValidClient(client, _, true))	{
		switch(type)	{
			case	TF2ResizeType_Head:		return TF2_GetClientHeadScale(client);
			case	TF2ResizeType_Torso:	return TF2_GetClientTorsoScale(client);
			case	TF2ResizeType_Hand:		return TF2_GetClientHandScale(client);
			case	TF2ResizeType_Model:	return GetEntityModelScale(client);
			case	TF2ResizeType_Steps:	return GetClientStepSize(client);
		}
	}
	
	return	-1.0;
}

/**
 *	Set the users head scale.
 *
 *	@param	client		The users index.
 *	@param	scale		Head scale.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool TF2_SetClientHeadScale(int client, float scale)	{
	if(Tklib_IsValidClient(client, _, true))	{
		SetEntPropFloat(client, Prop_Send, "m_flHeadScale", scale);
		return	true;
	}
	
	return	false;
}

/**
 *	Returns the users head scale.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this return -1.0.
 */
stock float TF2_GetClientHeadScale(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloat(client, Prop_Send, "m_flHeadScale"):-1.0;
}

/**
 *	Set the users torso scale.
 *
 *	@param client		The users index.
 *	@param scale		Torso scale.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock float TF2_SetClientTorsoScale(int client, float scale)	{
	if(Tklib_IsValidClient(client, _, true))	{
		SetEntPropFloat(client, Prop_Send, "m_flTorsoScale", scale);
		return	true;
	}
	
	return	false;
}

/**
 *	Returns the users torso scale.
 *
 *	@param	client		The users index.
 *
 *	@param	If the user is invalid, this returns 0.0.
 */
stock float TF2_GetClientTorsoScale(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloat(client, Prop_Send, "m_flTorsoScale"):-1.0;
}

/**
 *	Set the users hand scale.
 *
 *	@param	client		The users index.
 *	@param	scale		Hand scale.
 *
 *	@error	If the client is invalid, this returns false.
 */
stock float TF2_SetClientHandScale(int client, float scale)	{
	if(Tklib_IsValidClient(client, _, true))	{
		SetEntPropFloat(client, Prop_Send, "m_flHandScale", scale);
		return	true;
	}
	
	return	false;
}

/**
 *	Returns the users hand scale.
 *
 *	@param	client		The users index.
 *
 *	@error	If the client is invalid, this returns -1.0
 */
stock float TF2_GetClientHandScale(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloat(client, Prop_Send, "m_flHandScale"):-1.0;
}

/**
 *	Set the entitys model scale/size.
 *
 *	@param	entity		Entity index.
 *	@param	scale		The model scale.
 *
 *	@error	If the entity or user is invalid, this returns false.
 */
stock float SetEntityModelScale(int entity, float scale)	{
	if(Tklib_IsValidClient(entity, _, true) || IsValidEntityEx(entity))	{
		SetEntPropFloat(entity, Prop_Send, "m_flModelScale", scale);
		return	true;
	}
	
	return	false;
}

/**
 *	Returns the entitys model scale/size.
 *
 *	@param	entity		Entity index.
 *
 *	@error	If the entity or user is invalid, this returns -1.0
 */
stock float GetEntityModelScale(int entity)	{
	return	bool(Tklib_IsValidClient(entity, _, true) || IsValidEntityEx(entity)) ? GetEntPropFloat(entity, Prop_Send, "m_flModelScale"):-1.0;
}

/**
 *	Set the users step scale/size.
 *
 *	@param	client		The users index.
 *	@param	scale		The size/scale.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool SetClientStepSize(int client, float scale)	{
	if(Tklib_IsValidClient(client, _, true))	{
		SetEntPropFloat(client, Prop_Send, "m_flStepSize", scale);
		return	true;
	}
	
	return	false;
}

/**
 *	Returns the users step size.
 *
 *	@param	client		The users index.
 *
 *	@error	If the client is invalid, this returns -1.0
 */
stock float GetClientStepSize(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloat(client, Prop_Send, "m_flStepSize"):-1.0;
}

#endif