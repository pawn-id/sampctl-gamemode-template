
timer OnPlayerLoginTimeout[MAX_LOGIN_TIMEOUT * 1000](playerid)
{
	DelayedKick(playerid, 300);
	return 1;
}
