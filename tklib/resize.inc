enum	TF2ResizeType
{
	TF2ResizeType_Head = 0,
	TF2ResizeType_Torso = 1,
	TF2ResizeType_Hand = 2,
	TF2ResizeType_Model = 3,
	TF2ResizeType_Steps = 4
}

/**
 *	Resize a clients body part.	[TF2]
 *
 *	@param client		Client index.
 *	@param type			ResizeType type.
 *	@param value		The specified resize value.
 */
stock float TF2_SetClientResize(int client, TF2ResizeType type, float value)	{
	switch(type)	{
		case	TF2ResizeType_Head:
		{
			TF2_SetClientHeadScale(client, value);
		}
		case	TF2ResizeType_Torso:
		{
			TF2_SetClientTorsoScale(client, value);
		}
		case	TF2ResizeType_Hand:
		{
			TF2_SetClientHandScale(client, value);
		}
		case	TF2ResizeType_Model:
		{
			SetEntityModelScale(client, value);
		}
		case	TF2ResizeType_Steps:
		{
			SetClientStepSize(client, value);
		}
	}
}

/**
 *	Get clients size of a clients body part.	[TF2]
 *
 *	@param client		Client index.
 *	@param type			ResizeType type.
 */
stock float TF2_GetClientResize(int client, TF2ResizeType type)	{
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

/**
 *	Set the clients head scale.
 *
 *	@param client		Client index.
 *	@param scale		Head scale.
 */
stock float TF2_SetClientHeadScale(int client, float scale)	{
	SetEntPropFloat(client, Prop_Send, "m_flHeadScale", scale);
}

/**
 *	Get the clients head scale.
 *
 *	@param client		Client index.
 */
stock float TF2_GetClientHeadScale(int client)	{
	return	GetEntPropFloat(client, Prop_Send, "m_flHeadScale");
}


/**
 *	Set the clients torso scale.
 *
 *	@param client		Client index.
 *	@param scale		Torso scale.
 */
stock float TF2_SetClientTorsoScale(int client, float scale)	{
	SetEntPropFloat(client, Prop_Send, "m_flTorsoScale", scale);
}

/**
 *	Get the clients torso scale.
 *
 *	@param client		Client index.
 */
stock float TF2_GetClientTorsoScale(int client)	{
	return	GetEntPropFloat(client, Prop_Send, "m_flTorsoScale");
}

/**
 *	Set the clients hand scale.
 *
 *	@param client		Client index.
 *	@param scale		Hand scale.
 */
stock float TF2_SetClientHandScale(int client, float scale)	{
	SetEntPropFloat(client, Prop_Send, "m_flHandScale", scale);
}

/**
 *	Get the clients hand scale.
 *
 *	@param client		Client index.
 */
stock float TF2_GetClientHandScale(int client)	{
	return	GetEntPropFloat(client, Prop_Send, "m_flHandScale");
}

/**
 *	Set the entitys model scale/size.
 *
 *	@param entity		Entity index.
 *	@param scale		The model scale.
 */
stock float SetEntityModelScale(int entity, float scale)	{
	SetEntPropFloat(entity, Prop_Send, "m_flModelScale", scale);
}

/**
 *	Get the entitys model scale/size.
 *
 *	@param client		Entity index.
 */
stock float GetEntityModelScale(int entity)	{
	return	GetEntPropFloat(entity, Prop_Send, "m_flModelScale");
}

/**
 *	Set the clients step scale/size.
 *
 *	@param client		Client index.
 *	@param scale		The size/scale.
 */
stock float SetClientStepSize(int client, float scale)	{
	SetEntPropFloat(client, Prop_Send, "m_flStepSize", scale);
}

/**
 *	Get the clients step size.
 *
 *	@param client		Client index.
 */
stock float GetClientStepSize(int client)	{
	return	GetEntPropFloat(client, Prop_Send, "m_flStepSize");
}