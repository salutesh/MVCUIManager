modded class MissionGameplay
{
    ref MVCUIMenuManager m_MVCUIMenuManager;

	override void Pause()
	{
		if ( GetDayZGame().GetMVCUIManager().GetMenu() )
			return;
		
		super.Pause();
	}

	override void CloseAllMenus()
	{
		super.CloseAllMenus();
		
		if ( GetDayZGame().GetMVCUIManager().GetMenu() )
			GetDayZGame().GetMVCUIManager().CloseAll();
	}

    void CreateMVCUIMenuManager()
	{
		ref MVCUIManager mvcUIManager = GetDayZGame().GetMVCUIManager();
		if (mvcUIManager && !m_MVCUIMenuManager)
			m_MVCUIMenuManager = new MVCUIMenuManager(mvcUIManager);
	}
	
	void DestroyExpansionUIMenuManager()
	{
		if (m_MVCUIMenuManager)
			delete m_MVCUIMenuManager;
	}
	
	MVCUIMenuManager GetMVCUIMenuManager()
	{
		return m_MVCUIMenuManager;
	}
};