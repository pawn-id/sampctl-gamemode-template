
// Include guard (versi simpel)
// Ini akan mengamankan file untuk tidak memasukkan kode yang sama ketika di include dua kali atau lebih.
#if defined _INC_components_database
	#endinput
#endif

#define _INC_components_database

// Module Include
// Plugin/include yang ingin dipakai bisa ditaruh disini
#include <a_mysql>

// Fungsi/Callback bisa ditaruh disini
forward MySQL:Database_GetHandleId();
forward OnVersionInformationAvailable(MySQL:handle);

// Include module kalian (bersifat internal)
#include <database\database_entry>
