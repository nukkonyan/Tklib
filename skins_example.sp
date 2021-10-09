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
	RegConsoleCmd("sm_skins", SkinsCmd);
	
	AddCommandListener(Skins_Listener,	"say");
	AddCommandListener(Skins_Listener,	"say_team");
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
	
	Entity weapon = GetCSGOWeapon(arg1);
	
	if(weapon == Entity_Invalid)	{
		PrintToChat(client, "[Plugin] The weapon specified is invalid");
		return	Plugin_Handled;
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
	
	PrintToChat(client, "[Skins Example] Weapon has been created.");
	
	EquipPlayerWeaponEx(client, weapon);
	
	return	Plugin_Handled;
}

Entity GetCSGOWeapon(const char[] weapon_name)
{
	Entity weapon;
	
	if(StrEqual(weapon_name, "weapon_knifegg", false))
	{
		weapon = new Entity("weapon_knifegg");
	}
	if(StrContainsEx(weapon_name, "weapon_knife", false) || StrContainsEx(weapon_name, "weapon_bayonet", false))
	{
		weapon = new Entity("weapon_knife");
	}
	else
	{
		weapon = new Entity(weapon_name);
	}
	
	if(weapon == Entity_Invalid)
	{
		return	weapon;
	}
	
	if(StrContainsEx(weapon_name, "weapon_knife_", false) || StrContainsEx(weapon_name, "weapon_bayonet", false))
	{
		if(StrContainsEx(weapon_name, "weapon_knife_ghost", false) || StrContainsEx(weapon_name, "weapon_knife_spectral", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Spectral;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_bayonet", false) || StrContainsEx(weapon_name, "weapon_bayonet", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Bayonet;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_css", false) || StrContainsEx(weapon_name, "weapon_knife_classic", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Classic;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_flip", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Flip;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_gut", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Gut;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_karambit", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Karambit;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_m9_bayonet", false) || StrContainsEx(weapon_name, "weapon_m9_bayonet", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_M9_Bayonet;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_tactical", false) || StrContainsEx(weapon_name, "weapon_knife_huntsman", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Huntsman;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_falchion", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Falchion;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_survival_bowie", false) || StrContainsEx(weapon_name, "weapon_knife_bowie", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Bowie;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_butterfly", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Butterfly;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_push", false) || StrContainsEx(weapon_name, "weapon_knife_shadowdaggers", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_ShadowDaggers;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_paracord", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Paracord;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_survival", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Survival;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_ursus", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Ursus;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_navaja", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Navaja;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_nomad", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Nomad;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_stiletto", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Stiletto;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_widowmaker", false) || StrContainsEx(weapon_name, "weapon_knife_talon", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Talon;
		}
		else if(StrContainsEx(weapon_name, "weapon_knife_skeleton", false))
		{
			weapon.DefinitionIndex = CSGO_Knife_Skeleton;
		}
		
		weapon.SetClassname("weapon_knifegg");
	}
	
	return	weapon;
}

//Skin menu

char item_selected[64][MAXPLAYERS];

Entity entity_selected[MAXPLAYERS] = {Entity_Invalid, ...};

bool skin_select[MAXPLAYERS] = {false, ...};
bool wear_select[MAXPLAYERS] = {false, ...};
bool pattern_select[MAXPLAYERS] = {false, ...};
bool stattrak_select[MAXPLAYERS] = {false, ...};

Action Skins_Listener(int client, const char[] command, int args)
{
	char arg1[64];
	GetCmdArg(1, arg1, sizeof(arg1));
	
	if(skin_select[client])
	{
		if(StrEqual(arg1, "!cancel", false))
		{
			skin_select[client] = false;
			entity_selected[client] = Entity_Invalid;
			item_selected[client] = "";
			
			//Lets stop here if cancelled, we shall not keep the event continuing to prevent messing things up.
			return	Plugin_Handled;
		}
		
		if(!StrContainsNumber(arg1) && !StrEqual(arg1, "off", false))
		{
			PrintToChat(client, "[Skins Example] Please specify a valid skin index number. Type '!cancel' to cancel this procedure.");
			return	Plugin_Handled;
		}
		
		//Lets grab the skin index the user specified.
		CSGO_SetWeaponSkin(entity_selected[client], StringToInt(arg1));
		
		//We finished grabbing, now lets proceed onto the wear float.
		PrintToChat(client, "Specify the skin's wear float in chat. Specifying '!cancel' Cancels this process.");
		skin_select[client] = false;
		wear_select[client] = true;
		
		//Block the chat message.
		return	Plugin_Handled;
	}
	
	if(wear_select[client])
	{
		if(StrEqual(arg1, "!cancel", false))
		{
			wear_select[client] = false;
			entity_selected[client] = Entity_Invalid;
			item_selected[client] = "";
			
			//Lets stop here if cancelled.
			return	Plugin_Handled;
		}
		
		if(!StrContainsNumber(arg1) && !StrEqual(arg1, "off", false))
		{
			PrintToChat(client, "[Skins Example] Please specify a valid wear float. Type '!cancel' to cancel this procedure.");
			return	Plugin_Handled;
		}
		
		//Lets grab the float number the user specified.
		CSGO_SetWeaponWear(entity_selected[client], StringToFloat(arg1));
		
		//We finished grabbing, now lets proceed onto the pattern.
		PrintToChat(client, "Specify the skin's pattern index number in chat. Specifying '!cancel' Cancels this process.");
		wear_select[client] = false;
		pattern_select[client] = true;
		
		//Block the chat message.
		return	Plugin_Handled;
	}
	
	if(pattern_select[client])
	{
		if(StrEqual(arg1, "!cancel", false))
		{
			pattern_select[client] = false;
			entity_selected[client] = Entity_Invalid;
			item_selected[client] = "";
			
			//Lets stop here if cancelled.
			return	Plugin_Handled;
		}
		
		//Lets grab the pattern index number.
		CSGO_SetWeaponPattern(entity_selected[client], StringToInt(arg1));
		
		//We finished grabbing, now lets proceed onto the stattrak module.
		PrintToChat(client, "Specify the skin's stattrak counter in chat. If you specify 'off', the stattrak module will be off. \nSpecifying '!cancel' Cancels this process.");
		pattern_select[client] = false;
		stattrak_select[client] = true;
		
		//Block the chat message.
		return	Plugin_Handled;
	}
	
	if(stattrak_select[client])
	{
		if(StrEqual(arg1, "!cancel", false))
		{
			stattrak_select[client] = false;
			entity_selected[client] = Entity_Invalid;
			item_selected[client] = "";
			
			//Lets stop here if cancelled.
			return	Plugin_Handled;
		}
		
		if(!StrContainsNumber(arg1) && !StrEqual(arg1, "off", false))
		{
			PrintToChat(client, "[Skins Example] Please specify a valid number. Type 'off' for no stattrak counter. \nOr '!cancel' to cancel this procedure");
			return	Plugin_Handled;
		}
		
		//Lets grab the stattrak count.
		if(!StrEqual(arg1, "off", false))
		{
			CSGO_SetWeaponStatTrak(entity_selected[client], StringToInt(arg1));
		}
		
		//We finished grabbing, now lets proceed onto the stattrak name.
		PrintToChat(client, "[Skins Example] Weapon has been created.");
		stattrak_select[client] = false;
		
		//We finished grabbing, now lets proceed equipping the weapon.
		CSGO_FixWeaponId(entity_selected[client]);
		CSGO_SetWeaponOwner(entity_selected[client], client);
		EquipPlayerWeaponEx(client, entity_selected[client]);
		
		//Block the chat message.
		return	Plugin_Handled;
	}
	
	return	Plugin_Continue;
}

Action SkinsCmd(int client, int args)
{
	Menu menu = new Menu(Handler_Skins);
	
	menu.SetTitle("Choose Item");
	
	menu.AddItem("weapon_glock",			"Glock");
	menu.AddItem("weapon_usp_silencer",		"USP-S");
	menu.AddItem("weapon_hkp2000",			"P2000");
	menu.AddItem("weapon_p250",				"P250");
	menu.AddItem("weapon_tec9",				"Tec-9");
	menu.AddItem("weapon_cz75a",			"CZ75-A");
	menu.AddItem("weapon_revolver",			"R8 Revolver");
	menu.AddItem("weapon_deagle",			"Deagle");
	menu.AddItem("weapon_ak47",				"Ak47");
	menu.AddItem("weapon_m4a1",				"M4A4");
	menu.AddItem("weapon_m4a1_silencer",	"M4A1-S");
	menu.AddItem("weapon_sg556",			"SG556");
	menu.AddItem("weapon_aug",				"Aug");
	menu.AddItem("weapon_galilar",			"GalilAR");
	menu.AddItem("weapon_famas",			"Famas");
	menu.AddItem("weapon_ssg08",			"Scout");
	menu.AddItem("weapon_awp",				"AWP");
	menu.AddItem("weapon_g3sg1",			"G3SG1");
	menu.AddItem("weapon_scar20",			"Scar-20");
	menu.AddItem("weapon_negev",			"Negev");
	menu.AddItem("weapon_m249",				"M249");
	menu.AddItem("weapon_mp5sd",			"MP5-SD");
	menu.AddItem("weapon_mp7",				"MP7");
	menu.AddItem("weapon_mp9",				"MP9");
	menu.AddItem("weapon_mac10",			"MAC-10");
	menu.AddItem("weapon_ump45",			"UMP-45");
	menu.AddItem("weapon_p90",				"P90");
	menu.AddItem("weapon_bizon",			"PP-Bizon");
	menu.AddItem("weapon_xm1014",			"XM1014");
	menu.AddItem("weapon_mag7",				"MAG-7");
	menu.AddItem("weapon_sawedoff",			"Sawed-Off");
	menu.AddItem("weapon_taser",			"Zeus");
	menu.AddItem("weapon_nova",				"Nova");
	menu.AddItem("weapon_knife_ct",			"CT Knife");
	menu.AddItem("weapon_knife_t",			"T Knife");
	menu.AddItem("weapon_knifegg",			"Golden Knife");
	menu.AddItem("weapon_knife_spectral",	"Spectral Knife");
	menu.AddItem("weapon_bayonet",			"Bayonet Knife");
	menu.AddItem("weapon_knife_classic",	"Classic Knife");
	menu.AddItem("weapon_knife_flip",		"Flip Knife");
	menu.AddItem("weapon_knife_gut",		"Gut Knife");
	menu.AddItem("weapon_knife_karambit",	"Karambit Knife");
	menu.AddItem("weapon_knife_m9_bayonet",	"M9 Bayonet Knife");
	menu.AddItem("weapon_knife_tactical",	"Huntman Knife");
	menu.AddItem("weapon_knife_falchion",	"Falchion Knife");
	menu.AddItem("weapon_knife_survival_bowie",	"Bowie Knife");
	menu.AddItem("weapon_knife_butterfly",	"Butterfly Knife");
	menu.AddItem("weapon_knife_push",		"Shadow Daggers");
	menu.AddItem("weapon_knife_paracord",	"Paracord Knife");
	menu.AddItem("weapon_knife_survival",	"Survival Knife");
	menu.AddItem("weapon_knife_ursus",		"Ursus Knife");
	menu.AddItem("weapon_knife_navaja",		"Navaja Knife");
	menu.AddItem("weapon_knife_nomad",		"Nomad Knife");
	menu.AddItem("weapon_knife_stiletto",	"Stiletto Knife");
	menu.AddItem("weapon_knife_talon",		"Talon Knife");
	menu.AddItem("weapon_knife_skeleton",	"Skeleton Knife");
	menu.AddItem("weapon_c4",				"C4 Bomb");
	menu.AddItem("weapon_flashbang",		"Flashbang");
	menu.AddItem("weapon_hegrenade",		"Frag Grenade");
	menu.AddItem("weapon_smokegrenade",		"Smoke Grenade");
	menu.AddItem("weapon_molotov",			"Molotov Grenade");
	menu.AddItem("weapon_decoy",			"Decoy Grenade");
	menu.AddItem("weapon_incgrenade",		"Incendiary Grenade");
	menu.AddItem("weapon_tacgrenade",		"Tactical Grenade");
	
	menu.ExitButton = true;
	
	menu.Display(client, MENU_TIME_FOREVER);
}

int Handler_Skins(Menu menu, MenuAction action, int client, int selection)
{
	switch(action)
	{
		case	MenuAction_Select:
		{
			menu.GetItem(selection, item_selected[client], sizeof(item_selected[]));
			
			skin_select[client] = true;
			
			entity_selected[client] = GetCSGOWeapon(item_selected[client]);
			
			PrintToChat(client, "Select skin index to use on your selected item in chat. Specifying '!cancel' Cancels this process.");
		}
		case	MenuAction_Cancel, MenuAction_End:
		{
			delete menu;
		}
	}
}

/*
 *	Returns if the string contains a number.
 *
 *	@param	str		String buffer to check.
 *
 *	@return	If the string contains a number, this returns true. False otherwise.
 *
 *	@error	If the string is empty, this returns false.
 */
bool StrContainsNumber(const char[] str)
{
	if(strlen(str) < 1)
		return	false;
	
	if(!StrEqual(str, "0", false) &&
	!StrEqual(str, "1", false) &&
	!StrEqual(str, "2", false) &&
	!StrEqual(str, "3", false) &&
	!StrEqual(str, "4", false) &&
	!StrEqual(str, "5", false) &&
	!StrEqual(str, "6", false) &&
	!StrEqual(str, "7", false) &&
	!StrEqual(str, "8", false) &&
	!StrEqual(str, "9", false))	{
		return	false;
	}
	
	return	true;
}