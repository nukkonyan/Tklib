stock char DOD_GetTeamStringName[][]	=	{
	"{grey}Unassigned{default}",
	"{grey}Spectators{defualt}",
	"{red}Wehrmacht{default}",
	"{blue}U.S Army{default}"
};

stock char DODS_GetTeamColour[][]	=	{
	"{grey}",
	"{grey}",
	"{red}",
	"{blue}"
};

//Day of Defeat: Source enum
enum	DODTeam	{
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
 *	@error	If the user is invalid, it will return DODTeam_Unassigned.
 */
stock DODTeam DOD_GetClientTeam(int client)	{
	return Tklib_IsValidClient(client) ? DODTeam(GetClientTeam(client)):DODTeam_Unassigned;
}

/**
 *	Changes the users current team.
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, nothing will happen.
 */
stock void DOD_ChangeClientTeam(int client, DODTeam team)	{
	if(Tklib_IsValidClient(client))
		ChangeClientTeam(client,	view_as<int>(team));
}