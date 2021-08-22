/*****************************************\
 *			Tk Libraries (Tklib)		 *
 *										 *
 * 		Made by Tk /id/Teamkiller324	 *
\*****************************************/

//Changelogs

// > Version 1.1.0
// + Fixed Set weapon ammo being only at 0.
// + Updated the code lines to be not filled with tab spaces.
// + Added numerous new set/change functions.
// + Added checks to return error if the client is invalid.

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
// + More stuff added in /additionals subinclude.
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

// > Version 1.2.1
// + Updated L4DTeam enum L4DTeam_Zombie to L4DTeam_Infected

// > Version 1.2.2
// + Updated TF_GetPlayerWeaponSlot to TF2_GetPlayerWeaponSlot.
// + Added TFSlot_Invalid.
// + Added SetWeaponDefinitionIndex

// > Version 1.3.0
// + Loads of changes and new functions.
// + Integrated Game Identifier.

// > Version 1.3.1
// + Minor additions such as SetClientModel & TF2_SetClientModel and TF2_SetClassAnimations.
// + Minor fixes to certain functions to work correctly.
// + Updated Tk_Include_Version definition to Tklib_Version.
// + Integrated Fortress Forever include.

// > Version 1.3.2
// + Minor Corrections.

// > Version 1.3.3
// + Additional minor Corrections.
// + Fixed Bool & BoolEx having incorrect placements.
// + Added AddFolderToDownloadsTable.
// + Added AddFileToDownloadsTableEx.
// + Added <game>_GetTeamColour string table to gain the teams colour.
// + Updated the TFFlag enum to use 'TFFlag' than not having a main constructor.
// + Added new definitions to possibly replace 'view_as'. Example: 'view_as<int>(function)' turns into 'int(function)' or 'view_as<Database>(function)' into 'Database(function)' (Makes it easier!)
// - Removed SetClientCookieInt as it is practically useless. Use the updated clientprefs include instead.
// + Updated entities include as a methodmap.
// + Added 'This' definition as replacement for 'this', so it is seen as 'any' (Makes it easier to handle methodmaps)
// + Added 'Ent' definition to use for turning integer entity indexes to 'Entity' index. Example: Ent(function)
// + Updated the functions to check if the netprop exists on the entity/client before proceeding, preventing errors.

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

#define		CONSOLE			0

#if defined Tklib_Included
	#endinput
#endif
#define		Tklib_Included
#define		TKlib_Version	"1.3.3"

//Core includes
#include	"tklib/gameidentifier"
#include	"tklib/resize"
#include	"tklib/weapons"
#include	"tklib/clients"
#include	"tklib/entities"
#include	"tklib/additional"

#include	"tklib/tf2"
#include	"tklib/cstrike"
#include	"tklib/csgo"
#include	"tklib/l4d"
#include	"tklib/dods"
#include	"tklib/fortress_forever"