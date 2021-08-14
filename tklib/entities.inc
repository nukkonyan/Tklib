/**
 *	Returns the Absolute Origin of an entity.
 *
 *	@param	entity		The entity index.
 *	@param	vec			3 dimensional vector array.
 *	@error	If entity is invalid, it will return 0.0.
 */
stock void GetEntityAbsOrigin(int entity, float vec[3])	{
	(IsValidEdict(entity) || IsValidEntity(entity)) ? GetEntPropVector(entity, Prop_Send, "m_vecOrigin", vec):vec=0.0;
}

/**
 *	Returns the entity name
 *
 *	@param entity		Entity index.
 *	@param buffer		Buffer storage.
 *	@param maxlen		Buffer max length.
 *	@error	If the entity is invalid, it will return false.
 */
stock bool GetEntityName(int entity, char[] buffer, int maxlen)	{
	if(IsValidEdict(entity) || IsValidEntity(entity))	{
		GetEntPropString(entity, Prop_Data, "m_iName", buffer, maxlen);
		return	true;
	}
	
	return	false;
}

/**
 *	Set entity name
 *
 *	@param	entity		Entity index.
 *	@param	name		Entity name.
 */
stock void SetEntityName(int entity, char[] name)	{
	if(IsValidEdict(entity) || IsValidEntity(entity))
		DispatchKeyValue(entity, "targetname", name);
}

/**
 *	Find entity if it exists.
 *
 *	@param	classname	Entity classname.
 *	@error	If the entity is invalid, this will return false.
 */
stock bool FindEntity(char[] classname)	{
	int entity = -1;
	if((entity = FindEntityByClassname(entity, classname)) != -1)
		return	true;
	
	return	false;
}

/**
 *	Creates an entity by string name but does not spawn it (see DispatchSpawn).
 *	If ForceEdictIndex is not -1, then it will use an edict by that index. If the index is
 *	invalid or there is already an edict using that index, it will error out.
 *	This provides additional ability to force name on the entity you created.
 *
 *	@param	classname		Entity classname.
 *	@param	name			Entity name it will be referred as.
 *	@param	ForceEdictIndex	Edict index used by the created entity (Ignored on Orangebox and above).
 *	@error	Returns false if invalid edict index, or no mod support.
 */
stock bool CreateEntityByNameEx(char[] classname, char[] name, int ForceEdictIndex=-1)	{
	int entity = -1;
	if((entity = CreateEntityByName(classname, ForceEdictIndex)) != -1)	{
		SetEntityName(entity, name);
		return	true;
	}
	
	return false;
}

/**
 *	Should entity start disabled?
 *
 *	@param entity		Entity index.
 *	@param disabled		If true, starts disabled, else enabled if false
 */
stock void SetEntityDisabled(int entity, bool disabled)	{
	DispatchKeyValue(entity, "StartDisabled", disabled ? "true":"false");
}

/**
 *	Returns the entity's model name path
 *
 *	@param entity		Entity index.
 *	@param buffer		Buffer storage.
 *	@param maxlen		Length of the buffer.
 *	@error	If the entity is invalid, it will return false.
 */
stock bool GetEntityModel(int entity, char[] buffer, int maxlen)	{
	if(IsValidEdict(entity) || IsValidEntity(entity))	{
		GetEntPropString(entity, Prop_Data, "m_ModelName", buffer, maxlen);
		return	true;
	}
	
	return	false;
}

/**
 *	Returns an index of the entity owner.
 *
 *	@param	entity		The entity index.
 *	@error	If the index of the entity owner is invalid, it will return -1.
 */
stock int GetEntityOwner(int entity)	{
	return (IsValidEdict(entity) || IsValidEntity(entity)) ? GetEntPropEnt(entity, Prop_Data, "m_hOwnerEntity"):-1;
}