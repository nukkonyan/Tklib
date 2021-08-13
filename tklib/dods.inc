stock char DOD_GetTeamStringName[][]	=	{
	"{grey}Unassigned{default}",
	"{grey}Spectators{defualt}",
	"{red}Wehrmacht{default}",
	"{blue}U.S Army{default}"
};

//Day of Defeat: Source enum
enum	DODTeam	{
	DODTeam_Unassigned	=	0,
	DODTeam_Spectator	=	1,
	DODTeam_Red			=	2,
	DODTeam_Blue		=	3
}

/**
 *	Gets a client's current team.
 *
 *	@param	client		The players index.
 *	@error	If the client is invalid, it will return DODTeam_Unassigned.
 */
stock DODTeam DOD_GetClientTeam(int client)	{
	return Tklib_IsValidClient(client) ? view_as<DODTeam>(GetClientTeam(client)):DODTeam_Unassigned;
}

/**
 * Changes a client's current team.
 *
 *	@param	client		The players index.
 *	@error	If the client is invalid, nothing will happen.
 */
stock void DOD_ChangeClientTeam(int client, DODTeam team)	{
	if(Tklib_IsValidClient(client))
		ChangeClientTeam(client,	view_as<int>(team));
}