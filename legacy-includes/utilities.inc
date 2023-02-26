
/*
	@Title: Utilities module
	@Version: 0.0.1
	@Author: pawn-id

	Module utilitiy untuk template gamemode
*/

#if defined _INC_utilities
	#endinput
#endif

#define _INC_utilities

#include <YSI_Coding\y_inline>
#include <YSI_Extra\y_inline_timers>

stock DelayedKick(playerid, interval = 1000)
{
	inline onKicked()
	{
		Kick(playerid);
	}
	Timer_CreateCallback(using inline onKicked, interval, 1);
	return 1;
}
