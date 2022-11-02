methodmap MenuEx < Menu {
	public MenuEx(MenuHandler handler) { return view_as<MenuEx>(new Menu(handler)); }
	
	/*
	 *	Displays a menu to a user.
	 *
	 *	@param	client	The users index.
	 *	@param	time	Maximum time to leave menu on the screen.
	 *
	 *	@return	True on success, false on failure.
	 */
	public bool Display(int client, int time = MENU_TIME_FOREVER) { return view_as<Menu>(this).Display(client, time); }

	/*
	 *	Displays a menu to a user, starting from the given item.
	 *
	 *	@param	client		The users index.
	 *	@param	first_item	First item to begin drawing from.
	 *	@param	time		Maximum time to leave menu on the screen.
	 *
	 *	@return	True on success, false on failure.
	 */
	public bool DisplayAt(int client, int first_item, int time = MENU_TIME_FOREVER) { return view_as<Menu>(this).DisplayAt(client, first_item, time); }
	
	public void SetTitle(const char[] fmt, any ...) {
		int maxlen = strlen(fmt)+65;
		char[] format = new char[maxlen];
		VFormat(format, maxlen, fmt, 3);
		view_as<Menu>(this).SetTitle(format);
	}
	
	public void GetTitle(char[] buffer, int maxlen) { view_as<Menu>(this).GetTitle(buffer, maxlen); }
	
	public bool AddItem(const char[] info, const char[] display, int style = ITEMDRAW_DEFAULT) { return view_as<Menu>(this).AddItem(info, display, style); }
	
	public bool AddItemEx(const char[] info, const char[] display, int style = ITEMDRAW_DEFAULT, any ...) {
		int maxlen = strlen(display)+65;
		char[] format = new char[maxlen];
		VFormat(format, maxlen, display, 5);
		return view_as<Menu>(this).AddItem(info, format, style);
	}
	
	public bool AddItemInt(int info, const char[] display, int style = ITEMDRAW_DEFAULT) {
		char dummy[8];
		IntToString(info, dummy, sizeof(dummy));
		return view_as<Menu>(this).AddItem(dummy, display, style);
	}
	
	public bool AddItemIntEx(int info, const char[] display, int style = ITEMDRAW_DEFAULT, any ...) {
		char dummy[8];
		IntToString(info, dummy, sizeof(dummy));
		int maxlen = strlen(display)+65;
		char[] format = new char[maxlen];
		VFormat(format, maxlen, display, 5);
		return view_as<Menu>(this).AddItem(dummy, format, style);
	}
	
	public bool AddItemAny(any info, const char[] display, int style = ITEMDRAW_DEFAULT) {
		char dummy[16];
		IntToString(info, dummy, sizeof(dummy));
		return view_as<Menu>(this).AddItem(dummy, display, style);
	}
	
	public bool AddItemAnyEx(any info, const char[] display, int style = ITEMDRAW_DEFAULT, any ...) {
		char dummy[16];
		IntToString(info, dummy, sizeof(dummy));
		int maxlen = strlen(display)+65;
		char[] format = new char[maxlen];
		VFormat(dummy, maxlen, display, 5);
		return view_as<Menu>(this).AddItem(dummy, format, style);
	}
	
	public bool AddItemFloat(float info, const char[] display, int style = ITEMDRAW_DEFAULT) {
		char dummy[16];
		FloatToString(info, dummy, sizeof(dummy));
		return view_as<Menu>(this).AddItem(dummy, display, style);
	}
	
	public bool AddItemFloatEx(float info, const char[] display, int style = ITEMDRAW_DEFAULT, any ...) {
		char dummy[16];
		FloatToString(info, dummy, sizeof(dummy));
		int maxlen = strlen(display)+65;
		char[] format = new char[maxlen];
		VFormat(format, maxlen, display, 5);
		return view_as<Menu>(this).AddItem(dummy, format, style);
	}
	
	public bool VoteMenuAll(int time, int flags = 0) { return VoteMenuToAll(view_as<Menu>(this), time, flags); }
	
	public int GetItemIndex(int position, int &style=0, char[] dispBuf="", int dispBufLen=0) {
		char dummy[16];
		view_as<Menu>(this).GetItem(position, dummy, sizeof(dummy), style, dispBuf, dispBufLen);
		return StringToInt(dummy);
	}
	
	public float GetItemFloat(int position, int &style=0, char[] dispBuf="", int dispBufLen=0) {
		char dummy[16];
		view_as<Menu>(this).GetItem(position, dummy, sizeof(dummy), style, dispBuf, dispBufLen);
		return StringToFloat(dummy);
	}
	
	public any GetItemAny(int position, int &style=0, char[] dispBuf="", int dispBufLen=0) {
		char dummy[16];
		view_as<Menu>(this).GetItem(position, dummy, sizeof(dummy), style, dispBuf, dispBufLen);
		return StringToAny(dummy);
	}
	
	/**
	 *	Returns if the item position contains string.
	 *
	 *	@param	position		The item position.
	 *	@param	substr			The substring used to check if item contains defined string value.
	 *	@param	caseSensitive	If true, search is case sensitive.
	 */
	public bool ItemStrContains(int position, const char[] substr, bool caseSensitive=false) {
		char dummy[128];
		view_as<Menu>(this).GetItem(position, dummy, sizeof(dummy));
		return (StrContains(dummy, substr, caseSensitive) > 0);
	}
}

methodmap PanelEx < Panel {
	/*
	 *	Constructor for a new Panel.
	 *
	 *	@param	hStyle	MenuStyle Handle, or null to use the default style.
	 */
	public PanelEx(Handle hStyle=null) {return view_as<PanelEx>(new Panel(hStyle));}
	
	/*
	 *	Sets the panel's title.
	 *
	 *	@param	text	Text to set as the title.
	 *	@param	...		Additional parameters.
	 */
	public bool SetTitle(const char[] text, any ...) {
		int maxlen = strlen(text)+65;
		char[] dummy = new char[maxlen];
		VFormat(dummy, maxlen, text, 3); /* 1 is the panel, 2 is the input, 3 is the parameters */
		view_as<Panel>(this).SetTitle(dummy);
	}
	
	/*
	 *	Draws an item on a panel.  If the item takes up a slot, the position is returned.
	 *
	 *	@param	text	Display text to use.  If not a raw line,
	 *					the style may automatically add color markup.
	 *					No numbering or newlines are needed.
	 *
	 *	@param	...		Additional parameters.
	 *
	 *	@return			A slot position, or 0 if item was a rawline or could not be drawn.
	 */
	public int DrawItem(const char[] text, any ...) {
		int maxlen = strlen(text)+65;
		char[] dummy = new char[maxlen];
		VFormat(dummy, maxlen, text, 3);
		return view_as<Panel>(this).DrawItem(dummy);
	}
	
	/*
	 *	Draws an item on a panel.  If the item takes up a slot, the position is returned.
	 *
	 *	@param	text	Display text to use.  If not a raw line,
	 *					the style may automatically add color markup.
	 *					No numbering or newlines are needed.
	 *
	 *	@param	style	ITEMDRAW style flags.
	 *	@param	...		Additional parameters.
	 *
	 *	@return			A slot position, or 0 if item was a rawline or could not be drawn.
	 */
	public int DrawItemEx(const char[] text, int style=ITEMDRAW_DEFAULT, any ...) {
		int maxlen = strlen(text)+65;
		char[] dummy = new char[maxlen];
		VFormat(dummy, maxlen, text, 4);
		return view_as<Panel>(this).DrawItem(dummy, style);
	}
	
	/*
	 *	Draws a raw line of text on a panel, without any markup other than a newline.
	 *
	 *	@param	text	Display text to use.
	 *	@param	...		Additional parameters.
	 *
	 *	@return			True on success, false if raw lines are not supported.
	 */
	public bool DrawText(const char[] text, any ...) {
		int maxlen = strlen(text)+65;
		char[] dummy = new char[maxlen];
		VFormat(dummy, maxlen, text, 3);
		return view_as<Panel>(this).DrawText(dummy);
	}
	
	/*
	 *	Draws a space on a panel.
	 *
	 *	@return			True on success, false if raw lines are not supported.
	 */
	public bool DrawSpace() { return view_as<Panel>(this).DrawText(" "); }
	
	/*
	 *	Returns whether or not the given drawing flags are supported by the menu style.
	 *
	 *	@param	style	ITEMDRAW style flags.
	 *
	 *	@return		True if item is drawable, false otherwise.
	 */
	public bool CanDrawFlags(int style) { return view_as<Panel>(this).CanDrawFlags(style); }
	
	/*
	 *	Sets the selectable key map of a panel. This is not supported by
	 *											all styles (only by Radio, as of this writing).
	 *
	 *	@param	keys	An integer where each bit N allows key
	 *					N+1 to be selected.  If no keys are selectable,
	 *					then key 0 (bit 9) is automatically set.
	 *
	 *	@return			True if supported, false otherwise.
	 */
	public bool SetKeys(int keys) { return view_as<Panel>(this).SetKeys(keys); }
	
	/*
	 *	Sends a panel to a client.	Unlike full menus, the handler
	 *								function will only receive the following actions, both of
	 *								which will have null for a menu, and the client as param1.
	 *
	 *	MenuAction_Select (param2 will be the key pressed)
	 *	MenuAction_Cancel (param2 will be the reason)
	 *
	 *	Also, if the menu fails to display, no callbacks will be called.
	 *
	 *	The panel will be automatically destroyed after being sent.
	 *
	 *	@param	client		A client to draw to.
	 *	@param	handler		The MenuHandler function to catch actions with.
	 *	@param	time		Time to hold the menu for.
	 *
	 *	@return				True on success, false on failure.
	 */
	public void Send(int client, MenuHandler handler, int time=MENU_TIME_FOREVER)	{
		view_as<Panel>(this).Send(client, handler, time);
		delete view_as<Panel>(this);
	}
	
	/*
	 *	Returns the amount of text the menu can still hold.  If this is
	 *	limit is reached or overflowed, the text is silently truncated.
	 *
	 *	Radio menus: Currently 511 characters (512 bytes).
	 *	Valve menus: Currently -1 (no meaning).
	 */
	property int TextRemaining {
		public get() { return view_as<Panel>(this).TextRemaining; }
	}
	
	/*
	 *	Returns or sets the current key position, starting at 1. This cannot be
	 *	used to traverse backwards.
	 */
	property int CurrentKey {
		public get() { return view_as<Panel>(this).CurrentKey; }
		public set(int key) { view_as<Panel>(this).CurrentKey = key; }
	}
	
	/*
	 *	Returns the panel's style. Style handles are global and cannot be closed.
	 */
	property Handle Style {
		public get() { return view_as<Panel>(this).Style; }
	}
}

//Same as DBResultSet, just added DBResultSet.FetchBool value.
methodmap DBResultSetEx < DBResultSet {
	// Advances to the next set of results.
	//
	// In some SQL implementations, multiple result sets can exist on one query.  
	// This is possible in MySQL with simple queries when executing a CALL 
	// query.  If this is the case, all result sets must be processed before
	// another query is made.
	//
	// @return             True if there was another result set, false otherwise.
	public bool FetchMoreResults() { return view_as<DBResultSet>(this).FetchMoreResults(); }

	// Returns whether or not a result set exists.  This will
	// return true even if 0 results were returned, but false
	// on queries like UPDATE, INSERT, or DELETE.
	property bool HasResults {
		public get() { return view_as<DBResultSet>(this).HasResults; }
	}

	// Retrieves the number of rows in the last result set.
	// 
	// @param query        A query (or statement) Handle.
	// @return             Number of rows in the current result set.
	property int RowCount {
		public get() { return view_as<DBResultSet>(this).RowCount; }
	}

	// Retrieves the number of fields in the last result set.
	property int FieldCount {
		public get() { return view_as<DBResultSet>(this).FieldCount; }
	}

	// Returns the number of affected rows from the query that generated this
	// result set.
	property int AffectedRows {
		public get() { return view_as<DBResultSet>(this).AffectedRows; }
	}

	// Returns the insert id from the query that generated this result set.
	property int InsertId {
		public get() { return view_as<DBResultSet>(this).InsertId; }
	}

	// Retrieves the name of a field by index.
	// 
	// @param field        Field number (starting from 0).
	// @param name         Name buffer.
	// @param maxlength    Maximum length of the name buffer.
	// @error              Invalid field index, or no current result set.
	public void FieldNumToName(int field, char[] name, int maxlength) { view_as<DBResultSet>(this).FieldNumToName(field, name, maxlength); }

	// Retrieves a field index by name.
	// 
	// @param name         Name of the field (case sensitive).
	// @param field        Variable to store field index in.
	// @return             True if found, false if not found.
	// @error              No current result set.
	public bool FieldNameToNum(const char[] name, int &field) { view_as<DBResultSet>(this).FieldNameToNum(name, field); }

	// Fetches a row from the current result set.  This must be 
	// successfully called before any results are fetched.
	//
	// If this function fails, MoreRows can be used to
	// tell if there was an error or the result set is finished.
	// 
	// @return             True if a row was fetched, false otherwise.
	public bool FetchRow() { return view_as<DBResultSet>(this).FetchRow(); }

	// Returns if there are more rows.
	// 
	// @return             True if there are more rows, false otherwise.
	property bool MoreRows {
		public get() { return view_as<DBResultSet>(this).MoreRows; }
	}

	// Rewinds a result set back to the first result.
	// 
	// @return             True on success, false otherwise.
	// @error              No current result set.
	public bool Rewind() { return view_as<DBResultSet>(this).Rewind(); }

	// Fetches a string from a field in the current row of a result set.  
	// If the result is NULL, an empty string will be returned.  A NULL 
	// check can be done with the result parameter, or SQL_IsFieldNull().
	// 
	// @param field        The field index (starting from 0).
	// @param buffer       String buffer.
	// @param maxlength    Maximum size of the string buffer.
	// @param result       Optional variable to store the status of the return value.
	// @return             Number of bytes written.
	// @error              Invalid field index, invalid type conversion requested
	//                     from the database, or no current result set.
	public int FetchString(int field, char[] buffer, int maxlength, DBResult &result=DBVal_Error) { return view_as<DBResultSet>(this).FetchString(field, buffer, maxlength, result); }

	// Fetches a float from a field in the current row of a result set.  
	// If the result is NULL, a value of 0.0 will be returned.  A NULL 
	// check can be done with the result parameter, or SQL_IsFieldNull().
	// 
	// @param field        The field index (starting from 0).
	// @param result       Optional variable to store the status of the return value.
	// @return             A float value.
	// @error              Invalid field index, invalid type conversion requested
	//                     from the database, or no current result set.
	public float FetchFloat(int field, DBResult &result=DBVal_Error) { return view_as<DBResultSet>(this).FetchFloat(field, result); }

	// Fetches an integer from a field in the current row of a result set.  
	// If the result is NULL, a value of 0 will be returned.  A NULL 
	// check can be done with the result parameter, or SQL_IsFieldNull().
	// 
	// @param field        The field index (starting from 0).
	// @param result       Optional variable to store the status of the return value.
	// @return             An integer value.
	// @error              Invalid field index, invalid type conversion requested
	//                     from the database, or no current result set.
	public int FetchInt(int field, DBResult &result=DBVal_Error) { return view_as<DBResultSet>(this).FetchInt(field, result); }
	
	// Fetches a boolean from a field in the current row of a result set.  
	// If the result is NULL, a value of false will be returned.  A NULL 
	// check can be done with the result parameter, or SQL_IsFieldNull().
	// 
	// @param field        The field index (starting from 0).
	// @param result       Optional variable to store the status of the return value.
	// @return             A boolean value.
	// @error              Invalid field index, invalid type conversion requested
	//                     from the database, or no current result set.
	public bool FetchBool(int field, DBResult &result=DBVal_Error) { return view_as<bool>(view_as<DBResultSet>(this).FetchInt(field, result)); }

	// Returns whether a field's data in the current row of a result set is 
	// NULL or not.  NULL is an SQL type which means "no data."
	// 
	// @param field        The field index (starting from 0).
	// @return             True if data is NULL, false otherwise.
	// @error              Invalid field index, or no current result set.
	public bool IsFieldNull(int field) { return view_as<DBResultSet>(this).IsFieldNull(field); }

	// Returns the length of a field's data in the current row of a result
	// set.  This only needs to be called for strings to determine how many
	// bytes to use.  Note that the return value does not include the null
	// terminator.
	// 
	// @param field        The field index (starting from 0).
	// @return             Number of bytes for the field's data size.
	// @error              Invalid field index or no current result set.
	public int FetchSize(int field) { return view_as<DBResultSet>(this).FetchSize(field); }
}

/**
 *	Creates a new console boolean variable.
 *
 *	@param	name			Name of new convar.
 *	@param	defaultValue	The default boolean value of new convar.
 *	@param	description		Optional description of the convar.
 *	@param	flags			Optional bitstring of flags determining how the convar should be handled. See FCVAR_* constants for more details.
 *	@param	hasMin			Optional boolean that determines if the convar has a minimum value.
 *	@param	min				Minimum floating point value that the convar can have if hasMin is true.
 *	@param	hasMax			Optional boolean that determines if the convar has a maximum value.
 *	@param	max				Maximum floating point value that the convar can have if hasMax is true.
 *
 *	@return					A handle to the newly created convar. If the convar already exists, a handle to it will still be returned.
 *
 *	@error               Convar name is blank or is the same as an existing console command.
 */
stock ConVar CreateConVarBool(const char[] name, bool defaultValue, const char[] description, int flags=0) { return CreateConVar(name, defaultValue ? "1":"0", description, flags, true, 0.0, true, 1.0); }

/**
 *	Adds ConVar flag(s).
 *
 *	@param	cvar	The ConVar to change.
 *	@param	flags	The flags to add.
 *
 *	@error	If the ConVar is invalid, this returns false.
 */
stock bool AddConVarFlags(ConVar cvar, int flags)	{
	if(cvar == null) return	false;
	
	cvar.Flags |= flags;
	return true;
}

/**
 *	Adds ConVar flag(s).
 *
 *	@param	cvar	The ConVar name to change.
 *	@param	flags	The flags to add.
 *
 *	@error	If the ConVar is invalid, this returns false.
 */
stock bool AddConVarFlagsEx(const char[] convar, int flags)	{
	ConVar cvar = FindConVar(convar);
	if(cvar == null) {
		delete cvar;
		return false;
	}
	
	cvar.Flags |= flags;
	delete cvar;
	return true;
}

/**
 *	Removes ConVar flag(s).
 *
 *	@param	cvar	The ConVar to change.
 *	@param	flags	The flags to remove.
 *
 *	@error	If the ConVar is invalid, this returns false.
 */
stock bool RemoveConVarFlags(ConVar cvar, int flags)	{
	if(cvar == null) return false;
	
	int flag = cvar.Flags;
	flag &= ~flags;
	cvar.Flags = flag;
	return true;
}

/**
 *	Removes ConVar flag(s).
 *
 *	@param	cvar	The ConVar name to change.
 *	@param	flags	The flags to remove.
 *
 *	@error	If the ConVar is invalid, this returns false.
 */
stock bool RemoveConVarFlagsEx(const char[] convar, int flags)	{
	ConVar cvar = FindConVar(convar);
	if(cvar == null) {
		delete cvar;
		return false;
	}
	
	int flag = cvar.Flags;
	flag &= ~flags;
	cvar.Flags = flag;
	delete cvar;
	return true;
}

/**
 *	Returns if the address handle is valid.
 *
 *	@param	address		The address handle.
 *
 *	@return	If handle is valid, this returns true. Returns false otherwise.
 */
stock bool IsValidAddress(Address address) { return view_as<bool>(address != Address_Null); }