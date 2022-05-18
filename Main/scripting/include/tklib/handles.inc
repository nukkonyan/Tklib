methodmap MenuEx < Menu {
	public MenuEx(MenuHandler handler) {
		return view_as<MenuEx>(new Menu(handler));
	}
	
	public void SetTitle(const char[] fmt, any ...) {
		char format[256];
		VFormat(format, sizeof(format), fmt, 3);
		
		view_as<Menu>(this).SetTitle(format);
	}
	
	public bool AddItem(const char[] info, const char[] display, int style = ITEMDRAW_DEFAULT) {
		return view_as<Menu>(this).AddItem(info, display, style);
	}
	
	public bool AddItemEx(const char[] info, const char[] display, int style = ITEMDRAW_DEFAULT, any ...) {
		char format[256];
		VFormat(format, sizeof(format), display, 5);
		
		return view_as<Menu>(this).AddItem(info, format, style);
	}
	
	public bool AddItemInt(int info, const char[] display, int style = ITEMDRAW_DEFAULT) {
		char format[256];
		Format(format, sizeof(format), "%i", info);
		return view_as<Menu>(this).AddItem(format, display, style);
	}
	
	public bool AddItemIntEx(int info, const char[] display, int style = ITEMDRAW_DEFAULT, any ...) {
		char format1[256], format2[256];
		Format(format1, sizeof(format1), "%i", info);
		VFormat(format2, sizeof(format2), display, 5);
		
		return view_as<Menu>(this).AddItem(format1, format2, style);
	}
	
	public bool AddItemFloat(float info, const char[] display, int style = ITEMDRAW_DEFAULT) {
		char format[256];
		Format(format, sizeof(format), "%f", info);
		return view_as<Menu>(this).AddItem(format, display, style);
	}
	
	public bool AddItemFloatEx(float info, const char[] display, int style = ITEMDRAW_DEFAULT, any ...) {
		char format1[256], format2[256];
		Format(format1, sizeof(format1), "%f", info);
		VFormat(format2, sizeof(format2), display, 5);
		
		return view_as<Menu>(this).AddItem(format1, format2, style);
	}
	
	public bool VoteMenuAll(int time, int flags = 0) {
		return VoteMenuToAll(view_as<Menu>(this), time, flags);
	}
	
	public int GetItemIndex(int position, int &style=0, char[] dispBuf="", int dispBufLen=0) {
		char buffer[256];
		view_as<Menu>(this).GetItem(position, buffer, sizeof(buffer), style, dispBuf, dispBufLen);
		return StringToInt(buffer);
	}
	
	public float GetItemFloat(int position, int &style=0, char[] dispBuf="", int dispBufLen=0) {
		char buffer[256];
		view_as<Menu>(this).GetItem(position, buffer, sizeof(buffer), style, dispBuf, dispBufLen);
		return StringToFloat(buffer);
	}
}

methodmap PanelEx < Panel {
	/*
	 *	Constructor for a new Panel.
	 *
	 *	@param	hStyle	MenuStyle Handle, or null to use the default style.
	 */
	public PanelEx(Handle hStyle=null) {
		return view_as<PanelEx>(new Panel(hStyle));
	}
	
	/*
	 *	Sets the panel's title.
	 *
	 *	@param	text	Text to set as the title.
	 *	@param	...		Additional parameters.
	 */
	public bool SetTitle(const char[] text, any ...) {
		char buffer[96];
		VFormat(buffer, sizeof(buffer), text, 3); /* 1 is the panel, 2 is the input, 3 is the parameters */
		view_as<Panel>(this).SetTitle(buffer);
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
		char buffer[96];
		VFormat(buffer, sizeof(buffer), text, 3);
		return view_as<Panel>(this).DrawItem(buffer);
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
		char buffer[96];
		VFormat(buffer, sizeof(buffer), text, 4);
		return view_as<Panel>(this).DrawItem(buffer, style);
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
		char buffer[96];
		VFormat(buffer, sizeof(buffer), text, 3);
		return view_as<Panel>(this).DrawText(buffer);
	}
	
	/*
	 *	Draws a space on a panel.
	 *
	 *	@return			True on success, false if raw lines are not supported.
	 */
	public bool DrawSpace() {
		return view_as<Panel>(this).DrawText(" ");
	}
	
	/*
	 *	Returns whether or not the given drawing flags are supported by the menu style.
	 *
	 *	@param	style	ITEMDRAW style flags.
	 *
	 *	@return		True if item is drawable, false otherwise.
	 */
	public bool CanDrawFlags(int style) {
		return view_as<Panel>(this).CanDrawFlags(style);
	}
	
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
	public bool SetKeys(int keys) {
		return view_as<Panel>(this).SetKeys(keys);
	}
	
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
	public void Send(int client, MenuHandler handler, int time)	{
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
		public get() {
			return view_as<Panel>(this).TextRemaining;
		}
	}
	
	/*
	 *	Returns or sets the current key position, starting at 1. This cannot be
	 *	used to traverse backwards.
	 */
	property int CurrentKey {
		public get() {
			return view_as<Panel>(this).CurrentKey;
		}
		public set(int key) {
			view_as<Panel>(this).CurrentKey = key;
		}
	}
	
	/*
	 *	Returns the panel's style. Style handles are global and cannot be closed.
	 */
	property Handle Style {
		public get() {
			return view_as<Panel>(this).Style;
		}
	}
}