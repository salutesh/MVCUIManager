modded class DayZGame
{
	ref MVCUIManager m_MVCUIManager;

	void DayZGame()
	{
		CreateMVCUIManager();
	}

	void ~DayZGame()
	{
		DestroyMVCUIManager();
	}

	void CreateMVCUIManager()
	{
		if (!m_MVCUIManager)
			m_MVCUIManager = new MVCUIManager();
	}

	void DestroyMVCUIManager()
	{
		if (m_MVCUIManager)
			delete m_MVCUIManager;
	}

	MVCUIManager GetMVCUIManager()
	{
		return m_MVCUIManager;
	}
}