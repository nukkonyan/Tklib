/**
 *	Tk Libraries
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
 *	Tk Libraries.
 *	Get entity name
 *
 *	@param entity		Entity index.
 *	@param buffer		Buffer storage.
 *	@param maxlen		Buffer max length.
 */
stock int GetEntityName(int entity, char[] buffer, int maxlen)	{
	GetEntPropString(entity, Prop_Data, "m_iName", buffer, maxlen);
}

/**
 *	Tk Libraries.
 *	Set entity name
 *
 *	@param entity		Entity index.
 *	@param name			Entity name.
 */
stock void SetEntityName(int entity, char[] name)	{
	DispatchKeyValue(entity, "targetname", name);
}

/**
 *	Tk Libraries.
 *	Find entity if it exists.
 *
 *	@param classname	Entity classname.
 *	@return				Returns true on success, or false on failure.
 *	@error				Invalid entity.
 */
stock bool FindEntity(char[] classname)	{
	int entity = -1;
	if((entity = FindEntityByClassname(entity, classname)) != -1)
		return	true;
	
	return	false;
}

/**
 *	Tk Libraries.
 *	Creates an entity by string name but does not spawn it (see DispatchSpawn).
 *	If ForceEdictIndex is not -1, then it will use an edict by that index. If the index is
 *	invalid or there is already an edict using that index, it will error out.
 *	This provides additional ability to force name on the entity you created.
 *
 *	@param classname		Entity classname.
 *	@param name				Entity name it will be referred as.
 *	@param ForceEdictIndex	Edict index used by the created entity (Ignored on Orangebox and above).
 *	@return					Entity index on success, or -1 on failure.
 *	@error					Invalid edict index, or no mod support.
 */
stock int CreateEntityByNameEx(char[] classname, char[] name, int ForceEdictIndex=-1)	{
	int entity = CreateEntityByName(classname, ForceEdictIndex);
	SetEntityName(entity, name);
	return entity;
}

/**
 *	Tk Libraries.
 *	Should entity start disabled?
 *
 *	@param entity		Entity index.
 *	@param disabled		If true, starts disabled, else enabled if false
 */
stock void SetEntityDisabled(int entity, bool disabled)	{
	DispatchKeyValue(entity, "StartDisabled", disabled ? "true":"false");
}

/**
 *	Tk Libraries.
 *	Sets the entity's model name/path
 *
 *	@param	entity		Entity index.
 *	@param	modelname	The model name path.
 *	@error	If the entity is invalid, nothing will happen.
 */
stock void SetEntityModelEx(int entity, char[] modelname)	{
	if(IsValidEdict(entity) || IsValidEntity(entity))
		SetEntPropString(entity, Prop_Data, "m_ModelName", modelname);
}

/**
 *	Tk Libraries.
 *	Returns the entity's model name path
 *
 *	@param entity		Entity index.
 *	@param buffer		Buffer storage.
 *	@param maxlen		Length of the buffer.
 *	@error	If the entity is invalid, nothing will happen.
 */
stock void GetEntityModel(int entity, char[] buffer, int maxlen)	{
	if(IsValidEdict(entity) || IsValidEntity(entity))
		GetEntPropString(entity, Prop_Data, "m_ModelName", buffer, maxlen);
}

/**
 *	Tk Libraries.
 *	Returns an index of the entity owner.
 *
 *	@param	entity		The entity index.
 *	@error	If the index of the entity owner is invalid, it will return -1.
 */
stock int GetEntityOwner(int entity)	{
	return (IsValidEdict(entity) || IsValidEntity(entity)) ? GetEntPropEnt(entity, Prop_Data, "m_hOwnerEntity"):-1;
}