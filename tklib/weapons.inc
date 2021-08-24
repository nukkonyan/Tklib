/**
 *	Removes all weapons from the client.
 *
 *	@param client		Client index.
 */
stock bool RemoveAllWeapons(int client)	{
	for(int i = 0; i < 10; i++)	{
		int wep = -1;
		if((wep = GetPlayerWeaponSlot(client, i)) != -1)	{
			RemovePlayerItem(client, wep);
			RemoveEdict(wep);
		}
	}
}

/**
 *	Returns the weapon definition index value
 *
 *	@param	weapon		Weapon entity.
 *	@error	If the weapon entity is invalid, it will return -1.
 */
stock int GetWeaponDefinitionIndex(int weapon)	{
	return	HasEntPropEx(weapon, Prop_Send, "m_iItemDefinitionIndex") ? GetEntProp(weapon, Prop_Send, "m_iItemDefinitionIndex"):-1;
}

/**
 *	Set the weapon definition index value
 *
 *	@param	weapon		Weapon entity.
 *	@param	value		Definition index value.
 *	@error	If the weapon entity is invalid, nothing will happen.
 */
stock int SetWeaponDefinitionIndex(int weapon, int value)	{
	if(IsValidEntityEx(weapon) && HasEntProp(weapon, Prop_Send, "m_iItemDefinitionIndex"))
		SetEntProp(weapon, Prop_Send, "m_iItemDefinitionIndex", value);
}

/**
 *	Returns the clients current active weapon.
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return -1.
 */
stock int GetClientActiveWeapon(int client)	{
	return	bool(Tklib_IsValidClient(client, _, true) && HasEntProp(client, Prop_Send, "m_hActiveWeapon")) ? GetEntPropEnt(client, Prop_Send, "m_hActiveWeapon"):-1;
}

/**
 *	Forces the clients current active weapon.
 *
 *	@param	client		The users index.
 *	@param	slot		The players weapon slot.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientActiveWeapon(int client, int slot)	{
	if(Tklib_IsValidClient(client, _, true) && HasEntProp(client, Prop_Send, "m_hActiveWeapon"))
		SetEntPropEnt(client, Prop_Send, "m_hActiveWeapon", slot);
}

/**
 *	Set the clients primary ammo
 *
 *	@param	client		The users client index.
 *	@param	value		Primary ammo amount.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientWeaponAmmo(int client, int value)	{
	if(Tklib_IsValidClient(client, _, true) && HasEntProp(GetClientActiveWeapon(client), Prop_Send, "m_iClip1"))
		SetEntProp(GetClientActiveWeapon(client), Prop_Send, "m_iClip1", value);
}

/**
 *	Set the clients current active primary and secondary weapon ammo.
 *
 *	@param	client		The users client index.
 *	@param	primary		Primary ammo amount.
 *	@param	secondary	Secondary ammo amount.
 */
stock void SetClientWeaponAmmoEx(int client, int primary=0, int secondary=0)	{
	if(primary > 0)
		SetClientWeaponAmmo(client, primary);
	if(secondary > 0)
		SetClientWeaponReserveAmmo(client, secondary);
}

/**
 *	Set the weapon primary ammo
 *
 *	@param weapon		Weapon entity.
 *	@param value		Amount value.
 */
stock void SetWeaponAmmo(any weapon, int value)	{
	if(HasEntPropEx(weapon, Prop_Send, "m_iClip1"))
		SetEntProp(weapon, Prop_Send, "m_iClip1", value);
}

/**
 *	Set the weapon primary and secondary ammo.
 *
 *	@param	weapon		Weapon entity.
 *	@param	primary		Primary ammo amount. Zero amount input will do nothing.
 *	@param	secondary	Secondary ammo amount. Zero amount input will do nothing.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetWeaponAmmoEx(any weapon, int primary=0, int secondary=0)	{
	if(Tklib_IsValidClient(client, _, true))	{
		if(primary != 0)
			SetWeaponAmmo(weapon, primary);
		if(secondary != 0)
			SetWeaponReserveAmmo(weapon, secondary);
	}
}

/**
 *	Returns the weapons primary ammo
 *
 *	@param	weapon		Weapon entity.
 *	@error	If the weapon is invalid, it returns -1.
 */
stock int GetWeaponAmmo(int weapon)	{
	return	HasEntPropEx(weapon, Prop_Send, "m_iClip1") ? GetEntProp(weapon, Prop_Send, "m_iClip1"):-1;
}

/**
 *	Returns the clients current active weapon primary ammo
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return -1.
 */
stock int GetClientWeaponAmmo(int client)	{
	return	Tklib_IsValidClient(client, _, true)) ? GetWeaponAmmo(GetClientActiveWeapon(client)):-1;
}

/**
 *	Set the clients current active weapon reserve ammo.
 *
 *	@param client		The users index.
 *	@param value		Secondary ammo amount.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void SetClientWeaponReserveAmmo(int client, int value)	{
	if(Tklib_IsValidClient(client, _, true))
		SetWeaponAmmo(GetClientActiveWeapon(client), value);
}

/**
 *	Set the weapon reserve ammo
 *
 *	@param	weapon		Weapon entity.
 *	@param	value		Secondary ammo amount.
 *	@error	If the weapon entity is invalid, nothing will happen.
 */
stock void SetWeaponReserveAmmo(any weapon, int value)	{
	if(IsValidEntityEx(weapon) && HasEntProp(weapon, Prop_Send, "m_iPrimaryReserveAmmoCount"))
		SetEntProp(weapon, Prop_Send, "m_iPrimaryReserveAmmoCount", value);
}

/**
 *	Return the weapon reserve ammo
 *
 *	@param	weapon		Weapon entity.
 *	@error	If the weapon entity is invali, it will return -1.
 */
stock int GetWeaponReserveAmmo(any weapon)	{
	return	HasEntPropEx(weapon, Prop_Send, "m_iPrimaryReserveAmmoCount")) ? GetEntProp(weapon, Prop_Send, "m_iPrimaryReserveAmmoCount"):-1;
}

/**
 *	Return the weapon reserve ammo
 *
 *	@param	client		The users index.
 *	@error	If the client is invalid, it will return -1.
 */
stock int GetClientWeaponReserveAmmo(int client)	{
	return	Tklib_IsValidClient(client, _, true) ? GetWeaponReserveAmmo(GetClientActiveWeapon(client)):-1;
}

/**
 *	Tk Libraries: Weapons.
 *	Returns the ammotype of the weapon.
 *
 *	@param	weapon		The weapon entity.
 *	@error	If weapon is invalid, it will return -1.
 */
stock int GetWeaponAmmoType(any weapon)	{
	return HasEntPropEx(weapon, Prop_Send, "m_iPrimaryAmmoType") ? GetEntProp(weapon, Prop_Send, "m_iPrimaryAmmoType"):-1;
}

/**
 *	Returns the array size of weapons of the specified client.
 *
 *	@param	client		The users index.
 *	@error	If client is invalid, it will return -1.
 */
stock int GetClientWeaponArraySize(int client)	{
	return (Tklib_IsValidClient(client, false, true) && HasEntProp(client, Prop_Send, "m_hMyWeapons")) ? GetEntPropArraySize(client, Prop_Send, "m_hMyWeapons"):-1;
}

/**
 *	Tk Libraries.
 *	Returns the weapon entity of a specified client via element.
 *
 *	@param	client		The users index.
 *	@param	element		The element to gain weapon entity from.
 *	@error	If client or weapon entity is invalid, it will return -1.
 */
stock int GetClientWeaponEntity(int client, int element)	{
	return Tklib_IsValidClient(client, false, true) ? GetEntPropEnt(client, Prop_Send, "m_hMyWeapons", element):-1;
}

/**
 *	Equips a players weapon.
 *	This is an alternative to that, this method fixes 0 clip magazine and glitchy reload animations because
 *	it was being spawned onto the client too early when using CreateEntityByName.
 *
 *	@param	client		The users index.
 *	@param	weapon		Weapon entity.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void EquipPlayerWeaponEx(int client, any weapon)	{
	if(Tklib_IsValidClient(client, _, true))	{
		//Credits to Bacardi for part of the code.
		
		float origin[3];
		GetClientAbsOrigin(client, origin);
		//origin[2] += 100.0;
		
		TeleportEntity(weapon, origin, NULL_VECTOR, NULL_VECTOR);
		SetEntPropVector(weapon, Prop_Send, "m_vecOrigin", origin);
		
		//Lets force the weapon to never respawn.
		int SF_NORESPAWN = (1 << 30);
		int flags = GetEntProp(weapon, Prop_Data, "m_spawnflags");
		flags |= SF_NORESPAWN;
		
		SetEntProp(weapon, Prop_Data, "m_spawnflags", flags);
		
		DispatchSpawn(weapon);
	}
}