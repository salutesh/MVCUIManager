class MVCUIMenuManager
{
    ref MVCUIManager m_MVCUIManager;
	void ExpansionUIMenuManager(MVCUIManager uiManager)
	{
		m_MVCUIManager = uiManager;
		
		RegisterMenus();
	}
	
	void RegisterMenus();
	
	MVCUIManager GetMVCUIManager()
	{
		return m_MVCUIManager;
	}
};