/*************************************************\
 *				Contagion include				 *
 *												 *
 *			Made by Tk /id/Teamkiller324		 *
 *												 *
\*************************************************/

#define	Contagion_Include_Version	"1.0.0"

enum	CETeam
{
	CETeam_Unassigned	=	0,
	CETeam_Spectators	=	1,
	CETeam_Survivors		=	2,
	CETeam_Zombies		=	3
}

/**
 * Gets a client's current team.
 *
 * @param client        Client index.
 * @return              Current CETeam of client.
 * @error               Invalid client index.
 */
stock	CETeam	CE_GetClientTeam(int client)	{
	return	view_as<CETeam>(GetClientTeam(client));
}

/**
 * Changes a client's current team.
 *
 * @param client        Client index.
 * @param team          CETeam team symbol.
 * @error               Invalid client index.
 */
stock	void	CE_ChangeClientTeam(int client,	CETeam team)	{
	ChangeClientTeam(client,	view_as<int>(team));
}