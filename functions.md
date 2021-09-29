# Functions divided by sections. (Work in progress - Not finished)


# Game Identifier

```
Returns the current Game_*
If the game is unknown. this returns Game_Unknown.

IdentifyGame()
```

# Resize

```
Resize a users body part.
If the user is invalid, this returns false.

TF2_SetClientSize()
```

```
Returns the size of a users body part.
If the user is invalid, this returns -1.0.

TF2_GetClientSize()
```

```
Set the users head scale.
If the user is invalid, this returns false.

TF2_SetClientHeadScale()
```

```
Returns the users head scale.
If the user is invalid, this returns -1.0.

TF2_GetClientHeadScale()
```

```
Set the users torso scale.
If the user is invalid, this returns false.

TF2_SetClientTorsoScale()
```

```
Returns the users torso scale.
If the user is invalid, this returns -1.0.

TF2_GetClientTorsoScale()
```

```
Set the users hand scale.
If the user is invalid, this returns false.

TF2_SetClientHandScale()
```

```
Returns the users hand scale.
If the user is invalid, this returns -1.0.

TF2_GetClientHandScale()
```

```
Set the entity's model scale/size
If the entity or user is invalid, this returns false.

SetEntityModelScale()
```

```
Returns the entity's model scale/size
If the entity or user is invalid, this returns -1.0.

GetEntityModelScale()
```

```
Set the users step scale/size
If the user is invalid or unsupported mod, this returns false.

SetClientStepSize()
```

```
Returns the users step scale/size
If the user is invalid or unsupported mod, this returns -1.0.

GetClientStepSize()
```

# Weapons

```
Removes all weapons from the user.
If the user is invalid, this returns false.

RemoveAllWeapons()
```

```
Returns the weapon definition index value.
If the weapon entity is invalid or has no definition index property, this returns -1.

GetWeaponDefinitionIndex()
```

```
Set the weapon definition index value.
If the weapon entity is invalid or has no definition index property, this returns false.

SetWeaponDefinitionIndex()
```

```
Returns the users current wielding weapon.
If the user is invalid or has no active weapon, this returns -1.

GetClientActiveWeapon()
```

```
Set the users current active weapon.
If the user is invalid, this returns false

Note this may cause the client to crash if invalid slot was specified.

SetClientActiveWeapon()
```

```
Set the users current wielding weapon ammmo.
If the user is invalid or has no wielding weapon, this returns false.

SetClientWeaponAmmo()
```

```
Set the users current wielding weapon primary & secondary ammo.
If the user is invalid or has no wielding weapon, nothing will happen.

SetClientWeaponAmmoEx()
```

```
Set the weapons primary ammo.
If the weapon entity is invalid or has no primary ammo property, this returns false.

SetWeaponAmmo()
```

```
Set the weapons primary & secondary ammo.
If the weapon entity is invalid or has no primary/reserve ammo property, nothing will happen.

SetWeaponAmmoEx()
```

```
Returns the weapons primary ammo.
If the weapon entity is invalid or has no primary ammo property, this returns -1.

GetWeaponAmmo()
```

```
Returns the users current wielding weapons primary ammo.
If the user is invalid or weapon has no primary ammo property, this returns -1.

GetClientActiveWeaponAmmo()
```

```
Returns the users current wielding weapons reserve ammo.
If the user is invalid or weapon has no secondary ammo property, this returns -1.

GetClientActiveWeaponReserveAmmo()
```

```
Set the weapons reserve ammo.
If the weapon entity is invalid or has no reserve ammo property, this returns false.

SetWeaponReserveAmmo()
```

```
Returns the weapons reserve ammo.
If the weapon entity is invalid or has no reserve ammo property, this returns -1.

GetWeaponReserveAmmo()
```

```
Returns the users current wielding weapons reserve ammo.
If the user or weapon entity is invalid or weapon has no reserve ammo property, this returns -1.

GetClientWeaponReserveAmmo()
```

```
Returns the ammotype of the weapon.
If the weapon is invalid or has no ammotype, this returns -1.

GetWeaponAmmoType()
```

```
Returns the array size of weapons from the specified user.
If the user or weapon is invalid or weapon has no arraysize property, this returns -1.

GetClientActiveWeaponsArraySize()
```

```
Returns the weapon entity of a specified user via element/slot.
If the user is invalid or has no weapon arraysize property, this returns -1.

GetClientWeaponEntity()
```

```
Returns the users weapon offsets.
If the user is invalid or has no weapon arraysize property, this returns -1.

GetClientWeaponOffset()
```

```
Returns if the weapon is invalid by searching via its classname if it contains 'weapon_'
If the weapon is invalid or has no classname property, this returns false.

IsValidWeapon()
```

```
Equips a players weapon.
This is an alternative to EquipPlayerWeapon, this method fixes 0 clip magazines and glitchty animations
because it was being spawned onto the user too early when using CreateEntityByName()

If the user or weapon is invalid, this returns false.

EquipPlayerWeaponEx()
```


# Clients

```
Returns if the user is the console.

IsClientConsole()
```

```
Returns if the user is the Owner.

IsClientOwner()
```

```
Returns if the user is an Admin.

IsClientAdmin()
```

```
Returns if the user is a Moderator.

IsClientModerator()
```

```
Returns if the user is a Vip.

IsClientVip()
```

```
Returns if the user has the specified flag access.

IsClientFlag()
```

```
Returns if the users is the same player.

IsSamePlayers()
```

```
Returns if the user and target is on the same team.

IsSameTeam()
```

```
Set the users scoreboard ping.
If the user is invalid, this returns false.

SetClientPing()
```

```
Returns the users scoreboard ping.
If the user is invalid, this returns -1.

GetClientPing()
```

```
Set the users death count.
If the user is invalid, this returns false.

SetClientDeaths()
```

```
Set the users frag count.
If the user is invalid, this returns false.

SetClientFrags()
```

```
Set the users health.
If the user is invalid, this returns false.

SetClientHealth()
```

```
Set the users maximum health.
If the user is invalid, this returns false.

SetClientMaxHealth()
```

```
Returns the users maximum health.
If the user is invalid, this returns -1.

GetClientMaxHealth()
```

```
Set the users health & maximum health.
If the user is invalid, this returns false.

SetClientHealthEx()
```

```
Set the users team index called from game's network property m_iTeamNum.
If the user is invalid, this returns false.

SetClientTeamNum()
```

```
Returns the users team index called from game's network property m_iTeamNum.
If the user is invalid, this returns -1.

GetClientTeamNum()
```

```
Set the users field-of-view.
If the user is invalid or has no field-of-view property, this returns false.

SetClientFOV()
```

```
Returns the users field-of-view.
If the user is invalid or has no field-of-view property, this returns -1.

GetClientFOV()
```

```
Set the users default field-of-view.
If the user is invalid or has no default field-of-view property, this returns false.

SetClientDefaultFOV()
```

```
Returns the users default field-of-view.
If the user is invalid or has no default field-of-view property, this returns -1.

GetClientDefaultFOV()
```


# Entities

# Additions


# Team Fortress 2

# Counter-Strike

# Counter-Strike: Global Offensive

# Left 4 Dead

```
Returns the users current team.
If the user is invalid, this returns L4DTeam_Unassigned.

L4D_GetClientTeam()
```

```
Changees the users current team.
If the user is invalid, this returns false.

L4D_ChangeClientTeam()
```

# Day of Defeat: Source

```
Returns the users current team.
If the user is invalid, this returns DODTeam_Unassigned.

DOD_GetClientTeam()
```

```
Changes the users curent team.
If the user is invalid, this returns false.

DOD_ChangeClientTeam()
```

# Fortress-Forever

```
Returns the users current team.
If the user is invalid, this returns FFTeam_Unassigned.

FF_GetClientTeam()
```

```
Changes the users current team.
If the user is invalid, this returns false.

FF_ChangeClientTeam()
```

# Contagion


# Multi-Colors
