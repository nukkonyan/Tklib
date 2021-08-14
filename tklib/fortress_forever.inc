enum	FFTeam	{
	FFTeam_Unassigned	=	0,
	FFTeam_Spectators	=	1,
	FFTeam_Red			=	2,
	FFTeam_Blue			=	3
}

enum	FFClass	{
	//Will be filled.
}

stock char FF_GetTeamStringName[][]	=	{
	"{grey}Unassigned{default}",
	"{grey}Spectators{default}",
	"{red}Red{default}",
	"{blue}Blue{default}"	
};

/**
 *	Returns the users current team.
 *
 *	@param	client        Client index.
 *	@error	If the user is invalid, it will return FFTeam_Unassigned.
 */
stock FFTeam FF_GetClientTeam(int client)	{
	return Tklib_IsValidClient(client) ? view_as<FFTeam>(GetClientTeam(client)):FFTeam_Unassigned;
}

/**
 *	Changes the users current team.
 *
 *	@param	client        Client index.
 *	@param	team          FFTeam team symbol.
 *	@error	If the user is invalid, nothing will happen.
 */
stock void FF_ChangeClientTeam(int client, FFTeam team)	{
	if(Tklib_IsValidClient(client))
		ChangeClientTeam(client, view_as<int>(team));
}