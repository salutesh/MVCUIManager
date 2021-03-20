class MVCPlayerListEntry: MVCScriptView
{	
	protected ImageWidget player_icon;
	protected TextWidget player_name;
	string m_Name;
	string m_ID;
	
	void MVCPlayerListEntry(string name, string id)
	{
		SetName(name);
		SetID(id);
	}
	
	override string GetLayoutFile() 
	{
		return "Steve/MVCUIM/GUI/layouts/mvc_player_list_entry.layout";
	}
	
	override typename GetControllerType()
	{
		return MVCPlayerListEntryController;
	}
	
	void SetName(string name)
	{
		MVCPlayerListEntryController controller = MVCPlayerListEntryController.Cast(GetController());
		if (controller)
		{
			controller.PlayerName = name;
			controller.NotifyPropertyChanged("PlayerName");
		}
		
		m_Name = name;
	}
	
	void SetID(string id)
	{
		MVCPlayerListEntryController controller = MVCPlayerListEntryController.Cast(GetController());
		if (controller)
		{
			controller.PlayerID = id;
			controller.NotifyPropertyChanged("PlayerID");
		}
		
		m_ID = id;
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == GetLayoutRoot())
		{
			player_name.SetColor(ARGB(255,1,1,1));
			player_icon.SetColor(ARGB(255,1,1,1));
		}
		
		return super.OnMouseEnter(w, x, y);
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w == GetLayoutRoot())
		{
			player_name.SetColor(ARGB(255,220,220,220));
			player_icon.SetColor(ARGB(255,220,220,220));
		}
		
		return super.OnMouseLeave(w, enterW, x, y);
	}
};