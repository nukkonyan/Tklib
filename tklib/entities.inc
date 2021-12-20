//==========================================//
// Tklib / Entities.
//==========================================//

enum	Entity	{
	Entity_Invalid = -1
}

/**
 *	Returns the absolute origin of an entity.
 *
 *	@param	entity		The entity index.
 *	@param	vec			3 dimensional vector array.
 *
 *	@error	If entity is invalid, this returns false.
 */
stock bool GetEntityAbsOrigin(any entity, float vec[3])	{
	if(!HasEntPropEx(entity, Prop_Send, "m_vecOrigin"))
		return	false;
	
	GetEntPropVector(entity, Prop_Send, "m_vecOrigin", vec);
	return	true;
}

/**
 *	Set the entity's absolute origin.
 *
 *	@param	entity		The entity index.
 *	@param	vec			3 dimensional vector array.
 *
 *	@error	If entity is invalid, this returns false.
 */
stock bool SetEntityAbsOrigin(any entity, const float vec[3])	{
	if(!HasEntPropEx(entity, Prop_Send, "m_vecOrigin"))
		return	false;
	
	SetEntPropVector(entity, Prop_Send, "m_vecOrigin", vec);
	return	true;
}

/**
 *	Returns the entity name
 *
 *	@param entity		Entity index.
 *	@param buffer		Buffer storage.
 *	@param maxlen		Buffer max length.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool GetEntityName(any entity, char[] buffer, int maxlen)	{
	return	GetEntPropStringEx(entity, Prop_Data, "m_iName", buffer, maxlen);
}

/**
 *	Set entity name
 *
 *	@param	entity		Entity index.
 *	@param	name		Entity name.
 *
 *	@error	If entity is invalid, it will returns false.
 */
stock bool SetEntityName(any entity, const char[] name)	{
	return	SetEntPropStringEx(entity, Prop_Data, "m_iName", name);
}

/**
 *	Find entity via classname if it exists.
 *
 *	@param	classname	Entity classname.
 *
 *	@error	If the entity is invalid, this will return false.
 */
stock bool FindEntity(const char[] classname)	{
	return bool(FindEntityByClassname(-1, classname) != -1);
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
 *
 *	@error	Invalid edict index, or no mod support.
 */
stock int CreateEntityByNameEx(const char[] classname, const char[] name="", int ForceEdictIndex=-1)	{
	int entity = CreateEntityByName(classname, ForceEdictIndex);
	
	if(!StrEqual(name, ""))
		SetEntityName(entity, name);
	
	return entity;
}

/**
 *	Should entity start disabled?
 *
 *	@param	entity		Entity index.
 *	@param	disabled	If true, starts disabled, else enabled if false
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool SetEntityDisabled(any entity, bool disabled)	{
	return	IsValidEntityEx(entity) ? DispatchKeyValue(entity, "StartDisabled", disabled ? "true":"false"):false;
}

/**
 *	Returns if the entity is disabled.
 *
 *	@param	entity		Entity index.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool GetEntityDisabled(int entity)	{
	return	GetEntPropBool(entity, Prop_Send, "m_bDisabled");
}

/**
 *	Sets the entity's model name path
 *
 *	@param	entity		Entity index.
 *	@param	model		Model path.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool SetEntityModelEx(int entity, const char[] model)	{
	return	SetEntPropStringEx(entity, Prop_Data, "m_ModelName", model);
}

/**
 *	Returns the entity's model name path
 *
 *	@param	entity		Entity index.
 *	@param	buffer		Buffer storage.
 *	@param	maxlen		Length of the buffer.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool GetEntityModel(int entity, char[] buffer, int maxlen)	{
	return	GetEntPropStringEx(entity, Prop_Data, "m_ModelName", buffer, maxlen);
}

/**
 *	Set the entity owner.
 *
 *	@param	entity		The entity index.
 *	@param	client		The users index.
 *
 *	@error	If the index of the entity owner is invalid, it will return -1.
 */
stock bool SetEntityOwner(int entity, int client)	{
	return	SetEntPropEntEx(entity, Prop_Data, "m_hOwnerEntity", client);
}

/**
 *	Returns an index of the entity owner.
 *
 *	@param	entity		The entity index.
 *
 *	@error	If the index of the entity owner is invalid, it will return -1.
 */
stock int GetEntityOwner(int entity)	{
	return	GetEntPropEntEx(entity, Prop_Data, "m_hOwnerEntity");
}

/**
 *	Returns if the entity or edict is valid.
 *	Use this over IsValidEntity and IsValidEdict as this combines them.
 *
 *	@param	entity	Entity index.
 *
 *	@error	If the entity/edict is invalid, this returns false.
 */
stock bool IsValidEntityEx(any entity)	{
	return	bool(IsValidEdict(int(entity)) || IsValidEntity(int(entity)));
}

/**
 *	Kills the entity.
 *	Same as AcceptEntityInput with "Kill".
 *	This one makes sure if the entity is valid or not.
 *
 *	@param	entity	Entity index.
 *
 *	@error	If entity is invalid, this returns false.
 */
stock bool KillEntity(any entity, const char[] input="", int activator=-1, int caller=-1, int outputid=0)	{
	return	IsValidEntityEx(entity) ? AcceptEntityInput(entity, "Kill"):false;
}

/**
 *	Set the entitys skin.
 *
 *	@param	entity	Entity index.
 *	@param	skin	Skin index.
 *
 *	@error	If the entity is invalid, nothing will happen.
 */
stock bool SetEntitySkin(any entity, int skin)	{
	return	SetEntPropEx(entity, Prop_Send, "m_nSkin", skin);
}

/**
 *	Returns the entitys skin
 *
 *	@param	entity	Entity index.
 *	@error	If entity is invalid, this will return -1.
*/
stock int GetEntitySkin(any entity)	{
	return	GetEntPropEx(entity, Prop_Send, "m_nSkin");
}

/**
 *	Sets the classname of an entity.
 *
 *	@param	entity		Index of the entity.
 *	@param	clsname		Buffer to store the classname.
 *	@param	maxlength	Maximum length of the buffer.
 *
 *	@return				True on success, false if there is no classname set.
 *
 *	@error	If the entity has no valid classname, this returns false.
 */
stock bool SetEntityClassname(any entity, const char[] clsname)	{
	return	SetEntPropStringEx(entity, Prop_Data, "m_iClassname", clsname);
}

/**
 *	Retrieves the classname of an entity.
 *	This is like GetEdictClassname(), except it works for ALL
 *	entities, not just edicts.
 *
 *	@param	entity		Index of the entity.
 *	@param	clsname		Buffer to store the classname.
 *	@param	maxlength	Maximum length of the buffer.
 *	@return				True on success, false if there is no classname set or has no valid classname/invalid entity.
 */
stock bool GetEntityClassnameEx(any entity, char[] clsname, int maxlength)	{
	return	GetEntPropStringEx(entity, Prop_Data, "m_iClassname", clsname, maxlength);
}

/**
 *	Returns the entity's parent entity.
 *
 *	@param	entity	Entity index.
 *	@param	parent	Entity index to parent.
 *
 *	@error	If the entities is invalid, this returns false.
 */
stock bool SetEntityParentEntity(any entity, any parent)	{
	return	SetEntPropEx(entity, Prop_Send, "m_iParentAttachment", parent);
}

/**
 *	Returns the entity's parent entity.
 *
 *	@param	entity	Entity index.
 *
 *	@error	If the entity is invalid, this returns -1.
 */
stock int GetEntityParentEntity(any entity)	{
	return	GetEntPropEx(entity, Prop_Send, "m_iParentAttachment");
}

/**
 *	Set the entity moving parent entity.
 *
 *	@param	entity	Entity index.
 *	@param	parent	Entity parent index.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool SetEntityMoveParent(any entity, any parent)	{
	return	SetEntPropEntEx(entity, Prop_Data, "m_hMoveParent", parent);
}

/**
 *	Returns the entity's moving parent entity.
 *
 *	@param	entity	Entity index.
 *
 *	@error	If the entity is invalid, this returns -1.
 */
stock int GetEntityMoveParent(any entity)	{
	return	GetEntPropEntEx(entity, Prop_Data, "m_hMoveParent");
}

/**
 *	Set the entity to be initialized.
 *
 *	@param	entity			Entity index.
 *	@param	initialized		If true, the entity will be 'initialized'.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool SetEntityInitialized(any entity, bool initialized)	 {
	return	SetEntPropEx(entity, Prop_Send, "m_bInitialized", initialized);
}

/**
 *	Returns if the entity is initialized.
 *
 *	@param	entity	Entity index.
 *
 *	@error	If the entity is invalid, this will return false.
 */
stock bool IsEntityInitialized(any entity)	{
	return	GetEntPropBool(entity, Prop_Send, "m_bInitialized");
}

/**
 *	Set the entity's definition index value
 *
 *	@param	entity		Entity index.
 *	@param	value		Definition index value.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool SetEntityDefinitionIndex(any entity, int value)	{
	return	SetEntPropEx(entity, Prop_Send, "m_iItemDefinitionIndex", value);
}

/**
 *	Returns the entity's definition index value
 *
 *	@param	entity		Entity index.
 *
 *	@error	If the entity is invalid, this returns -1.
 */
stock int GetEntityDefinitionIndex(any entity)	{
	return	GetEntPropEx(entity, Prop_Send, "m_iItemDefinitionIndex");
}

/**
 *	Returns if the entity classname is fully or partially matching.
 *
 *	@param	entity			Entity index.
 *	@param	classname		Classname to check.
 *	@param	partialMatch	If true, it will return true if match was partial.
 *
 *	@return	Returns if the match was found.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool IsEntityClassnameMatching(any entity, const char[] classname, bool partialMatch=false)	{
	if(!IsValidEntityEx(entity))
		return	false;
	
	//Credits JonnyBoy0719 - Contagion include.
	char entity_classname[64];
	GetEntityClassname(entity, entity_classname, sizeof(entity_classname));

	if(partialMatch)
		return	(StrContainsEx(entity_classname, classname));
	
	return	StrEqual(entity_classname, classname);
}

/**
 *	Returns the entity's team index.
 *
 *	@param	entity	The entity index.
 *
 *	@return	The team index of the entity.
 *
 *	@error	If the entity is invalid, this returns -1.
 */
stock int GetEntityTeamNum(any entity)	{
	return	GetEntPropEx(entity, Prop_Send, "m_iTeamNum");
}

/**
 *	Set the entity's team index.
 *
 *	@param	entity	The entity index.
 *
 *	@return	The team index of the entity.
 *
 *	@error	If the entity is invalid, this returns false.
 */
stock bool SetEntityTeamNum(any entity, int team)	{
	return	SetEntPropEx(entity, Prop_Send, "m_iTeamNum", team);
}

/**
 *	Set the entity effect.
 *
 *	@param	entity		The entity index.
 *	@param	effect		The effect value.
 *
 *	@error	If the index of the entity owner is invalid, it will return -1.
 */
stock bool SetEntityEffect(int entity, int value)	{
	return	SetEntPropEntEx(entity, Prop_Data, "m_hEffectEntity", value);
}

/**
 *	Returns a value of the entity effect.
 *
 *	@param	entity		The entity index.
 *
 *	@error	If the index of the entity owner is invalid, it will return -1.
 */
stock int GetEntityEffect(int entity)	{
	return	GetEntPropEntEx(entity, Prop_Data, "m_hEffectEntity");
}

//Netprops

/**
 *	Sets an integer value in an entity's property.
 *
 *	This function is considered safer and more robust over SetEntData,
 *	because it performs strict offset checking and typing rules.
 *
 *	@param	entity		Entity/edict index.
 *	@param	type		Property type.
 *	@param	prop		Property name.
 *	@param	value		Value to set.
 *	@param	size		Number of bytes to write (valid values are 1, 2, or 4).
 *						This value is auto-detected, and the size parameter is
 *						only used as a fallback in case detection fails.
 *	@param	element		Element # (starting from 0) if property is an array.
 *	@error				Invalid entity or offset out of reasonable bounds or property not found will return false.
 */
stock bool SetEntPropEx(any entity, PropType type, const char[] prop, any value, int size=4, int element=0)	{
	if(HasEntProp(entity, type, prop))	{
		SetEntProp(entity, type, prop, value, size, element);
		return	true;
	}
	
	return	false;	
}

/**
 *	Sets an entity index in an entity's property.
 *
 *	This function is considered safer and more robust over SetEntDataEnt*,
 *	because it performs strict offset checking and typing rules.
 *
 *	@param	entity		Entity/edict index.
 *	@param	type		Property type.
 *	@param	prop		Property name.
 *	@param	other		Entity index to set, or -1 to unset.
 *	@param	element		Element # (starting from 0) if property is an array.
 *
 *	@error				Invalid entity or offset out of reasonable bounds or property not found will return false.
 */
stock bool SetEntPropEntEx(any entity, PropType type, const char[] prop, int other, int element=0)	{
	if(HasEntProp(entity, type, prop))	{
		SetEntPropEnt(entity, type, prop, other, element);
		return	true;
	}
	
	return	false;	
}

/**
 *	Retrieves an integer value from an entity's property.
 *	Considered safer over GetEntProp.
 *
 *	This function is considered safer and more robust over GetEntData,
 *	because it performs strict offset checking and typing rules.
 *
 *	@param	entity		Entity/edict index.
 *	@param	type		Property type.
 *	@param	prop		Property name.
 *	@param	size		Number of bytes to write (valid values are 1, 2, or 4).
 *						This value is auto-detected, and the size parameter is
 *						only used as a fallback in case detection fails.
 *	@param	element		Element # (starting from 0) if property is an array.
 *
 *	@return				Bool value at the given property offset.
 *
 *	@error				If entity is invalid or property not found, this returns -1.
 */
stock int GetEntPropEx(any entity, PropType type, const char[] prop, int size=4, int element=0)	{
	return	HasEntPropEx(entity, type, prop) ? GetEntProp(entity, type, prop, size, element):-1;
}

/**
 *	Retrieves an integer value from an entity's property.
 *	Considered safer over GetEntProp.
 *
 *	This function is considered safer and more robust over GetEntDataEnt*,
 *	because it performs strict offset checking and typing rules.
 *
 *	@param	entity		Entity/edict index.
 *	@param	type		Property type.
 *	@param	prop		Property name.
 *	@param	element		Element # (starting from 0) if property is an array.
 *
 *	@return				Bool value at the given property offset.
 *
 *	@error				If entity is invalid or property not found, this returns -1.
 */
stock int GetEntPropEntEx(any entity, PropType type, const char[] prop, int element=0)	{
	return	HasEntPropEx(entity, type, prop) ? GetEntPropEnt(entity, type, prop, element):-1;
}

/**
 *	Retrieves a boolean value from an entity's property.
 *	Considered safer over GetEntProp.
 *
 *	This function is considered safer and more robust over GetEntData,
 *	because it performs strict offset checking and typing rules.
 *
 *	@param	entity		Entity/edict index.
 *	@param	type		Property type.
 *	@param	prop		Property name.
 *	@param	size		Number of bytes to write (valid values are 1, 2, or 4).
 *						This value is auto-detected, and the size parameter is
 *						only used as a fallback in case detection fails.
 *	@param	element		Element # (starting from 0) if property is an array.
 *
 *	@return				Bool value at the given property offset.
 *
 * @error				If entity is invalid or property not found, this returns false.
 */
stock bool GetEntPropBool(any entity, PropType type, const char[] prop, int size=4, int element=0)	{
	return	HasEntPropEx(entity, type, prop) ? bool(GetEntProp(entity, type, prop, size, element)):false;
}

/**
 *	Gets a network property as a string.
 *
 *	@param	entity		Entity/Edict index.
 *	@param	type		Property type.
 *	@param	prop		Property to use.
 *	@param	buffer		Destination string buffer.
 *	@param	maxlen		Maximum length of output string buffer.
 *	@param	element		Element # (starting from 0) if property is an array.
 *
 *	@return				Returns true/false if the procedure was valid.
 *
 *	@error				If entity, offset out of reasonable bounds, or property is not a valid string, this returns false.
 */
stock bool GetEntPropStringEx(any entity, PropType type, const char[] prop, char[] buffer, int maxlen, int element=0)	{
	return	HasEntPropEx(entity, type, prop) ? bool(GetEntPropString(entity, type, prop, buffer, maxlen, element) != -1):false;
}

/**
 *	Sets a network property as a string.
 *
 *	@param	entity		Entity/Edict index.
 *	@param	type		Property type.
 *	@param	prop		Property to use.
 *	@param	buffer		String to set.
 *	@param	element		Element # (starting from 0) if property is an array.
 *
 *	@return				Returns true/false if the procedure was valid.
 *
 *	@error				If entity, offset out of reasonable bounds, or property is not a valid string, this returns false.
 */
stock bool SetEntPropStringEx(any entity, PropType type, const char[] prop, const char[] buffer, int element=0)	{
	return	HasEntPropEx(entity, type, prop) ? bool(SetEntPropString(entity, type, prop, buffer, element) != -1):false;
}

/**
 *	Returns if the entity is valid and has the network property.
 *
 *	@param	entity		Entity/Edict index.
 *	@param	type		Property type.
 *	@param	prop		Property to check.
 *
 *	@error	If entity or property is invalid/not found, this returns false.
 */
stock bool HasEntPropEx(any entity, PropType type, const char[] prop)	{
	return	bool(IsValidEntityEx(entity) && HasEntProp(entity, type, prop));
}

/**
 *	Sets a float value in an entity's property.
 *	This function is considered safer and more robust over SetEntDataFloat,
 *	because it performs strict offset checking and typing rules.
 *
 *	@param	entity		Entity/Edict index.
 *	@param	type		Property type.
 *	@param	prop		Property name.
 *	@param	value		Value to set.
 *	@param	element		Element # (starting from 0) if property is an array.
 *
 *	@error				If entity, offset or property is not valid, this returns false. (if out of bounds, this spits out an error).
 */
stock bool SetEntPropFloatEx(any entity, PropType type, const char[] prop, float value, int element=0)	{
	if(HasEntPropEx(entity, type, prop))	{
		SetEntPropFloat(entity, type, prop, value, element);
		return	true;
	}
	
	return	false;
}

/**
 *	Retrieves a float value from an entity's property.
 *
 *	This function is considered safer and more robust over GetEntDataFloat,
 *	because it performs strict offset checking and typing rules.
 *
 *	@param	entity		Entity/edict index.
 *	@param	type		Property type.
 *	@param	prop		Property name.
 *	@param	element		Element # (starting from 0) if property is an array.
 *
 *	@return				Value at the given property offset.
 *
 *	@error				If entity is invalid, offset out of reasonable bounds or invalid property, this returns -1.0.
 */
stock float GetEntPropFloatEx(any entity, PropType type, const char[] prop, int element=0)	{
	return	HasEntPropEx(entity, type, prop) ? GetEntPropFloat(entity, type, prop, element):-1;
}

//Methodmap

methodmap	Entity	__nullable__	{
	public Entity(const char[] classname="", const char[] name="", int ForceEdictIndex=-1)
	{
		return Ent(CreateEntityByNameEx(classname, name, ForceEdictIndex));
	}
	
	public bool GetAbsOrigin(float vec[3])
	{
		return GetEntityAbsOrigin(This, vec);
	}
	
	public bool GetName(char[] buffer, int maxlen)
	{
		return GetEntityName(This, buffer, maxlen);
	}
	
	public bool SetName(const char[] name)
	{
		return SetEntityName(This, name);
	}
	
	public static Entity FindByClassname(any startEnt, const char[] classname)
	{
		return Ent(FindEntityByClassname(startEnt, classname));
	}
	
	public static bool Find(const char[] classname)
	{
		return FindEntity(classname);
	}
	
	property bool Disabled
	{
		public set(bool value)
		{
			SetEntityDisabled(This, value);
		}
		public get()
		{
			return GetEntityDisabled(This);
		}
	}
	
	public bool SetModel(const char[] model)
	{
		return SetEntityModelEx(This, model);
	}
	
	public bool GetModel(char[] buffer, int maxlen)
	{
		return GetEntityModel(This, buffer, maxlen);
	}
	
	property int Owner
	{
		public set(int client)
		{
			SetEntityOwner(This, client);
		}
		public get()
		{
			return GetEntityOwner(This);
		}
	}

	property int Health
	{
		public set(int value)
		{
			SetEntPropEx(This, Prop_Send, "m_iHealth", value);
		}
		public get()
		{
			return	GetEntPropEx(This, Prop_Send, "m_iHealth");
		}
	}
	
	public bool IsValid()
	{
		return IsValidEntityEx(This);
	}
	
	public bool Kill(const char[] input="", int activator=-1, int caller=-1, int outputid=0)
	{
		return KillEntity(This, input, activator, caller, outputid);
	}
	public void Remove()
	{
		RemoveEntity(This);
	}
	public void RemoveEx()
	{
		RemoveEdict(This);
	}

	property int Skin
	{
		public set(int skin)
		{
			SetEntitySkin(This, skin);
		}
		public get()
		{
			return GetEntitySkin(This);
		}
	}
	
	property int ParentEntity
	{
		public set(int parent)
		{
			SetEntityParentEntity(This, parent);
		}
		public get()
		{
			return GetEntityParentEntity(This);
		}
	}
	
	property bool Initialized
	{
		public set(bool initialized)
		{
			SetEntityInitialized(This, initialized);
		}
		public get()
		{
			return IsEntityInitialized(This);
		}
	}
	
	property int DefinitionIndex
	{
		public set(int defindex)
		{
			SetEntityDefinitionIndex(This, defindex);
		}
		public get()
		{
			return	GetEntityDefinitionIndex(This);
		}
	}
	
	//Netprops
	
	public bool HasProp(PropType type, const char[] prop)
	{
		return	HasEntProp(This, type, prop);
	}
	public bool HasPropEx(PropType type, const char[] prop)
	{
		return	HasEntPropEx(This, type, prop);
	}
	
	public void SetProp(PropType type, const char[] prop, any value, int size=4, int element=0)
	{
		SetEntProp(This, type, prop, value, size, element);
	}
	public bool SetPropEx(PropType type, const char[] prop, any value, int size=4, int element=0)
	{
		return	SetEntPropEx(This, type, prop, value, size, element);
	}
	public void SetPropEnt(PropType type, const char[] prop, int other, int element=0)
	{
		SetEntPropEnt(This, type, prop, other, element);
	}
	public bool SetPropEntEx(PropType type, const char[] prop, int other, int element=0)
	{
		return	SetEntPropEntEx(This, type, prop, other, element);
	}
	public void SetPropBool(PropType type, const char[] prop, bool value, int size=4, int element)
	{
		SetEntProp(This, type, prop, value, size, element);
	}
	
	public int GetProp(PropType type, const char[] prop, int size=4, int element=0)
	{
		return	GetEntProp(This, type, prop, size, element);
	}
	public int GetPropEx(PropType type, const char[] prop, int size=4, int element=0)
	{
		return	GetEntPropEx(This, type, prop, size, element);
	}
	public int GetPropEnt(PropType type, const char[] prop, int element=0)
	{
		return	GetEntPropEnt(This, type, prop, element);
	}
	public int GetPropEntEx(PropType type, const char[] prop, int element=0)
	{
		return	GetEntPropEntEx(This, type, prop, element);
	}
	public int GetPropArraySize(PropType type, const char[] prop)
	{
		return	GetEntPropArraySize(This, type, prop);
	}
	public bool GetPropBool(PropType type, const char[] prop, int size=4, int element=0)
	{
		return	GetEntPropBool(This, type, prop, size, element);
	}
	
	public void SetPropFloat(PropType type, const char[] prop, float value, int element=0)
	{
		SetEntPropFloat(This, type, prop, value, element);
	}
	public bool	SetPropFloatEx(PropType type, const char[] prop, float value, int element=0)
	{
		return SetEntPropFloatEx(This, type, prop, value, element);
	}
	public float GetPropFloat(PropType type, const char[] prop, int element=0)
	{
		return	GetEntPropFloat(This, type, prop, element);
	}
	
	public int SetPropString(PropType type, const char[] prop, const char[] buffer, int element=0)
	{
		return	SetEntPropString(This, type, prop, buffer, element);
	}
	public bool SetPropStringEx(PropType type, const char[] prop, const char[] buffer, int element=0)
	{
		return	SetEntPropStringEx(This, type, prop, buffer, element);
	}
	public int GetPropString(PropType type, const char[] prop, char[] buffer, int maxlen, int element=0)
	{
		return	GetEntPropString(This, type, prop, buffer, maxlen, element);
	}
	public bool GetPropStringEx(PropType type, const char[] prop, char[] buffer, int maxlen, int element=0)
	{
		return	GetEntPropStringEx(This, type, prop, buffer, maxlen, element);
	}
	
	public void SetPropVector(PropType type, const char[] prop, const float vec[3], int element)
	{
		SetEntPropVector(This, type, prop, vec, element);
	}
	public void GetPropVector(PropType type, const char[] prop, float vec[3], int element=0)
	{
		GetEntPropVector(This, type, prop, vec, element);
	}
	
	public void SetData(int offset, any value, int size=4, bool changeState=false)
	{
		SetEntData(offset, value, size, changeState);
	}
	public int GetData(int offset, int size=4)
	{
		return	GetEntData(This, offset, size);
	}
	
	public void SetDataEnt2(int offset, int other, bool changeState=false)
	{
		SetEntDataEnt2(This, offset, other, changeState);
	}
	public int GetDataEnt2(int offset)
	{
		return	GetEntDataEnt2(This, offset);
	}
	
	public void SetDataFloat(int offset, float value, bool changeState=false)
	{
		SetEntDataFloat(This, offset, value, changeState);
	}
	public float GetDataFloat(int offset)
	{
		return	GetEntDataFloat(This, offset);
	}
	
	public void SetDataString(int offset, const char[] buffer, int maxlen, bool changeState=false)
	{
		SetEntDataString(This, offset, buffer, maxlen, changeState);
	}
	public int GetDataString(int offset, char[] buffer, int maxlen)
	{
		return	GetEntDataString(This, offset, buffer, maxlen);
	}

	public void SetDataVector(int offset, const float vec[3], bool changeState=false)
	{
		SetEntDataVector(This, offset, vec, changeState);
	}
	public void GetDataVector(int offset, float vec[3])
	{
		GetEntDataVector(This, offset, vec);
	}
	
	public void SetDataArray(int offset, const int[] array, int arraySize, int dataSize=4, bool changeState=false)
	{
		SetEntDataArray(This, offset, array, arraySize, dataSize, changeState);
	}
	public void GetDataArray(int offset, int[] array, int arraySize, int dataSize=4)
	{
		GetEntDataArray(This, offset, array, arraySize, dataSize);
	}
	
	//Other
	
	property int Flags
	{
		public set(int flags)
		{
			SetEntityFlags(This, flags);
		}
		public get()
		{
			GetEntityFlags(This);
		}
	}
	
	property int FlagsEx
	{
		public set(int flags)
		{
			SetEdictFlags(This, flags);
		}
		public get()
		{
			GetEdictFlags(This);
		}
	}
	
	property float Gravity
	{
		public set(float amount)
		{
			SetEntityGravity(This, amount);
		}
		public get()
		{
			GetEntityFlags(This);
		}
	}
	
	property MoveType moveType 
	{
		public set(MoveType mt)
		{
			SetEntityMoveType(This, mt);
		}
		public get()
		{
			GetEntityMoveType(This);
		}
	}
	
	public void SetRenderColor(int r=255, int g=255, int b=255, int a=255)
	{
		SetEntityRenderColor(This, r, g, b, a);
	}
	public void GetRenderColor(int& r, int& g, int& b, int& a)
	{
		GetEntityRenderColor(This, r, g, b, a);
	}
	
	public void SetRenderFx(RenderFx fx)
	{
		SetEntityRenderFx(This, fx);
	}
	public RenderFx GetRenderFx()
	{
		return GetEntityRenderFx(This);
	}
	
	public void SetRenderMode(RenderMode mode)
	{
		SetEntityRenderMode(This, mode);
	}
	public RenderMode GetRenderMode()
	{
		return GetEntityRenderMode(This);
	}
	
	public bool AcceptInput(const char[] input, any activator=-1, any caller=-1, int outputid=0)
	{
		return AcceptEntityInput(This, input, activator, caller, outputid);
	}
	
	public void SetVariant()
	{
		SetVariantEntity(This);
	}
	
	public void FireOutput(const char[] output, int activator=-1, float delay=0.0)
	{
		FireEntityOutput(This, output, activator, delay);
	}
	
	public void Activate()
	{
		ActivateEntity(This);
	}
	public void Extinguish()
	{
		ExtinguishEntity(This);
	}
	
	//Put 'any' to support team enums.
	property any Team
	{
		public set(any value) 
		{
			SetEntPropEx(This, Prop_Send, "m_iTeamNum", value);
		}
		public get()
		{
			return GetEntPropEx(This, Prop_Send, "m_iTeamNum");
		}
	}
	
	public bool IsClassnameMatching(const char[] classname, bool partialMatch=false)
	{
		return	IsEntityClassnameMatching(This, classname, partialMatch);
	}
	
	public void Ignite(float time, bool npc=false, float size=0.0, bool level=false)
	{
		IgniteEntity(This, time, npc, size, level);
	}
	
	public void Teleport(const float origin[3]=NULL_VECTOR, const float angles[3]=NULL_VECTOR, const float velocity[3]=NULL_VECTOR)
	{
		TeleportEntity(This, origin, angles, velocity);
	}
	
	public void Kv(const char[] keyName, const char[] value)
	{
		DispatchKeyValue(This, keyName, value);
	}
	public void KvFloat(const char[] keyName, float value)
	{
		DispatchKeyValueFloat(This, keyName, value);
	}
	public void KvVec(const char[] keyName, const float vec[3])
	{
		DispatchKeyValueVector(This, keyName, vec);
	}
	public bool Spawn()
	{
		return DispatchSpawn(This);
	}
	
	public bool IsNetworkable()
	{
		return IsEntNetworkable(This);
	}
	
	public bool SetClassname(char[] clsname)
	{
		return SetEntityClassname(This, clsname);
	}
	public bool GetClassname(char[] clsname, int maxlength)
	{
		return GetEntityClassnameEx(This, clsname, maxlength);
	}
	public bool GetNetClass(char[] clsname, int maxlength)
	{
		return IsValidEntityEx(This) ? GetEntityNetClass(This, clsname, maxlength):false;
	}
	public Address GetAddress()
	{
		return GetEntityAddress(This);
	}
	
	public void ChangeState(int offset=0)
	{
		ChangeEdictState(This, offset);
	}
	
	property int MoveParent
	{
		public set(int parent)
		{
			SetEntityMoveParent(This, parent);
		}
		public get()
		{
			return GetEntityMoveParent(This);
		}
	}
	
	public int FindMapInfo(const char[] prop, PropFieldType type=PropFieldType(0), int num_bits=0, int local_offset=0)
	{
		return IsValidEntityEx(This) ? FindDataMapInfo(This, prop, type, num_bits, local_offset):-1;
	}
	
	public static int FindPropInfo(const char[] cls, const char[] prop, PropFieldType type=PropFieldType(0), int num_bits=0, int local_offset=0, int array_size=0)
	{
		return FindSendPropInfo(cls, prop, type, num_bits, local_offset, array_size);
	}
	
	property int Effect
	{
		public set(int value)
		{
			SetEntityEffect(This, value);
		}
		public get()
		{
			return GetEntityEffect(This);
		}
	}
}