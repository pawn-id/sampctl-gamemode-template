
static
	g_sRequestClassPassed[MAX_PLAYERS],
	Timer:g_sPlayerLoginTimer[MAX_PLAYERS],
	g_sPlayerLoginAttempts[MAX_PLAYERS];

#include <YSI_Coding\y_hooks>
hook OnPlayerRequestClass(playerid, classid)
{
	// Untuk mencegah F3
	if (!g_sRequestClassPassed[playerid])
	{
		new jam, menit;
		gettime(jam, menit, _);

		TogglePlayerSpectating(playerid, true);
		SetPlayerTime(playerid, jam, menit);

		AccLib_FetchAccount(playerid);
		return 1;
	}
	return 0;
}

hook OnAccountFetched(playerid, bool:success)
{
	if (success) // jika pemain datanya ada, loginkan
	{
		inline onLoginResponse(response, listitem, string:inputtext[])
		{
			if (!response)
			{
				Kick(playerid);
				return 0;
			}

			if (!IsNull(inputtext))
			{
				AccLib_LoginPlayer(playerid, inputtext);
				return 1;
			}

			if (++g_sPlayerLoginAttempts[playerid] >= MAX_WRONG_PASSWORD)
			{
					g_sPlayerLoginAttempts[playerid] = 0;
					Dialog_Show(playerid, "NAMAPROJECTMU - Message Notice", "{FFFFFF}Anda telah memasukkan password yang salah sebanyak 3 kali!", "Okay", "");
					DelayedKick(playerid);
					return 0;
			}

			Dialog_ShowCallback(playerid, using inline dialogLoginRespond, DIALOG_STYLE_PASSWORD, "Login", "Invalid password specified!\nPlease enter your password in the field below:", "Login", "Abort");
			return 0;
		}

		new string:loginFmt[64];
		format(loginFmt, sizeof(loginFmt), "{FFFFFF}Hallo {00FF00}%s{FFFFFFFF}, selamat datang kembali di NAMAPROJECTMU!\nAnda diberi waktu "#MAX_LOGIN_TIMEOUT" untuk memasukkan password dibawah untuk melanjutkan.", ReturnPlayerName(playerid));
		Dialog_ShowCallback(playerid, using inline onLoginResponse, DIALOG_STYLE_PASSWORD, "NAMAPROJECTMU - Login Screen", loginFmt, "Login", "Abort");
	
		g_sPlayerLoginTimer[playerid] = defer OnPlayerLoginTimeout(playerid);
		return 1;
	}

	Dialog_Show(playerid, "NAMAPROJECTMU - Register", "{FFFFFF}Maaf, pendaftaran hanya ada di discord (seperti FiveM)", "Okay :( (anjing lo)", "");
	return 0;
}

hook OnAccountLogin(playerid, bool:success)
{
	if (!success)
	{
		if (++g_sPlayerLoginAttempts[playerid] >= MAX_WRONG_PASSWORD)
		{
				g_sPlayerLoginAttempts[playerid] = 0;
				Dialog_Show(playerid, "NAMAPROJECTMU - Message Notice", "{FFFFFF}Anda telah memasukkan password yang salah sebanyak 3 kali!", "Okay", "");
				DelayedKick(playerid);
				return 0;
		}
		Dialog_ShowCallback(playerid, using inline dialogLoginRespond, DIALOG_STYLE_PASSWORD, "Login", "Invalid password specified!\nPlease enter your password in the field below:", "Login", "Abort");
		return 0;
	}

	// Jika sukses, set spawn
	SetSpawnInfo(playerid, 0, 24, 0.0, 0.0, 1.5, 90.0, 0, 0, 0, 0, 0, 0);
	TogglePlayerSpectating(playerid, false);

	// Matikan timernya
	stop g_sPlayerLoginTimer[playerid];
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	// Reset variable jika sudah keluar
	g_sPlayerLoginAttempts[playerid] = 0;
	stop g_sPlayerLoginTimer[playerid];
	g_sRequestClassPassed[playerid] = 0;
	return 1;
}
