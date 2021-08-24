enum	Entity	{
	Entity_Invalid = -1
}

/**
 *	Returns the Absolute Origin of an entity.
 *
 *	@param	entity		The entity index.
 *	@param	vec			3 dimensional vector array.
 *	@error	If entity is invalid, it will return false.
 */
stock bool GetEntityAbsOrigin(any entity, float vec[3])	{
	return	HasEntPropEx(entity, Prop_Send, "m_vecOrigin") ? GetEntPropVector(entity, Prop_Send, "m_vecOrigin", vec):false;
}

/**
 *	Returns the entity name
 *
 *	@param entity		Entity index.
 *	@param buffer		Buffer storage.
 *	@param maxlen		Buffer max length.
 *	@error	If the entity is invalid, it will return false.
 */
stock bool GetEntityName(any entity, char[] buffer, int maxlen)	{
	return	HasEntPropEx(entity, Prop_Data, "m_iName")) ? GetEntPropStringEx(entity, Prop_Data, "m_iName", buffer, maxlen):false;
}

/**
 *	Set entity name
 *
 *	@param	entity		Entity index.
 *	@param	name		Entity name.
 *	@error	If entity is invalid, it will returns false.
 */
stock bool SetEntityName(any entity, const char[] name)	{
	return	HasEntPropEx(entity, Prop_Data, "m_iName") ? SetEntPropStringEx(entity, Prop_Data, "m_iName", name):false;
}

/**
 *	Find entity via classname if it exists.
 *
 *	@param	classname	Entity classname.
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
 *	@error	If the entity is invalid, nothing will happen.
 */
stock void SetEntityDisabled(any entity, bool disabled)	{
	if(IsValidEntityEx(entity)))
		DispatchKeyValue(entity, "StartDisabled", disabled ? "true":"false");
}

/**
 *	Returns if the entity is disabled.
 *
 *	@param	entity		Entity index.
 *	@error	If the entity is invalid, this returns false.
 */
stock bool GetEntityDisabled(int entity)	{
	return	HasEntPropEx(entity, Prop_Send, "m_bDisabled")) ? GetEntPropBool(entity, Prop_Send, "m_bDisabled"):false;
}

/**
 *	Sets the entity's model name path
 *
 *	@param	entity		Entity index.
 *	@param	model		Model path.
 *	@error	If the entity is invalid, it will return false.
 */
stock bool SetEntityModelEx(int entity, const char[] model)	{
	return	HasEntPropEx(entity, Prop_Data, "m_ModelName") ? SetEntPropStringEx(entity, Prop_Data, "m_ModelName", model):false;
}

/**
 *	Returns the entity's model name path
 *
 *	@param	entity		Entity index.
 *	@param	buffer		Buffer storage.
 *	@param	maxlen		Length of the buffer.
 *	@error	If the entity is invalid, it will return false.
 */
stock bool GetEntityModel(int entity, char[] buffer, int maxlen)	{
	return	HasEntPropEx(entity, Prop_Data, "m_ModelName") ? GetEntPropStringEx(entity, Prop_Data, "m_ModelName", buffer, maxlen):false;
}

/**
 *	Set the entity owner.
 *
 *	@param	entity		The entity index.
 *	@param	client		The users index.
 *	@error	If the index of the entity owner is invalid, it will return -1.
 */
stock bool SetEntityOwner(int entity, int client)	{
	if(!HasEntPropEx(entity, Prop_Data, "m_hOwnerEntity") || Tklib_IsValidClient(client, _, _, false))
		return	false;
	
	SetEntPropEnt(entity, Prop_Data, "m_hOwnerEntity", client);
	return	true;
}

/**
 *	Returns an index of the entity owner.
 *
 *	@param	entity		The entity index.
 *	@error	If the index of the entity owner is invalid, it will return -1.
 */
stock int GetEntityOwner(int entity)	{
	return	HasEntPropEx(entity, Prop_Data, "m_hOwnerEntity") ? GetEntPropEnt(entity, Prop_Data, "m_hOwnerEntity"):-1;
}

/**
 *	Returns if the entity or edict is valid.
 *	Use this over IsValidEntity and IsValidEdict as this combines them.
 *
 *	@param	entity	Entity index.
 *	@error	If the entity or edict is invalid, it will return false.
 */
stock bool IsValidEntityEx(any entity)	{
	return	bool((IsValidEdict(int(entity)) || IsValidEntity(int(entity))));
}

/**
 *	Kills the entity.
 *	Same as AcceptEntityInput with "Kill".
 *	This one makes sure if the entity is valid or not.
 *
 *	@param	entity	Entity index to 'Kill'.
 *	@error	If entity is invalid, it will return false.
 */
stock bool KillEntity(any entity, const char[] input="", int activator=-1, int caller=-1, int outputid=0)	{
	return	IsValidEntityEx(entity) ? AcceptEntityInput(int(entity), "Kill"):false;
}

/**
 *	Set the entitys skin.
 *
 *	@param	entity	Entity index.
 *	@param	skin	Skin index.
 *	@error	If the entity is invalid, nothing will happen.
 */
stock bool SetEntitySkin(any entity, int skin)	{
	if(!HasEntPropEx(entity, Prop_Send, "m_nSkin"))
		return	false;
	
	SetEntProp(int(entity), Prop_Send, "m_nSkin", skin);
	return	true;
}

/**
 *	Returns the entitys skin
 *
 *	@param	entity	Entity index.
 *	@error	If entity is invalid, this will return -1.
*/
stock int GetEntitySkin(any entity)	{
	if(!HasEntPropEx(entity, Prop_Send, "m_nSkin"))
		return	-1;
	
	return	GetEntProp(entity, Prop_Send, "m_nSkin");
}

/**
 *	Sets the classname of an entity.
 *
 *	@param	entity		Index of the entity.
 *	@param	clsname		Buffer to store the classname.
 *	@param	maxlength	Maximum length of the buffer.
 *	@return				True on success, false if there is no classname set or has no valid classname/invalid entity.
 */
stock bool SetEntityClassname(any entity, const char[] clsname)	{
	return	HasEntPropEx(int(entity), Prop_Data, "m_iClassname") ? SetEntPropStringEx(entity, Prop_Data, "m_iClassname", clsname):false;
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
	return	HasEntPropEx(int(entity), Prop_Data, "m_iClassname") ? GetEntPropStringEx(entity, Prop_Data, "m_iClassname", clsname, maxlength):false;
}

//Netprops

/**
 *	Retrieves a boolean value from an entity's property.
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
 * @param	element		Element # (starting from 0) if property is an array.
 * @return				Bool value at the given property offset.
 * @error				Invalid entity or property not found.
 */
stock bool GetEntPropBool(int entity, PropType type, const char[] prop, int size=4, int element=0)	{
	return	bool(GetEntProp(entity, type, prop, size, element));
}

/**
 *	Gets a network property as a string.
 *
 *	@param	entity		Edict index.
 *	@param	type		Property type.
 *	@param	prop		Property to use.
 *	@param	buffer		Destination string buffer.
 *	@param	maxlen		Maximum length of output string buffer.
 *	@param	element		Element # (starting from 0) if property is an array.
 *	@return				Returns true/false if the procedure was valid.
 *	@error				Invalid entity, offset out of reasonable bounds, or property is not a valid string.
 */
stock bool GetEntPropStringEx(int entity, PropType type, const char[] prop, char[] buffer, int maxlen, int element=0)	{
	return	bool(GetEntPropString(entity, type, prop, buffer, maxlen, element) != -1);
}

/**
 *	Sets a network property as a string.
 *
 *	@param	entity		Edict index.
 *	@param	type		Property type.
 *	@param	prop		Property to use.
 *	@param	buffer		String to set.
 *	@param	element		Element # (starting from 0) if property is an array.
 *	@return				Returns true/false if the procedure was valid.
 *	@error				Invalid entity, offset out of reasonable bounds, or property is not a valid string.
 */
stock bool SetEntPropStringEx(int entity, PropType type, const char[] prop, const char[] buffer, int element=0)	{
	return	bool(SetEntPropString(entity, type, prop, buffer, element) != -1);
}

/**
 *	Returns if the entity is valid and has the network property.
 *
 *	@param	entity		Edict index.
 *	@param	type		Property type.
 *	@param	prop		Property to check.
 *	@error	If entity or property is invalid/not found, this returns false.
 */
stock bool HasEntPropEx(int entity, PropType type, const char[] prop)	{
	return	bool(IsValidEntityEx(entity) && HasEntProp(entity, type, prop));
}

//Methodmap

methodmap	Entity	__nullable__	{
	public Entity(const char[] classname="", const char[] name="", int ForceEdictIndex=-1)
	{
		return StrEqual(classname, "") ? Entity_Invalid:Ent(CreateEntityByNameEx(classname, name, ForceEdictIndex));
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
	
	public static int FindByClassname(int startEnt, const char[] classname)
	{
		return FindEntityByClassname(startEnt, classname);
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
			if(HasEntPropEx(This, Prop_Send, "m_iHealth"))
				SetEntProp(This, Prop_Send, "m_iHealth", value);
		}
		public get()
		{
			return	HasEntPropEx(This, Prop_Send, "m_iHealth") ? GetEntProp(This, Prop_Send, "m_iHealth"):-1;
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
	
	//Netprops
	
	public bool HasProp(PropType type, const char[] prop)
	{
		return HasEntProp(This, type, prop);
	}
	public bool HasPropEx(PropType type, const char[] prop)
	{
		return HasEntPropEx(This, type, prop);
	}
	
	public void SetProp(PropType type, const char[] prop, any value, int size=4, int element=0)
	{
		SetEntProp(This, type, prop, value, size, element);
	}
	public void SetPropEnt(PropType type, const char[] prop, int other, int element=0)
	{
		SetEntPropEnt(This, type, prop, other, element);
	}
	public void SetPropBool(PropType type, const char[] prop, bool value, int size=4, int element)
	{
		SetEntProp(This, type, prop, value, size, element);
	}
	
	public int GetProp(PropType type, const char[] prop, int size=4, int element=0)
	{
		return GetEntProp(This, type, prop, size, element);
	}
	public int GetPropEnt(PropType type, const char[] prop, int element=0)
	{
		return GetEntPropEnt(This, type, prop, element);
	}
	public int GetPropArraySize(PropType type, const char[] prop)
	{
		return GetEntPropArraySize(This, type, prop);
	}
	public bool GetPropBool(PropType type, const char[] prop, int size=4, int element=0)
	{
		return GetEntPropBool(This, type, prop, size, element);
	}
	
	public void SetPropFloat(PropType type, const char[] prop, float value, int element=0)
	{
		SetEntPropFloat(This, type, prop, value, element);
	}
	public float GetPropFloat(PropType type, const char[] prop, int element=0)
	{
		return GetEntPropFloat(This, type, prop, element);
	}
	
	public int SetPropString(PropType type, const char[] prop, const char[] buffer, int element=0)
	{
		return SetEntPropString(This, type, prop, buffer, element);
	}
	public bool SetPropStringEx(PropType type, const char[] prop, const char[] buffer, int element=0)
	{
		return SetEntPropStringEx(This, type, prop, buffer, element);
	}
	public int GetPropString(PropType type, const char[] prop, char[] buffer, int maxlen, int element=0)
	{
		return GetEntPropString(This, type, prop, buffer, maxlen, element);
	}
	public bool GetPropStringEx(PropType type, const char[] prop, char[] buffer, int maxlen, int element=0)
	{
		return GetEntPropStringEx(This, type, prop, buffer, maxlen, element);
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
		return GetEntData(This, offset, size);
	}
	
	public void SetDataEnt2(int offset, int other, bool changeState=false)
	{
		SetEntDataEnt2(This, offset, other, changeState);
	}
	public int GetDataEnt2(int offset)
	{
		return GetEntDataEnt2(This, offset);
	}
	
	public void SetDataFloat(int offset, float value, bool changeState=false)
	{
		SetEntDataFloat(This, offset, value, changeState);
	}
	public float GetDataFloat(int offset)
	{
		return GetEntDataFloat(This, offset);
	}
	
	public void SetDataString(int offset, const char[] buffer, int maxlen, bool changeState=false)
	{
		SetEntDataString(This, offset, buffer, maxlen, changeState);
	}
	public int GetDataString(int offset, char[] buffer, int maxlen)
	{
		return GetEntDataString(This, offset, buffer, maxlen);
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
			if(HasEntProp(This, Prop_Send, "m_iTeamNum"))
				SetEntProp(This, Prop_Send, "m_iTeamNum", value);
		}
		public get()
		{
			return HasEntProp(This, Prop_Send, "m_iTeamNum") ? GetEntProp(This, Prop_Send, "m_iTeamNum"):-1;
		}
	}
	
	public void Ignite(float time, bool npc=false, float size=0.0, bool level=false)
	{
		IgniteEntity(This, time, npc, size, level);
	}
	
	public void Teleport(const float origin[3], const float angles[3], const float velocity[3])
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
	public void Spawn()
	{
		DispatchSpawn(This);
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
}