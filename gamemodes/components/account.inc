
// Include guard (versi simpel)
// Ini akan mengamankan file untuk tidak memasukkan kode yang sama ketika di include dua kali atau lebih.
#if defined _INC_components_account
	#endinput
#endif

#define _INC_components_account

// Module configuration
#define MAX_LOGIN_TIMEOUT			60 // in seconds
#define MAX_WRONG_PASSWORD          3
#define ACCLIB_AUTO_KICK_ON_ERROR

// Module Include
// Plugin/include yang ingin dipakai bisa ditaruh disini
#include <utilities>
#include <components\database>

#include <account-lib>
#include <YSI_Coding\y_inline>
#include <YSI_Coding\y_timers>
#include <YSI_Visual\y_dialog>

// Fungsi/Callback bisa ditaruh disini
forward bool:AccLib_LogoutPlayer(playerid, refetch = false);
forward AccLib_GetAccountId(playerid);
forward bool:AccLib_GetAccountName(playerid, string:name[], len = sizeof(name));
forward bool:AccLib_SetAccountName(playerid, const string:name[]);
forward bool:AccLib_SetAccountPassword(playerid, const string:password[]);

// Include module kalian (bersifat internal)
#include <account\account_entry>
