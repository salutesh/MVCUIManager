class MVCPlayerListMenu: MVCScriptViewMenu
{
	ref MVCPlayerListMenuController m_MenuController;
	
	void MVCPlayerListMenu()
	{
		m_MenuController = MVCPlayerListMenuController.Cast(GetController());
	}
	
	override string GetLayoutFile() 
	{
		return "Steve/MVCUIM/GUI/layouts/mvc_player_list.layout";
	}
	
	override typename GetControllerType() 
	{
		return MVCPlayerListMenuController;
	}
	
	void PopulatePlayerList()
	{
		for (int i = 0; i < m_MenuController.PlayerList.Count(); i++) {
			m_MenuController.PlayerList.Remove(i);
		}

		foreach (SyncPlayer player: ClientData.m_PlayerList.m_PlayerList) {
			if (!player) {
				continue;
			}

			m_MenuController.PlayerList.Insert(new MVCPlayerListEntry(player.m_PlayerName, player.m_RUID));
		}
		
		m_MenuController.PlayerCount = m_MenuController.PlayerList.Count();
		m_MenuController.NotifyPropertyChanged("PlayerCount");
	}
	
	override void OnShow()
	{
		super.OnShow();
		
		PopulatePlayerList();
	}
};