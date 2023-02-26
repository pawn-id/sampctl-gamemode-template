
timer OnPlayerLoginTimeout[MAX_LOGIN_TIMEOUT](playerid)
{
	DelayedKick(playerid, 300);
	return 1;
}