/*****************************************\
 *			Tk Libraries (Tklib)		 *
 *										 *
 * 		Made by Tk /id/Teamkiller324	 *
\*****************************************/

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
#define		player(%1)			view_as<Player>(%1)
#define boolean bool

#define		CONSOLE			0

#if defined Tklib_Included
	#endinput
#endif

//Core includes
#include	<tklib/gameidentifier>
#include	<tklib/resize>
#include	<tklib/weapons>
#include	<tklib/clients>
#include	<tklib/entities>
#include	<tklib/additional>
#include	<tklib/events>

#include	<tklib/tf2>
#include	<tklib/cstrike>
#include	<tklib/csgo>
#include	<tklib/l4d>
#include	<tklib/dods>
#include	<tklib/fortress_forever>
#include	<tklib/contagion>

#if !defined NoMultiColors
#include	<tklib/multicolors>
#endif