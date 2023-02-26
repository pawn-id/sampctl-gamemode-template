
// Fungsi by Vince0789
stock MySQL:Database_GetHandleId()
{
	new MySQL:handle = MySQL:getproperty(.name = "gDatabaseHandle");

	if(handle == MYSQL_INVALID_HANDLE)
	{
		handle = mysql_connect_file();
		setproperty(.name = "gDatabaseHandle", .value = _:handle);

		if(mysql_errno(handle) == 0)
		{
			mysql_set_charset("utf8mb4", handle);
			mysql_tquery(handle, "SET @@SESSION.time_zone = '+00:00';"); 
			mysql_tquery(handle, "\
				SELECT CONCAT_WS(' ', 'Your MySQL connection id is', CONNECTION_ID()) \
				UNION \
				SELECT CONCAT_WS(' ', 'Server version:', @@version, @@version_comment);", 
				"OnVersionInformationAvailable", "d", _:handle
			);
		}
	}
	return handle;
}

public OnVersionInformationAvailable(MySQL:handle)
{
	new versionText[64];
	
	cache_get_value_index(0, 0, versionText);
	printf("\n[info] %s", versionText);

	cache_get_value_index(1, 0, versionText);
	printf("[info] %s\n", versionText);
}