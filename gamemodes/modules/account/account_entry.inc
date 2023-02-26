
#include <account\account_timer>
#include <account\account_auth>

// Initialisation
@init(.order = script_init) OnAccountInit()
{
	AccLib_Init(Database_GetHandleId(), 
		//--------
		"accounts",
		//--------
		"id", 
		"name",
		"password"
		//--------
	);

	print("[+] Account module is successfully loaded.");
	return 1;
}
