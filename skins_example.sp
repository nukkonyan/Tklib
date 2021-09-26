#include	<tklib>

#pragma		semicolon	1
#pragma		newdecls	required

public	Plugin	myinfo	=	{
	name		=	"[CS:GO] Skins Example",
	author		=	"Tk /id/Teamkiller324",
	description	=	"Plugin",
	version		=	"0.01a",
	url			=	"https://steamcommunity.com/id/Teamkiller324"
}

public void OnPluginStart()	{
	RegConsoleCmd("sm_skin", SkinCmd);
}

Action SkinCmd(int client, int args)	{
	if(args < 1 || args > 6)	{
		PrintToChat(client, "[Skins Example] Usage: sm_skin \"weapon\" <skin index> <wear> <pattern> \"name tag\" <stattrak>");
		return	Plugin_Handled;
	}
	
	char arg1[64], arg2[64], arg3[64], arg4[64], arg5[64], arg6[64];
	GetCmdArg(1, arg1, sizeof(arg1));
	GetCmdArg(2, arg2, sizeof(arg2));
	GetCmdArg(3, arg3, sizeof(arg3));
	GetCmdArg(4, arg4, sizeof(arg4));
	GetCmdArg(5, arg5, sizeof(arg5));
	GetCmdArg(6, arg6, sizeof(arg6));
	
	Entity weapon;
	
	if(StrContainsEx(arg1, "weapon_knife") || StrContainsEx(arg1, "weapon_bayonet"))
	{
		weapon = new Entity("weapon_knife");
	}
	else
	{
		weapon = new Entity(arg1);
	}
	
	if(weapon == Entity_Invalid)	{
		PrintToChat(client, "[Plugin] The weapon specified is invalid");
		return	Plugin_Handled;
	}
	
	if(StrContainsEx(arg1, "weapon_knife_") || StrContainsEx(arg1, "weapon_bayonet"))
	{
		if(StrContainsEx(arg1, "weapon_knife_ghost") || StrContainsEx(arg1, "weapon_knife_spectral"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Spectral;
		}
		else if(StrContainsEx(arg1, "weapon_knife_bayonet") || StrContainsEx(arg1, "weapon_bayonet"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Bayonet;
		}
		else if(StrContainsEx(arg1, "weapon_knife_css") || StrContainsEx(arg1, "weapon_knife_classic"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Classic;
		}
		else if(StrContainsEx(arg1, "weapon_knife_flip"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Flip;
		}
		else if(StrContainsEx(arg1, "weapon_knife_gut"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Gut;
		}
		else if(StrContainsEx(arg1, "weapon_knife_karambit"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Karambit;
		}
		else if(StrContainsEx(arg1, "weapon_knife_m9_bayonet") || StrContainsEx(arg1, "weapon_m9_bayonet"))
		{
			weapon.DefinitionIndex = CSGO_Knife_M9_Bayonet;
		}
		else if(StrContainsEx(arg1, "weapon_knife_tactical weapon_knife_huntsman"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Huntsman;
		}
		else if(StrContainsEx(arg1, "weapon_knife_falchion"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Falchion;
		}
		else if(StrContainsEx(arg1, "weapon_knife_survival_bowie") || StrContainsEx(arg1, "weapon_knife_bowie"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Bowie;
		}
		else if(StrContainsEx(arg1, "weapon_knife_butterfly"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Butterfly;
		}
		else if(StrContainsEx(arg1, "weapon_knife_push") || StrContainsEx(arg1, "weapon_knife_shadowdaggers"))
		{
			weapon.DefinitionIndex = CSGO_Knife_ShadowDaggers;
		}
		else if(StrContainsEx(arg1, "weapon_knife_paracord"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Paracord;
		}
		else if(StrContainsEx(arg1, "weapon_knife_survival"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Survival;
		}
		else if(StrContainsEx(arg1, "weapon_knife_ursus"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Ursus;
		}
		else if(StrContainsEx(arg1, "weapon_knife_navaja"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Navaja;
		}
		else if(StrContainsEx(arg1, "weapon_knife_nomad"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Nomad;
		}
		else if(StrContainsEx(arg1, "weapon_knife_stiletto"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Stiletto;
		}
		else if(StrContainsEx(arg1, "weapon_knife_widowmaker") || StrContainsEx(arg1, "weapon_knife_talon"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Talon;
		}
		else if(StrContainsEx(arg1, "weapon_knife_skeleton"))
		{
			weapon.DefinitionIndex = CSGO_Knife_Skeleton;
		}
		
		weapon.SetClassname("weapon_knifegg");
	}
	
	CSGO_FixWeaponId(weapon);
	CSGO_SetWeaponOwner(weapon, client);
	
	//Set skin.
	if(!StrEqual(arg2, ""))
	{
		CSGO_SetWeaponSkin(weapon, StringToInt(arg2));
	}
	
	//Set wear.
	if(!StrEqual(arg3, ""))
	{
		CSGO_SetWeaponWear(weapon, StringToFloat(arg3));
	}
	
	//Set pattern.
	if(!StrEqual(arg4, ""))
	{
		CSGO_SetWeaponPattern(weapon, StringToInt(arg4));
	}
	
	//Set nametag.
	if(!StrEqual(arg5, ""))
	{
		CSGO_SetWeaponNametag(weapon, arg5);
	}
	
	//Set stattrak.
	if(!StrEqual(arg6, ""))
	{
		CSGO_SetWeaponStatTrak(weapon, StringToInt(arg6));
	}
	
	weapon.Spawn();
	
	EquipPlayerWeaponEx(client, weapon);
	
	return	Plugin_Handled;
}