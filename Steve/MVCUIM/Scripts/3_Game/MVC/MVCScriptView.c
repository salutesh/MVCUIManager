class MVCScriptView: ScriptView
{
	private bool m_IsVisible = true;
	protected ref Timer m_UpdateTimer;
	
	void MVCScriptView()
	{		
		Debug_Logging = true;
	}
	
	void SetIsVisible(bool state)
	{
		m_IsVisible = state;
	}
	
	bool IsVisible()
	{
		return m_IsVisible;
	}
	
	void Show()
	{			
		SetIsVisible(true);
		GetLayoutRoot().Show(true);
		CreateUpdateTimer();
		OnShow();
	}
	
	void OnShow();
	
	void Hide()
	{
		SetIsVisible(false);
		GetLayoutRoot().Show(false);
		DestroyUpdateTimer();
		OnHide();
	}
	
	void OnHide();
	
	bool CanShow()
	{
		return false;
	}
	
	float GetUpdateTickRate()
	{
		return -1;
	}
	
	private void CreateUpdateTimer()
	{
		if (!m_UpdateTimer && GetUpdateTickRate() != -1)
		{
			m_UpdateTimer = new Timer(CALL_CATEGORY_GUI);
			m_UpdateTimer.Run(GetUpdateTickRate(), this, "Update", NULL, true);
		}
	}
	
	private void DestroyUpdateTimer()
	{
		if (m_UpdateTimer)
		{
			m_UpdateTimer.Stop();
			delete m_UpdateTimer;
		}
	}
	
	void Update();
}