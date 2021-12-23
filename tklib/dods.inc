//==========================================//
// Tklib / Day of Defeat: Source.
//==========================================//

stock char DOD_GetTeamStringName[][] = {
	"{grey}Unassigned{default}",
	"{grey}Spectators{defualt}",
	"{red}Wehrmacht{default}",
	"{blue}U.S Army{default}"
}, DODS_GetTeamColour[][] = {
	"{grey}",
	"{grey}",
	"{red}",
	"{blue}"
};

//Day of Defeat: Source enum
enum	DODTeam	{
	DODTeam_Invalid		=	-1,
	DODTeam_Unassigned	=	0,
	DODTeam_Spectator	=	1,
	DODTeam_Red			=	2,
	DODTeam_Blue		=	3
}

#define	DODTeam(%1)		view_as<DODTeam>(%1)

/**
 *	Returns the users current team.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns DODTeam_Unassigned.
 */
stock DODTeam DOD_GetClientTeam(int client)	{
	return Tklib_IsValidClient(client) ? DODTeam(GetClientTeam(client)):DODTeam_Unassigned;
}

/**
 *	Changes the users current team.
 *
 *	@param	client		The users index.
 *
 *	@error	If the user is invalid, this returns false.
 */
stock bool DOD_ChangeClientTeam(int client, DODTeam team)	{
	if(Tklib_IsValidClient(client))	{
		ChangeClientTeam(client, int(team));
		return	true;
	}
	
	return	false;
}

/**
 *	Returns a random DODTeam team (Red or Blue)
 *
 *	@return	Returns a DODTeam team.
 */
stock DODTeam DOD_GetRandomTeam()	{
	return	DODTeam(GetRandomInt(2, 3));
}