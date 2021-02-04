/*****************************************\
 *		  Fortress Forever Include		 *
 *										 *
 * 		Made by Tk /id/Teamkiller324	 *
\*****************************************/

#define	FF_Include_Version	"1.0.0"

enum	FFTeam
{
	FFTeam_Unassigned	=	0,
	FFTeam_Spectators	=	1,
	FFTeam_Red			=	2,
	FFTeam_Blue			=	3
};

stock	char	FF_GetTeamStringName[][128]		=	{
	"{grey}Unassigned",
	"{grey}Spectators",
	"{red}Red",
	"{blue}Blue"	
};

/**
 * Gets a client's current team.
 *
 * @param client        Client index.
 * @return              Current FFTeam of client.
 * @error               Invalid client index.
 */
stock	FFTeam	FF_GetClientTeam(int client)	{
	return	view_as<FFTeam>(GetClientTeam(client));
}

/**
 * Changes a client's current team.
 *
 * @param client        Client index.
 * @param team          FFTeam team symbol.
 * @error               Invalid client index.
 */
stock	void	FF_ChangeClientTeam(int client,	FFTeam team)	{
	ChangeClientTeam(client,	view_as<int>(team));
}