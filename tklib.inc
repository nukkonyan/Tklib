/*****************************************\
 *			Tk Libraries (Tklib)		 *
 *										 *
 * 		Made by Tk /id/Teamkiller324	 *
\*****************************************/

//Changelogs

// > Version 1.1.0
// + Added numerous new set/change functions.
// + Added checks to return error if the client is invalid.
// + Fixed Set weapon ammo being only at 0.
// + Updated the code lines to be not filled with tab spaces.

// > Version 1.1.1
// + Added Day of Defeat: Source
// + Added TFFlag event type support (Events related to example picking up, defending, capturing and dropping intelligence in tf2.)
// + Updated some enum structures to better match the existing ones.

// > Version 1.1.2
// + Added Return/Set client lifestate function. (1 = Dead, 0 = Alive)
// + Added TFFlag_Carrier to TFFlag enum structure.
// + Few other changes on some functions.

// > Version 1.2.0
// + Updated name to Tk Libraries from Tk Include.
// + Added CSGORank enum, making it easier to handle ranks.
// + Added CSGO_SetWeaponSkin and CSGO_GetWeaponSkin to get or set the clients current skin of their weapon.
// + Added CSGO_SetWeaponStatTrak and CSGO_SetWeaponStatTrak to get or set clients current stattrak of their weapon.
// + Added CSGO_SetWeaponOwner to set the owner of the weapon as the client specified.
// + Added CSGO_SetWeaponQuality to set the quality of the weapon. By default (3) adds a star to the weapon name.
// + Added CSGO_SetWeaponNametag and CSGO_GetWeaponNametag to set or get the clients current name of their weapon.
// + Added CSGO_SetCompetitiveOffset and CSGO_GetCompetitiveOffset to set or get the clients competitive offsets. Useful for the plugins that sets custom ranks.
// + Added CSGO_SetCompetitiveType and CSGO_GetCompetitiveType to set or get the clients competitive types. Also useful for the plugins that sets custom ranks.
// + Added CSGO_SetArmModel to be easier to set the model of the players arm.
// + Added EquipPlayerWeaponEx as alternative option to EquipPlayerWeapon. Fixes issues regarding EquipPlayerWeapon when it comes to spawning weapons. (Credit to bacardi for part of the code.)
// + Added GetEntityName to return the entitys name.
// + Added SetEntityName to set the entitys name.
// + Added FindEntity to return true or false wheter the entity by classname exists in the current map.
// + Added CreateEntityByNameEx which does same functionality as CreateEntityByName but it has additional string to put in the entitys custom name you specify.
// + Added SetEntityDisabled if the entity you target should start disabled or not as a boolean. true/false statement.
// + Added GetEntityModel as easier method to return the model of the entity.
// + Added GetClientAuth which is same as GetClientAuthId but it functions similiarly to GetClientAuthString.
// + More stuff added in /additionals subinclude.

// > Version 1.2.1
// + Updated L4DTeam enum L4DTeam_Zombie to L4DTeam_Infected.

// > Version 1.2.2
// + Added TFSlot_Invalid.
// + Added SetWeaponDefinitionIndex.
// + Updated TF_GetPlayerWeaponSlot to TF2_GetPlayerWeaponSlot.

// > Version 1.3.0
// + Loads of changes and new functions.
// + Integrated Game Identifier.

// > Version 1.3.1
// + Updated Tk_Include_Version definition to Tklib_Version.
// + Minor additions such as SetClientModel & TF2_SetClientModel and TF2_SetClassAnimations.
// + Minor fixes to certain functions to work correctly.
// + Integrated Fortress Forever include.

// > Version 1.3.2
// + Minor Corrections.

// > Version 1.3.3

// + Added AddFolderToDownloadsTable.
// + Added AddFileToDownloadsTableEx.
// + Added <game>_GetTeamColour string table to gain the teams colour.
// + Added new definitions to possibly replace 'view_as'. Example: 'view_as<int>(function)' turns into 'int(function)' or 'view_as<Database>(function)' into 'Database(function)' (Makes it easier!)
// + Added 'This' definition as replacement for 'this', so it is seen as 'any' (Makes it easier to handle methodmaps)
// + Added 'Ent' definition to use for turning integer entity indexes to 'Entity' index. Example: Ent(function)
// + Updated the TFFlag enum to use 'TFFlag' than not having a main constructor.
// + Updated entities include as a methodmap.
// + Updated the functions to check if the netprop exists on the entity/client before proceeding, preventing errors.
// + Fixed Bool & BoolEx having incorrect placements.
// - Removed SetClientCookieInt as it is practically useless. Use the updated clientprefs include instead.
// + Additional minor Corrections.

// > Version 1.3.4
// + Added CSGO_GetClientArmModel.
// + Added SetEntPropStringEx (Same as SetEntPropString but returns true/false if the procedure was valid).
// + Added GetEntPropStringEx (Same as GetEntPropString but returns true/false if the procedure was valid).
// + Added HasEntPropEx (Same as HasEntProp but returns true/false if the network property and entity is valid).
// + Added TF2_SetBuildingLevel.
// + Added TF2_GetBuildingLevel.
// + Added TF2_SetBuildingMaxLevel.
// + Added TF2_GetBuildingMaxLevel.
// + Added TF2_SetBuildingMetalRequired.
// + Added TF2_GetBuildingMetalRequired. 
// + Added GetClientObserverTarget.
// + Added GetClientObserverMode.
// + Updated Entity.Health to properly check if the entity has the property 'm_iHealth', preventing errors.
// + Updated SetEntityName to force name via 'm_iName' over 'DispatchKeyValue'
// + Updated CSGO_SetClientArmModel.
// + Updated entity stock functions in order for supporting the new Entity constructor.
// + Updated Entity methodmap for the new stock functions.
// + Updated TF2_IsEntityBuilding.
// + Updated TF2_IsEntityMiniBuilding.
// + Updated SetClientObserverTarget.
// + Updated GameIdentifier, adding Game_SDK2006, Game_SDK2007 & Game_SDK2013.
// + Integrated Multicolors.

// > Version 1.3.5
// + (Undocumented from Version 1.3.4) Added TF2_GetBuildingOwner.
// + Added GetClientViewAngles - Returns where the player is looking at.
// + Added TF2_SetBuildingOwner.
// + Added SetEntityAbsOrigin.
// + Added GetCmdBool.
// + Added SetClientPendingTeam.
// + Added GetClientPendingTeam.
// + Added SetEntPropEx, essentially SetEntProp but returns false if the network property exists. (Safer).
// + Added SetEntPropEntEx, essentially SetentPropEnt but returns false if the network property exists. (Safer).
// + Added SetEntityParentEntity.
// + Added GetEntityParentEntity.
// + Added CPrintToChat2.
// + Added 'Bot' definition. Example: If(Bot(client)) and so on.
// + Added StringToBool.
// + Added AddConVarFlags to add flags to cvar.
// + Added RemoveConVarFlags to remove flags from a cvar.
// + Added AddConVarFlagsEx to add flags to cvar via its name.
// + Added RemoveConVarFlagsEx to remove flags from a cvar via its name.
// + Added SetEntityMoveParent.
// + Added GetEntityMoveParent.
// + Added SetEntityInitialized.
// + Added IsEntityInitialized.
// + Added SetEntityDefinitionIndex.
// + Added GetEntityDefinitionIndex.
// + Added a whole CSGO_* enum which is reflected on the weapon definition index.
// + Added Game_CSCO to gameidentifier include. (Late addition, should've been added already).
// + Added IsClientDucking.
// + Added SetClientDucking.
// + Added IsClientNoclipping.
// + Added SetEntPropFloatEx.
// + Added GetEntPropFloatEx.
// + Added GetEntPropEx.
// + Added CS_GetTeamName.
// + Added CS_GetBombsiteCount.
// + Added CS_GetBombsite.
// + Added GetEntPropEntEx.
// + Fixed GetEntityAbsOrigin.
// + Fixed several errors related to multi-colors include.
// + Fixed GetEntityName.
// + Updated GetCmdInt.
// + Updated stock functions.
// + Updated description on stock functions.
// + Updated CPrintToChat.
// + Updated Entities methodmap to reflect latest additions.
// + Updated SetClientNoclip description.
// + Updated TF2_SetClientResize to TF2_SetClientSize.
// + Updated TF2_GetclientResize to TF2_GetClientSize.
// + Updated the Entity methodmap for the new additions.
// + Updated GetEntPropBool.
// + Renamed GetClientWeaponAmmo to GetClientActiveWeaponAmmo.
// + Renamed GetClientWeaponArraySize to GetClientActiveWeaponsArraySize
// + Renamed SlayPlayer to SlayClient.
// - Deprecated CS_IsWarmupRound due to only returning 'true' (for some odd reason).
// + Several stock function updates, changes & fixes including its description.

// > Version 1.3.6
// + Added CSGO_SetWeaponWear.
// + Added CSGO_GetWeaponWear.
// + Added CSGO_SetWeaponPattern.
// + Added CSGO_GetWeaponPattern.
// + Added NoMultiColors definition if you don't want multi-colors to be included. ('#define NoMultiColors' before including this include to make it prevent.)
// + Fixed FF_GetClientTeam to properly return a boolean value.
// + Updated GetEntityParentEntity.
// + Updated the Get* networking properties to be int instead of Entity on methodmap.
// + Updated CS:GO Include.

//SM Includes
#include	<sdktools>
#include	<sdkhooks>
#undef		REQUIRE_EXTENSIONS
#undef		REQUIRE_PLUGIN
#include	<cstrike>
#include	<tf2_stocks>

//Extra things that should be part of SourceMod, making it easier.
#define		int(%1)				view_as<int>(%1)
#define		any(%1)				view_as<any>(%1)
#define		float(%1)			view_as<float>(%1)		//doesn't break float(int value) function. %1 means it is the first parameter, %2 would be second, and so on (you get it).
#define		bool(%1)			view_as<bool>(%1)
#define		char(%1)			view_as<char>(%1)
#define		Handle(%1)			view_as<Handle>(%1)
#define		Database(%1)		view_as<Database>(%1)
#define		DBResult(%1)		view_as<DBResult>(%1)
#define		DBResultSet(%1)		view_as<DBResultSet(%1)
#define		APLRes(%1)			view_as<APLRes>(%1)
#define		AdminFlag(%1)		view_as<AdminFlag>(%1)
#define		PropFieldType(%1)	view_as<PropFieldType>(%1)
#define		PropType(%1)		view_as<PropType>(%1)
#define		Ent(%1)				view_as<Entity>(%1)
#define		This				view_as<any>(this)
#define		Bot(%1)				IsFakeClient(%1)

#define		CONSOLE			0

#if defined Tklib_Included
	#endinput
#endif

#define		Tklib_Included
#define		Tklib_Version	"1.3.6"

//Core includes
#include	<tklib/gameidentifier>
#include	<tklib/resize>
#include	<tklib/weapons>
#include	<tklib/clients>
#include	<tklib/entities>
#include	<tklib/additional>

#include	<tklib/tf2>
#include	<tklib/cstrike>
#include	<tklib/csgo>
#include	<tklib/l4d>
#include	<tklib/dods>
#include	<tklib/fortress_forever>

#if !defined NoMultiColors
#include	<tklib/multicolors>
#endif