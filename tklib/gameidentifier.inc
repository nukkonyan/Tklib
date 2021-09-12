enum	GameIdentifier	{
	Game_Unknown		= -1,
	Game_SDK2006		= 0,
	Game_SDK2007		= 1,
	Game_SDK2013		= 2,
	Game_AlienSwarm		= 3,
	Game_BGT			= 4,
	Game_BloodyGoodTime	= 5,
	Game_DarkMessiah	= 6,
	Game_Eye			= 7,
	Game_Dota			= 8,
	Game_Blade			= 9,
	Game_Insurgency		= 10,
	Game_Contagion		= 11,
	Game_BlackMesa		= 12,
	Game_DOI			= 13,
	Game_HL2DM			= 14,
	Game_DODS			= 15,
	Game_Portal1		= 16,
	Game_Portal2		= 17,
	Game_L4D1			= 18,
	Game_L4D2			= 19,
	Game_CSGO			= 20,
	Game_CSCO			= 21,
	Game_CSS			= 22,
	Game_TF2			= 23,
	Game_TF2B			= 24,
	Game_TF2Beta		= 24,
	Game_TF2C			= 25,
	Game_TF2Classic		= 25,
	Game_TF2V			= 26,
	Game_TF2Vintage		= 26,
	Game_TF2OP			= 27,
	Game_TF2OpenFortress= 27,
	Game_OpenFortress	= 27,
	Game_CSPro			= 28,
	Game_CSPromod		= 28
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
		case	Engine_CSGO:	{
			if(StrEqual(checkgame, "csgo"))
				return	Game_CSGO;
			if(StrEqual(checkgame, "csco"))
				return	Game_CSCO;
		}
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
		case	Engine_SourceSDK2006:	return	Game_SDK2006;
		case	Engine_SourceSDK2007:	{
			if(StrEqual(checkgame, "portal"))
				return	Game_Portal1;
			else if(StrEqual(checkgame, "cspromod"))
				return	Game_CSPromod;
			else return Game_SDK2007;
		}
		case	Engine_SDK2013:			return	Game_SDK2013;
	}
	return	Game_Unknown;
}