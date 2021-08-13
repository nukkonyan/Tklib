enum	TF2ResizeType
{
	TF2ResizeType_Head = 0,
	TF2ResizeType_Torso = 1,
	TF2ResizeType_Hand = 2,
	TF2ResizeType_Model = 3,
	TF2ResizeType_Steps = 4
}

/**
 *	Tk Libraries: Resize.
 *	Resize a clients body part.
 *
 *	@param	client		The players client index.
 *	@param	type		ResizeType type.
 *	@param	value		The specified resize value.
 *	@error	If the client is invalid, nothing will happen.
 */
stock float TF2_SetClientResize(int client, TF2ResizeType type, float value)	{
	if(Tklib_IsValidClient(client, _, true))	{
		switch(type)	{
			case	TF2ResizeType_Head:		TF2_SetClientHeadScale(client, value);
			case	TF2ResizeType_Torso:	TF2_SetClientTorsoScale(client, value);
			case	TF2ResizeType_Hand:		TF2_SetClientHandScale(client, value);
			case	TF2ResizeType_Model:	SetEntityModelScale(client, value);
			case	TF2ResizeType_Steps:	SetClientStepSize(client, value);
		}
	}
}

/**
 *	Tk Libraries: Resize.
 *	Returns the clients size of a clients body part.
 *
 *	@param	client		The players client index.
 *	@param	type		ResizeType type.
 *	@error	If the client is invalid, it will return -1.0
 */
stock float TF2_GetClientResize(int client, TF2ResizeType type)	{
	if(Tklib_IsValidClient(client, _, true))	{
		float value;
		switch(type)	{
			case	TF2ResizeType_Head: value = TF2_GetClientHeadScale(client);
			case	TF2ResizeType_Torso:value = TF2_GetClientTorsoScale(client);
			case	TF2ResizeType_Hand:	value = TF2_GetClientHandScale(client);
			case	TF2ResizeType_Model:value = GetEntityModelScale(client);
			case	TF2ResizeType_Steps:value = GetClientStepSize(client);
		}
		return	value;
	}
	return -1.0;
}

/**
 *	Tk Libraries: Resize.
 *	Set the clients head scale.
 *
 *	@param	client		The players client index.
 *	@param	scale		Head scale.
 *	@error	If the client is invalid, nothing will happen.
 */
stock float TF2_SetClientHeadScale(int client, float scale)	{
	if(Tklib_IsValidClient(client, _, true))
		SetEntPropFloat(client, Prop_Send, "m_flHeadScale", scale);
}

/**
 *	Tk Libraries: Resize.
 *	Returns the clients head scale.
 *
 *	@param	client		The players client index.
 *	@error	If the client is invalid, it will return -1.0.
 */
stock float TF2_GetClientHeadScale(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloat(client, Prop_Send, "m_flHeadScale"):-1.0;
}


/**
 *	Tk Libraries: Resize.
 *	Set the clients torso scale.
 *
 *	@param client		The players client index.
 *	@param scale		Torso scale.
 */
stock float TF2_SetClientTorsoScale(int client, float scale)	{
	SetEntPropFloat(client, Prop_Send, "m_flTorsoScale", scale);
}

/**
 *	Tk Libraries: Resize.
 *	Returns the clients torso scale.
 *
 *	@param	client		The players client index.
 *	@param	If the client is invalid, it will return 0.0.
 */
stock float TF2_GetClientTorsoScale(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloat(client, Prop_Send, "m_flTorsoScale"):-1.0;
}

/**
 *	Tk Libraries: Resize.
 *	Set the clients hand scale.
 *
 *	@param	client		The players client index.
 *	@param	scale		Hand scale.
 *	@error	If the client is invalid, nothing will happen.
 */
stock float TF2_SetClientHandScale(int client, float scale)	{
	if(Tklib_IsValidClient(client, _, true))
		SetEntPropFloat(client, Prop_Send, "m_flHandScale", scale);
}

/**
 *	Tk Libraries: Resize.
 *	Returns the clients hand scale.
 *
 *	@param	client		The players client index.
 *	@error	If the client is invalid, it will return -1.0
 */
stock float TF2_GetClientHandScale(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloat(client, Prop_Send, "m_flHandScale"):-1.0;
}

/**
 *	Tk Libraries: Resize.
 *	Set the entitys model scale/size.
 *
 *	@param	entity		Entity index.
 *	@param	scale		The model scale.
 *	@error	If the entity or client is invalid, nothing will happen.
 */
stock float SetEntityModelScale(int entity, float scale)	{
	if(Tklib_IsValidClient(entity, _, true) || (IsValidEdict(entity) || IsValidEntity(entity)))
		SetEntPropFloat(entity, Prop_Send, "m_flModelScale", scale);
}

/**
 *	Tk Libraries: Resize.
 *	Returns the entitys model scale/size.
 *
 *	@param	client		Entity index.
 *	@error	If the entity or client is invalid, it will return -1.0
 */
stock float GetEntityModelScale(int entity)	{
	return (Tklib_IsValidClient(entity, _, true) || (IsValidEdict(entity) || IsValidEntity(entity))) ? GetEntPropFloat(entity, Prop_Send, "m_flModelScale"):-1.0;
}

/**
 *	Tk Libraries.
 *	Set the clients step scale/size.
 *
 *	@param	client		The players client index.
 *	@param	scale		The size/scale.
 *	@error	If the client is invalid, nothing will happen.
 */
stock float SetClientStepSize(int client, float scale)	{
	if(Tklib_IsValidClient(client, _, true))
		SetEntPropFloat(client, Prop_Send, "m_flStepSize", scale);
}

/**
 *	Tk Libraries.
 *	Returns the clients step size.
 *
 *	@param	client		The players client index.
 *	@error	If the client is invalid, it will return -1.0
 */
stock float GetClientStepSize(int client)	{
	return Tklib_IsValidClient(client, _, true) ? GetEntPropFloat(client, Prop_Send, "m_flStepSize"):-1.0;
}