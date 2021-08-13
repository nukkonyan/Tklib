enum	GameIdentifier	{
	Game_Unknown		= -1,
	Game_AlienSwarm		= 0,
	Game_BGT			= 1,
	Game_BloodyGoodTime	= 1,
	Game_DarkMessiah	= 2,
	Game_Eye			= 3,
	Game_Dota			= 4,
	Game_Blade			= 5,
	Game_Insurgency		= 6,
	Game_Contagion		= 7,
	Game_BlackMesa		= 8,
	Game_DOI			= 9,
	Game_HL2DM			= 10,
	Game_DODS			= 11,
	Game_Portal1		= 12,
	Game_Portal2		= 13,
	Game_L4D1			= 14,
	Game_L4D2			= 15,
	Game_CSGO			= 16,
	Game_CSS			= 17,
	Game_TF2			= 18,
	Game_TF2B			= 19,
	Game_TF2Beta		= 19,
	Game_TF2C			= 20,
	Game_TF2Classic		= 20,
	Game_TF2V			= 21,
	Game_TF2Vintage		= 22,
	Game_TF2OP			= 23,
	Game_TF2OpenFortress= 23,
	Game_OpenFortress	= 23,
	Game_CSPro			= 24,
	Game_CSPromod		= 24
}

/**
 *	This is to make game identification much easier.
 *
 *	@return			Returns as example Game_TF2Vintage, Game_CSPromod, etc.
 */
stock GameIdentifier IdentifyGame()	{
	char checkgame[64];
	GetGameFolderName(checkgame, sizeof(checkgame));
	switch(GetEngineVersion())	{
		case	Engine_Unknown:			return	Game_Unknown;
		case	Engine_AlienSwarm:		return	Game_AlienSwarm;
		case	Engine_BloodyGoodTime:	return	Game_BloodyGoodTime;
		case	Engine_DarkMessiah:		return	Game_DarkMessiah;
		case	Engine_EYE:				return	Game_Eye;
		case	Engine_DOTA:			return	Game_Dota;
		case	Engine_Blade:			return	Game_Blade;
		case	Engine_Insurgency:		return	Game_Insurgency;
		case	Engine_Contagion:		return	Game_Contagion;
		case	Engine_BlackMesa:		return	Game_BlackMesa;
		case	Engine_DOI:				return	Game_DOI;
		case	Engine_HL2DM:			return	Game_HL2DM;
		case	Engine_DODS:			return	Game_DODS;
		case	Engine_Portal2:			return	Game_Portal2;
		case	Engine_Left4Dead:		return	Game_L4D1;
		case	Engine_Left4Dead2:		return	Game_L4D2;
		case	Engine_CSGO:			return	Game_CSGO;
		case	Engine_CSS:				return	Game_CSS;
		case	Engine_TF2:	{
			if(StrEqual(checkgame, "tf"))
				return	Game_TF2;
			if(StrEqual(checkgame, "tfbeta"))
				return	Game_TF2Beta;
			if(StrEqual(checkgame, "tf2classic"))
				return	Game_TF2Classic;
			if(StrEqual(checkgame, "tf2vintage"))
				return	Game_TF2Vintage;
			if(StrEqual(checkgame, "open_fortress"))
				return	Game_TF2OpenFortress;
		}
		case	Engine_SourceSDK2007:	{
			if(StrEqual(checkgame, "portal"))
				return	Game_Portal1;
			if(StrEqual(checkgame, "cspromod"))
				return	Game_CSPromod;
		}
	}
	return	Game_Unknown;
}