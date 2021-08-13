/*****************************************\
 *			Tk Libraries (Tklib)		 *
 *										 *
 * 		Made by Tk /id/Teamkiller324	 *
 *										 *
 *				Version 1.3.0			 *
\*****************************************/

//Changelogs

// - Version 1.1.0
// + Fixed Set weapon ammo being only at 0.
// + Updated the code lines to be not filled with tab spaces.
// + Added numerous new set/change functions.
// + Added checks to return error if the client is invalid.

// - Version 1.1.1
// + Added Day of Defeat: Source
// + Added TFFlag event type support (Events related to example picking up, defending, capturing and dropping intelligence in tf2.)
// + Updated some enum structures to better match the existing ones.

// - Version 1.1.2
// + Added Get & Set client lifestate function.
// + Added TFFlag_Carrier to TFFlag enum structure.
// + Few other changes on some functions.

// - Version 1.2.0
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
// + Added GetEntityName to get the entitys name.
// + Added SetEntityName to set the entitys name.
// + Added FindEntity to return true or false wheter the entity by classname exists in the current map.
// + Added CreateEntityByNameEx which does same functionality as CreateEntityByNameEx but it has additional string to put in the entitys custom name you specify.
// + Added SetEntityDisabled if the entity you target should start disabled or not as a boolean. true/false statement.
// + Added GetEntityModel as easier method to return the model of the entity.
// + Added GetClientAuth which is same as GetClientAuthId but it functions similiarly to GetClientAuthString.

// - Version 1.2.1
// + Updated L4DTeam enum L4DTeam_Zombie to L4DTeam_Infected

// - Version 1.2.2
// + Updated TF_GetPlayerWeaponSlot to TF2_GetPlayerWeaponSlot.
// + Added TFSlot_Invalid.
// + Added SetWeaponDefinitionIndex

// - Version 1.2.5
// + Loads of changes and new functions.
// + Integrated Game Identifier.

#if defined Tklib_Included
	#endinput
#endif
#define Tklib_Included

//SM Includes
#include	<sdktools>
#include	<sdkhooks>
#undef		REQUIRE_EXTENSIONS
#undef		REQUIRE_PLUGIN
#include	<cstrike>
#include	<tf2_stocks>

#define		CONSOLE		0
#define		TK_Include_Version	"1.3.0"

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