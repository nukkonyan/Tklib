stock char L4D_GetTeamStringName[][]	=	{
	"{grey}Unassigned{default}",
	"{grey}Spectators{default}",
	"{orange}Survivors{default}",
	"{lightred}Zombies{default}"
};

stock char L4D_GetTeamColour[][]	=	{
	"{grey}",
	"{grey}",
	"{orange}",
	"{lightred}"
};

//Left 4 Dead enum
enum	L4DTeam	{
	L4DTeam_Unassigned	=	0,
	L4DTeam_Spectator	=	1,
	L4DTeam_Survivor	=	2,
	L4DTeam_Infected	=	3
}

#define	L4DTeam(%1)		view_as<L4DTeam>(%1)

/**
 *	Returns the users current team.
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, it will return L4DTeam_Unassigned.
 */
stock L4DTeam L4D_GetClientTeam(int client)	{
	return Tklib_IsValidClient(client) ? L4DTeam(GetClientTeam(client)):L4DTeam_Unassigned;
}

/**
 *	Changes a users current team.
 *
 *	@param	client		The users index.
 *	@error	If the user is invalid, nothing will happen.
 */
stock void L4D_ChangeClientTeam(int client, L4DTeam team)	{
	if(Tklib_IsValidClient(client))
		ChangeClientTeam(client, view_as<int>(team));
}